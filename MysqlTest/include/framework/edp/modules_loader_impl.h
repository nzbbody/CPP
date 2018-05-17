/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _MODULES_LOADER_I_H
#define _MODULES_LOADER_I_H


#include <modules/modules_loader_i.h>

#include <modules/modules_i.h>
#include <file_i.h>
#include <hash_table_i.h>





class modulesLoaderImpl : public modulesLoaderI
{
	DECLARE_SUPPORTI
		
public:

	
	
	virtual t_int32 loadModules0(modulesManagerI *mgr, fileI *file, modulesI **result);

public:
	hashTableI mLibraries;

	
	
};




struct modulesLoaderData
{

	modulesLoaderData(modulesI *m = 0, modulesLibrary *l = 0) : module(m), library(l) {}
	
	modulesI *module;

	modulesLibrary *library;
};


#endif


