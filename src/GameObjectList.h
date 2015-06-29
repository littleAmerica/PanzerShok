#ifndef __GAME_OBJECT_LIST__
#define __GAME_OBJECT_LIST__

#include <vector>

class GameObject;

typedef GameObject* GameObjectPtr;

class GameObjectList
{
public:
	void addGameObject(GameObjectPtr gameObject);
	GameObjectPtr getNthGameObject(size_t index) const;
	size_t GetSize() const;


private:
	//hold all gameObjects
	//TODO add shared_ptr 
	//We can consider rewriting this in case 
	//we need some sort of order in rendering the game object
	std::vector<GameObjectPtr> m_gameObjectList;
};

#endif