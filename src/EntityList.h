#ifndef ENTITYLIST_H_
#define ENTITYLIST_H_

#include <vector>
#include <memory>

#include "Entity.h"

class Enity;
typedef std::shared_ptr<Entity> EntityPtr;

class EntityList : public Entity
{
public:

	virtual void update(float deltaTime); 
	virtual void draw(Screen* pScreen, Camera* pCamera = NULL);

	virtual int id();

	void addGameObject(EntityPtr gameObject);
	EntityPtr getNthGameObject(size_t index) const;
	size_t GetSize() const;


private:
	//hold all gameObjects
	//We can consider rewriting this in case 
	//we need some sort of order in rendering the game object
	std::vector<EntityPtr> m_gameObjectList;
};

#endif // ENTITYLIST_H_
