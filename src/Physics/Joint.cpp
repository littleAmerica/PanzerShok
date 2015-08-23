#include "Joint.h"
#include "PhysEngine.h"
#include "Physics_Base.h"

#include "../Utils/Asserts.h"


PinBodies::PinBodies(Physics* first, Physics* second, Vec2 place)
	:m_first(dynamic_cast<Physics_Base*>(first)),
	m_second(dynamic_cast<Physics_Base*>(second))
{
	ASSERT(m_first && m_second);

	b2RevoluteJointDef rjd;
	rjd.Initialize(m_first->body(), m_second->body(), place);
	m_joint = m_physEngine->world()->CreateJoint(&rjd);
}

void PinBodies::Release()
{
	m_first->clearJoin();
	m_second->clearJoin();

	m_physEngine->world()->DestroyJoint( m_joint );
}
