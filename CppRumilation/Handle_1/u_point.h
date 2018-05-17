#ifndef U_POINT_H_
#define U_POINT_H_

#include "point.h"

// UPoint��Ŀ���Ƕ�Point�����ü�����װ���û��ǲ��ɼ���
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