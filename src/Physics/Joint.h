#ifndef _PHYSIC_JOINT_OBJECT_
#define _PHYSIC_JOINT_OBJECT_

#include "Utils//Singleton.h"
#include "PhysEngine.h"
#include "Physics.h"

class Physics_Base;

class PinBodies
{
public:
	PinBodies(Physics* first, Physics* second, Vec2 place);

	void Release();
private:
	Physics_Base* m_first;
	Physics_Base* m_second;

	b2Joint* m_joint;

	An<PhysEngine>	m_physEngine;
};


#endif // _PHYSIC_RIGIT_OBJECT_
