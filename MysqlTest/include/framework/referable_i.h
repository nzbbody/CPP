

#ifndef _REFERABLE_I_H
#define _REFERABLE_I_H

#include <atomic_i.h>

class DLL_EXPORT referableI
{

public:
	referableI();
	virtual ~referableI();

public:
	
	virtual void addRef();

	virtual void release();
	

private:
	atomicI mRefCount;
};

//#include <referable_i.inl>

#endif

