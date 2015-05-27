#ifndef _RENDER_ENGINE_
#define _RENDER_ENGINE_

#include "SDL.h"
#include <string>
#include <SDL_image.h>
#include "Singleton.h"

class RenderEngine
{
private:

	RenderEngine(){}

public:
	static RenderEngine& Instance();
	
	bool init(const std::string& name, int xpos, int ypos, int height, int width);
	void step();
	void clean();

private:

	SDL_Window*		m_pWindow;
	SDL_Renderer*	m_pRenderer;
	SDL_Surface*	m_Surface;
};


template<> void anFill<RenderEngine>(An<RenderEngine>& renderEngine);

#endif 