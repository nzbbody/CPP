/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

 
#ifndef _MODULES_REGISTER_I_H
#define _MODULES_REGISTER_I_H

#include <modules/support_i.h>
#include <data_types.h>

#include <file_i.h>

class modulesRegisterI : public supportI
{
public:
	virtual t_int32 autoRegister(fileI &file) = 0;
	virtual t_int32 autoUnregister(fileI &file) = 0;

	virtual t_int32 registerFactory(const t_int8 *mid) = 0;
	virtual t_int32 unregisterFactory(const t_int8 *mid) = 0;
	
};

#endif

