#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_

#include <memory>

#include "Singleton.h"
#include "PhysBody.h"

class PhysEngine;
class RenderEngine;

class GameObject
{	
public:
	GameObject();

	void render();
	
	~GameObject();
private:
	An<PhysEngine> m_physEngine;
	An<RenderEngine> m_renderEngine;

	PhysBodyPtr m_physBody;
};

#endif