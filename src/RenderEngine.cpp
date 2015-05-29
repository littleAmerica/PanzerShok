#include "RenderEngine.h"

template<> void anFill<RenderEngine>(An<RenderEngine>& renderEngine)
{
	RenderEngine& re = RenderEngine::Instance();
	renderEngine = &re;
}



RenderEngine& RenderEngine::Instance()
{
	static RenderEngine renderEngine;
	return renderEngine;
}



bool RenderEngine::init(const std::string& name, int xpos, int ypos, int height, int width)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	int flags = SDL_WINDOW_SHOWN;

	// if succeeded create our window
	m_pWindow = SDL_CreateWindow(name.c_str(), xpos, ypos, height, width, flags);

	// if the window creation succeeded create our renderer
	if(m_pWindow == NULL)
		return false;

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	if (m_pRenderer == NULL)
		return false;

	SDL_SetRenderDrawColor(m_pRenderer,	0, 0, 0, 255);

	//Initialize Image loading
	int imgFlags = IMG_INIT_PNG;
	if(IMG_Init( imgFlags ) == 0)
		return false;

	//Get window surface
	m_Surface = SDL_GetWindowSurface( m_pWindow );

	return true;
}


void RenderEngine::step()
{
	SDL_RenderClear(m_pRenderer);

	for (auto object : objects)
	{
		object->render();
	}

	SDL_RenderPresent(m_pRenderer);

	SDL_GL_SwapWindow(m_pWindow);
}

void RenderEngine::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
