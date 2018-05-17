

template<class X>   void
autoBasicPtr<X>::dump (void) const
{

}

template<class X>   void
autoBasicArrayPtr<X>::dump (void) const
{

}

template<class X>  
autoBasicPtr<X>::autoBasicPtr (autoBasicPtr<X> &rhs)
: p_ (rhs.release ())
{
	printf ("autoBasicPtr<X>::autoBasicPtr");
}

template<class X>   X *
autoBasicPtr<X>::get (void) const
{
	printf ("autoBasicPtr<X>::get");
	return this->p_;
}

template<class X>   X *
autoBasicPtr<X>::release (void)
{
	printf ("autoBasicPtr<X>::release");
	X *old = this->p_;
	this->p_ = 0;
	return old;
}

template<class X>   void
autoBasicPtr<X>::reset (X *p)
{
	printf ("autoBasicPtr<X>::reset");
	if (this->get () != p)
		delete this->get ();
	this->p_ = p;
}

template<class X>   autoBasicPtr<X> &
autoBasicPtr<X>::operator= (autoBasicPtr<X> &rhs)
{
	printf ("autoBasicPtr<X>::operator=");
	if (this != &rhs)
	{
		this->reset (rhs.release ());
	}
	return *this;
}

template<class X>  
autoBasicPtr<X>::~autoBasicPtr (void)
{
	printf ("autoBasicPtr<X>::~autoBasicPtr");
	delete this->get ();
}

template<class X>   X &
autoBasicPtr<X>::operator *() const
{
	printf ("autoBasicPtr<X>::operator *()");
	return *this->get ();
}


template<class X>   X *
autoPtr<X>::operator-> () const
{
	printf ("autoPtr<X>::operator->");
	return this->get ();
}

template<class X>   X *
autoBasicArrayPtr<X>::get (void) const
{
	printf ("autoBasicArrayPtr<X>::get");
	return this->p_;
}

template<class X>   X *
autoBasicArrayPtr<X>::release (void)
{
	printf ("autoBasicArrayPtr<X>::release");
	X *old = this->p_;
	this->p_ = 0;
	return old;
}

template<class X>   void
autoBasicArrayPtr<X>::reset (X *p)
{
	printf ("autoBasicArrayPtr<X>::reset");
	if (this->get () != p)
		delete [] this->get ();
	this->p_ = p;
}

template<class X>  
autoBasicArrayPtr<X>::autoBasicArrayPtr (autoBasicArrayPtr<X> &rhs)
: p_ (rhs.release ())
{
	printf ("autoBasicArrayPtr<X>::autoBasicArrayPtr");
}

template<class X>   autoBasicArrayPtr<X> &
autoBasicArrayPtr<X>::operator= (autoBasicArrayPtr<X> &rhs)
{
	printf ("autoBasicArrayPtr<X>::operator=");
	if (this != &rhs)
	{
		this->reset (rhs.release ());
	}
	return *this;
}

template<class X>  
autoBasicArrayPtr<X>::~autoBasicArrayPtr (void)
{
	printf ("autoBasicArrayPtr<X>::~autoBasicArrayPtr");
	delete [] this->get ();
}

template<class X>   X &
autoBasicArrayPtr<X>::operator *() const
{
	return *this->get ();
}

template<class X>   X &
autoBasicArrayPtr<X>::operator[](int i) const
{
	X *array = this->get ();
	return array[i];
}

template<class X>   X *
autoArrayPtr<X>::operator->() const
{
	return this->get ();
}

