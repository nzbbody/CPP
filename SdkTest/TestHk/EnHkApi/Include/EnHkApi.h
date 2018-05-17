#ifndef ENHKAPI_H_
#define ENHKAPI_H_

#ifdef  WIN32
	#ifdef ENHKAPI_EXPORTS
	#define AUTOREGDEVICE_API __declspec(dllexport)
	#else
	#define AUTOREGDEVICE_API __declspec(dllimport)
	#endif
#else
	#define AUTOREGDEVICE_API extern "C"
	#define __stdcall
#endif

#ifdef  WIN32
	typedef void (__stdcall *ENHCRealDataCallBackFunc)(long lRealHandle, unsigned long dwDataType, unsigned char *pBuffer,
								  unsigned long dwBufSize,unsigned long dwUser);
#else
typedef void (__stdcall *ENHCRealDataCallBackFunc)(int lRealHandle, unsigned int dwDataType, unsigned char *pBuffer,
												  unsigned int dwBufSize,unsigned int dwUser);
#endif
AUTOREGDEVICE_API int __stdcall EnHK_Init();

AUTOREGDEVICE_API int __stdcall EnHK_Login();

AUTOREGDEVICE_API int __stdcall EnHK_OpenRealMedia(long loginHandle, ENHCRealDataCallBackFunc fun, unsigned int user);

#endif //ENHKAPI_H_