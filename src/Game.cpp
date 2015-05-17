#include "Game.h"

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
	init();
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
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		int flags = SDL_WINDOW_SHOWN;

		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(m_name.c_str(), m_xpos, m_ypos, m_width, m_height, flags);

		// if the window creation succeeded create our renderer
		if(m_pWindow != 0)
		{
			m_context = SDL_GL_CreateContext(m_pWindow);

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer)
			{
				SDL_SetRenderDrawColor(m_pRenderer,	255, 0, 255, 255);
				m_running = true;
			}
		}
	}
}

void Game::render()
{
	SDL_GL_SwapWindow(m_pWindow);
}

void Game::update()
{

}

void Game::handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch(event.type) {
			case SDL_QUIT: 
				m_running = false;
			break;
			default:
				break;
		}
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

