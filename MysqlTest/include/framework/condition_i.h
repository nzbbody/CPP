


#ifndef _CONDITION_I_H
#define _CONDITION_I_H

#include <thread/os_thread_i.h>
#include <mutex_i.h>

class conditionI;
class conditionAttributeI
{
public:
	/// Constructor
	conditionAttributeI (int type);

	/// Destructor
	~conditionAttributeI (void);

private:
	friend class conditionI;

	/// The attributes
	thread_condattr_t attributes_;

private:
	// = Prevent assignment and initialization.
	void operator= (const conditionAttributeI &);
	conditionAttributeI (const conditionAttributeI &);
};


class DLL_EXPORT conditionI
{
public:
	/// Initialize the condition variable.
	conditionI (mutexI &m);

	/// Initialize the condition variable.
	conditionI (mutexI &m,
		conditionAttributeI &attributes);

	/// Implicitly destroy the condition variable.
	~conditionI(void);

	/**
	* Explicitly destroy the condition variable.  Note that only one
	* thread should call this method since it doesn't protect against
	* race conditions.
	*/
	int remove (void);

	/**
	* Block on condition, or until absolute time-of-day has passed.  If
	* abstime == 0 use "blocking" <wait> semantics.  Else, if <abstime>
	* != 0 and the call times out before the condition is signaled
	* <wait> returns -1 and sets errno to ETIME.
	*/
	int wait (const timeval_t *abstime);

	/// Block on condition.
	int wait (void);

	/**
	* Block on condition or until absolute time-of-day has passed.  If
	* abstime == 0 use "blocking" wait() semantics on the <mutex>
	* passed as a parameter (this is useful if you need to store the
	* <Condition> in shared memory).  Else, if <abstime> != 0 and the
	* call times out before the condition is signaled <wait> returns -1
	* and sets errno to ETIME.
	*/
	int wait (mutexI &mutex, const timeval_t *abstime = 0);

	/// Signal one waiting thread.
	int signal (void);

	/// Signal *all* waiting threads.
	int broadcast (void);

	/// Returns a reference to the underlying mutex;
	mutexI& mutex (void);

	/// Dump the state of an object.
	void dump (void) const;


protected:
	/// Condition variable.
	thread_cond_t cond_;

	/// Reference to mutex lock.
	mutexI &mutex_;

	/// Keeps track of whether <remove> has been called yet to avoid
	/// multiple <remove> calls, e.g., explicitly and implicitly in the
	/// destructor.  This flag isn't protected by a lock, so make sure
	/// that you don't have multiple threads simultaneously calling
	/// <remove> on the same object, which is a bad idea anyway...
	int removed_;

private:
	// = Prevent assignment and initialization.
	void operator= (const conditionI &);
	//conditionI (const conditionI &);
};


#endif

