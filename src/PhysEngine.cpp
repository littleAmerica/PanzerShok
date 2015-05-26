#include "PhysEngine.h"


PhysEngine& PhysEngine::Instance()
{
	static PhysEngine instance;

	return instance;
}


PhysEngine::PhysEngine()
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


void PhysEngine::Dispose()
{
	delete m_world;
}
