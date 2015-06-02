#ifndef _GAME_OBJECT_CONTEXT_
#define _GAME_OBJECT_CONTEXT_

#include <memory>

#include "Box2D.h"
#include "Types.h"
#include "Singleton.h"

class PhysEngine;
class GameObject;

class GameObjectContext
{	
public:
	GameObjectContext(GameObject* object, Point position);	
	~GameObjectContext();

	b2Body* body();
	GameObject* getGameObject();
	Point		getCenter();

private:
	GameObject* m_gameObject;	
	b2Body* m_body;

	An<PhysEngine> m_physEngine;
};

#endif