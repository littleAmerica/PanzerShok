#ifndef RENDER_ENGINE_H_
#define RENDER_ENGINE_H_

#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Singleton.h"

#include "Entity.h"
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

#endif // RENDER_ENGINE_H_
