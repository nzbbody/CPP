#ifndef MYSQL_I_H
#define MYSQL_I_H

#include <database_i.h>
#include <mysql/mysql.h>

#define MSG_LENGTH	1024
class mysqlI :public databaseI
{
	public:
		mysqlI();
		~mysqlI();
	public:
		t_int32 connect(const t_int8 *ip, t_uint32 port, const t_int8 *userName,
				const t_int8 *password, const t_int8 *dbName);
		t_int32 disConnect();
		t_int32 setConnected(t_bool setValue);
		t_int32 savePara(const t_int8 *ip, t_uint32 port, const t_int8 * userName, 
			    const t_int8 * password, const t_int8 *dbName);
		t_int32 selectExec(const t_int8 *cmdText);
		t_int32 modifyExec(const t_int8 *cmdText);
		t_int32 reConnect();
		t_int32 freePreResult();
		t_int32 getErrMsg(t_int8 **errCode);
		t_int32 getErrCode(t_int32 *errCode);

	private:
		MYSQL m_connection;
		MYSQL_RES *m_result;
		MYSQL_ROW row;
		t_int32 m_fieldsNum;	
		t_int8	m_errMsg[MSG_LENGTH];
};
#endif
