#ifndef SQLITE_I_H
#define SQLITE_I_H

#include <database_i.h>
#include <sqlite3/sqlite3.h>

#define MSG_LENGTH	1024

class sqliteI : public databaseI
{
	public:
		sqliteI();
		virtual ~sqliteI();
	public:
		t_int32 connect(const char *dbName);
		t_int32 disConnect();
		t_int32 selectExec(const char *cmdText);
		t_int32 modifyExec(const char *cmdText);
		t_int32 getResult(t_int8 ***result_ptr, t_int32 &row, t_int32 &column);
		
		t_int32 getErrCode(t_int32 *errCode);
		t_int32 getErrMsg(t_int8 **errCode);
		t_int32 freePreResult();
	protected: 
		t_int32 setConnected( t_bool setValue);

	private:
		sqlite3 *db;


	public:
		t_int8 **dbResult;
		t_int32 nRow;
		t_int32 nColumn;

	private:
		t_int8 ErrMsg[MSG_LENGTH];
};

#endif

