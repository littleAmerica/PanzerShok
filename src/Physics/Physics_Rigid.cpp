#include "Physics_Rigid.h"
#include "PhysEngine.h"

static b2Vec2 vec2Tob2vec2(const Vec2& vec);
static Vec2 b2vec2ToVec2(const b2Vec2& vec);


Physics_Rigid::Physics_Rigid(const PhysicInfo&  physicInfo, int x, int y)
	:m_physicInfo(physicInfo)
{
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(x, y);
	bodyDef.type = b2_dynamicBody;
	m_body = m_physEngine->world()->CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
	polygonShape.SetAsBox( m_physicInfo.bounds.w / 2, m_physicInfo.bounds.h / 2);
	m_body->CreateFixture(&polygonShape, 1);//shape density
}

void Physics_Rigid::applyForce(const Vec2& force)
{
	m_body->ApplyForce( vec2Tob2vec2(force), m_body->GetWorldCenter(), true );
}

void Physics_Rigid::applyTorque(float torque)
{
	m_body->ApplyTorque(torque, true);
}

Vec2 Physics_Rigid::linearVelocity()
{
	return b2vec2ToVec2(m_body->GetLinearVelocity());
}

Vec2 Physics_Rigid::lateralVelocity()
{
	b2Vec2 currentRightNormal = m_body->GetWorldVector( b2Vec2(1,0) );
	return b2vec2ToVec2(b2Dot( currentRightNormal, vec2Tob2vec2(linearVelocity()) ) * currentRightNormal);
}

Vec2 Physics_Rigid::forwardVelocity()
{
	b2Vec2 currentForwardNormal = m_body->GetWorldVector( b2Vec2(0,1) );
	return b2vec2ToVec2(b2Dot( currentForwardNormal, vec2Tob2vec2(linearVelocity()) ) * currentForwardNormal);
}

float Physics_Rigid::mass()
{
	return m_body->GetMass();
}

Vec2 Physics_Rigid::worldCenter()
{
	return b2vec2ToVec2(m_body->GetWorldCenter());
}

float Physics_Rigid::angle()
{
	return m_body->GetAngle();
}

Vec2 Physics_Rigid::forwardNormal()
{
	return b2vec2ToVec2(m_body->GetWorldVector( b2Vec2(0,1) ));
}

void Physics_Rigid::applyLinearImpulse(const Vec2& impulse)
{
	m_body->ApplyLinearImpulse(vec2Tob2vec2(impulse), m_body->GetWorldCenter(), true);
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

float Physics_Rigid::currentSpeed()
{
	Vec2 currentForwardNormal = forwardNormal();
	return DotProduct( forwardVelocity(), currentForwardNormal );
}





b2Vec2 vec2Tob2vec2(const Vec2& vec)
{
	return	b2Vec2(vec.x, vec.y);
}

Vec2 b2vec2ToVec2(const b2Vec2& vec)
{
	return Vec2(vec.x, vec.y);
}