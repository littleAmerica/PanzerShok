#include "Game.h"

#include <exception>
#include <iostream>

#include "RenderEngine.h"
#include "Player.h"
#include "Physics/PhysEngine.h"
#include "GameObjectLibrary.h"

#include "Entity.h"
#include "States.h"
#include "Timer.h"

Game::Game(const std::string& name, int xpos, int ypos, int height, int width)
    : m_running(false),
      m_pCamera(),
      m_pScreen(NULL),
      player(NULL),
	m_name(name),
	m_xpos(xpos),
	m_ypos(ypos),
	m_width(width),
    m_height(height)
{

}

static const int FRAMES_PER_SECOND = 40;

void Game::run()
{
	init();

	Timer timer;

	while(running())
	{
		timer.start();

		handleEvents();

		update();

		render();

		int ticks = timer.ticks();

		if(ticks < 1000 / FRAMES_PER_SECOND)
			timer.wait(( 1000 / FRAMES_PER_SECOND ) - ticks);
	}

	clean();
}

void Game::init()
{
	m_physEngine->init();
	m_renderEngine->init(this);
	m_pCamera.reset(new Camera(m_width, m_height));
	
	m_pScreen = m_renderEngine->screen();

	m_running = true;
					
	player = new Player(100, 100);
	m_eventListeners.push_back(player);
	m_gameObjectList.addGameObject(EntityPtr(player));


	m_eventListeners.push_back(this);
}

void Game::render()
{
	//m_pCamera->setCenter(player->center());

	m_pScreen->clear();
	m_gameObjectList.draw(m_pScreen, m_pCamera.get());
	m_pScreen->swapBuffer();
}

void Game::update()
{
	m_physEngine->step(1.f/60);

	m_gameObjectList.update(0.f); 
}

void Game::handleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		for(EventListener* eventListener : m_eventListeners)
			eventListener->OnEvent(&event);
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

void Game::OnLButtonDown(int mX, int mY)
{
	Vec2 word = m_pCamera->camera2world(Vec2(mX, mY));
	
	m_gameObjectList.addGameObject(EntityPtr(new Entity_Base(word.x, word.y)));
}

CameraPtr Game::camera()
{
	return m_pCamera;
}

std::string Game::gameName()
{
	return m_name;
}

int Game::windowWidth()
{
	return m_width;
}

int Game::windowHeight()
{
	return m_height;
}

int Game::windowXpos()
{
	return m_xpos;
}

int Game::windowYpos()
{
	return m_ypos;
}

void Game::OnKeyDown(SDL_Keycode sym, Uint16 mod)
{
	if(sym == SDLK_q)
	{
		if(m_pCamera)
			m_pCamera->setCameraFactor(m_pCamera->zoomFactorX() * 1.01f, m_pCamera->zoomFactorY() * 1.01f);
	}
	else if(sym == SDLK_e)
	{
		if(m_pCamera)
			m_pCamera->setCameraFactor(m_pCamera->zoomFactorX() / 1.01f, m_pCamera->zoomFactorY() / 1.01f);
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
