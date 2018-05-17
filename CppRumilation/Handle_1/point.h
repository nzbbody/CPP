#ifndef POINT_H_
#define POINT_H_

class Point
{
public:
	Point():_x(0),_y(0){}
	Point(int x,int y):_x(x),_y(y){}
	Point(const Point& rhs):_x(rhs._x),_y(rhs._y){}

	Point& SetX(int x)
	{
		_x = x;
		return *this;
	}

	int GetX()
	{
		return _x;
	}

	Point& SetY(int y)
	{
		_y = y;
		return *this;
	}

	int GetY()
	{
		return _y;
	}

private:
	int		_x;
	int		_y;
};


#endif