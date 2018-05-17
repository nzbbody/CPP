/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _DIRECTORY_IMPL_H
#define _DIRECTORY_IMPL_H

#include <directory_i.h>

#include <string_i.h>
#include <dirent.h>


class directoryImpl : public directoryI
{

public:
	virtual t_int32 getNext(fileI **result);
	virtual t_int32 getNextEntry();
	virtual t_int32 hasEntry(t_bool *result);
	virtual t_int32 init(fileI *file);
	virtual t_int32 close();
public:
	t_int32 getNextFile(fileI **result);

private:
	
	DIR *mDir;
	struct dirent *mEntry;
	stringI mParentPath;
	
};

#endif

