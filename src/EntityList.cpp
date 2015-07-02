#include "EntityList.h"


void EntityList::addGameObject(EntityPtr gameObject)
{
	m_gameObjectList.push_back(gameObject);
}

EntityPtr EntityList::getNthGameObject(size_t index) const
{
	return m_gameObjectList.at(index);
}

size_t EntityList::GetSize() const
{
	return m_gameObjectList.size();
}

