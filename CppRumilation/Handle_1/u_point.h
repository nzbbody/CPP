#ifndef U_POINT_H_
#define U_POINT_H_

#include "point.h"

// UPoint的目的是对Point和引用计数封装，用户是不可见的
class UPoint
{
	friend class Handle_1;

private:
	Point p;
	int	  u;
	
	UPoint():u(1){}

	UPoint(int x,int y)
	{
		p.SetX(x);
		p.SetY(y);
		u = 1;
	}

	UPoint(const Point& rhs)
	{
		p = rhs;
		u = 1;
	}
};


#endif