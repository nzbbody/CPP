#include "niu_log.h"

#include <stdio.h>
#include <time.h>


#define LOG(x) do\
{\
	if((_output & (OUTPUT_STD+OUTPUT_CONSOLE)) == 0)\
	{\
		return;\
	}\
	if((_level & LOG_##x) == 0)\
	{\
		return;\
	}\
	char buf[2048] = {0};\
	sprintf(buf,"[" #x " %s %s:%s:%d] ",\
		this->getNowTimeAsString().c_str(),\
		file,\
		func,\
		lineNum);\
	char* p = buf+strlen(buf);\
	va_list ap;\
	va_start(ap, format);\
	p += _vsnprintf(p, sizeof(buf) - 1, format, ap);\
	va_end(ap);\
	int len = strlen(buf);\
	buf[len] = '\r';\
	buf[len+1] = '\n';\
	if((_output & OUTPUT_STD) >0)\
	{\
		printf(buf);\
	}\
	if((_output & OUTPUT_CONSOLE) >0)\
	{\
		::OutputDebugStringA(buf);\
	}\
} while (0)


NiuLog::NiuLog()
{
	_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
}

void NiuLog::Debug(const char* file,const char* func,int lineNum,const char* format, ...)
{
	SetConsoleColor(FOREGROUND_GREEN);
	LOG(DEBUG);
}

void NiuLog::Info(const char* file,const char* func,int lineNum,const char* format, ...)
{
	SetConsoleColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	LOG(INFO);
}

void NiuLog::Warn(const char* file,const char* func,int lineNum,const char* format, ...)
{
	SetConsoleColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	LOG(WARN);
}

void NiuLog::Error(const char* file,const char* func,int lineNum,const char* format, ...)
{
	SetConsoleColor(FOREGROUND_RED|FOREGROUND_INTENSITY);
	LOG(ERROR);
}

void NiuLog::Fatal(const char* file,const char* func,int lineNum,const char* format, ...)
{
	SetConsoleColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	LOG(FATAL);
}

void NiuLog::SetLevel(int level)
{
	_level = level;
}

void NiuLog::SetOutput(int output)
{
	_output = output;
}

string NiuLog::getNowTimeAsString()
{
	char buf[64] = {0};
	time_t now = time(NULL);
	//方法1：
	/*tm* ptm = localtime(&now);
	sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", 
		ptm->tm_year+1900, 
		ptm->tm_mon+1, 
		ptm->tm_mday,
		ptm->tm_hour,
		ptm->tm_min, 
		ptm->tm_sec);*/

	//方法2：
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S",localtime(&now));
	return buf;
}


void NiuLog::SetConsoleColor(WORD colorValue)  
{  
	if (_consoleHandle != INVALID_HANDLE_VALUE)
	{
		SetConsoleTextAttribute(_consoleHandle, colorValue); 
	}	
}  