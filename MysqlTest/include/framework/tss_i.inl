
#include <tss_i.h>
#include <memory_i.h>

template <class TYPE> inline
tssI<TYPE>::~tssI (void)
{
#ifdef _WIN32
	cleanup(0);
#endif
	if (this->once_ != 0)
	{
		OS_THREAD::thread_key_free (this->key_);
	}
}

template <class TYPE>inline
tssI<TYPE>::tssI (TYPE *ts_obj)
: once_ (0)
{

	if(ts_obj != 0)
	{
		if(this->ts_init () == -1)
		{
			return;
		}

		this->ts_value (ts_obj);
	}


//	OS_THREAD::thr_key_set(this->key_,(void *) ts_obj);


}

template <class TYPE> int
tssI<TYPE>::ts_init (void) 
{
	int result = OS_THREAD::thread_key_create(&key_,&cleanup);

	
	if(result != 0)
	{
		return -1;
	}
	else
	{
		this->once_ = true;
	}
	
	return result;
}

template <class TYPE> inline TYPE *
tssI<TYPE>::ts_object (void) const
{
	if(!this->once_)
	{
		return 0;
	}
	return ts_value();
}

template <class TYPE> inline int 
tssI<TYPE>::ts_object (TYPE *type)
{

	if(!this->once_)
	{
		if(ts_init() == -1)
			return 0;
	}

	return ts_value(type);
}
 
template <class TYPE> inline TYPE *
tssI<TYPE>::ts_get (void) const
{
	if(!this->once_)
	{
		if(const_cast<tssI< TYPE > *>(this)->ts_init() == -1)
		{
			return 0;
		}
	}

	TYPE *ts_obj = 0;

	ts_obj = ts_value();
	if(ts_obj == 0)
	{
		ts_obj = makeTssType();
		if(!ts_obj)
			return 0;

		if(ts_value(ts_obj) == -1)
		{
			delete (ts_obj);
			return 0;
		}

		
	}
	return ts_obj;
}

template <class TYPE> TYPE *
tssI<TYPE>::operator-> () const
{
	return this->ts_get ();
}

template <class TYPE>
tssI<TYPE>::operator TYPE *(void) const
{
	return this->ts_get ();
}

template <class TYPE> inline TYPE *
tssI<TYPE>::makeTssType (void) const
{
	TYPE *temp = 0;

	temp = os_new(TYPE);
	return temp;
}

template <class TYPE> inline void
tssI<TYPE>::dump (void) const
{
	this->keylock_.dump();
}

template <class TYPE> inline void
tssI<TYPE>::cleanup (void *ptr)
{
	// Cast this to the concrete TYPE * so the destructor gets called.
	delete ((TYPE *)ptr);
}

template <class TYPE> inline TYPE *
tssI<TYPE>::ts_value () const
{
	return (TYPE *)OS_THREAD::thread_key_get(key_);
}


template <class TYPE> inline int
tssI<TYPE>::ts_value(TYPE *new_ts_obj) const
{
	return OS_THREAD::thread_key_set(key_,(void *)new_ts_obj);
}

