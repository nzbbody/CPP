#ifndef HANDLE_2_H_
#define HANDLE_2_H_

#include "point.h"
#include "use_count.h"

/*
class Handle_2
{
public:
	Handle_2():_p(new Point),_u(new int(1)){}

	Handle_2(int x,int y):_p(new Point(x,y)),_u(new int(1)){}

	Handle_2(const Point& rhs):_p(new Point(rhs)),_u(new int(1)){}

	~Handle_2()
	{
		subRef();
	}

	Handle_2(const Handle_2& rhs)
	{
		addRef(rhs);
	}

	Handle_2& operator=(const Handle_2& rhs)
	{
		if(this != &rhs)
		{
			subRef();
			addRef(rhs);
		}
		
		return * this;
	}


	int GetX()
	{
		return _p->GetX();
	}

	int GetY()
	{
		return _p->GetY();
	}

	Handle_2& SetX(int x)
	{
		if(*_u == 1) // 当前是唯一的引用
		{
			_p->SetX(x);
		}
		else
		{
			--*_u;
			_p = new Point(x,_p->GetY());
		}
		return *this;
	}

	Handle_2& SetY(int y)
	{
		if(*_u == 1) // 当前是唯一的引用
		{
			_p->SetY(y);
		}
		else
		{
			--*_u;
			_p = new Point(_p->GetX(),y);
		}
		return *this;
	}

private:
	void addRef(const Handle_2& rhs) // 复制对象指针和引用计数指针，增加引用
	{
		_p = rhs._p;
		_u = rhs._u;
		++*_u;
	}
	
	void subRef()// 减少引用，判断是否delete对象和引用计数
	{
		if(--*_u == 0)
		{
			delete _p;
			delete _u;
		}
	}

private:
	Point* _p;
	int*   _u;
};
*/

class Handle_2
{
public:
	Handle_2():_p(new Point){}

	Handle_2(int x,int y):_p(new Point(x,y)){}

	Handle_2(const Point& rhs):_p(new Point(rhs)){}

	~Handle_2()
	{
		subRef();
	}

	Handle_2(const Handle_2& rhs)
	{
		addRef(rhs);
	}

	Handle_2& operator=(const Handle_2& rhs)
	{
		if(this != &rhs)
		{
			subRef();
			addRef(rhs);
		}

		return * this;
	}


	int GetX()
	{
		return _p->GetX();
	}

	int GetY()
	{
		return _p->GetY();
	}

	Handle_2& SetX(int x)
	{
		if(_u.IsOnly()) // 当前是唯一的引用
		{
			_p->SetX(x);
		}
		else
		{
			_u.MakeOnly();
			_p = new Point(x,_p->GetY());
		}
		return *this;
	}

	Handle_2& SetY(int y)
	{
		if(_u.IsOnly()) // 当前是唯一的引用
		{
			_p->SetY(y);
		}
		else
		{
			_u.MakeOnly();
			_p = new Point(_p->GetX(),y);
		}
		return *this;
	}

private:
	void addRef(const Handle_2& rhs)
	{
		_p = rhs._p;
		_u = rhs._u;
	}

	void subRef()
	{
		if(_u.IsOnly())
		{
			delete _p;
		}
	}

private:
	Point*     _p;
	UseCount   _u;
};

#endif