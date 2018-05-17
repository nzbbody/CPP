
/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */
 

#ifndef _LIST_I_H
#define _LIST_I_H

#include <data_types.h>



struct nodeBase
{
	nodeBase *mPrev;
	nodeBase *mNext;
};

template <class T>
struct listNode : public nodeBase
{
	listNode()
	{
		mPrev = NULL;
		mNext = NULL;
	}
	listNode(const T & _s) 
	{ 
		mData = _s;
		mPrev = NULL;
		mNext = NULL;
	}
	T mData;
};


struct iteratorBase
{
	iteratorBase() {}
	 iteratorBase(nodeBase* _s) : mNode(_s) {}
	nodeBase *mNode;

	void incr() { mNode = mNode->mNext; }
	void decr() { mNode = mNode->mPrev; }
};

template <class T>
struct listIterator : public iteratorBase
{
	listIterator() {}
	listIterator( listNode<T>* _s) : iteratorBase(_s) {}

	T& operator*() const { return ((listNode<T> *) mNode)->mData; }

	listIterator<T>& operator++() { this->incr(); return *this; }
	listIterator<T>& operator--() { this->decr(); return *this; }
	
};

template <class T>
class listBase
{

public:
	listBase ()
	{
		mlNode = os_new(listNode<T>);
		mlNode->mPrev = mlNode;
		mlNode->mNext = mlNode;
	}

	
protected:
	listNode<T> *mlNode;	
};

template <class T>
class listI : protected listBase<T>
{
public:
	typedef listIterator<T> iterator;
	using listBase<T>::mlNode;
	
	
	listI() : listBase<T>() {};
	~listI(){};

	T& front() { return *begin(); }

	T& back() { return  *(--end()); }
	
	void pushFront(const T &_s) { insert(begin(), _s); }
	void pushBack(const T &_s) { insert(end(), _s); }

	void popFront() { erase(begin()); }
	void popBack() { iterator _t = end(); erase(--_t); }
	
	iterator erase(iterator _position) 
	{
		nodeBase *prev = _position.mNode->mPrev;
		nodeBase *next = _position.mNode->mNext;

		listNode<T> *n = (listNode<T> *)_position.mNode;
		prev->mNext = next;
		next->mPrev = prev;

		destroyNode(n);
		
		return iterator((listNode<T> *)next);
	}
	
	iterator begin() { return (listNode<T> *)mlNode->mNext; }
	iterator end()  { return mlNode; }
	
protected:

	listNode<T> *createNode(const T &_s)
	{
		listNode<T> *_p = os_new(listNode<T>(_s));

		

		return _p;
	}

	void destroyNode(listNode<T> *_p)
	{
		_p->mData.~T();

		delete _p deleteEnd;
	}
	
	iterator  insert(iterator _position, const T &_s)
	{
		listNode<T> *_node = createNode(_s);

		_node->mNext = _position.mNode;
		_node->mPrev = _position.mNode->mPrev;
		
		_position.mNode->mPrev->mNext = _node;
		_position.mNode->mPrev = _node;

		return _node;
	}
	


};




#endif

