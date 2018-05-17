/**
 * 	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:smart_ptr_i.h
 *
 * 	@brief:  此文件时智能指针的实现，包括各种类型的智能指针
 *
 * 	@author:  
 * 
 *	@date:		2012-12-21
 *
 * 	@note:
 */

#ifndef SMART_PTR_I_H
#define SMART_PTR_I_H



#include <atomic_i.h>


class smartPtrBaseI;

/** 
 *
 *	class:		fw_atomic_t
 * 	@brief:		fw_atomic_t为最基本的计数类，引用计数值为int，支持增加引用计数，减少引用计数
 * 	@author:	 
 *	@date:		2012-12-21
 *	@note:	
 */
class DLL_EXPORT smartPtrI
{
protected:
	//ensure not be alloced from stack, or refer crashed
	//smartPtrI构造函数
	smartPtrI(){}
	//it's neccessory when "delete this" in release()
	//smartPtrI析构函数
	virtual ~smartPtrI(){}
	//not support copy & copy constuctor
	//重载=号
	//smartPtrI& operator =( const smartPtrI& ){}
	//拷贝构造函数
	//smartPtrI( const smartPtrI& ){}
	
	//should not be called by anyone but smartPtrBaseImpl
	friend class smartPtrBaseI;
protected:
	void addRef()//计数器加1
	{
		mRefCount.ref();
	}
	//decrease the refer count, delete self automatically when at last one.
	void release()//计数器减1
	{
		if (mRefCount.deref()) 
		{
			os_delete(this) ;
		}
	}
	
	//can only be used by myself
private:
	atomicI mRefCount;//计数器类
};

/*/////////////////////////////////////////////////////////////////////
smartPtrBaseImpl
use this class to use class smartPtrI, simlar as std::auto_ptr
  you can use the class as a pointer of class smartPtrI usually.
  smartPtrBaseI is used to be a friend class of smartPtrI

though there are class derieved from smartPtrBaseImpl, the methods
  needn't be virtual. because the derieved class is a simple wrapper
/////////////////////////////////////////////////////////////////////*/
class smartPtrBaseI
{
protected:
	smartPtrI* mRefPtr;

public:
	//be care that here do addRef() once
	//用smartPtrI构造smartPtrBaseI，如果RefPtr不为空，新构造的smartPtrBaseI和RefPtr
	//指向同一个基础对象，所以基础对象的引用计数要加1
	smartPtrBaseI( smartPtrI* RefPtr = NULL )
		: mRefPtr( RefPtr )
	{
		if( mRefPtr ) mRefPtr->addRef();
	};
	//auto matically release the pointer
	//care that it's not virtual, so the derived class shouldn't have destructor
	//析构函数，每次调用的时候基础对象的引用计数要减1
	virtual ~smartPtrBaseI()
	{
		if( mRefPtr ) mRefPtr->release();
	}

	//拷贝构造函数，基础对象的引用计数加1
	smartPtrBaseI( const smartPtrBaseI& RefPtr )
		: mRefPtr( RefPtr.mRefPtr )
	{
		if( mRefPtr ) mRefPtr->addRef();
	}

	//重载赋值操作符=，用smartPtrI给smartPtrBaseI赋值
	smartPtrBaseI& operator =( smartPtrI* RefPtr )
	{
		if(mRefPtr!=RefPtr){//必须判断相等，否则自身赋值
			if(mRefPtr) mRefPtr->release();
			if((mRefPtr=RefPtr)!=0) mRefPtr->addRef();
		}
		return *this;
	}

	//重载赋值操作符=，用smartPtrBaseI给smartPtrBaseI赋值
	smartPtrBaseI& operator =( const smartPtrBaseI& RefPtr )
	{
		return operator=(RefPtr.mRefPtr);
	}

	//判断smartPtrBaseI是否为空
	bool IsEmpty() const
	{
		return mRefPtr == NULL;
	}

	//重载->符号，用来获取smartPtrI
	smartPtrI* operator ->()
	{
		//mustn't be null here
		//assert( mRefPtr );
		
		return mRefPtr;
	}

	//重载->符号，用来获取smartPtrI
	const smartPtrI* operator ->() const
	{
		//mustn't be null here
		//assert( mRefPtr );
		return mRefPtr;
	}
};

//warpper of smartPtrBaseI, add template function
//refer to smartPtrBaseI
//as you see, in fact, smartPtrBaseImpl is very similar as smartPtrBaseI,
//   just some like void *

template<typename X> class smartImpl;

/** 
 *
 *	class:		smartPtrBaseImpl
 * 	@brief:		smartPtrBaseImpl为智能指针类模板
 * 	@author:	chenjiang modify
 *	@date:		2012-12-24
 *	@note:	
 */
template <typename X>
class smartPtrBaseImpl : public smartPtrBaseI
{
public:
	//(smartPtrI*) can't remove, it's some strange
	smartPtrBaseImpl<X>( smartImpl<X>* pRef = NULL ) 
		: smartPtrBaseI( pRef ) {}

	smartPtrBaseImpl<X>( const smartPtrBaseImpl<X>& RefPtr ) 
		: smartPtrBaseI( RefPtr ) {}
	
	smartPtrBaseImpl<X>& operator =( smartImpl<X>* pRef )
	{ 
		return (smartPtrBaseImpl<X>&)(smartPtrBaseI::operator =(pRef)); 
	}

	smartPtrBaseImpl<X>& operator =( const smartPtrBaseImpl<X>& RefPtr )
	{ 
		return (smartPtrBaseImpl<X>&)(smartPtrBaseI::operator=(RefPtr)); 
	}

	X* operator ->()
	{
		//assert( mRefPtr ); 
		return (X*)( *(smartImpl<X>*)mRefPtr ); 
	}

	const X* operator ->() const
	{ 
		//assert( mRefPtr ); 
		return (X*)( *(smartImpl<X>*)mRefPtr );
	}
};

//if your class (X) have implement (derived from) smartPtrI,
//you can use this wrapper to do
template<typename X>
class smartPtrImpl : public smartPtrBaseI
{
public:
	smartPtrImpl<X>( X* pRef = NULL ) : smartPtrBaseI( pRef ) {}

	smartPtrImpl<X>( const smartPtrImpl<X>& RefPtr ) 
		: smartPtrBaseI( RefPtr ) {}

	smartPtrImpl<X>& operator =( X* pRef )
	{ 
		return ( smartPtrImpl<X>& ) ( smartPtrBaseI::operator =( pRef ) ); 
	}

	smartPtrImpl<X>& operator =( const smartPtrBaseImpl<X>& RefPtr )
	{ 
		return ( smartPtrImpl<X>& ) ( smartPtrBaseI::operator =( RefPtr ) ); 
	}

	X* operator ->()
	{ 
		//assert( mRefPtr ); 
		return (X*)mRefPtr; 
	}
	const X* operator ->() const
	{ 
		//assert( mRefPtr ); 
		return (X*)mRefPtr; 
	}
};

/*/////////////////////////////////////////////////////////////////////
smartImpl: template
this is a simple class to wrapper your class to realize referable
if your class can derived from smartPtrI byself, this class is useless
/////////////////////////////////////////////////////////////////////*/
template<typename X>
class smartImpl : public smartPtrI
{
protected:
	//ensure not be alloced from stack, or refer crashed
	//you should construct this object after you have create an X object.
	smartImpl<X>( X* DataPtr )	: mDataPtr( DataPtr )
	{
		//Refer to NULL pointer is useless, but harmless, just let it be.
		//ASSERT( DataPtr );
	}

	virtual ~smartImpl<X>()
	{
		//delete NULL pointer is harmless
		if(mDataPtr != NULL)
			 os_delete(mDataPtr);
	}
public:
	//instead of the constructor
	static smartImpl<X>* createObject(  X* DataPtr )
	{
		return os_new(smartImpl<X>( DataPtr ));
	}

	X* operator ->()
	{
		return mDataPtr;
	}
	
	const X* operator ->() const
	{
		return mDataPtr;
	}
	
protected:
	X* mDataPtr;

};

	
#endif


