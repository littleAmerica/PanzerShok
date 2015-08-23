#include "Physics_Base.h"
#include "PhysEngine.h"
#include "Joint.h"
#include "Utils/Box2D_platform.h"
#include "Utils/Asserts.h"


void Physics_Base::applyForce(const Vec2& force)
{
	m_body->ApplyForce( vec2Tob2vec2(force), m_body->GetWorldCenter(), true );
}

void Physics_Base::applyTorque(float torque)
{
	m_body->ApplyTorque(torque, true);
}

Vec2 Physics_Base::linearVelocity()
{
	return b2vec2ToVec2(m_body->GetLinearVelocity());
}

Vec2 Physics_Base::lateralVelocity()
{
	b2Vec2 currentRightNormal = m_body->GetWorldVector( b2Vec2(1,0) );
	return b2vec2ToVec2(b2Dot( currentRightNormal, vec2Tob2vec2(linearVelocity()) ) * currentRightNormal);
}

Vec2 Physics_Base::forwardVelocity()
{
	b2Vec2 currentForwardNormal = m_body->GetWorldVector( b2Vec2(0,1) );
	return b2vec2ToVec2(b2Dot( currentForwardNormal, vec2Tob2vec2(linearVelocity()) ) * currentForwardNormal);
}

float Physics_Base::mass()
{
	return m_body->GetMass();
}

Vec2 Physics_Base::worldCenter()
{
	return b2vec2ToVec2(m_body->GetWorldCenter());
}

float Physics_Base::angle()
{
	return m_body->GetAngle();
}

Vec2 Physics_Base::forwardNormal()
{
	return b2vec2ToVec2(m_body->GetWorldVector( b2Vec2(0,1) ));
}

void Physics_Base::applyLinearImpulse(const Vec2& impulse)
{
	m_body->ApplyLinearImpulse(vec2Tob2vec2(impulse), m_body->GetWorldCenter(), true);
}

void Physics_Base::applyAngularImpulse(float impulse)
{
	m_body->ApplyAngularImpulse(impulse, true);
}

float Physics_Base::angularVelocity()
{
	return m_body->GetAngularVelocity();
}

float Physics_Base::inertia()
{
	return m_body->GetInertia();
}

int Physics_Base::entityID()
{
	return m_entityID;
}

void Physics_Base::setEntityID(int id)
{
	m_entityID = id;
}

float Physics_Base::currentSpeed()
{
	Vec2 currentForwardNormal = forwardNormal();
	return DotProduct( forwardVelocity(), currentForwardNormal );
}

void Physics_Base::stopMoving()
{
	m_body->SetLinearVelocity(b2Vec2(0,0));
	m_body->SetAngularVelocity(0);
}

void Physics_Base::setBody(b2Body* body)
{				  
	if (m_body)
		throw 1; //need to free the body????
	m_body = body;
}

b2Body* Physics_Base::body()
{
	return m_body;
}

void Physics_Base::clearJoin()
{
	m_pinBodies.reset();	
}

Physics_Base::~Physics_Base()
{
	clearJoin();
	DestroyBody();
}

void Physics_Base::DestroyBody()
{
	assert(m_body);
	m_physEngine->world()->DestroyBody(m_body);
}

void Physics_Base::setAngle(float angle)
{
	m_body->SetTransform(m_body->GetWorldCenter(), angle);
}

void Physics_Base::attachPhysics(Physics* other, const Vec2& place)
{
	Physics_Base* _other = dynamic_cast<Physics_Base*>(other);
	ASSERT(other);

	clearJoin();
	m_pinBodies.reset(new PinBodies(this, _other, place));	
}

b2Vec2 vec2Tob2vec2(const Vec2& vec)
{
	return	b2Vec2(vec.x, vec.y);
}

Vec2 b2vec2ToVec2(const b2Vec2& vec)
{
	return Vec2(vec.x, vec.y);
}