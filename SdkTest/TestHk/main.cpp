#include <stdio.h>
#include <EnHkApi.h>
#ifdef WIN32
	#include "winsock2i.h"
	#include <windef.h>
	#include <errno.h>
	#include <process.h>
#else
	#define CALLBACK
#endif


#ifdef  WIN32
void CALLBACK HCRealDataCallBackFunc(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser);
#else
void HCRealDataCallBackFunc(int lRealHandle, unsigned int dwDataType, unsigned char *pBuffer,
												   unsigned int dwBufSize,unsigned int dwUser);
#endif

class MyHk
{
public:
	MyHk()
	{

	}
	~MyHk()
	{

	}
	int Run()
	{
		EnHK_Init();
		long loginHandle = EnHK_Login();
		EnHK_OpenRealMedia(loginHandle, (ENHCRealDataCallBackFunc)HCRealDataCallBackFunc, (unsigned int)this);
		return 0;
	}
	int Data(char* buffer, int size)
	{
		printf("%d\n",size);
		static FILE* file = fopen("hk.dav", "wb");
		fwrite(buffer,1,size, file);
		fflush(file);
		return 0;
	}
};
#ifdef WIN32

void CALLBACK CALLBACK HCRealDataCallBackFunc(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser)
#else
void CALLBACK HCRealDataCallBackFunc(int lRealHandle, unsigned int dwDataType, unsigned char *pBuffer,
									   unsigned int dwBufSize,unsigned int dwUser)
#endif
{
	MyHk* hk = (MyHk*)dwUser;
	hk->Data((char*)pBuffer, dwBufSize);
}
int main()
{
	MyHk hk;
	hk.Run();
	getchar();
}