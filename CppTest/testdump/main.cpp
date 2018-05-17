#include <stdio.h>
#include <Windows.h>
#include <DbgHelp.h>
#include <assert.h>

#pragma comment(lib, "Dbghelp.lib")

LONG WINAPI MyUnhandledExceptionFilter(PEXCEPTION_POINTERS pExceptionPointers)
{
	SetErrorMode(SEM_NOGPFAULTERRORBOX);

	DWORD dwBufferSize = MAX_PATH;    
	SYSTEMTIME stLocalTime;

	GetLocalTime(&stLocalTime);

	HMODULE currentModule=GetModuleHandle(NULL);
	char exeFileName[512]={0};
	char workFullDir[512]={0};
	char szFileName[512]={0};

	if(!GetModuleFileNameA(currentModule,exeFileName,sizeof(exeFileName)-1))
	{
		int res=GetLastError();
		if(0<res)
			res=0-res;
		res+=-10;
		return res;
	}
	strncpy(workFullDir,exeFileName,sizeof(workFullDir));
	char* pos=strrchr(workFullDir,'\\');
	if(NULL==pos)
		return -2;
	++pos;
	*pos=0;  

	sprintf(szFileName, "%s-%04d%02d%02d-%02d%02d%02d.dmp",
		exeFileName,
		stLocalTime.wYear, stLocalTime.wMonth, stLocalTime.wDay,
		stLocalTime.wHour, stLocalTime.wMinute, stLocalTime.wSecond);

	HANDLE hDumpFile = CreateFileA(szFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);

	MINIDUMP_EXCEPTION_INFORMATION ExpParam = {0};
	ExpParam.ThreadId = GetCurrentThreadId();
	ExpParam.ExceptionPointers = pExceptionPointers;
	ExpParam.ClientPointers = FALSE;

	MINIDUMP_TYPE MiniDumpWithDataSegs = (MINIDUMP_TYPE)(MiniDumpNormal | MiniDumpWithHandleData | MiniDumpWithUnloadedModules);
	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpWithDataSegs, &ExpParam, NULL, NULL);
	CloseHandle(hDumpFile);

	return EXCEPTION_CONTINUE_SEARCH; 
}


void DumpCore()
{
	SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);
	void *addr = (void *)GetProcAddress(GetModuleHandleA("kernel32.dll"), "SetUnhandledExceptionFilter");
	if (addr != NULL)
	{
		unsigned char code[16] = {0};
		int size = 0;
		code[size++] = 0x33;
		code[size++] = 0xC0;
		code[size++] = 0xC2;
		code[size++] = 0x04;
		code[size++] = 0x00;
		DWORD dwOldFlag = 0, dwTmpFlag = 0;

		VirtualProtect(addr, size, PAGE_READWRITE, &dwOldFlag);
		WriteProcessMemory(GetCurrentProcess(), addr, code, size, NULL);
		VirtualProtect(addr, size, dwOldFlag, &dwTmpFlag);
	}
}

void Check()
{
	int ptrSize = sizeof(void*);
	printf("Pointer Size[%d]\n", ptrSize);

#if defined WIN64 || __LP64__
	assert(ptrSize == 8);
#else
	assert(ptrSize == 4);
#endif
}


int main(int argc, char* argv[])
{
	Check();
	DumpCore();
	int a = 0;
	return 1;
}

