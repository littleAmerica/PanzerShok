#ifndef _PHYSIC_RIGIT_OBJECT_
#define _PHYSIC_RIGIT_OBJECT_

#include "Box2D.h"
#include "Physics.h"

#include "../Singleton.h"
#include "PhysEngine.h"

class Physics_Rigid : public Physics
{
public:
	Physics_Rigid(const PhysicInfo&  physicInfo, int x, int y);

	virtual void	applyForce(const b2Vec2& force);
	virtual void	applyTorque(float torque);
	virtual void	applyLinearImpulse(const b2Vec2& impulse);
	virtual void	applyAngularImpulse(float impulse);

	virtual b2Vec2	linearVelocity();
	virtual b2Vec2	lateralVelocity();
	virtual b2Vec2	forwardVelocity();
	virtual float	angularVelocity(); 

	virtual b2Vec2	forwardNormal();

	virtual float	mass();
	virtual b2Vec2	worldCenter();
	virtual float	inertia();	
	virtual float	angle();
	virtual Rect_t	bounds();

	virtual void	setEntityID(int id); 
	virtual int		entityID();
private:
	b2Body* m_body;
	const PhysicInfo&  m_physicInfo;

	int	m_entityID;

	An<PhysEngine>	m_physEngine;
};

#endif // _PHYSIC_RIGIT_OBJECT_