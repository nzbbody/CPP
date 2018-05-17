/*
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _LOCAL_FILE_IMPL_H
#define _LOCAL_FILE_IMPL_H

#include <sys/stat.h>

#include <file_i.h>
#include <modules/modules_i.h>


class localFileImpl : public fileI
{
	DECLARE_SUPPORTI
		
public:
	static t_int create(supportI *sI, const mIID &mid, void **instancePtr);

	
	virtual t_int createFile(t_int type, t_int permissons);

	virtual t_int getFileSize(t_long *fileSize);
	virtual t_int setFileSize(t_long fileSize);

	virtual t_int getFilePath(stringI &filePath);
	virtual t_int setFilePath(stringI &filePath);
	virtual t_int setFileLeafName(stringI &leafName);
	virtual t_int getFileLeafName(stringI &leafName);


	virtual t_int isExist(t_bool *retVal);
	virtual t_int isWritable(t_bool *retVal);
	virtual t_int isExecutable(t_bool *retVal);
	virtual t_int isFile(t_bool *retVal);
	virtual t_int isDirectory(t_bool *retVal);
	virtual t_int isSymLink(t_bool *retVal);

	virtual t_int getParent(fileI **parent);
	virtual t_int getDirectory(directoryI **result);

	virtual t_int load(modulesLibrary **result);
	virtual t_int findFunctionSymbol(modulesLibrary *mLibrary, t_char *symbol, void **result);

private:
	t_int loadLibrary(t_char *name, modulesLibrary **result);
	t_int getFileStat();

private:
	struct stat mFileStat;
	stringI mPath;
	stringI mLeafName;
};

#endif
