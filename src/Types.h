#ifndef __TYPES__
#define __TYPES__


struct Point_t
{
	float x;
	float y;
	
	Point_t():
		x(0.f),
		y(0.f)
	{
	}
	Point_t(float _x, float _y):
		x(_x),
		y(_y)
	{
	}
};

struct Rect_t
{
	float x1;
	float x2;
	float y1;
	float y2;
	
	Rect_t():
		x1(0.f),
		x2(0.f),
		y1(0.f),
		y2(0.f)
	{
	}
	Rect_t(float _x1, float _x2, float _y1, float _y2):
		x1(_x1),
		x2(_x2),
		y1(_y1),
		y2(_y2)
	{
	}
};

#endif