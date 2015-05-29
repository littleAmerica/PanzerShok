#ifndef _PHYS_BODY_
#define _PHYS_BODY_

#include <memory>

#include "Box2D.h"
#include "Types.h"
#include "Singleton.h"

class PhysEngine;

class PhysBody
{
private:
	PhysBody();
public:
	friend class PhysEngine;

	Point getCenter();

	void move(int state);

	void dispose();

	~PhysBody();
private:
	An<PhysEngine> m_physEngine;

	b2Body* m_body;
};

typedef std::shared_ptr<PhysBody> PhysBodyPtr;

#endif