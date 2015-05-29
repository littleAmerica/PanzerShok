#include "GameObject.h"

#include "PhysEngine.h"
#include "RenderEngine.h"

#include "SDL.h"


GameObject::GameObject()
{
	m_physBody = m_physEngine->createBoxPhysBody(Point(100, 100), 32, 32);
}

GameObject::~GameObject()
{	
}

void GameObject::render()
{
	SDL_Surface *s;
	s = SDL_CreateRGBSurface(0, 32, 32, 32, 0, 0, 0, 0);
	SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 255, 0, 0));

	SDL_Texture* text = SDL_CreateTextureFromSurface(m_renderEngine->m_pRenderer, s);
	SDL_Rect origin = {0, 0, 40, 40};

	Point center = m_physBody->getCenter();

	SDL_Rect dest = {center.x - 16, center.y - 16, 32, 32};
	SDL_RenderCopy(m_renderEngine->m_pRenderer, text, &origin, &dest);
}

