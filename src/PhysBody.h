#ifndef _PHYS_BODY_
#define _PHYS_BODY_

#include "PhysEngine.h"

#include "Box2D.h"
#include "Types.h"

class PhysBody
{
private:
	PhysBody();
public:
	friend class PhysEngine;

	Point getCenter();
	Rect getBounds();

	void dispose();

	~PhysBody();
private:
	An<PhysEngine> m_physEngine;

	b2Body* m_body;
};

typedef std::shared_ptr<PhysBody> PhysBodyPtr;

#endif