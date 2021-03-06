#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <time.h>
#include "dhnetsdk.h"
#include "dhconfigsdk.h"

#pragma comment(lib , "dhnetsdk.lib")
#pragma comment(lib , "dhconfigsdk.lib")

static LLONG g_lLoginHandle = 0L;
static char g_szDevIp[32] = "10.65.200.168";
static int  g_nPort = 37777;
static char g_szUserName[64] = "admin";
static char g_szPasswd[64] = "admin";

const int SdkWaitTime = 1000*20; // 毫秒

typedef enum tagAUTO_TYPE
{
    AT_ALL  = 0 ,   //全自动
    AT_IP       ,   //IP可输
    AT_IPPORT   ,   //IP和端口
    AT_NULL     ,   //全手输
}AUTO_TYPE;

//**********************************************************************************************
//工具函数集合

void GetNowTime(char *szTime , int nStrLen)
{
    time_t tTime;
    time(&tTime);
    struct tm* t = localtime(&tTime);
    t->tm_year += 1900;
    t->tm_mon +=1;
    
    _snprintf(szTime, nStrLen , "%04d_%02d_%02d_%02d_%02d_%02d", 
        t->tm_year, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
}

int GetIntInput(char *szPromt)
{
    printf(szPromt);
    char szUserInput[32] = "";
    gets(szUserInput);
    return atoi(szUserInput);
}

void GetStringInput(char *szPromt , char *szBuffer)
{
    printf(szPromt);
    gets(szBuffer);
}

BOOL TestAgain()
{
    char szUserInput[32] = "";
    printf("Test Again(y/Y)==>");
    gets(szUserInput);
    if( stricmp(szUserInput , "y") == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
//**********************************************************************************************

//**********************************************************************************************
//常用回调集合
void CALLBACK DisConnectFunc(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, 
							  DWORD dwUser)
{
	printf("Device Disconnect, IP=%s+++++++++++++++++++++++\n", pchDVRIP);
}

//**********************************************************************************************


void EndTest()
{
	printf("input any key to quit!\n");
	getchar();
	
	printf("CLIENT_Cleanup!\n");
	CLIENT_Cleanup();
	exit(0);
}

void GetUserInput(AUTO_TYPE emType)
{
    char szUserInput[64] = "";
    if( emType > AT_ALL )
    {
        memset(g_szDevIp , 0 , sizeof(g_szDevIp));
        printf("Input Login IP ==>\n");
        gets(szUserInput);
        strncpy( g_szDevIp , szUserInput , sizeof(g_szDevIp)-1);
    }

    if ( emType >AT_IP )
    {
        memset(szUserInput , 0 , sizeof(szUserInput));
        printf("Input Login Port ==>\n");
        gets(szUserInput);
        g_nPort = atoi(szUserInput);
    }

    if( emType > AT_IPPORT )
    {
        memset(g_szUserName , 0 , sizeof(g_szUserName));
        memset(szUserInput , 0 , sizeof(szUserInput));
        printf("Input Login User ==>\n");
        gets(szUserInput);
        strncpy( g_szUserName , szUserInput , sizeof(g_szUserName)-1);

        memset(g_szPasswd , 0 , sizeof(g_szPasswd));
        memset(szUserInput , 0 , sizeof(szUserInput));
        printf("Input Login Passwd  ==>\n");
        gets(szUserInput);
        strncpy( g_szPasswd , szUserInput , sizeof(g_szUserName)-1);
    }
}

void InitTest(AUTO_TYPE emType)
{
	CLIENT_Init(DisConnectFunc, 0);
	printf("Initialize client SDK done; \n");
	
	NET_DEVICEINFO stDevInfo = {0};
	int nError = 0;
    while(!g_lLoginHandle)
    {
        GetUserInput(emType);

	    g_lLoginHandle = CLIENT_Login(g_szDevIp, g_nPort, g_szUserName, g_szPasswd, &stDevInfo, &nError);
	    
	    if( g_lLoginHandle == 0 )
	    {
		    printf("CLIENT_Login %s[%d]Failed!Last Error[%x]\n" , g_szDevIp , g_nPort , CLIENT_GetLastError());
	    }
	    else
	    {
		    printf("CLIENT_Login %s[%d] Success\n" , g_szDevIp , g_nPort);
	    }
        Sleep(1000);
        printf("\n");
    }
}

#define TEST_FILE_NUM   1  //不能为1

/*
const char * gszFilePath[TEST_FILE_NUM] = {
    "C:/IVS-S-File/SynRecordFile//1080P_1Min.dav" , "shit"
};
*/

//const char * gszFilePath[TEST_FILE_NUM] = {
//	"C:/davFile/aaa.dav" , "C:/davFile/bbb.dav"
//};

const char * gszFilePath[TEST_FILE_NUM] = {
	"E:/ivss/OrgFile/10000_1010050310113055[20160812T133719Z__20160812T134003Z].dav"
	//"E:/ivss/OrgFile/hhh.dav"
};


//const char * gszFilePath[TEST_FILE_NUM] = {
//	"V:/aaa.dav" , "V:/bbb.dav"
//};
//
//
//
const char * filePath = "V:/";

DWORD gnTaskID[TEST_FILE_NUM];

BOOL gbPreOver = FALSE;

int CALLBACK VideoSynopsisState(LLONG lRealLoadHandle, NET_REAL_SYNOPSIS_STATE_INFO* pSynopsisStateInfos, int nInfoCount, LDWORD dwUser, void* pReserved)
{
	printf("VideoSynopsisState CallBack Handle[%d],TaskId[%d],ObjectNum[%d],TotalProcess[%d]"
		"SynopsisStatus[%s],SynopsisProcess[%d],ErrCode[%s],PicPath[%s],MaxTime[%d],MinTime[%d]\n",
		lRealLoadHandle,
		pSynopsisStateInfos->dwTaskID,
		pSynopsisStateInfos->nObjectNum,
		pSynopsisStateInfos->nTaolProgress,
		pSynopsisStateInfos->szState,
		pSynopsisStateInfos->nProgressOfCurrentState,
		pSynopsisStateInfos->szFailedCode,
		pSynopsisStateInfos->szPicPath,
		pSynopsisStateInfos->nMaxTime,
		pSynopsisStateInfos->nMinTime);

	int hh = dwUser;

    if( pSynopsisStateInfos->nProgressOfCurrentState == 100 )
    {
        gbPreOver = TRUE;
    }

    if( strcmp(pSynopsisStateInfos->szState , "SynopsisFailed") == 0 )
    {
        gbPreOver = TRUE;
    }

    return 0;
}

HWND GetConsoleHandle()
{
    SetConsoleTitleA("Console");
    Sleep(40);
    return FindWindowA(NULL, "Console" );
}

DWORD g_nPlayID = 0;






void SetFilePath()
{
	NET_IN_SET_FILEPATHINFO pathInfo;
	pathInfo.dwSize=sizeof(NET_IN_SET_FILEPATHINFO);
	pathInfo.dwCount=1;
	pathInfo.pFilePathInfo=&filePath;
	pathInfo.dwWaitTime=SdkWaitTime;

	if(CLIENT_SetFilePathInfo(g_lLoginHandle,&pathInfo))
	{
		printf("CLIENT_SetFilePathInfo Success\n");
	}
	else
	{
		printf("CLIENT_SetFilePathInfo Failed!Last Error = %x\n" , CLIENT_GetLastError());
		return;
	}
}


// 特别注意，对struct要初始化为0，再去设置字段，千万不要依赖库的作者初始化
void SetParamForSysnopsis(NET_IN_ADD_VIDEOSYNOPSIS& inParam,NET_OUT_ADD_VIDEOSYNOPSIS& outParam)
{
	memset(&inParam,0,sizeof(NET_IN_ADD_VIDEOSYNOPSIS));
	inParam.dwSize = sizeof(NET_IN_ADD_VIDEOSYNOPSIS);

	memset(&inParam.stuGlobalInfo,0,sizeof(NET_GLOBAL_INFO));
	inParam.stuGlobalInfo.dwSize = sizeof(NET_GLOBAL_INFO);

	memset(&inParam.stuModuleInfo,0,sizeof(NET_MODULE_INFO));
	inParam.stuModuleInfo.dwSize = sizeof(NET_MODULE_INFO);
	// 值越小灵敏度越低 为了更好的效果，建议写10，提高灵敏度
	inParam.stuModuleInfo.bSensitivity = 10;


	memset(&inParam.stuRuleInfo,0,sizeof(NET_VIDEOSYNOPSISRULE_INFO));
	inParam.stuRuleInfo.dwSize   = sizeof(NET_VIDEOSYNOPSISRULE_INFO);
	// 浓缩后输出资料的类型,1-视频大纲(一组快照);2-浓缩视频;3-既有快照又有视频
	inParam.stuRuleInfo.byOutputType = 3;
	// 值越小浓缩密度越低 建议写1
	inParam.stuRuleInfo.byDensity = 1;

	NET_OBJFILTER_INFO filter;
	memset(&filter,0,sizeof(NET_OBJFILTER_INFO));
	filter.dwSize = sizeof(NET_OBJFILTER_INFO);
	sprintf(filter.szObjectType,"Unknown");
	inParam.stuRuleInfo.stuFilter[0] = filter;
	inParam.stuRuleInfo.dwObjFilterNum = 1;
	inParam.nWaitTime = 10000;

	inParam.stuRuleInfo.bShowTime = true;
	inParam.stuRuleInfo.bShowBox = true;
	inParam.stuRuleInfo.bEnableRecordResult = false;
	inParam.stuRuleInfo.bEnableSmoothBorder = FALSE;
	// FALSE-根据原始视频分辨率生产浓缩视频
	inParam.stuRuleInfo.bCustomResolution = FALSE;
	inParam.stuRuleInfo.bEnableMaxUsedCPU = FALSE;

	 // 文件位置信息，用户分配空间
	inParam.dwFileCount = TEST_FILE_NUM;
	inParam.pFilePathInfo = new NET_FILEPATH_INFO[TEST_FILE_NUM];
	memset(inParam.pFilePathInfo,0,sizeof(NET_FILEPATH_INFO)*TEST_FILE_NUM);
	for( int i=0 ; i<TEST_FILE_NUM ; i++)
	{
		inParam.pFilePathInfo[i].dwSize = sizeof(NET_FILEPATH_INFO);
		inParam.pFilePathInfo[i].bFileType = TRUE;
		inParam.pFilePathInfo[i].stuLocalFile.dwSize = sizeof(NET_LOCALFILE_INFO);
		strncpy(inParam.pFilePathInfo[i].stuLocalFile.szFilePath, 
			gszFilePath[i] , MAX_PATH);
	}

	outParam.dwSize = sizeof(NET_OUT_ADD_VIDEOSYNOPSIS);	
	outParam.nTaskIDCount = TEST_FILE_NUM;
	outParam.pnTaskID = gnTaskID;
	memset(outParam.pnTaskID , 0 , sizeof(DWORD)*TEST_FILE_NUM );
}

void OldVideoSynopsisTask()
{
    NET_IN_ADD_VIDEOSYNOPSIS  stAddInParam;
	NET_OUT_ADD_VIDEOSYNOPSIS stAddOutParam;
	SetParamForSysnopsis(stAddInParam,stAddOutParam);

    
    if( CLIENT_AddVideoSynopsisTask(g_lLoginHandle,  &stAddInParam , &stAddOutParam))
    {
        printf("CLIENT_AddVideoSynopsisTask Success\n");
    }
    else
    {
        printf("CLIENT_AddVideoSynopsisTask Failed!Last Error = %d\n" , CLIENT_GetLastError());
        return;
    }

    {
        NET_IN_REALLAOD_SYNOPSISSTATE stInParam = {sizeof(NET_IN_REALLAOD_SYNOPSISSTATE)};
        stInParam.nTaskIDNum = TEST_FILE_NUM;
        stInParam.pTaskIDs = gnTaskID;
        stInParam.nWaitTime = 1000;
        stInParam.cbVideoSynopsisState = VideoSynopsisState;
		stInParam.dwUser = 5;
        NET_OUT_REALLOAD_SYNOPSISSTATE stOutParam = {sizeof(NET_OUT_REALLOAD_SYNOPSISSTATE)};
        if( CLIENT_RealLoadSynopsisState(g_lLoginHandle, &stInParam, &stOutParam))
        {
            printf("CLIENT_RealLoadSynopsisState Success!Handle = %d\n" , stOutParam.lRealLoadHandle);
        }
        else
        {
            printf("CLIENT_RealLoadSynopsisState Failed!Last Error = %d\n" , CLIENT_GetLastError());
        }

		Sleep(1000);
    }

    while (TRUE)
    {
        Sleep(1000);
    }
}

void RunTest()
{
	//SetFilePath();
    OldVideoSynopsisTask();
	return;
}

int main()
{
	char tmp[64];
	sprintf(tmp,"123456");
	sprintf(tmp,"abc");




	InitTest(AT_ALL);
	
	RunTest();
	
	EndTest();
	
	return 0;
}
