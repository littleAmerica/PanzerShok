#include "GameObjectLibrary.h"

template<> void anFill<GameObjectLibrary>(An<GameObjectLibrary>& renderEngine)
{
	GameObjectLibrary& re = GameObjectLibrary::Instance();
	renderEngine = &re;
}


GameObjectLibrary& GameObjectLibrary::Instance()
{
	static GameObjectLibrary gamaeObjectLibrary;
	return gamaeObjectLibrary;
}

GameObject* GameObjectLibrary::find(const std::string& name)
{
	GameObjectIter iter = m_library.find(name);
	return iter != m_library.end() ? iter->second : NULL;
}

void GameObjectLibrary::registerGameObject()
{
//	GameObject* gameobject = new GameObject();
//	m_library["the only"] = gameobject;
}

GameObjectLibrary::~GameObjectLibrary()
{
	for(GameObjectMapType& instance: m_library)
	{
		delete instance.second;
		instance.second = NULL;
	}
	m_library.clear();
}

GameObjectLibrary::GameObjectLibrary()
{

}
