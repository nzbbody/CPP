#ifndef PLAT_COMMON_I_H
#define PLAT_COMMON_I_H



//����ƽ̨�˳�����ָ��
typedef t_int32 (*platformExitFunc)(void*);
//����ƽ̨�˳�������������
t_int32 DLL_EXPORT setPlatformExitFunc(platformExitFunc);


#endif
