/*
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _MUTEX_I_H
#define _MUTEX_I_H


#include <thread/os_thread_i.h>


class DLL_EXPORT mutexI
{
public:
	/// Initialize the mutex.
  	mutexI (int type = USYNC_THREAD);

  	/// Implicitly destroy the mutex.
  	~mutexI (void);

  	/// Explicitly destroy the mutex.
	  /**
	   * @note Only one thread should call this method since it doesn't
	   *        protect against race conditions.
	   */
  	int remove (void);

  	/// Acquire lock ownership (wait on queue if necessary).
  	int acquire (void);

	  /// Block the thread until the mutex is acquired or @a tv times out,
	  /// in which case -1 is returned and @c errno == @c ETIME.
	  /**
	   * @note @a tv is assumed  to be in "absolute" rather than
	   * "     relative" time.  The value of @a tv is updated upon return
	   *       to show the actual(absolute) acquisition time.
	   */
  	int acquire (timeval_t &tv);

	  /// Block the thread until the mutex is acquired or @a *tv times
	  /// out, in which case -1 is returned and @c errno == @c ETIME.
	  /**
	   * If @a tv == 0 then call @c acquire() directly.  Otherwise, block
	   * the thread until the mutex is acquired or @a tv times out, in
	   * which case -1 is returned and @c errno == @c ETIME.
	   *
	   * @note @a *tv is assumed to be in "absolute" rather than
	   *       "relative" time.  The value of @a *tv is updated upon
	   *       return to show the actual (absolute) acquisition time.
	   */
  	int acquire (timeval_t *tv);

	  /// Conditionally acquire lock (i.e., don't wait on queue).
	  /**
	   * @return -1 on failure.  If we "failed" because someone
	   *         else already had the lock, @c errno is set to @c EBUSY.
	   */
  	int tryacquire (void);

  	/// Release lock and unblock a thread at head of queue.
  	int release (void);

	  /// Acquire mutex ownership.
	  /**
	   * This calls @c acquire and is only here to make the @c ACE_Mutex
	   * interface consistent with the other synchronization APIs.
	   */
  	int acquire_read (void);

	  /// Acquire mutex ownership.
	  /**
	   * This calls @c acquire and is only here to make the @c ACE_Mutex
	   * interface consistent with the other synchronization APIs.
	   */
  	int acquire_write (void);

	  /// Conditionally acquire mutex (i.e., won't block).
	  /**
	   * This calls @c tryacquire and is only here to make the @c ACE_Mutex
	   * interface consistent with the other synchronization APIs.
	   *
	   * @return -1 on failure.  If we "failed" because someone else
	   *         already had the lock, @c errno is set to @c EBUSY.
	   */
  	int tryacquire_read (void);

	  /// Conditionally acquire mutex (i.e., won't block).
	  /**
	   * This calls @c tryacquire and is only here to make the @c ACE_Mutex
	   * interface consistent with the other synchronization APIs.
	   *
	   * @return -1 on failure.  If we "failed" because someone else
	   *         already had the lock, @c errno is set to @c EBUSY.
	   */
  	int tryacquire_write (void);


 	 /// Return the underlying mutex.
  	const thread_mutex_t &lock (void) const;
  	thread_mutex_t &lock (void);

  	// = This should be protected but some C++ compilers complain...
public:
  	/// This lock resides in shared memory.
  	thread_mutex_t *process_lock_;


  	/// Mutex type supported by the OS.
  	thread_mutex_t lock_;

	  /// Keeps track of whether @c remove has been called yet to avoid
	  /// multiple @c remove calls, e.g., explicitly and implicitly in the
	  /// destructor.  This flag isn't protected by a lock, so make sure
	  /// that you don't have multiple threads simultaneously calling
	  /// @c remove on the same object, which is a bad idea anyway.
  	bool removed_;

private:
  	// Prevent assignment and initialization.
  	void operator= (const mutexI &);
  	mutexI (const mutexI &);
};

class DLL_EXPORT safeLock
{
public:
	safeLock(mutexI & lock):m_lock(lock) { m_lock.acquire(); }
	~safeLock() { m_lock.release(); }
private:
	mutexI & m_lock;
}; 
#define SAFELOCK(x) safeLock __guard(x)

#endif

