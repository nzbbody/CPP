#ifndef NIU_LOG_H_
#define NIU_LOG_H_

#ifdef DLL_FILE
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#include <stdarg.h>
#include <string>
#include <windows.h>

using namespace std;

#define LOG_DEBUG	1
#define LOG_INFO	2
#define LOG_WARN	4
#define LOG_ERROR	8
#define LOG_FATAL	16

#define OUTPUT_STD		1
#define OUTPUT_CONSOLE	2


class DLL_API NiuLog
{
public:
	NiuLog();
public:
	void Debug(const char* file,const char* func,int lineNum,const char* format, ...);
	void Info (const char* file,const char* func,int lineNum,const char* format, ...);
	void Warn (const char* file,const char* func,int lineNum,const char* format, ...);
	void Error(const char* file,const char* func,int lineNum,const char* format, ...);
	void Fatal(const char* file,const char* func,int lineNum,const char* format, ...);

	void SetLevel(int level);
	void GetLevel(int& level);

	void SetOutput(int output);
	void GetOutput(int& output);

	inline void SetConsoleColor(WORD colorValue);

private:
	inline string getNowTimeAsString();
	
private:
	int		_level;
	int		_output;
	HANDLE	_consoleHandle;
};

#define LogDebug(log,format,...) do\
{\
	log.Debug(__FILE__, __FUNCTION__, __LINE__,format,##__VA_ARGS__);\
}while(0)

#define LogInfo(log,format,...) do\
{\
	log.Info(__FILE__, __FUNCTION__, __LINE__,format,##__VA_ARGS__);\
}while(0)

#define LogWarn(log,format,...) do\
{\
	log.Warn(__FILE__, __FUNCTION__, __LINE__,format,##__VA_ARGS__);\
}while(0)

#define LogError(log,format,...) do\
{\
	log.Error(__FILE__, __FUNCTION__, __LINE__,format,##__VA_ARGS__);\
}while(0)

#define LogFatal(log,format,...) do\
{\
	log.Fatal(__FILE__, __FUNCTION__, __LINE__,format,##__VA_ARGS__);\
}while(0)


#endif
