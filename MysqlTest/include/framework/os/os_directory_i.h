#ifndef _OS_DIRECTORY_I_H
#define _OS_DIRECTORY_I_H

#include <directory/directory_i.h>
#include <errno/error_i.h>
#include <trace/trace_i.h>
#ifdef WIN32
#include <direct.h>
#include <conio.h>
#include <ctype.h>
#include <io.h>
#include <Windows.h>
#include <Shlwapi.h>

#pragma comment(lib, "Shlwapi.lib")

#else
#include <unistd.h>
#endif

#ifdef WIN32
#define dirSymbol "\\" 
#define dirJudge '\\'
#define PATH_MAX_I MAX_PATH
#else 
#define dirSymbol "/"
#define dirJudge '/'
#define PATH_MAX_I PATH_MAX
#endif


namespace OS_DIRECTORY
{

#ifdef WIN32

#else

extern DIR *m_Dir;
extern struct dirent *m_Entry;

#endif

 t_int32 isFile(const char *path);

 t_int32 isDir(const char *path);

 t_int32 getFilePath(const char *path, const char *fileName, char *filePath);

 t_bool isSpecialDir(const char *path);

 t_int32 dirDelete(const char *path);

 t_int32 fileCopy(const char *fpathname, const char *tpathname);


#ifndef WIN32
 t_int32 copy(char *fPathName, char *tPathName);
#endif

 t_int32 dirCopy(const char *fPathName, const char *tPathName);

 t_int32 isDirExist(const char *path);


 t_int32 dirScan(const char *path);

};

#endif
