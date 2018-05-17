/**
 * 	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:smart_ptr_i.h
 *
 * 	@brief:  ���ļ�ʱ����ָ���ʵ�֣������������͵�����ָ��
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
 * 	@brief:		fw_atomic_tΪ������ļ����࣬���ü���ֵΪint��֧���������ü������������ü���
 * 	@author:	 
 *	@date:		2012-12-21
 *	@note:	
 */
class DLL_EXPORT smartPtrI
{
protected:
	//ensure not be alloced from stack, or refer crashed
	//smartPtrI���캯��
	smartPtrI(){}
	//it's neccessory when "delete this" in release()
	//smartPtrI��������
	virtual ~smartPtrI(){}
	//not support copy & copy constuctor
	//����=��
	//smartPtrI& operator =( const smartPtrI& ){}
	//�������캯��
	//smartPtrI( const smartPtrI& ){}
	
	//should not be called by anyone but smartPtrBaseImpl
	friend class smartPtrBaseI;
protected:
	void addRef()//��������1
	{
		mRefCount.ref();
	}
	//decrease the refer count, delete self automatically when at last one.
	void release()//��������1
	{
		if (mRefCount.deref()) 
		{
			os_delete(this) ;
		}
	}
	
	//can only be used by myself
private:
	atomicI mRefCount;//��������
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
	//��smartPtrI����smartPtrBaseI�����RefPtr��Ϊ�գ��¹����smartPtrBaseI��RefPtr
	//ָ��ͬһ�������������Ի�����������ü���Ҫ��1
	smartPtrBaseI( smartPtrI* RefPtr = NULL )
		: mRefPtr( RefPtr )
	{
		if( mRefPtr ) mRefPtr->addRef();
	};
	//auto matically release the pointer
	//care that it's not virtual, so the derived class shouldn't have destructor
	//����������ÿ�ε��õ�ʱ�������������ü���Ҫ��1
	virtual ~smartPtrBaseI()
	{
		if( mRefPtr ) mRefPtr->release();
	}

	//�������캯����������������ü�����1
	smartPtrBaseI( const smartPtrBaseI& RefPtr )
		: mRefPtr( RefPtr.mRefPtr )
	{
		if( mRefPtr ) mRefPtr->addRef();
	}

	//���ظ�ֵ������=����smartPtrI��smartPtrBaseI��ֵ
	smartPtrBaseI& operator =( smartPtrI* RefPtr )
	{
		if(mRefPtr!=RefPtr){//�����ж���ȣ���������ֵ
			if(mRefPtr) mRefPtr->release();
			if((mRefPtr=RefPtr)!=0) mRefPtr->addRef();
		}
		return *this;
	}

	//���ظ�ֵ������=����smartPtrBaseI��smartPtrBaseI��ֵ
	smartPtrBaseI& operator =( const smartPtrBaseI& RefPtr )
	{
		return operator=(RefPtr.mRefPtr);
	}

	//�ж�smartPtrBaseI�Ƿ�Ϊ��
	bool IsEmpty() const
	{
		return mRefPtr == NULL;
	}

	//����->���ţ�������ȡsmartPtrI
	smartPtrI* operator ->()
	{
		//mustn't be null here
		//assert( mRefPtr );
		
		return mRefPtr;
	}

	//����->���ţ�������ȡsmartPtrI
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
 * 	@brief:		smartPtrBaseImplΪ����ָ����ģ��
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


