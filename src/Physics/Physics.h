#ifndef _PHYSIC_OBJECT_
#define _PHYSIC_OBJECT_

#include "Utils/Types.h"

struct PhysicInfo
{
	Rect_t	bounds;
	float angle; //default angle in world coordinate
};

class Physics;
typedef std::shared_ptr<Physics> PhysicsPtr;

class Physics
{
public:
	virtual ~Physics(){}

	virtual void	setEntityID(int id) = 0; 
	virtual int		entityID() = 0;
	
	virtual void	applyForce(const Vec2& force) = 0;
	virtual void	applyTorque(float torque) = 0;
	virtual void	applyLinearImpulse(const Vec2& impulse) = 0;
	virtual void	applyAngularImpulse(float impulse) = 0;
	virtual	void	stopMoving() = 0;

	virtual void	setAngle(float angle) = 0;

	virtual Vec2	linearVelocity() = 0;
	virtual Vec2	lateralVelocity() = 0;
	virtual Vec2	forwardVelocity() = 0;
	virtual float	angularVelocity() = 0;		//angular velocity in radiance/second

	virtual Vec2 forwardNormal() = 0;
	
	virtual float	currentSpeed() = 0;			//current speed in forward direction

	virtual float	mass() = 0;
	virtual Vec2	worldCenter() = 0;
	virtual float	inertia() = 0;
	virtual float	angle() = 0;
	virtual Rect_t	bounds() = 0;

	virtual void	attachPhysics(Physics* other, const Vec2& place) = 0; //make a join
};



#endif