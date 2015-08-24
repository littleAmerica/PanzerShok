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
	Physics_Rigid(const Physic_Info& physicInfo, Vec2 pos);

	Rect_t bounds();

private:
	Physic_Info  m_physicInfo;

	int	m_entityID;

	An<PhysEngine>	m_physEngine;
};


class Physics_Static : public Physics_Base
{
public:
	Physics_Static(const Physic_Info&  physicInfo, Vec2 pos);

	Rect_t bounds();

private:
	const Physic_Info&  m_physicInfo;

	int	m_entityID;

	An<PhysEngine>	m_physEngine;
};


class Physics_Kinematic : public Physics_Base
{
public:
	Physics_Kinematic(const Physic_Info&  physicInfo, Vec2 pos);

	Rect_t bounds();

private:
	const Physic_Info&  m_physicInfo;

	int	m_entityID;

	An<PhysEngine>	m_physEngine;
};


#endif // _PHYSIC_RIGIT_OBJECT_
