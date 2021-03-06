#ifndef _RENDER_ENGINE_
#define _RENDER_ENGINE_

#include <vector>

#include "Utils/SDL_platform.h"
#include <string>
#include "Utils//Singleton.h"

#include "Entities/Entity.h"
#include "Screen.h"

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

	SDL_Renderer*	renderer();
	Screen* screen();
	SDL_Window*	window();

private:
	Screen	m_screen;
	
	SDL_Window*		m_pWindow;
	SDL_Renderer*	m_pRenderer;
	SDL_Surface*	m_Surface;
};


template<> void anFill<RenderEngine>(An<RenderEngine>& renderEngine);

#endif 
