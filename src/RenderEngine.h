#ifndef _RENDER_ENGINE_
#define _RENDER_ENGINE_

#include <vector>

#include "SDL.h"
#include <string>
#include <SDL_image.h>
#include "Singleton.h"

#include "Entity.h"

class EntityList;
class Game;

class RenderEngine
{
private:

	RenderEngine(){}

public:
	static RenderEngine& Instance();
	
	bool init(Game* game);
	void step(const EntityList& objects);
	void clean();

	SDL_Renderer* renderer();

	//SDL_Surface* RenderEngine::rotate(SDL_Surface* source, double angle, double zoom, int smooth);

	public:
	Game*	m_game;
	SDL_Window*		m_pWindow;
	SDL_Renderer*	m_pRenderer;
	SDL_Surface*	m_Surface;
};


template<> void anFill<RenderEngine>(An<RenderEngine>& renderEngine);

#endif 