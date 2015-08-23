#ifndef _PHYSIC_RIGIT_OBJECT_
#define _PHYSIC_RIGIT_OBJECT_

#include "../Utils/Box2D_platform.h"
#include "Physics.h"
#include "Physics_Base.h"

#include "Joint.h"

#include "Utils/Singleton.h"
#include "PhysEngine.h"

class Physics_Rigid : public Physics_Base
{
public:
	Physics_Rigid(const PhysicInfo&  physicInfo, int x, int y);

	Rect_t bounds();

private:
	const PhysicInfo&  m_physicInfo;

	int	m_entityID;

	An<PhysEngine>	m_physEngine;
};


class Physics_Static : public Physics_Base
{
public:
	Physics_Static(const PhysicInfo&  physicInfo, int x, int y);

	Rect_t bounds();

private:
	const PhysicInfo&  m_physicInfo;

	int	m_entityID;

	An<PhysEngine>	m_physEngine;
};


class Physics_Kinematic : public Physics_Base
{
public:
	Physics_Kinematic(const PhysicInfo&  physicInfo, int x, int y);

	Rect_t bounds();

private:
	const PhysicInfo&  m_physicInfo;

	int	m_entityID;

	An<PhysEngine>	m_physEngine;
};


#endif // _PHYSIC_RIGIT_OBJECT_
