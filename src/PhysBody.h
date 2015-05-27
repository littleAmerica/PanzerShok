#ifndef _PHYS_BODY_
#define _PHYS_BODY_

#include "PhysEngine.h"

struct Point
{
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

class PhysBody
{
private:
	PhysBody();
public:
	friend class PhysEngine;

	Point getCenter();
	Rect getBounds();

private:
	
};


#endif