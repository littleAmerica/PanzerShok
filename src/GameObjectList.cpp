#include "GameObjectList.h"


void GameObjectList::addGameObject(GameObjectPtr gameObject)
{
	m_gameObjectList.push_back(gameObject);
}

GameObjectPtr GameObjectList::getNthGameObject(size_t index) const
{
	return m_gameObjectList.at(index);
}

size_t GameObjectList::GetSize() const
{
	return m_gameObjectList.size();
}

