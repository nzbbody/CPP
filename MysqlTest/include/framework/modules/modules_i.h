/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _MODULES_I_H
#define _MODULES_I_H


#include <modules/support_i.h>

struct modulesInfo;
class modulesManagerI;
class fileI;
class modulesI;


typedef t_int32 (*constructorProc)(supportI *sI, const mIID &mid, void **instancePtr);
typedef t_int32 (*destructorProc)(void);

typedef t_int32 (*registerSelfProc)(modulesManagerI *mgr, const modulesInfo *mInfo);
typedef t_int32 (*unregisterSelfProc)(modulesManagerI *mgr, const modulesInfo *mInfo);

typedef t_int32 (*autoRunProc)(void);
typedef t_int32 (*autoStopProc)(void);


typedef t_int32 (*getModuleProc)(modulesManagerI *mgr, fileI *file, modulesI **result);


typedef t_int32 (*modulesConstructorProc)(modulesI *self);
typedef t_int32 (*modulesDestructorProc)(modulesI *self);


#define GET_MODULE_SYMBOL_PROC "getModules"

struct modulesInfo
{
	const t_int8 *mName;
	const mIID mId;
	constructorProc mContructor;
	destructorProc mDestructor;
	registerSelfProc mRegister;
	unregisterSelfProc mUnregister;
	autoRunProc mAutoRunner;
	autoStopProc mAutoStopper;
};


struct modulesInfoObject
{
	t_uint32 mVersion; 
	const t_int8 *mName;
	const modulesInfo *mInfo;
	t_uint32 mCount;
	modulesConstructorProc mCtor;
	modulesDestructorProc mDtor;
};


#define DECLARE_GETMODULES_IMPL(name, modules) 


struct modulesLibrary
{
	t_int8 *name;
	void *mH;
};



///模块入口地址

#define GETMODULES_ENTRY_POINT extern "C" t_int32 DLL_EXPORT getModules

#define DECLARE_GETMODULES(_name, _modules)								\
static modulesInfoObject mObject =													\
{																			\
	0x1234,																		\
	(#_name),																\
	(_modules),																	\
	ARRAY_SIZE(_modules),													\
	NULL,																		\
	NULL,																	\
};																				\
GETMODULES_ENTRY_POINT(modulesManagerI *mgr, fileI *file, modulesI **result)		\
{\
	(void)file;	\
	return mgr->newModulesImpl(&mObject, result);								\
}


#define MODULES_I_NAME "modules interface name"
#define MODULES_I_MID {"modules interface mid",} 


class modulesI : public supportI
{
public:
	virtual ~modulesI() {};

public:
	virtual t_int32 registerSelf(modulesManagerI *mgr, fileI *file) = 0;
	virtual t_int32 unregisterSelf(modulesManagerI *mgr, fileI *file) = 0;

	DECLARE_MODULE_IID(MODULES_I_MID)
//public:								
//		template <class dummy>				
//		struct modulesIID					
//		{									
//			static const mIID mId;			
//		};									
//		static const mIID &getIID(){	return modulesIID<int>::mId; }
};

DEFINE_MODULE_IID(modulesI, MODULES_I_MID)
//static mIID transmodulesI() 
//{ 
//	const char * const tt[] = {"modules interface mid",}; 
//	mIID temp; 
//	temp.mid = tt[0]; 
//	return temp; 
//}
//template <class dummy>							
//	const mIID modulesI::modulesIID<dummy>::mId = transmodulesI();


#endif


