// TestOdbc.cpp : Defines the entry point for the console application.
//
#ifndef OTL_ODBC
#define OTL_ODBC // Compile OTL 4/ODBC
#endif

#ifndef OTL_STL
#define OTL_STL // Compile OTL-STL 4/ODBC
#endif

#include <string>
#include <stdio.h>
#include <time.h>

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

#include "otlv4.h"

using namespace std;

struct DB_Info
{
	int loginNum;
	int executeNum;
	int sleepTime;
	string name;
	string user;
	string password;

	DB_Info()
	{
		loginNum = 0;
		executeNum = 0;
		name = "";
		user = "";
		password = "";
	}
};

void removeNewLine(char* p)
{
	int length = strlen(p);
	for(int i =0; i<length;++i)
	{
		if(p[i] == '\r' || p[i] == '\n')
		{
			p[i] = 0;
		}
	}
}

void ReadConfig(DB_Info& dbInfo)
{
	char buf[128];
	FILE* pFile = fopen("conf.txt","r");
	int row = 0;

	while(fgets(buf,128,pFile) != NULL)
	{
		removeNewLine(buf);
		switch(row)
		{
		case 0:
			dbInfo.loginNum = atoi(buf);
			break;

		case 1:
			dbInfo.executeNum = atoi(buf);
			break;

		case 2:
			dbInfo.sleepTime = atoi(buf);
			break;

		case 3:
			dbInfo.user= buf;
			break;

		case 4:
			dbInfo.password = buf;
			break;

		case 5:
			dbInfo.name = buf;
			break;

		default:
			break;
		}
		++row;
	}
}

string GetNowTime()
{
	char buf[64] = {0};
	time_t now = time(NULL);
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S",localtime(&now));
	return string(buf);
}

void LoginDB(otl_connect& otlConn, const DB_Info& dbInfo)
{
	char connInfo[256] = {0};
	sprintf(connInfo, "%s/%s@%s", 
		dbInfo.user.c_str(), 
		dbInfo.password.c_str(), 
		dbInfo.name.c_str());

	try
	{
		otl_connect::otl_initialize(1);		
		otlConn.logoff();
		otlConn.rlogon(connInfo, 1);
	}
	catch(otl_exception& ex)
	{
		printf("[%s] Connect DB User[%s], Pwd[%s], DB[%s], ERROR[%s]\n",
			GetNowTime().c_str(),
			dbInfo.user.c_str(), 
			dbInfo.password.c_str(), 
			dbInfo.name.c_str(),
			ex.msg);
		fflush(stdout);
		return;
	}

	printf("[%s] Connect DB User[%s], Pwd[%s], DB[%s], OK\n",
		GetNowTime().c_str(),
		dbInfo.user.c_str(), 
		dbInfo.password.c_str(), 
		dbInfo.name.c_str());
	fflush(stdout);
}

void Insert(otl_connect& otlConn,DB_Info& dbInfo)
{
	const char* sql = "INSERT INTO STU(NAME,AGE,TIME,CLASS,TEACHER,CHINESESCORE,MATHSCORE,ENGLISHSCORE) \
					  VALUES (:NAME<char[64]>, :AGE<int>, NOW(),:CLASS<char[64]>,:TEACHER<char[64]>,\
					  :CHINESESCORE<int>,:MATHSCORE<int>,:ENGLISHSCORE<int>)";
	try
	{		
		otl_stream stream;
		stream.open(1, sql, otlConn);
		stream<<"Andy"<<29<<"3-1Class"<<"Mr Li"<<70<<80<<90;
	}
	catch (otl_exception& ex)
	{
		printf("[%s] Execute Sql Error[%s]\n",
			GetNowTime().c_str(),
			ex.msg);
		fflush(stdout);

		LoginDB(otlConn,dbInfo);
	}
}

void Select(otl_connect& otlConn,DB_Info& dbInfo)
{
	const char* sql = "SELECT MAX(ID) FROM STU";
	int maxId;
	try
	{		
		otl_stream stream;
		stream.open(1, sql, otlConn);
		stream>>maxId;
	}
	catch (otl_exception& ex)
	{
		printf("[%s] Execute Sql Error[%s]\n",
			GetNowTime().c_str(),
			ex.msg);
		fflush(stdout);

		LoginDB(otlConn,dbInfo);
	}

	//otl_stream stream;
	//stream.open(1, sql, otlConn);
	//stream>>maxId;


	const char* sql_2 = "SELECT ID,NAME,AGE FROM STU WHERE ID = :ID<int>";
	int Id;
	string name;
	int age;
	try
	{		
		otl_stream stream_2;
		stream_2.open(1, sql_2, otlConn);
		stream_2<< maxId;

		while(!stream_2.eof())
		{
			stream_2>>Id>>name>>age;
		}
	}
	catch (otl_exception& ex)
	{
		printf("[%s] Execute Sql Error[%s]\n",
			GetNowTime().c_str(),
			ex.msg);
		fflush(stdout);

		LoginDB(otlConn,dbInfo);
	}
}


void ExecuteSql(otl_connect& otlConn,DB_Info& dbInfo)
{
	// Insert(otlConn,dbInfo);
	Select(otlConn,dbInfo);
}

void ThreadSleep(int msec)
{
	#ifdef WIN32
	::Sleep(msec);
	#else
	::usleep(msec*1000);
	#endif
}

#ifdef WIN32
DWORD WINAPI TestOdbc(PVOID param)
#else
void* TestOdbc(void* param)
#endif
{
	DB_Info* dbInfo = (DB_Info*)param;
	otl_connect otlConn;

	LoginDB(otlConn,*dbInfo);

	for(int i =0; i<dbInfo->loginNum; ++i)
	{
		for(int j =0; j<dbInfo->executeNum; ++j)
		{
			ExecuteSql(otlConn,*dbInfo);
		}

		ThreadSleep(dbInfo->sleepTime * 1000); // sleep
	}




	//for(int i =0; i<dbInfo->loginNum; ++i)
	//{
	//	LoginDB(otlConn,*dbInfo);

	//	for(int j =0; j<dbInfo->executeNum; ++j)
	//	{
	//		ExecuteSql(otlConn);
	//	}

	//	ThreadSleep(dbInfo->sleepTime * 1000); // sleep
	//}

	printf("Thread End\n");
	fflush(stdout);

	return 0;
}


int main(int argc, char* argv[])
{
	DB_Info dbInfo;	
	ReadConfig(dbInfo);

#ifdef WIN32
	for(int i =0;i<5;++i)
	{
		HANDLE hThread = CreateThread(NULL,0,TestOdbc,&dbInfo,0,NULL);
		CloseHandle(hThread);
	}
#else
	for(int i =0;i<5;++i)
	{
		pthread_t hThread;
		pthread_create(&hThread,NULL,TestOdbc,(void*)&dbInfo);
	}
#endif

	getchar();
	return 0;
}
