/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */



#ifndef _MEMORY_I_H
#define _MEMORY_I_H

#include <data_types.h>


/*!\brief
 *
 * 简单而有效内存泄露处理
 * 
 * code Example:
 *
 * For new 32 char:
 *
 * 	new char[32] newEnd;
 *
 * For delete char[]:
 *
 *   delete char[] deleteEnd;
 *
 *
 * malloc: use mallocI 
 * free: use freeI 
 *
 */

DLL_EXPORT void newTrace(const t_int8 *file, const t_int32 line);
DLL_EXPORT void deleteTrace(const t_int8 *file, const t_int32 line);

#if 0
#define new ({ newTrace(__FILE__, __LINE__); new 
#define newEnd ;})


#define delete ({ deleteTrace(__FILE__, __LINE__); delete
#define deleteEnd ;})
#endif

#if 1 


#define os_new(T) new T; newTrace(__FILE__, __LINE__)

#define os_delete(T) delete T; deleteTrace(__FILE__,__LINE__);
#define os_deletex(T) delete[](T);deleteTrace(__FILE__,__LINE__);
#endif

DLL_EXPORT void *mallocTrace(t_uint32 size, const t_int8 *file, const t_int32 line);
DLL_EXPORT void freeTrace(void *ptr, const t_int8 *file, const t_int32 line);

#define mallocI(size) mallocTrace(size, __FILE__, __LINE__)
#define freeI(ptr) freeTrace(ptr, __FILE__, __LINE__)	


t_int32 mmTraceFunc(t_int32 flags);

DLL_EXPORT t_int32 enableMemTrace();
DLL_EXPORT t_int32 disableMemTrace();
#endif

