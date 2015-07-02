#ifndef _PHYSIC_OBJECT_
#define _PHYSIC_OBJECT_

#include "../Types.h"
#include "Box2D.h"

struct PhysicInfo
{
	Rect_t	bounds;
};


//TODO remove all b2 types from the interface for better compatibility
class Physics
{
public:
	virtual ~Physics(){}

	virtual void	setEntityID(int id) = 0; 
	virtual int		entityID() = 0;
	
	virtual void	applyForce(const b2Vec2& force) = 0;
	virtual void	applyTorque(float torque) = 0;
	virtual void	applyLinearImpulse(const b2Vec2& impulse) = 0;
	virtual void	applyAngularImpulse(float impulse) = 0;
	
	virtual b2Vec2	linearVelocity() = 0;
	virtual b2Vec2	lateralVelocity() = 0;
	virtual b2Vec2	forwardVelocity() = 0;
	virtual float	angularVelocity() = 0;		//angular velocity in radiance/second
	
	virtual b2Vec2	forwardNormal() = 0;
	
	virtual float	mass() = 0;
	virtual b2Vec2	worldCenter() = 0;
	virtual float	inertia() = 0;
	virtual float	angle() = 0;
	virtual Rect_t	bounds() = 0;
};


#endif