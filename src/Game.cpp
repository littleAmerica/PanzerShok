#include "Game.h"

#include <exception>
#include <iostream>


Game::Game(const std::string& name, int xpos, int ypos, int height, int width)
	:m_running(false),
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

	m_renderEngine->objects.push_back(new GameObject());

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
	m_physEngine->init();
	m_renderEngine->init(m_name, m_xpos, m_ypos, m_width, m_height);
					
	m_running = true;
					
	//text.SetRenderer(m_pRendererm_height;);
	//text.loadImage(".\\resource\\tank1.png");
}

void Game::render()
{
//	SDL_GL_SwapWindow(m_pWindow);
}

void Game::update()
{
	m_physEngine->step(1.f/60);
	m_renderEngine->step();	
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
	m_physEngine->clean();
	m_renderEngine->clean();	
}

bool Game::running()
{
	return m_running;
}


void Game::OnExit()
{
	m_running = false;
}


void Game::OnKeyDown(SDL_Keycode sym, Uint16 mod)
{
	if(sym == SDLK_w)
	{
//		m_renderEngine->objects[0]->m_physBody->move(1);	
	}
}

