#ifndef _GAME_OBJECT_LIBRARY_
#define _GAME_OBJECT_LIBRARY_

#include <memory>
#include <string>
#include <map>

#include "Singleton.h"

class GameObject;

class GameObjectLibrary
{	
	GameObjectLibrary();
	~GameObjectLibrary();
public:
	static GameObjectLibrary& Instance();
	void registerGameObject();

	GameObject* find(const std::string& name);

private:
	typedef std::map<std::string, GameObject*> GameObjectMap;
	typedef GameObjectMap::iterator GameObjectIter;
	typedef GameObjectMap::value_type GameObjectMapType;
	GameObjectMap m_library;
};


template<> void anFill<GameObjectLibrary>(An<GameObjectLibrary>& renderEngine);

#endif