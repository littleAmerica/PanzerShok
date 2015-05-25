#include "Game.h"
#include <SDL_image.h>
#include <exception>
#include <iostream>


Game::Game(const std::string& name, int xpos, int ypos, int height, int width)
	:m_running(false),
	m_pWindow(NULL),
	m_pRenderer(NULL),
	m_name(name),
	m_xpos(xpos),
	m_ypos(ypos),
	m_width(width),
	m_height(height)
{
}

void Game::run()
{
	init();

	while(running())
	{
		handleEvents();

		update();

		render();
	}

	clean();
}

void Game::init()
{
	if(initSDL())
		m_running = true;
	
	text.SetRenderer(m_pRenderer);
	text.loadImage("E:\\Projects\\PanzerShok\\resource\\tank1.png");
}

void Game::render()
{
//	SDL_GL_SwapWindow(m_pWindow);
}

void Game::update()
{
	SDL_RenderClear(m_pRenderer);
	
	text.render(200, 200);

	SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		OnEvent(&event);
	}
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

bool Game::running()
{
	return m_running;
}


void Game::OnExit()
{
	m_running = false;
	delete m_world;
}


bool Game::initSDL()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	int flags = SDL_WINDOW_SHOWN;

	// if succeeded create our window
	m_pWindow = SDL_CreateWindow(m_name.c_str(), m_xpos, m_ypos, m_width, m_height, flags);

	// if the window creation succeeded create our renderer
	if(m_pWindow == NULL)
		return false;

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	if (m_pRenderer == NULL)
		return false;
		
	SDL_SetRenderDrawColor(m_pRenderer,	255, 0, 255, 255);
	m_running = true;


	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if(IMG_Init( imgFlags ) == 0)
		return false;
		
	//Get window surface
	m_Surface = SDL_GetWindowSurface( m_pWindow );

	return true;
}

void Game::OnKeyDown(SDL_Keycode sym, Uint16 mod)
{

}

bool Game::initBox2D()
{
	b2Vec2 gravity;
	gravity.Set(0.0f, 0.0f);
	
	m_world = new b2World(gravity);
}

