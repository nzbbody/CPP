/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */



#ifndef _MODULES_H_
#define _MODULES_H_

#include <data_types.h>
#include <errno/error_i.h>
#include <stdio.h>
#include <memory_i.h>
#include <string/string_i.h>
/** 
 * \struct qID
 *
 * 实例接口ID 定义
 *
 */

struct qID
{
	t_int32 qid;

	t_int32 getQid()
	{
		return qid;
	}

	void setQid(t_int32 id)
	{
		qid = id;
	}

	inline t_bool equals(const qID &other) const
	{
		return (other.qid == qid) ? TRUE : FALSE;
	}
	
};

typedef struct qID qIID;


/** 
 * \struct mID
 *
 * 模块接口ID 定义
 *
 */

struct mID
{
	const t_int8 *mid;
	qIID qid;

	inline t_bool equals(const mID &other) const
	{

		if(!(mid && other.mid))
		{
			return FALSE;
		}

		const t_int8 *p1 = mid;
		const t_int8 *p2 = other.mid;

		t_int8 c1 = 0;
		t_int8 c2 = 0;

		do
		{
			c1 = *p1++;
			c2 = *p2++;
		}
		while(c1 != '\0' && c1 == c2);
	
		return (c1 == c2) ? TRUE : FALSE;

	}
};

typedef struct mID mIID;


#define NULL_MID {"NULL",{0}}

struct queryInterfaceTableEntry
{
	const mIID *mid;
	t_int32 offset;
};

/**
 * \class supportI
 *
 * 模块接口类
 * 
 */
class supportI
{
public:
	supportI(){};
	virtual ~supportI() {};

public:
	virtual t_int32 queryInterface(const mIID &mid, void **instancePtr) = 0;	//查询接口
	virtual t_int32 addRef(void) = 0;											//+1
	virtual t_int32 release(void) = 0;											//-1
};

/**
 * \class autoRefCnt
 *
 * 自动计数类
 * 
 */
class autoRefCnt
{
public:
	autoRefCnt() : mRefCnt(0) {}
	~autoRefCnt() {}
	t_int32 operator++() { return ++mRefCnt; }
	t_int32 operator--() { return --mRefCnt; }
	t_int32 operator=(t_int32 value) { return (mRefCnt = value); }
	operator t_int32() const { return mRefCnt; }

	t_int32 get() { return mRefCnt; }
private:
	t_int32 mRefCnt;
};

/** \def  声明实例接口ID */
#define DECLARE_MODULE_QID(qid) 		\
public:								\
	template <class dummy>				\
	struct modulesQID##qid					\
	{									\
		static const qIID qid;			\
	};									\


/** \def  声明模块接口ID */
#define DECLARE_MODULE_IID(iid) 			\
public:								\
	template <class dummy>				\
	struct modulesIID					\
	{									\
		static const mIID mId;			\
	};									\
	static const mIID &getIID(){	return modulesIID<int>::mId; }

/** \def 定义实例接口ID */
#define DEFINE_MODULE_QID(theInterface, qid, theQid)	\
	template <class dummy>							\
	const qIID theInterface::modulesQID##qid<dummy>::qid = theQid;

/** \def 定义模块接口ID */
#define DEFINE_MODULE_IID(theInterface, theIid)	\
	static mIID trans##theInterface() \
	{ \
		const char * const tt[] = theIid; \
		mIID temp; \
		temp.mid = tt[0]; \
		return temp; \
	} \
	template <class dummy>							\
	const mIID theInterface::modulesIID<dummy>::mId = trans##theInterface();

/** \def  获取实例接口ID */
#define GET_MODULE_QID(T, qid) (::T::modulesQID##qid<int>::qid)


/** \def  获取模块接口ID */
#define GET_MODULE_IID(T) (::T::modulesIID<int>::mId)

/** \def  声明模块接口类函数*/
#define DECLARE_SUPPORTI										\
public:																\
	virtual t_int32 queryInterface(const mIID &mid, void **instancePtr);	\
	virtual t_int32 addRef(void);											\
	virtual t_int32 release(void);										\
private:																\
	autoRefCnt mRefCnt;											\
public:																\
	
/** \def  定义模块接口类addRef */
#define SUPPORTI_ADDREF(_class)									\
t_int32 _class::addRef(void)												\
{																\
	if(!(t_int32(mRefCnt) >= 0)) 										\
	{															\
		traceI("This class: %s A reference: %d\n", #_class, t_int32(mRefCnt));	\
	}															\
	++mRefCnt;														\
	return (mRefCnt);												\
}

/** \def  定义模块接口类release */
#define SUPPORTI_RELEASE(_class)								\
t_int32 _class::release(void)												\
{																\
	if(!(t_int32(mRefCnt) != 0))										\
	{															\
		traceI("This class: %s R reference: %d\n", #_class, t_int32(mRefCnt));\
	}															\
	--mRefCnt;														\
	if(mRefCnt == 0)												\
	{																\
		delete (this);										\
	}																\
	return (mRefCnt);												\
}

t_int32 DLL_EXPORT tableDrivenQueryInterface(void* _this, const queryInterfaceTableEntry* entries, const mIID &mId, void **instancePtr);



#define INTERFACE_TABLE_HEAD(_class)										\
t_int32 _class::queryInterface(const mIID &mid, void **instancePtr)						\
{																			\
	if(instancePtr == 0)															\
	{																		\
		platErrno = E_INVALPTR;													\
		return E_FAIL; 														\
	}																			\
	t_int32 retVal = E_FAIL;													\
		

#define INTERFACE_TABLE_TAIL												\
	return retVal;														\
}

#define INTERFACE_TABLE_BEGIN											\
	static const queryInterfaceTableEntry table[] = {								\

#define INTERFACE_TABLE_ENTRY(_class, _interface)						\
{																			\
	&_interface::modulesIID<int>::mId,										\
	t_int32(reinterpret_cast<char*>(                                       					\
                        static_cast<_interface*>((_class*) 0x1000)) -         			\
               reinterpret_cast<char*>((_class*) 0x1000))							\
},


#define INTERFACE_TABLE_END												\
	{NULL, 0}};															\
	retVal = tableDrivenQueryInterface(static_cast<void *>(this), 					\
						table, mid, instancePtr);


#define INTERFACE_TABLE1(_class, _i1)										\
	INTERFACE_TABLE_BEGIN														\
	INTERFACE_TABLE_ENTRY(_class, _i1)										\
	INTERFACE_TABLE_END															\



#define SUPPORTI_QUERYINTERFACE1(_class, _i1)						\
	INTERFACE_TABLE_HEAD(_class)										\
	INTERFACE_TABLE1(_class, _i1)									\
	INTERFACE_TABLE_TAIL												\
	
	

#define DEFINE_SUPPORTI(_class, _i1)								\
	SUPPORTI_ADDREF(_class)										\
	SUPPORTI_RELEASE(_class)									\
	SUPPORTI_QUERYINTERFACE1(_class, _i1)							\

#endif

