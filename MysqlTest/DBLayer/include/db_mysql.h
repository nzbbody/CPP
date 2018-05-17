#ifndef DBLAYER_DBMYSQL_H_
#define DBLAYER_DBMYSQL_H_

#include "db_base.h"
#include "log/log_i.h"
#include "mysql.h"

namespace DBLayer
{
	using namespace std;

	class DBMysql : public DBBase
	{
	public:
		DBMysql();
		virtual ~DBMysql();

		virtual int Connect(const DBInfo& dbInfo, int timeout);
		virtual int Disconnect();

	public:
		int		KeepConnect();
		int		GetLastErrorCode();
		string	GetLastErrorMsg();

		int		Test();
		int		TestProcedure();

	private:
		int		freeResults(MYSQL_RES* results,bool isProcedure=false);

	private:
		MYSQL*	_conn;
	};


}
#endif