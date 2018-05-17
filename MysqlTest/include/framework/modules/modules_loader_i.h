/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _MODULES_LOADER_H
#define _MODULES_LOADER_H

#include <modules/support_i.h>

#include <file_i.h>
#include <modules/modules_i.h>


#define MODULES_LOADER_I_NAME "modules loader interface name"
#define MODULES_LOADER_I_MID {"modules loader interface mid",}

class modulesLoaderI : public supportI
{
public:
	virtual t_int32 loadModules0(modulesManagerI *mgr, fileI *mFile, modulesI **result) = 0;


	DECLARE_MODULE_IID(MODULES_LOADER_I_MID)
	
};

DEFINE_MODULE_IID(modulesLoaderI, MODULES_LOADER_I_MID)

#endif


