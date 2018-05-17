
#ifndef _OS_FILE_I_H
#define _OS_FILE_I_H

#include <modules/modules_i.h>
#include <data_types.h>
#include <trace/trace_i.h>
#include <directory/directory_i.h>
#include <errno/error_i.h>
#include <string/string_i.h>
#include <string/string_util_i.h>

#ifdef WIN32
#include <io.h>
#else
#include <dlfcn.h>
#include <unistd.h>
#include <sys/types.h>
#endif

#include <memory_i.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#ifdef WIN32
#include <tchar.h>
#endif


namespace OS_FILE {

#ifdef WIN32 
#define OS_RDONLY   GENERIC_READ
#define OS_WRONLY   GENERIC_WRITE
#define OS_RDWR     GENERIC_READ | GENERIC_WRITE
#define OS_APPEND   FILE_APPEND_DATA
#define OS_TRUNC    TRUNCATE_EXISTING
#else
#define OS_RDONLY   O_RDONLY
#define OS_WRONLY   O_WRONLY
#define OS_RDWR     O_RDWR
#define OS_APPEND   O_APPEND
#define OS_EXCL     O_EXCL
#define OS_TRUNC    O_TRUNC
#define OS_NOCTTY   O_NOCTTY
#define OS_NONBLOCK O_NONBLOCK
#define OS_DSYNC    O_DSYNC
#define OS_RSYNC    O_RSYNC
#define OS_SYNC     O_SYNC
#endif
/*
* 文件属性类型
*/
#ifdef WIN32      
typedef struct _stat os_stat;     
#else             
typedef struct stat os_stat;
#endif            

/*
* 文件句柄类型
*/
#ifdef WIN32 
typedef HANDLE os_fd; 
#else  
typedef t_int32 os_fd;
#endif

t_int32 os_closeFile(os_fd fd);

t_int32 os_openFile(const t_int8 *path, t_int64 type, t_int64 permissons, os_fd &fd);

t_int32 os_deleteFile(const t_int8* path);

t_int32 os_truncFile(const t_int8* path, t_int64& length);

t_int32 os_getStat(const t_int8* filePath, os_stat &mStat);

bool os_isExit(const t_int8 *filePath);

void* os_dlopen(const t_int8* libPath);

void* os_dlsym(void *handle, const t_int8 *symbol);

void os_dlclose(void* handle);


};


#endif

