#include <stdio.h>
#include "SimpOs.h"
#include "dhnetsdk.h"
#include <map>
#include <deque>
#include <vector>
#include <time.h>
//#include <Windows.h>
#include <iostream>
#include "Utils.h"

#define USE_THREAD

#define	MAX_NAME_LEN		64  //名称长度
#define MAX_VIDEO_CHNL_PER_DEV	256  //单个设备的视频通道数
#define MAX_CAMERA_NUM_PER_DEVICE	MAX_VIDEO_CHNL_PER_DEV//16
#define MAX_IP_LEN			16  //ip长度

typedef unsigned __int64	uint64;

using namespace std;

typedef struct  
{
	long	loginHandle;
	int		isLoginFlag; //是否已经登录，gaowei 10-01-18
	//存储设备地址，用户名密码，以备断线重连
	char devIp[MAX_IP_LEN];
	int devPort;
	char username[MAX_NAME_LEN];
	char userpsw[MAX_NAME_LEN];
	long  talkHandle;
	bool   talking;
	//[对讲通道 2011-9-5 LvBin]
	struct  
	{
		bool talking;
		long talkHandle;
	}talkInfos[MAX_CAMERA_NUM_PER_DEVICE];

	DHDEV_TALKDECODE_INFO talkMode;
	DHDEV_TALKFORMAT_LIST talkFormatList;

	union
	{
		NET_DEVICEINFO	dhDevInfo;	//dahua device info
		/*		NET_DVR_DEVICEINFO	hcDevInfo;	//hik device info*/
	}deviceInfo;

	struct  
	{
		long monHandle;	//监视句柄
		int  refCount;	//引用计数， -1 表示该通道未被添加
		uint64 lastMakeKeyFrameTime;	//上次调用强制Ｉ帧的时间点。
		DH_RealPlayType streamType;
	}chanInfos[MAX_CAMERA_NUM_PER_DEVICE];
}MonitorDeviceNode;

/*****************************************************************************/
DWORD dwLogin = 0;

typedef struct
{
	int type;
	int channel;
	long talkhandle;
}tmsg;

typedef struct
{
	int channel;
	long talkHandle;
}tinfo;

std::deque<tmsg> msgDeq;
std::map<int, tinfo> channelInfo;


MUTEX(infoMutex)
MUTEX(msgMutex)

MonitorDeviceNode _node = {0};

int openNum = 0;



int GetDeviceTalkCapability(MonitorDeviceNode& node)
{
	int queryTalkRetLen=0;
	BOOL bQueryTalkResult=CLIENT_QueryDevState(node.loginHandle,DH_DEVSTATE_TALK_ECTYPE,
		(char*)&node.talkFormatList,sizeof(node.talkFormatList),&queryTalkRetLen,2000);
	if(!bQueryTalkResult || sizeof(node.talkFormatList)!=queryTalkRetLen)
	{
		node.talkFormatList.nSupportNum=0;
		return -1;
	}
	//对node.talkFormatList进行排序，按照DH_TALK_CODING_TYPE中定义的值从小到大排序
	//如果有不是这里面的则按照sdk给出的顺排列在最后
	//typedef enum __TALK_CODING_TYPE
	//{
	//	DH_TALK_DEFAULT = 0,
	//	DH_TALK_PCM = 1,					//PCM
	//	DH_TALK_G711a,						//G711a
	//	DH_TALK_AMR,						//AMR
	//	DH_TALK_G711u,						//G711u
	//	DH_TALK_G726,						//G726
	//} DH_TALK_CODING_TYPE;
	DHDEV_TALKFORMAT_LIST& formatList=node.talkFormatList;
	std::map<int,DHDEV_TALKDECODE_INFO> tmpMap;
	int unknowIndex=32;
	const int formatCount=formatList.nSupportNum;
	int index=0;
	for(int i=0; formatCount>i;++i)
	{
		switch(formatList.type[i].encodeType)
		{
		case DH_TALK_PCM:
			index=2;
			break;
		case DH_TALK_G711a:
			index=0;
			break;
		case DH_TALK_AMR:
			index=9999;//确保把amr格式放在最后面
			break;
		case DH_TALK_G711u:
			index=1;
			break;
		case DH_TALK_G726:
			index=3;			
			break;
		default:
			index=++unknowIndex;
			break;
		}
		tmpMap[index]=formatList.type[i];
	}
	std::map<int,DHDEV_TALKDECODE_INFO>::iterator iter=tmpMap.begin();
	const std::map<int,DHDEV_TALKDECODE_INFO>::const_iterator end=tmpMap.end();
	index=0;
	for(;end!=iter;++iter)
	{
		formatList.type[index++]=iter->second;
	}
	return 0;
}

void CALLBACK apfAudioDataCallBack(LONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser)
{
// 	FILE *file = fopen("D:\\test1.txt", "a+b");
// 	if (NULL != file)
// 	{
// 		fwrite(pDataBuf, 1, dwBufSize, file);
// 		fclose(file);
// 	}
//	char temp[256] = {0};
//	printf(temp, "handle is %d\r\n", lTalkHandle);
	//OutputDebugString(temp);
	return;
} 

int CALLBACK AnalyzerDataCallBack(LONG lAnalyzerHandle, DWORD dwAlarmType, void* pAlarmInfo, BYTE *pBuffer, DWORD dwBufSize, DWORD dwUser, int nSequence, void *reserved)
{
	/*DEV_EVENT_ALARM_INFO *info = (DEV_EVENT_ALARM_INFO*)pAlarmInfo;
	FILE *file = fopen("D:\\1.jpg","a+b");
	if (NULL != file)
	{
		fwrite(pBuffer, 1, dwBufSize, file);
		fclose(file);
	}*/
	return 1;
}

void CALLBACK DhDisConnectCallBackFunc(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
	dwLogin = 0;
}
int openTalk(int channel, MonitorDeviceNode& node)
{
	int TLen = 1024*1024*8;
	char p[1024*16];

	printf("\n");	
	printf("\n");
	printf("\n");
	printf("openNum=[%d]\n", ++openNum);	

	DHDEV_TALKDECODE_INFO talkMode;
	talkMode = node.talkMode;

	BOOL bSuccess = CLIENT_SetDeviceMode(dwLogin, DH_TALK_ENCODE_TYPE, &talkMode);
	if(!bSuccess)
	{
		printf("DH_TALK_ENCODE_TYPE errot\n");
		return -1;
	}
	bSuccess = CLIENT_SetDeviceMode(dwLogin, DH_TALK_SERVER_MODE, NULL);
	if(!bSuccess)
	{
		printf("DH_TALK_SERVER_MODE errot\n");
		return -1;
	}
	printf("Begining Start Talk [%d]\n",channel);

	BOOL bSetRet1 = CLIENT_SetDeviceMode(dwLogin, DH_TALK_TALK_CHANNEL, &channel);
	if(!bSetRet1)
	{
		printf("DH_TALK_TALK_CHANNEL error channel=[%d]\n",channel);
		return -1;
	}
	long talkHandle = CLIENT_StartTalkEx(dwLogin, apfAudioDataCallBack, NULL);

	if (talkHandle <= 0)
	{
		int error = CLIENT_GetLastError();
		printf("Open Talk Failed------------channel=[%d] handle=[%ld] error=%d\n", channel,talkHandle,error&0xffff);
		return -1;
	}	
	else
	{

		printf("Open Talk Ok++++++++++++++++channel=[%d] handle=[%ld]\n", channel,talkHandle);
	}

	LOCK(infoMutex);
	channelInfo[channel].talkHandle = talkHandle;
	UNLOCK(infoMutex);

	return 0;
}
void *sendData(void *p)
{
	char* buf = new char[1024];
	int num = 0;
	while(TRUE)
	{
		LOCK(infoMutex);
		
		for(std::map<int, tinfo>::iterator ith = channelInfo.begin(); ith != channelInfo.end(); ++ith)
		{
			if (ith->second.talkHandle > 0)
			{
				if(500 == num++)
					printf("send....................... handle=[%ld]\n",ith->second.talkHandle);
				CLIENT_TalkSendData(ith->second.talkHandle, buf, 1024);
			}
		}
		UNLOCK(infoMutex);
		
		SLEEP(10);
	}
	
	return (void*)1;
}
void *openCh(void *p)
{
	printf("open\n");
	int len1 = 1024*1024*16;
	int len2 = 1024*16;
	char* pppp = new char[len1];

	char buffer[1024*16];

	while(TRUE)
	{
		char buffer[1024*16];
		LOCK(msgMutex);
		if(msgDeq.size() <= 0)
		{
			UNLOCK(msgMutex);
			SLEEP(10);
			continue;
		}
		tmsg msg = msgDeq.front();
		msgDeq.pop_front();
		UNLOCK(msgMutex);
		
		if(msg.type == 0)
		{
			LOCK(infoMutex);
			int handle = channelInfo[msg.channel].talkHandle;
			UNLOCK(infoMutex);

			if(handle == 0)
			{
				openTalk(msg.channel, _node);
			}
			
		}
		else
		{		
			LOCK(infoMutex);
			int handle = channelInfo[msg.channel].talkHandle;
			UNLOCK(infoMutex);

			if(handle > 0)
			{
				int ret = CLIENT_StopTalkEx(handle);	
				if(ret)
				{
					printf("Stop Talk Ok++++++++++++++++Channle[%d] handle=[%ld]\n", msg.channel, handle);
					LOCK(infoMutex);
					channelInfo[msg.channel].talkHandle = 0;
					UNLOCK(infoMutex);
				}
				else
				{
					printf("Stop Talk Failed------------Channle[%d] handle=[%ld]\n", msg.channel, handle);
				}
			}			
			
		}  
	}
	return (void*)1;
}
int useThread()
{
	INITMU(msgMutex);
	INITMU(infoMutex);

	char temp[256] = {0};
	CLIENT_Init(NULL,NULL);
	int nError = 0;
	NET_DEVICEINFO netInfor = {0};
	DWORD m_loginID = 0;
	dwLogin = CLIENT_Login("10.22.4.221", 20000, "admin","admin", &netInfor, &nError);
	if(dwLogin <= 0)
	{
		printf("Login device error\n");
		getchar();
		return 1;
	}

	std::vector<int> channels;

	_node.loginHandle = dwLogin;
	int getDevCapRet=GetDeviceTalkCapability(_node);

	_node.talkMode=_node.talkFormatList.type[0];

	tinfo ti;
	ti.talkHandle = 0;

	ti.channel = 2;
	channelInfo[2] = ti;

	ti.channel = 3;
	channelInfo[3] = ti;

	int num = 0;

	unsigned int* threadHandle;
	unsigned int threadId;

	unsigned int* threadHandle1;
	unsigned int threadId1;
	
	//CREATTHD(threadHandle, sendData, threadId, NULL);
	//CREATTHD(threadHandle1, openCh, threadId1, NULL);

	printf("%u   %u\n", threadHandle, threadId, NULL);
	printf("%u   %u\n", threadHandle1, threadId1, NULL);
	
	int len1 = 1024*1024*16;
	int len2 = 1024*16;
	char* p = new char[len1];

	char buffer[1024];

	while(TRUE)
	{
		*(p+openNum%len1) = openNum%10;
		buffer[openNum%len2] = openNum%10;

		num ++;
		tmsg msg = {0};
		msg.type = 0;
		msg.talkhandle = 0;
		switch(num%2)
		{
		case 0: 
		case 1:
			{
				LOCK(msgMutex);
				msg.channel = num%2 + 2;
				msgDeq.push_back(msg);		
				UNLOCK(msgMutex);
			}
			break;
		}
		SLEEP(500);

		LOCK(infoMutex);
		for(std::map<int, tinfo>::iterator ith = channelInfo.begin(); ith != channelInfo.end(); ++ith)
		{
			if(ith->second.talkHandle > 0)
			{
				tmsg msg1;
				msg1.type = 1;
				msg1.channel = ith->second.channel;
				msg1.talkhandle = ith->second.talkHandle;


				LOCK(msgMutex);
				msgDeq.push_back(msg1);
				UNLOCK(msgMutex);
			}
		}
		UNLOCK(infoMutex);;
	}
	
	return 1;
}

int openTalkNoThread(int channel, MonitorDeviceNode& node)
{
	printf("open no thread\n");
	printf("\n");
	printf("%d\n", ++openNum);
	printf("\n");
	printf("\n");
	DHDEV_TALKDECODE_INFO talkMode;
	talkMode = node.talkMode;

	BOOL bSuccess = CLIENT_SetDeviceMode(dwLogin, DH_TALK_ENCODE_TYPE, &talkMode);
	if(!bSuccess)
	{
		printf("DH_TALK_ENCODE_TYPE errot\n");
		return -1;
	}
	bSuccess = CLIENT_SetDeviceMode(dwLogin, DH_TALK_SERVER_MODE, NULL);
	if(!bSuccess)
	{
		printf("DH_TALK_SERVER_MODE errot\n");
		return -1;
	}
	printf("\n");
	printf("\n");
	printf("Begining Start Talk [%d]\n",channel);

	BOOL bSetRet1 = CLIENT_SetDeviceMode(dwLogin, DH_TALK_TALK_CHANNEL, &channel);
	if(!bSetRet1)
	{
		printf("DH_TALK_TALK_CHANNEL error channel=[%d]\n",channel);
		return -1;
	}
	long talkHandle = CLIENT_StartTalkEx(dwLogin, apfAudioDataCallBack, NULL);

	if (talkHandle <= 0)
	{
		int error = CLIENT_GetLastError();
		printf("Open Talk Failed-------------channel=[%d] handle=[%ld] error=%d\n", channel,talkHandle,error&0xffff);
		return -1;
	}	
	    printf("Open Talk Ok+++++++++++++++++Channel=[%d] handle=[%ld]\n", channel,talkHandle);		


	int ret = CLIENT_StopTalkEx(talkHandle);	
	if(ret)
	{
		printf("Stop Talk Ok+++++++++++++++++Channle=[%d] handle=[%ld]\n", channel, talkHandle);
	}
	else
	{
		printf("Stop Talk Failed-------------Channle=[%d] handle=[%ld]\n", channel, talkHandle);
	}
	return 0;
}
int noThread()
{
	char temp[256] = {0};
	CLIENT_Init(NULL,NULL);
	int nError = 0;
	NET_DEVICEINFO tmpInfo = {0};
	DWORD m_loginID = 0;

	NET_PARAM param = {0};
	param.nConnectTime = 3000; //连接建立等待时间稍长一些，防止网络复杂
	param.nConnectTryNum = 2; //为防止出现创建子连接失败，多尝试几次
	CLIENT_SetNetworkParam(&param);

	dwLogin = CLIENT_LoginEx("10.22.4.245", 37777, "admin","admin",6, 0, &tmpInfo, &nError);
	if(dwLogin <= 0)
	{
		printf("Login device error\n");
		return 1;
	}

	std::vector<int> channels;

	_node.loginHandle = dwLogin;
	int getDevCapRet=GetDeviceTalkCapability(_node);

	_node.talkMode=_node.talkFormatList.type[0];
	
	int len1 = 1024*1024*16;
	int len2 = 1024*16;
	char* p = new char[len1];

	char buffer[1024*8];
	while(TRUE)
	{
		*(p+openNum%len1) = openNum%10;
		buffer[openNum%len2] = openNum%10;

		openTalkNoThread(0, _node);
		SLEEP(500);
	}

}

void* TT(void* para)
{
	while(TRUE)
	{
		SLEEP(5);
	}
	return (void*)0;
}
void* TT1(void* para)
{
	while(TRUE)
	{
		SLEEP(5);
	}
	return (void*)0;
}
int testThread()
{
	unsigned int* threadHandle;
	unsigned int threadId;

	unsigned int* threadHandle1;
	unsigned int threadId1;

	CREATTHD(threadHandle, TT, threadId, NULL);
	CREATTHD(threadHandle1, TT1, threadId1,NULL);
	return 0;
}


int CALLBACK CBData(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser)
{
	/*static FILE* file = fopen("c:\\testdh.dav","wb");
	fwrite(pBuffer,dwBufSize,1,file);
	fflush(file);*/
	static time_t startT = time(NULL);
	static DWORD len = 0;
	static BOOL init = FALSE;
	if(init)
	{
		return 1;
	}
	if((time(NULL) - startT) > 10)
	{
		init = TRUE;
		printf("%d\n", len);
	}
	len += dwBufSize;
	return 1;
}
void CALLBACK CBPos(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser)
{
	return ;
}
void CALLBACK disconnectCallback(LONG loginHandle, char *ip, LONG port, DWORD cbParam)
{
	return;
}			   
int PlayBackByTime(const string& ip,int port)
{
	char temp[256] = {0};
	CLIENT_Init(disconnectCallback,NULL);
	int nError = 0;
	NET_DEVICEINFO tmpInfo = {0};
	DWORD m_loginID = 0;

	NET_PARAM param = {0};
	param.nConnectTime = 3000; //连接建立等待时间稍长一些，防止网络复杂
	param.nConnectTryNum = 2; //为防止出现创建子连接失败，多尝试几次
	CLIENT_SetNetworkParam(&param);

	//dwLogin = CLIENT_Login("10.65.2.61", 37777, "admin","admin",&tmpInfo, &nError);
	//dwLogin = CLIENT_LoginEx("10.65.2.64", 37777, "admn","admin",0, 0, &tmpInfo, &nError);


	//dwLogin = CLIENT_Login(const_cast<char*>(ip.c_str()), port, "admin","admin",&tmpInfo, &nError);
	dwLogin = CLIENT_LoginEx(const_cast<char*>(ip.c_str()), port, "admin","admin",0, 0, &tmpInfo, &nError);


	NET_TIME loginTime;


	time_t timeNow = time(NULL);
	//timeNow -= 3600*6;
	struct tm* tmp = localtime(&timeNow);
	if ( NULL == tmp )
	{
		return -1;
	}

	loginTime.dwYear = tmp->tm_year + 1900;
	loginTime.dwMonth = tmp->tm_mon + 1;
	loginTime.dwDay = tmp->tm_mday;
	loginTime.dwHour = tmp->tm_hour;
	loginTime.dwMinute = tmp->tm_min;
	loginTime.dwSecond = tmp->tm_sec;


	
	if(dwLogin <= 0)
	{
		printf("Time[%d-%d-%d] Login device：ip[%s]，port[%d], error[%d]\n",
			loginTime.dwHour,
			loginTime.dwMinute,
			loginTime.dwSecond,
			ip.c_str(),
			port,
			nError);

		std::cout<<endl;
		return 1;
	}

	printf("Time[%d-%d-%d] Login device：ip[%s]，port[%d], ok\n",
		loginTime.dwHour,
		loginTime.dwMinute,
		loginTime.dwSecond,
		ip.c_str(),
		port);

	std::cout<<endl;
	
	NET_TIME beginTime;
	NET_TIME endTime;


	timeNow = time(NULL);
	timeNow -= 3600*6;
	tmp = localtime(&timeNow);
	if ( NULL == tmp )
	{
		return -1;
	}

	beginTime.dwYear = tmp->tm_year + 1900;
	beginTime.dwMonth = tmp->tm_mon + 1;
	beginTime.dwDay = tmp->tm_mday;
	beginTime.dwHour = tmp->tm_hour;
	beginTime.dwMinute = tmp->tm_min;
	beginTime.dwSecond = tmp->tm_sec;

	timeNow = time(NULL);
	tmp = localtime(&timeNow);
	if ( NULL == tmp )
	{
		return -1;
	}

	endTime.dwYear = tmp->tm_year + 1900;
	endTime.dwMonth = tmp->tm_mon + 1;
	endTime.dwDay = tmp->tm_mday;
	endTime.dwHour = tmp->tm_hour;
	endTime.dwMinute = tmp->tm_min;
	endTime.dwSecond = tmp->tm_sec;

	LONG pbHandle = CLIENT_PlayBackByTimeEx(dwLogin, 0, &beginTime, &endTime, NULL,
		CBPos, NULL, CBData, NULL);

	/*
	if(pbHandle == 0)
		printf("CLIENT_PlayBackByTime error=[%d]\n",CLIENT_GetLastError()&0xFFFF);
	else
		printf("CLIENT_PlayBackByTime handle=[%d]\n",pbHandle);
	*/

	return 0;
}

void SearchDevice()
{
	char temp[256] = {0};
	CLIENT_Init(disconnectCallback,NULL);
	int nError = 0;
	NET_DEVICEINFO tmpInfo = {0};
	DWORD m_loginID = 0;

	NET_PARAM param = {0};
	param.nConnectTime = 3000; //连接建立等待时间稍长一些，防止网络复杂
	param.nConnectTryNum = 2; //为防止出现创建子连接失败，多尝试几次
	CLIENT_SetNetworkParam(&param);

	//BOOL CLIENT_SearchDevices(  char*      szBuf,  int        nBufLen,
	//	int*       pRetLen,  DWORD      dwSearchTime,  char*      szLocalIp=NULL);

	const int bufSize = 8096;
	char devBuf[bufSize];
	int totalLength;
	int searchTime = 0;

	printf("Please Input SearchTime(MilliSecond):");
	scanf("%d",&searchTime);

	bool ret = CLIENT_SearchDevices(devBuf,bufSize,&totalLength,searchTime);
	
	int devCount = 0;
	int offset = 0;	
	while(offset < totalLength)
	{
		DEVICE_NET_INFO device;
		memcpy(&device,devBuf+offset,sizeof(DEVICE_NET_INFO));
		offset+=sizeof(DEVICE_NET_INFO);
		PrintDevice(device);
		++devCount;
	}

	printf("Search Total Device[%d]\n\n\n",devCount);
}


int main(int argc, char* argv[])
{
	/*string ipArray[] = {"10.36.65.89","10.36.65.91","10.36.65.24","10.36.65.60",
						"10.36.65.112","10.36.65.55","10.22.4.160","10.65.200.173"};*/

	//string ipArray[] = {"10.36.65.89"};
	//
	//int size = sizeof(ipArray)/sizeof(ipArray[0]);
	//
	//for(int i = 0; i < size; ++i)
	//{
	//	string ip = ipArray[i];

	//	for(int j = 0; j < 40; ++j)
	//	{
	//		int port = j + 37777;
	//		PlayBackByTime(ip,port);
	//	}
	//}
	
	while(true)
	{
		SearchDevice();
	}

	system("pause");
	return 0;

}
