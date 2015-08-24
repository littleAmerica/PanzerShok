#ifndef _PHYSIC_BASE_OBJECT_
#define _PHYSIC_BASE_OBJECT_

#include "Physics.h"

#include "Utils//Singleton.h"
#include "PhysEngine.h"

#include <memory>

class b2Body;
class PinBodies;

class Physics_Base : public Physics
{
public:
	virtual void	applyForce(const Vec2& force);
	virtual void	applyTorque(float torque);
	virtual void	applyLinearImpulse(const Vec2& impulse);
	virtual void	applyAngularImpulse(float impulse);
	virtual void	setLinearVelocity(Vec2 velocity);

	virtual void	setAngle(float angle);

	virtual Vec2	linearVelocity();
	virtual Vec2	lateralVelocity();
	virtual Vec2	forwardVelocity();
	virtual float	angularVelocity(); 

	virtual Vec2 forwardNormal();
	virtual float	currentSpeed();

	virtual float	mass();
	virtual Vec2	worldCenter();
	virtual float	inertia();	
	virtual float	angle();
	virtual Rect_t	bounds() = 0;


	virtual void	stopMoving();

	virtual void	setEntityID(int id); 
	virtual int		entityID();

	virtual b2Body*	body(); //for inner "Box2d" usage only

	virtual void attachPhysics(Physics* other, const Vec2& place);

	~Physics_Base();



protected:
	friend class PinBodies;

	virtual void	clearJoin();
	
	void	DestroyBody();
	void	setBody(b2Body* body);

	b2Body* m_body;

	std::shared_ptr<PinBodies> m_pinBodies;

	int	m_entityID;

	An<PhysEngine>	m_physEngine;
};

b2Vec2 vec2Tob2vec2(const Vec2& vec);
Vec2 b2vec2ToVec2(const b2Vec2& vec);

#endif // _PHYSIC_BASE_OBJECT_
