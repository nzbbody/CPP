#ifndef HANDLE_1_H_
#define HANDLE_1_H_

#include "u_point.h"

class Handle_1
{
public:
	Handle_1():_up(new UPoint){}

	Handle_1(int x,int y):_up(new UPoint(x,y)){}

	Handle_1(const Point& rhs):_up(new UPoint(rhs)){}

	~Handle_1()
	{
		subRef();
	}

	// copy���죬����ָ�룬��������
	Handle_1(const Handle_1& rhs)
	{
		addRef(rhs._up);
	}

	// copy��ֵ����߼������ü������ж��Ƿ�delete���ұ��������ü������������Ҹ�ֵ
	Handle_1& operator=(const Handle_1& rhs)
	{
		if(this != &rhs)
		{
			subRef();
			addRef(rhs._up);
		}
		
		return * this;
	}


	int GetX()
	{
		return _up->p.GetX();
	}

	int GetY()
	{
		return _up->p.GetY();
	}

	Handle_1& SetX(int x)
	{
		//_up->p.SetX(x);
		if(_up->u == 1) // ��ǰ��Ψһ������
		{
			_up->p.SetX(x);
		}
		else
		{
			--_up->u;
			_up = new UPoint(x,_up->p.GetY());
		}
		return *this;
	}

	Handle_1& SetY(int y)
	{
		//_up->p.SetY(y);
		if(_up->u == 1) // ��ǰ��Ψһ������
		{
			_up->p.SetY(y);
		}
		else
		{
			--_up->u;
			_up = new UPoint(_up->p.GetX(),y);
		}
		return *this;
	}

private:
	void addRef(UPoint* up) // ����ָ�룬��������
	{
		_up = up;
		++_up->u;
	}
	
	void subRef()			// �������ã��ж��Ƿ�delete
	{
		if(--_up->u == 0)
		{
			delete _up;
		}
	}

private:
	UPoint* _up;
};


#endif