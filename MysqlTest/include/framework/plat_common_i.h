#ifndef PLAT_COMMON_I_H
#define PLAT_COMMON_I_H



//定义平台退出函数指针
typedef t_int32 (*platformExitFunc)(void*);
//定义平台退出函数类型设置
t_int32 DLL_EXPORT setPlatformExitFunc(platformExitFunc);


#endif
