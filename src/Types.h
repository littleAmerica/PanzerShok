#ifndef __TYPES__
#define __TYPES__


struct Point
{
	Point(int x_, int y_):x(x_),y(y_){}
	int x;
	int y;
};

struct Rect
{
	int x1;
	int x2;
	int y1;
	int y2;
};

#endif