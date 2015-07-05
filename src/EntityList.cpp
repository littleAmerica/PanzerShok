#include "EntityList.h"
#include <algorithm>
#include <functional>

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

void EntityList::update(float deltaTime)
{
	for(EntityPtr entity: m_gameObjectList)
	{
		entity->update(deltaTime);
	}
}

void EntityList::draw(Screen* pScreen, Camera* pCamera /*= NULL*/)
{
	for(EntityPtr entity: m_gameObjectList)
	{
		entity->draw(pScreen, pCamera);
	}
}

int EntityList::id()
{
	return 0;
}

