/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _DATABASE_I_H
#define _DATABASE_I_H

#include <data_types.h>
#include <string/string_i.h>
#include <errno/error_i.h>

class databaseI
{
public:
	virtual ~databaseI() {};

public:
	virtual t_int32 connect(const t_int8 *ip, t_uint32 port, const t_int8 *userName,
			const t_int8 *password, const t_int8 *dbName);
	virtual t_int32 connect(const t_int8 *dbPath);
	virtual t_int32 disConnect() = 0;
	virtual t_int32 selectExec(const t_int8 *cmdText) = 0;
	virtual t_int32 modifyExec(const t_int8 *cmdText) = 0;
	virtual t_int32 getErrMsg(t_int8 **errCode);
	virtual t_int32 getErrCode(t_int32 *errCode);
	
protected: 
	virtual t_int32 reConnect();
	virtual t_int32 savePara(const t_int8 *ip, t_uint32 port, const t_int8 *userName,
			const t_int8 *password, const t_int8 *dbName);
	virtual t_int32 setConnected( t_bool setValue) = 0;
	virtual t_int32 freePreResult() = 0;
	
public:

	//MapFieldNameIndex 
	t_bool  isConnected;
	
protected:	
	
	stringI m_dbIp;
	t_uint32 m_dbPort;
	stringI m_dbName;
	stringI m_dbUser;
	stringI m_dbPwd;
};		

#endif


