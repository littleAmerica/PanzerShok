#include "Physics_Rigid.h"
#include "PhysEngine.h"


Physics_Rigid::Physics_Rigid(const PhysicInfo&  physicInfo, int x, int y)
	:m_physicInfo(physicInfo)
{
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(x, y);
	bodyDef.type = b2_dynamicBody;
	m_body = m_physEngine->world()->CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
	polygonShape.SetAsBox( m_physicInfo.bounds.x2 / 2, m_physicInfo.bounds.y2 / 2);
	m_body->CreateFixture(&polygonShape, 1);//shape density
}

void Physics_Rigid::applyForce(const b2Vec2& force)
{
	m_body->ApplyForce( force, m_body->GetWorldCenter(), true );
}

void Physics_Rigid::applyTorque(float torque)
{
	m_body->ApplyTorque(torque, true);
}

b2Vec2 Physics_Rigid::linearVelocity()
{
	return m_body->GetLinearVelocity();
}

b2Vec2 Physics_Rigid::lateralVelocity()
{
	b2Vec2 currentRightNormal = m_body->GetWorldVector( b2Vec2(1,0) );
	return b2Dot( currentRightNormal, linearVelocity() ) * currentRightNormal;
}

b2Vec2 Physics_Rigid::forwardVelocity()
{
	b2Vec2 currentForwardNormal = m_body->GetWorldVector( b2Vec2(0,1) );
	return b2Dot( currentForwardNormal, linearVelocity() ) * currentForwardNormal;
}

float Physics_Rigid::mass()
{
	return m_body->GetMass();
}

b2Vec2 Physics_Rigid::worldCenter()
{
	return m_body->GetWorldCenter();
}

float Physics_Rigid::angle()
{
	return m_body->GetAngle();
}

b2Vec2 Physics_Rigid::forwardNormal()
{
	return m_body->GetWorldVector( b2Vec2(0,1) );
}

void Physics_Rigid::applyLinearImpulse(const b2Vec2& impulse)
{
	m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(), true);
}

void Physics_Rigid::applyAngularImpulse(float impulse)
{
	m_body->ApplyAngularImpulse(impulse, true);
}

float Physics_Rigid::angularVelocity()
{
	return m_body->GetAngularVelocity();
}

float Physics_Rigid::inertia()
{
	return m_body->GetInertia();
}

int Physics_Rigid::entityID()
{
	return m_entityID;
}

Rect_t Physics_Rigid::bounds()
{
	return m_physicInfo.bounds;
}

void Physics_Rigid::setEntityID(int id)
{
	m_entityID = id;
}




