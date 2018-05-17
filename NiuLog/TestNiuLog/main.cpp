
#include "niu_log.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	NiuLog log;
	log.SetLevel(LOG_DEBUG|LOG_INFO|LOG_WARN|LOG_ERROR|LOG_FATAL);
	log.SetOutput(OUTPUT_STD|OUTPUT_CONSOLE);

	LogDebug(log,"This is Debug");
	LogInfo (log,"This is Info");
	LogWarn (log,"This is Warn");
	LogError(log,"This is Error");
	LogFatal(log,"This is Fatal");


	int len = 50;
	string str ="";
	for(int i=0; i<len;++i)
	{
		str+="|";
	}
	log.SetConsoleColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	printf("start...\n");
	printf("%s\r",str.c_str()); // 打印竖线，然后回到行首

	str ="";
	for(int i=0; i<len;++i)
	{
		str+=">";
	}
	log.SetConsoleColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	
	for (int i = 0; i < len; ++i)  
	{  
		putchar(str[i]);  
		Sleep(200);  
	}  
	putchar('\n');
	printf("end\n");


	
	getchar();
	return 0;
}

