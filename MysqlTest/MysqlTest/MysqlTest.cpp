#include "db_mysql.h"

using namespace DBLayer;

int main(int argc, char* argv[])
{
	DBMysql mysql;

	DBInfo dbInfo;
	dbInfo._Host = "10.36.65.128";
	dbInfo._Port = 3306;
	dbInfo._UserName = "root";
	dbInfo._Password = "123456";
	dbInfo._DBName = "ibp_niu1";

	mysql.Connect(dbInfo,10);
	mysql.TestProcedure();
	mysql.TestProcedure();
	mysql.Test();
	mysql.Test();

	return 0;
}

