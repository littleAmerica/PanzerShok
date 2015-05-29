#include "PhysEngine.h"


template<> void anFill<PhysEngine>(An<PhysEngine>& physEngine)
{
	PhysEngine& pe = PhysEngine::Instance();
	physEngine = &pe;
}

PhysEngine& PhysEngine::Instance()
{
	static PhysEngine instance;
	return instance;
}


PhysEngine::PhysEngine():
	m_world(0)
{

}

void PhysEngine::step(float timeStep)
{
	m_world->Step(timeStep, m_velocityIterations, m_positionIterations);
}


void PhysEngine::init()
{
	b2Vec2 gravity;
	gravity.Set(0.0f, 0.0f);

	m_world = new b2World(gravity);

	m_velocityIterations = 8;
	m_positionIterations = 3;
}


void PhysEngine::clean()
{
	delete m_world;
}

PhysEngine::~PhysEngine()
{

}

PhysBodyPtr PhysEngine::createBoxPhysBody(const Point& position, int width, int height)
{
	PhysBodyPtr newBody(new PhysBody());

	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(position.x, position.y);
	bodyDef.type = b2_dynamicBody;

	newBody->m_body = m_world->CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(width,height);

	newBody->m_body->CreateFixture(&shape, 0.0f);

	return newBody;
}

void PhysEngine::destroyPhysBody(PhysBodyPtr body)
{
	m_world->DestroyBody(body->m_body);
}
