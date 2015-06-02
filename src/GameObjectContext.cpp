#include "GameObjectContext.h"

#include "PhysEngine.h"
#include "RenderEngine.h"

#include "GameObject.h"

#include "SDL.h"

GameObjectContext::GameObjectContext(GameObject* object, Point position)
	:m_gameObject(object)
{
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(position.x, position.y);
	bodyDef.type = b2_dynamicBody;

	m_body = m_physEngine->world()->CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(/*object->weight(), object->height()*/1, 1);

	m_body->CreateFixture(&shape, 1.f);
}


Point GameObjectContext::getCenter()
{
	b2Vec2 center = m_body->GetWorldCenter();
	return Point((int)center.x, (int)center.y);	
}


GameObjectContext::~GameObjectContext()
{
	m_physEngine->world()->DestroyBody(m_body);
}

GameObject* GameObjectContext::getGameObject()
{
	return m_gameObject;
}

b2Body* GameObjectContext::body()
{
	return m_body;
}

