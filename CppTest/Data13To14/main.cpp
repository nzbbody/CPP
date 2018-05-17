// TestOdbc.cpp : Defines the entry point for the console application.

#ifndef OTL_ODBC
#define OTL_ODBC // Compile OTL 4/ODBC
#endif

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
#include "type_define.h"

#include <windows.h>
#include "niu_log.h"

using namespace std;

NiuLog log;

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


void QryDevice(vector<Device>& vecDevice,otl_connect& otlConn)
{
	char sql[1024] = {0};
	sprintf(sql,"select domainid,devicecode from device \
				where fast =1 and parentdevicecode='-1'");

	otl_stream stream(100, sql, otlConn);

	Device device;
	while(!stream.eof())
	{
		stream>>device._DomId>>device._DevCode;
		vecDevice.push_back(device);
	}
	
	// 查询子节点
	for(vector<Device>::iterator iter = vecDevice.begin();
		iter != vecDevice.end(); ++iter)
	{
		memset(sql,0,1024);

		sprintf(sql,"select domainid,devicecode from device \
					where fast =1 and domainid = %d and parentdevicecode='%s'",
					iter->_DomId,
					iter->_DevCode.c_str());

		otl_stream stream_2(100, sql, otlConn);
		while(!stream_2.eof())
		{
			stream_2>>device._DomId>>device._DevCode;
			iter->_VecDevice.push_back(device);
		}
	}
	
	int yy =0;	
}


void QryOrg(Org& org,otl_connect& otlConn)
{
	char sql[1024] = {0};
	sprintf(sql,"select domainid, organizationcode, parentdomainid, parentorganizationcode,title,remark \
				from organization where parentdomainid=%d and parentorganizationcode = '%s'",
				org._DomId,
				org._OrgCode.c_str());

	otl_stream stream(100, sql, otlConn);

	Org child;
	while(!stream.eof())
	{
		stream>>child._DomId>>child._OrgCode>>child._ParentDomId
			>>child._ParentOrgCode>>child._Title>>child._Desc;

		org._VecOrg.push_back(child);
	}


	/*odprintf("Org[%d:%s] Has Children[%s]",
				org._DomId,
				org._OrgCode.c_str(),
				org._VecOrg.size());*/

	if(org._VecOrg.size() > 0)
	{
		for(vector<Org>::iterator iter = org._VecOrg.begin();
			iter != org._VecOrg.end(); ++iter)
		{
			QryOrg(*iter,otlConn);
		}
	}

	

}


void QryOrg(vector<Org>& vecOrg,otl_connect& otlConn)
{
	char sql[1024] = {0};
	sprintf(sql,"select domainid, organizationcode, parentdomainid, parentorganizationcode,title,remark \
				from organization where organizationcode = '1'");

	otl_stream stream(100, sql, otlConn);

	Org org;
	while(!stream.eof())
	{
		stream>>org._DomId>>org._OrgCode>>org._ParentDomId
			>>org._ParentOrgCode>>org._Title>>org._Desc;
		vecOrg.push_back(org);
	}

	for(vector<Org>::iterator iter = vecOrg.begin();iter != vecOrg.end(); ++iter)
	{
		QryOrg(*iter,otlConn);
	}
}








int main(int argc, char* argv[])
{
	log.SetLevel(LOG_DEBUG|LOG_INFO|LOG_WARN|LOG_ERROR|LOG_FATAL);
	log.SetOutput(OUTPUT_STD|OUTPUT_CONSOLE);

	DB_Info dbInfo;
	dbInfo.user = "root";
	dbInfo.password = "123456";
	dbInfo.name = "188_1.3_ibp";


	otl_connect otlConn;
	try
	{
		LoginDB(otlConn,dbInfo);

		//vector<Device> vecDevice;
		//QryDevice(vecDevice,otlConn);



		vector<Org> vecOrg;
		QryOrg(vecOrg,otlConn);

		
	}
	catch(otl_exception& ex)
	{
		printf("ExecuteSql Error, ErrorMsg[%s], Sql[%s]",
			ex.msg,
			ex.stm_text);
	}
	getchar();
	return 0;
}
