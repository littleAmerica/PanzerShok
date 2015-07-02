#include "RenderEngine.h"
#include "SDL2_rotozoom.h"
#include "EntityList.h"
#include "Game.h"

#include <math.h>

static double Radian2Degree(double degree);
static  SDL_Rect Rect2SDL_Rect(Rect_t rect);



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



bool RenderEngine::init(Game* game)
{
	if(!game)
		return false;
	m_game = game;

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	int flags = SDL_WINDOW_SHOWN;

	// if succeeded create our window
	m_pWindow = SDL_CreateWindow(game->gameName().c_str(), 
		game->windowXpos(), game->windowYpos(), 
		game->windowWidth(), game->windowHeight(), 
		flags);

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


////rotate image
//SDL_Surface* RenderEngine::rotate(SDL_Surface* source, double angle, double zoom, int smooth)
//{
//	//give initial for rotate image
//	SDL_Surface* rotatefile = NULL;
//
//	//give initial for optimizing rotate image
////	SDL_Surface* optimizedrotate = NULL;
//
//	//get rotate here
//	rotatefile = rotozoomSurface(source, angle, zoom, smooth);
//
//	//get optimizing
////	optimizedrotate = SDL_DisplayFormat(rotatefile);
//
//	//free surface
////	SDL_FreeSurface( rotatefile );
//
//	return rotatefile;
//}

#include "Texture.h"
#include "Camera.h"

void RenderEngine::step(const EntityList& objects)
{
	SDL_RenderClear(m_pRenderer);

	for(size_t i = 0; i < objects.GetSize(); ++i)
	{
		objects.getNthGameObject(i)->draw();
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

SDL_Renderer* RenderEngine::renderer()
{
	return m_pRenderer;
}

double Radian2Degree(double degree)
{
	return degree * 180.0 / M_PI;
}


SDL_Rect Rect2SDL_Rect(Rect_t rect)
{
	SDL_Rect sdl_rect = {rect.x1, rect.y1, rect.x2 - rect.x1, rect.y2 - rect.y1};
	return sdl_rect;
}