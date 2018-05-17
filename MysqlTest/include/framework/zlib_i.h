/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */




  
#ifndef _ZLIB_I_H_
#define _ZLIB_I_H_

#include <modules/support_i.h>
#include <modules/modules_i.h>
#include <modules/modules_manager_i.h>
#include <errno/error_i.h>
#include <trace/trace_i.h>

#include <zip/gzip.h>
#include <zip/gunzip.h>



#define ZLIB_I_NAME "zlib interface name"
#define ZLIB_I_MID {"zlib interface mid",}

class zlibI : public supportI
{
		
public:
	virtual t_int32 compress(char* srcFilePath) = 0;
	virtual t_int32 uncompress(char* srcFilePath) = 0;
	
	DECLARE_MODULE_IID(ZLIB_I_MID)
};

DEFINE_MODULE_IID(zlibI, ZLIB_I_MID)

#endif
