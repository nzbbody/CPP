#include "db_mysql.h"

using namespace DBLayer;

DBMysql::DBMysql()
{
	logI log;
	log.regMod(DBLog);

	_conn = NULL;
}

DBMysql::~DBMysql()
{
	
}

int DBMysql::Connect(const DBInfo& dbInfo, int timeout)
{
	_conn = mysql_init(NULL);
	if(_conn == NULL)
	{
		LogErr(DBLog, "mysql_init error[%d:%s]",
			GetLastErrorCode(),
			GetLastErrorMsg().c_str());
		return FAILURE;
	}
	mysql_options(_conn, MYSQL_OPT_CONNECT_TIMEOUT, (const char*)&timeout);

	if(mysql_real_connect(_conn,
		dbInfo._Host.c_str(),
		dbInfo._UserName.c_str(),
		dbInfo._Password.c_str(),
		dbInfo._DBName.c_str(),
		dbInfo._Port,
		NULL,
		CLIENT_MULTI_RESULTS|CLIENT_MULTI_STATEMENTS) == NULL)
	{
		mysql_close(_conn); //主要是为了释放资源
		_conn = NULL;
		return FAILURE;
	}

	return SUCCESS;
}

int DBMysql::Disconnect()
{
	return SUCCESS;
}

int DBMysql::KeepConnect()
{
	return SUCCESS;
}

int DBMysql::Test()
{
	if(mysql_query(_conn,"select devid from device") != SUCCESS)
	{
		return FAILURE;
	}

	MYSQL_RES* results = mysql_store_result(_conn);
	if(results == NULL)
	{
		return FAILURE;
	}
	
	MYSQL_ROW row;
	while((row = mysql_fetch_row(results)) != NULL)
	{
		LogInfo(DBLog,"%s",*row);
	}

	freeResults(results,false);
	return SUCCESS;
}

int DBMysql::TestProcedure()
{
	char* sql = "call niu1";
	if(mysql_query(_conn,sql) != SUCCESS)
	{
		return FAILURE;
	}

	MYSQL_RES* results = mysql_store_result(_conn);
	if(results == NULL)
	{
		return FAILURE;
	}

	MYSQL_ROW row;
	while((row = mysql_fetch_row(results)) != NULL)
	{
		LogInfo(DBLog,"%s",*row);
	}

	freeResults(results,true);
	return SUCCESS;
}

int	DBMysql::freeResults(MYSQL_RES* results,bool isProcedure)
{
	if(isProcedure == true)
	{
		do
		{
			results = mysql_store_result(_conn);
			mysql_free_result(results);
		}
		while((0 == mysql_next_result(_conn)));
	}
	else
	{
		mysql_free_result(results);
	}
	return SUCCESS;
}

int DBMysql::GetLastErrorCode()
{
	if(_conn == NULL)
	{
		return NULL;
	}
	return mysql_errno(_conn);
}

string DBMysql::GetLastErrorMsg()
{
	if(_conn == NULL)
	{
		return "_conn is null";
	}

	return mysql_error(_conn);
}