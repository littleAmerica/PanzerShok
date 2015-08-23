#include "Physics_Rigid.h"
#include "PhysEngine.h"


Physics_Rigid::Physics_Rigid(const PhysicInfo&  physicInfo, int x, int y)
	:m_physicInfo(physicInfo)
{
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(x, y);
	bodyDef.type = b2_dynamicBody;
	bodyDef.angle = physicInfo.angle;

	b2Body* body = m_physEngine->world()->CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
	polygonShape.SetAsBox( m_physicInfo.bounds.w / 2, m_physicInfo.bounds.h / 2);
	body->CreateFixture(&polygonShape, 1);//shape density
	setBody(body);
}

Rect_t Physics_Rigid::bounds()
{
	return m_physicInfo.bounds;
}

Physics_Static::Physics_Static(const PhysicInfo& physicInfo, int x, int y)
	:m_physicInfo(physicInfo)
{
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(x, y);
	bodyDef.type = b2_staticBody;
	b2Body* body = m_physEngine->world()->CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
	polygonShape.SetAsBox( m_physicInfo.bounds.w / 2, m_physicInfo.bounds.h / 2);
	body->CreateFixture(&polygonShape, 1);//shape density
	setBody(body);
}


Rect_t Physics_Static::bounds()
{
	return m_physicInfo.bounds;
}

Physics_Kinematic::Physics_Kinematic(const PhysicInfo& physicInfo, int x, int y)
	:m_physicInfo(physicInfo)
{
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(x, y);
	bodyDef.type = b2_kinematicBody;
	b2Body* body = m_physEngine->world()->CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
	polygonShape.SetAsBox( m_physicInfo.bounds.w / 2, m_physicInfo.bounds.h / 2);
	body->CreateFixture(&polygonShape, 1);//shape density
	setBody(body);
}

Rect_t Physics_Kinematic::bounds()
{
	return m_physicInfo.bounds;
}
