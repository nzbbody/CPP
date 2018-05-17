/* -*- C++ -*- */

//=============================================================================
/**
*  @file    Auto_Ptr.h
*
*  $Id: Auto_Ptr.h 92580 2010-11-15 09:48:02Z johnnyw $
*
*  @author Doug Schmidt <schmidt@uci.edu>
*  @author Irfan Pyarali <irfan@cs.wustl.edu>
*  @author Jack Reeves <jack@fx.com>
*  @author Dr. Harald M. Mueller <mueller@garwein.hai.siemens.co.at>
*/
//=============================================================================

#ifndef _AUTO_PTR_I_H
#define _AUTO_PTR_I_H



#include <data_types.h>


/**
* @class autoBasicPtr
*
* @brief Implements the draft C++ standard auto_ptr abstraction.
* This class allows one to work on non-object (basic) types
*/
template <typename X>
class autoBasicPtr
{
public:
	typedef X element_type;

	// = Initialization and termination methods
	explicit autoBasicPtr (X * p = 0) : p_ (p) {}

	autoBasicPtr (autoBasicPtr<X> & ap);
	autoBasicPtr<X> &operator= (autoBasicPtr<X> & rhs);
	~autoBasicPtr (void);

	// = Accessor methods.
	X &operator *() const;
	X *get (void) const;
	X *release (void);
	void reset (X * p = 0);

	/// Dump the state of an object.
	void dump (void) const;

	/// Declare the dynamic allocation hooks.

protected:
	X *p_;
};





/**
* @class auto_ptr
*
* @brief Implements the draft C++ standard auto_ptr abstraction.
*/
template <typename X>
class auto_ptr : public autoBasicPtr<X>
{
public:
	typedef X element_type;

	// = Initialization and termination methods
	explicit auto_ptr (X * p = 0) : autoBasicPtr<X> (p) {}
	auto_ptr (auto_ptr<X> & ap) : autoBasicPtr<X> (ap.release ()) {}

	X *operator-> () const;
};




/**
* @brief Implements the draft C++ standard auto_ptr abstraction.
* This version can be used instead of auto_ptr<T>
*/
template <typename X>
class autoPtr : public autoBasicPtr <X>
{
public:
	typedef X element_type;

	// = Initialization and termination methods
	explicit autoPtr (X * p = 0) : autoBasicPtr<X> (p) {}

	X *operator-> () const;
};

/**
* @class autoBasicArrayPtr
*
* @brief Implements an extension to the draft C++ standard auto_ptr
* abstraction.  This class allows one to work on non-object
* (basic) types that must be treated as an array, e.g.,
* deallocated via "delete [] foo".
*/
template<typename X>
class autoBasicArrayPtr
{
public:
	typedef X element_type;

	// = Initialization and termination methods.
	explicit autoBasicArrayPtr (X * p = 0) : p_ (p) {}

	autoBasicArrayPtr (autoBasicArrayPtr<X> & ap);
	autoBasicArrayPtr<X> &operator= (autoBasicArrayPtr<X> & rhs);
	~autoBasicArrayPtr (void);

	// = Accessor methods.
	X & operator* () const;
	X & operator[] (int i) const;
	X * get (void) const;
	X * release (void);
	void reset (X * p = 0);

	/// Dump the state of an object.
	void dump (void) const;

	/// Declare the dynamic allocation hooks.

protected:
	X * p_;
};

/**
* @class autoArrayPtr
*
* @brief Implements an extension to the draft C++ standard auto_ptr
* abstraction.
*/
template<typename X>
class autoArrayPtr : public autoBasicArrayPtr<X>
{
public:
	typedef X element_type;

	// = Initialization and termination methods.
	explicit autoArrayPtr (X *p = 0)
		: autoBasicArrayPtr<X> (p) {}

	X *operator-> () const;
};


/**
* @brief Reset given @c auto_ptr element to new element.
*
* Some platforms have an older version of auto_ptr support, which
* lacks reset, and cannot be disabled easily.  Portability to these
* platforms requires use of this function template.  This function
* template also works for the @c ACE_Auto_{Basic_}Array_Ptr class
* template, as well.
*/
template<typename AUTO_PTR_TYPE, typename PTR_TYPE>
inline void
ACE_auto_ptr_reset (AUTO_PTR_TYPE & ap,
					PTR_TYPE * p)
{

	ap.reset (p);
}


#include <auto_ptr_i.inl>



#endif /* ACE_AUTO_PTR_H */
