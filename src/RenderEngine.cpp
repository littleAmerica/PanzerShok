#include "RenderEngine.h"
#include "SDL2_rotozoom.h"
#include "GameObjectList.h"
#include "Game.h"

#include <math.h>

double Radian2Degree(double degree);
SDL_Rect Rect2SDL_Rect(Rect_t rect);



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

void RenderEngine::step(const GameObjectList& objects)
{
	SDL_RenderClear(m_pRenderer);

	//SDL_ScaleSurface(SDL_Surface* Surface, Uint16 Width, Uint16 Height);

	Texture text_;
	text_.SetRenderer(m_pRenderer);
	text_.loadImage("E:\\Projects\\PanzerShok\\resource\\tank1.png");

	CameraPtr camera = m_game ? m_game->camera() : NULL;

	for(size_t i = 0; i < objects.GetSize(); ++i)
	{
		GameObject* object = objects.getNthGameObject(i); 
		
		Rect_t size = object->rect();
		SDL_Rect origin = Rect2SDL_Rect(size);
		
		b2Vec2 center = object->center();
		SDL_Rect dest = {center.x - size.x1, center.y - size.x2, size.x2, size.y2};


		SDL_Surface *s = SDL_CreateRGBSurface(0, size.x2, size.y2, 32, 0, 0, 0, 0);
		SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 255, 0, 0));

		SDL_Texture* text = SDL_CreateTextureFromSurface(m_pRenderer, s);

		if(camera)
			dest = camera->apply(dest);
	
		SDL_RenderCopyEx(m_pRenderer, text_.textureHandle(), &text_.rect()/*origin*/, &dest, Radian2Degree(object->angle()) + 180, NULL, SDL_FLIP_NONE);
	
		SDL_DestroyTexture(text);
		SDL_FreeSurface(s);


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