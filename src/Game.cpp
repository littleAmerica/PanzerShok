#include "Game.h"

#include <exception>
#include <iostream>

#include "RenderEngine.h"
#include "PhysEngine.h"
#include "GameObjectLibrary.h"

#include "GameObjectContext.h"
#include "GameObject.h"
#include "States.h"

static GameObjectContext* player;
static int state = 0;


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
	m_gameObjectLibrary->registerGameObject();
					
	m_running = true;
					
	player = new GameObjectContext(m_gameObjectLibrary->find("the only"), Point(100, 100));
}

void Game::render()
{
	m_renderEngine->step(player);	
}

void Game::update()
{
	m_physEngine->step(1.f/60);
}

void Game::handleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		OnEvent(&event);
	}
	
	player->getGameObject()->updateFriction(player);
	player->getGameObject()->updateDrive(player, state);
	player->getGameObject()->updateTurn(player, state);
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
	switch (sym)
	{
	case SDLK_w: state |= UP; break;
	case SDLK_s: state |= DOWN; break;
	case SDLK_a: state |= LEFT; break;
	case SDLK_d: state |= RIGHT; break;
	default:
		break;
	}

}

void Game::OnKeyUp(SDL_Keycode sym, Uint16 mod)
{
	switch (sym)
	{
	case SDLK_w: state &= ~UP; break;
	case SDLK_s: state &= ~DOWN; break;
	case SDLK_a: state &= ~LEFT; break;
	case SDLK_d: state &= ~RIGHT; break;
	default:
		break;
	}
}

//
//void Keyboard(unsigned char key)
//{
//	switch (key) {
//	case 'a' : m_controlState |= TDC_LEFT; break;
//	case 'd' : m_controlState |= TDC_RIGHT; break;
//	case 'w' : m_controlState |= TDC_UP; break;
//	case 's' : m_controlState |= TDC_DOWN; break;
//	}
//}
//
//void KeyboardUp(unsigned char key)
//{
//	switch (key) {
//	case 'a' : m_controlState &= ~TDC_LEFT; break;
//	case 'd' : m_controlState &= ~TDC_RIGHT; break;
//	case 'w' : m_controlState &= ~TDC_UP; break;
//	case 's' : m_controlState &= ~TDC_DOWN; break;
//	}
//}