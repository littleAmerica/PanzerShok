#ifndef __GAME_OBJECT_LIST__
#define __GAME_OBJECT_LIST__

#include <vector>
#include <memory>

#include "Entities/Entity.h"

class Enity;
typedef std::shared_ptr<Entity> EntityPtr;

class EntityList : public Entity

{
public:
	static EntityList& instance();

	virtual void update(float deltaTime); 
	virtual void draw(Screen* pScreen, Camera* pCamera = NULL);

	virtual int id();

	void addGameObject(EntityPtr gameObject);
	EntityPtr getNthGameObject(size_t index) const;
	size_t GetSize() const;

	virtual void clear();
private:
	//hold all gameObjects
	//We can consider rewriting this in case 
	//we need some sort of order in rendering the game object
	std::vector<EntityPtr> m_gameObjectList;
};

#endif