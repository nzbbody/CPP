#include "EnHkApi.h"
#include <stdio.h>

#ifdef WIN32
	#include "winsock2i.h"
	#include <windef.h>
	#include <errno.h>
	#include <process.h>
#else
	#include <stdio.h>
#endif
#include "HCNetSDK.h"


AUTOREGDEVICE_API int __stdcall EnHK_Init()
{
	if ( !NET_DVR_Init() )
	{
		return -1;
	}
	return 0;
}
NET_DVR_DEVICEINFO Info = {0};

AUTOREGDEVICE_API int __stdcall EnHK_Login()
{
	printf("adf\n");
	printf("adf++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	long loginHandle = NET_DVR_Login("10.65.2.64", 37777,
		"admin", "admin",
 		&Info);

	return loginHandle;
}
AUTOREGDEVICE_API int __stdcall EnHK_OpenRealMedia(long loginHandle, ENHCRealDataCallBackFunc fun, unsigned int user)
{
	NET_DVR_CLIENTINFO cltInfo = {0};
	cltInfo.lChannel = Info.byStartChan;
	cltInfo.lLinkMode = 0;
	
	LONG monitorHandle = NET_DVR_RealPlay(loginHandle, &cltInfo);
	if (-1 == monitorHandle)
	{
		return -1;
	}
	/*BOOL b = NET_DVR_SetRealDataCallBack(monitorHandle, 
		(void (__stdcall *)(LONG,DWORD,BYTE *,DWORD,DWORD))fun, user);*/

	BOOL b = NET_DVR_SetRealDataCallBack(monitorHandle, 
		fun, user);
	if (!b)
	{
		int error = NET_DVR_GetLastError();
		return -1;
	}
	return monitorHandle;
}
