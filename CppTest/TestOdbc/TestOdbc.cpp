// TestOdbc.cpp : Defines the entry point for the console application.

/*
	千万不要定义宏OTL_ODBC_MYSQL，这玩意是针对MyODBC 2.5，
	如果定义了宏OTL_ODBC_MYSQL，会导致下面的情况：
	mysql服务关闭
	应用程序连接失败，sleep，然后重新连接，一直循环
	mysql服务启动，
	这个时候，重新连接mysql服务不能连接成功

	另外还有一点，otl_connect& otlConn不要使用动态分配。
*/

#ifndef OTL_ODBC
#define OTL_ODBC // Compile OTL 4/ODBC
#endif

// 定义下面的宏，o<<string 与 o<<char*，都可以
#ifndef OTL_STL
#define OTL_STL // Compile OTL-STL 4/ODBC
#endif

/*
	在Windows下面，加上 stream.flush(); 会明显影响效率，速度慢很多。
	但是，奇怪的是，在Linux环境下，加上 stream.flush(); 
	能够完整插入1000条，而且效率特别高，违反常识。
*/
#ifdef WIN32
#define FLUSH(s)
#else 
#define FLUSH(s)	s.flush()
#endif

// 注意，因为定义了OTL_STL，stream<<操作符既可以传递string，也可以传递char*
// 也就是说，stream<<s等价于stream<<s.c_str();

#include "otlv4.h"
#include <string>
#include <time.h>


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

string GetNowTime()
{
	char buf[64] = {0};
	time_t now = time(NULL);
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S",localtime(&now));
	return string(buf);
}
void LoginDB(otl_connect& otlConn, const DB_Info& dbInfo);

int ReLoginDB(otl_connect& otlConn,const DB_Info& dbInfo,int sleepMSec)
{
	try
	{
		::Sleep(sleepMSec);
		otlConn.logoff(); 
		LoginDB(otlConn,dbInfo);
	}
	catch(...)
	{		
		return -1;
	}
	return 0;
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
		printf("[%s] Connect DB User[%s], Pwd[%s], DB[%s], OK\n",
			GetNowTime().c_str(),
			dbInfo.user.c_str(), 
			dbInfo.password.c_str(), 
			dbInfo.name.c_str());
		fflush(stdout);
		return ;
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
	}

	ReLoginDB(otlConn,dbInfo,2000);
}

void TestSprintf(otl_connect& otlConn)
{
	printf("[%s] TestSprintf Begin\n",GetNowTime().c_str());

	char sql[1024] = {0};	
	for(int i = 0;i<10;i++)
	{			
		sprintf(sql,"insert into stu values(%d,'%s',%d)",
			i,
			"andy",
			28);
		/*
			注意：不使用占位符，下面的buf必须设为1，如果设置为5，会导致重复执行5次
		*/
		otl_stream stream(5, sql, otlConn);
	}

	printf("[%s] TestSprintf End\n",GetNowTime().c_str());
}


void TestInput(otl_connect& otlConn)
{
	printf("[%s] TestInput Begin\n",GetNowTime().c_str());

	string name = "Andy";
	char sql[1024] = {0};
	sprintf(sql,"insert into stu value(:Id<int>,:Name<char[64]>,:Age<int>)");
	otl_stream stream(100, sql, otlConn);

	for(int i = 0;i<200;i++)
	{
		stream<<i+10000<<name<<28;
		// 等价于
		// stream<<i+10000<<name.c_str()<<28;
	}

	printf("[%s] TestInput End\n",GetNowTime().c_str());
}

void DBStartTrans(otl_connect& otlConn)
{
	otl_cursor::direct_exec
		(
		otlConn,
		"start transaction",
		otl_exception::enabled // disable OTL exceptions
		); 
}

void DBCommit(otl_connect& otlConn)
{
	otl_cursor::direct_exec
		(
		otlConn,
		"commit",
		otl_exception::enabled // disable OTL exceptions
		); 
}

void DBRollBack(otl_connect& otlConn)
{
	otl_cursor::direct_exec
		(
		otlConn,
		"rollback",
		otl_exception::disabled // disable OTL exceptions
		); 
}

void TestTransaction(otl_connect& otlConn)
{
	printf("[%s] TestTransaction Begin\n",GetNowTime().c_str());

	char sql[1024] = {0};
	sprintf(sql,"call addStu(:Id<int>,:Name<char[64]>,:Age<int>)");

	DBStartTrans(otlConn);
	otl_nocommit_stream stream;
	stream.open(100, sql, otlConn);	

	
	for(int i = 0;i<1000;i++)
	{	
		stream<<i<<"Andy"<<28;
		FLUSH(stream);		
	}

	DBCommit(otlConn);

	printf("[%s] TestTransaction End\n",GetNowTime().c_str());
}

void TestSelectByPage(otl_connect& otlConn)
{
	char sql[1024] = {0};
	sprintf(sql,"call selectbypage(50,5,@count)");

	// sprintf(sql,"select * from stu limit 50,5;");

	otl_stream stream(100, sql, otlConn);

	int id;
	string name;
	int age;
	while(!stream.eof())
	{
		stream>>id>>name>>age;
	}

}


void TestCache(otl_connect& otlConn)
{
	string ss;
	for(int i =0; i< 10000;++i)
	{
		ss +="abcdefg";
	}


	try
	{
		DBStartTrans(otlConn);
		char sql[1024] = {0};
		sprintf(sql,"call test1(:Text<char[102400]>)");
		otl_stream stream(100, sql, otlConn,otl_implicit_select);
		stream<<ss;


		string id;
		while(!stream.eof())
		{
			stream>>id;
			//char sql2[1024] = {0};
			//sprintf(sql2,"call test2(:Id<int>)");
			//otl_stream stream2(100, sql2, otlConn,otl_implicit_select);
			//stream2<<id;

			//int ff =0;
			//while(!stream2.eof())
			//{
			//	stream2>>ff;
			//}
		}
		DBCommit(otlConn);
	}
	catch(otl_exception& ex)
	{
		printf("ExecuteSql Error, ErrorMsg[%s], Sql[%s]",
			ex.msg,
			ex.stm_text);
		int  gg =0;
	}
}

void TestSync(otl_connect& otlConn)
{
	char sql[1024] = {0};

	int result =0;
	const int& dd = result;

	sprintf(sql,"call test1(:in_Age<int>)");
	otl_stream stream1(1, sql, otlConn,otl_implicit_select);

	stream1<<101;
	stream1>>dd;
}


void TestSqlInject(otl_connect& otlConn)
{
	// 使用or
	string name="Andy";
	string password="1' or 1='1";

	// 使用注释
	//string name="Andy'/*";
	//string password="*/'";	

	char sql[1024] = {0};
	sprintf(sql,"select id from user where name='%s' and password='%s'",
		name.c_str(),
		password.c_str());

	otl_stream stream(1, sql, otlConn);
	
	int userId = -1;
	stream>>userId;
}

// 使用绑定变量
void RefuseSqlInject(otl_connect& otlConn)
{
	// 使用or
	string name="Andy";
	string password="1' or 1='1";

	// 使用注释
	//string name="Andy'/*";
	//string password="*/'";	

	char sql[1024] = {0};
	sprintf(sql,"select id from user "
	"where name=:Name<char[100]> and password=:Password<char[100]>");

	otl_stream stream(1, sql, otlConn);
	
	int userId = -1;
	stream<<name<<password;
	stream>>userId;
}


// 使用绑定变量
void Test1(otl_connect& otlConn)
{
	char* sql ="call test_return(45)";
	otl_stream stream(10, sql, otlConn,otl_implicit_select);

	int aa = 100;
	stream>>aa;

	int hh =0;
}

void Test2(otl_connect& otlConn)
{
	//char* sql ="select now()";
	//char* sql ="select cast(now() as char(32))";
	char* sql ="select convert(now(), char(32))";
	try
	{		
		otl_stream stream(1,sql,otlConn);
		string aa;
		stream>>aa;
		int hh = 0;
	}
	catch (otl_exception& ex)
	{
		printf("ExecuteSql Error, ErrorMsg[%s], Sql[%s]",
			ex.msg,
			ex.stm_text);
	}
}

void Test3(otl_connect& otlConn)
{
	char* sql ="insert into stu(name,age) value(:Name<char[40]>,:Age<int>);";
	try
	{		
		otl_stream stream(1,sql,otlConn);
		stream<<"aaa111"<<29;
	}
	catch (otl_exception& ex)
	{
		printf("ExecuteSql Error, ErrorMsg[%s], Sql[%s]",
			ex.msg,
			ex.stm_text);
	}
}

void Test4(otl_connect& otlConn)
{
	char* sql ="insert into t3(c1,c2) value('aaa10001bbb',456)";
	try
	{		
		otl_stream stream(1,sql,otlConn);
	}
	catch (otl_exception& ex)
	{
		printf("ExecuteSql Error, ErrorMsg[%s], Sql[%s]",
			ex.msg,
			ex.stm_text);
	}
}

void Test_Xutao(otl_connect& otlConn)
{
	char* sql ="select name from nbs_program_org where name=:Name<char[40]>";
	//char* sql ="select name from nbs_program_org where name='鍒嗙粍1'";
	string name;
	try
	{		
		otl_stream stream(1,sql,otlConn);
		stream<<"鍒嗙粍1";
		stream>>name;
	}
	catch (otl_exception& ex)
	{
		printf("ExecuteSql Error, ErrorMsg[%s], Sql[%s]",
			ex.msg,
			ex.stm_text);
	}
}

void Test_ZhuAnBo(otl_connect& otlConn)
{
	char* sql ="call lku_qry_vp_dev_info('24997')";
	try
	{		
		otl_stream stream(1,sql,otlConn,otl_implicit_select);
		string a1;
		string a2;
		string a3;
		string a4;
		string a5;
		string a6;
		int	   a7;
		int    a8;

		stream>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8;

	}
	catch (otl_exception& ex)
	{
		printf("ExecuteSql Error, ErrorMsg[%s], Sql[%s]",
			ex.msg,
			ex.stm_text);
	}
}



void Test_HuZhuHua(otl_connect& otlConn)
{
	try
	{
		DBStartTrans(otlConn);

		otl_nocommit_stream noStream;
		char* sql = "insert into teacher value(1,'niu')";
		noStream.open(1, sql, otlConn);

		DBCommit(otlConn);
	}
	catch (...)
	{
		//DBRollBack();
		int hh =0;
	}

	otl_stream stream;
	char* sql = "select name from stu";
	stream.open(100, sql, otlConn);
	
	string name;
	while(!stream.eof())
	{
		stream>>name;
	}
}


bool recordBlockInfoRecord(otl_connect& otlConn)
{
	char sql[1024] = {0};
	sprintf(sql,"replace into record_blockinfo(record_id,blockinfo_id) "
		"value(:recordid<int>,:blockid<int>)");	
	try
	{
		otl_cursor::direct_exec(otlConn,"start transaction",otl_exception::enabled); 
		otl_nocommit_stream  stream;

		stream.open(100, sql, otlConn);

		int aa = -1;
		unsigned int bb = 888;

		for(int i=0; i<10; ++i)
		{
			stream<<aa<<(int)bb;
			FLUSH(stream);
		}
		otl_cursor::direct_exec(otlConn,"commit",otl_exception::enabled); 
	}
	catch(otl_exception& ex)
	{
		return  false;
	}
	return true;
}


/*
	这里比较了三个方法的性能：
	1、TestSprintf：拼成一个完整的Sql，buf设置为1
	2、TestInput：使用了占位符，buf设置为100
	3、TestTransaction：使用了事务

	性能的结果是：
	TestSprintf的效率最差。
	TestInput对于不同的Mysql服务器，性能差别很大。
	TestTransaction的性能最好。
*/

int main(int argc, char* argv[])
{	
	DB_Info dbInfo;
	dbInfo.user = "root";
	dbInfo.password = "123456";
	dbInfo.name = "128_niu3";


	otl_connect otlConn;
	try
	{
		LoginDB(otlConn,dbInfo);

		//Test_HuZhuHua(otlConn);
		//Test1(otlConn);
		//Test2(otlConn);
		//Test3(otlConn);
		//Test4(otlConn);
		//Test_ZhuAnBo(otlConn);
		//Test_ZhuAnBo(otlConn);

		Test_Xutao(otlConn);
		
		//recordBlockInfoRecord(otlConn);


		//RefuseSqlInject(otlConn);

		//TestTransaction(otlConn);

		//TestCache(otlConn);
	}
	catch(otl_exception& ex)
	{
		printf("ExecuteSql Error, ErrorMsg[%s], Sql[%s]",
			ex.msg,
			ex.stm_text);
	}
	//getchar();
	return 0;
}
