/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _INITIALIZE_EX_H
#define _INITIALIZE_EX_H

#include <data_types.h>
#include <key_value_i.h>

struct modulesConfig
{
	t_int8 libPath[256];
	
};

struct initializeData
{
	t_int32 version;

	keyValueI confPath;

	
};


void initializeEx(t_int32 &, t_int8 *[], initializeData &initData);




#endif
