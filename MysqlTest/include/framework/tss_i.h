

#ifndef _TSS_I_H
#define _TSS_I_H

#include <mutex_i.h>


template <class TYPE>
class tssI
{
public:
	// = Initialization and termination methods.

	/**
	* If caller has passed us a non-NULL ts_obj *, then we'll just use
	* this to initialize the thread-specific value (but only for the
	* calling thread).  Thus, subsequent calls to <operator->> in this
	* thread will return this value.  This is useful since it enables
	* us to assign objects to thread-specific data that have
	* arbitrarily complex constructors.
	*
	*/
	tssI (TYPE *ts_obj = 0);

	/// Deregister with thread-key administration.
	virtual ~tssI (void);

	// = Accessors.

	/**
	* Get the thread-specific object for the key associated with this
	* object.  Returns 0 if the data has never been initialized,
	* otherwise returns a pointer to the data.
	*/
	TYPE *ts_object (void) const;

	/// Set the thread-specific object for the key associated with this
	/// object.
	int ts_object (TYPE *);

	/// Use a "smart pointer" to get the thread-specific object
	/// associated with the <key_>.
	TYPE *operator-> () const;

	/// Return or create and return the calling threads TYPE object.
	operator TYPE *(void) const;

	/// Hook for construction parameters.
	virtual TYPE *makeTssType (void) const;

	// = Utility methods.

	/// Dump the state of an object.
	void dump (void) const;

	// ACE_ALLOC_HOOK_DECLARE;
	// Declare the dynamic allocation hooks.

protected:
	/// Actually implements the code that retrieves the object from
	/// thread-specific storage.
	TYPE *ts_get (void) const;

	/// Factors out common code for initializing TSS.  This must NOT be
	/// called with the lock held...
	int ts_init (void);

	/// Avoid race conditions during initialization.
	mutexI keylock_;

	/// "First time in" flag.
	int once_;

	/// Key for the thread-specific error data.
	thread_key_t key_;

	/// "Destructor" that deletes internal TYPE * when thread exits.
	static void cleanup (void *ptr);

	TYPE *ts_value(void) const;
	int ts_value(TYPE *new_ts_obj) const;
private:
	void operator= (const tssI<TYPE> &);
	tssI (const tssI<TYPE> &);
};

template <class TYPE>
class tssTypeAdapter
{
public:
	/// Constructor.  Inlined here so that it should _always_ be inlined.
	tssTypeAdapter (const TYPE value = 0): value_ (value) {}

	/// TYPE conversion.  Inlined here so that it should _always_ be
	/// inlined.
	operator TYPE () const { return value_; };

	/// TYPE & conversion.  Inlined here so that it should _always_ be
	/// inlined.
	operator TYPE &() { return value_; };

private:
	/// The wrapped value.
	TYPE value_;
};

#include <tss_i.inl>

#endif
