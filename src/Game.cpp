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
	:m_running(false),
	m_name(name),
	m_xpos(xpos),
	m_ypos(ypos),
	m_width(width),
	m_height(height),
	m_camera()
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
	//m_gameObjectLibrary->registerGameObject();
					
	m_running = true;
					
	Player* player = new Player();
	m_eventListeners.push_back(player);
	m_gameObjectList.addGameObject(EntityPtr(player));
	player = NULL;

	m_camera.reset(new Camera(m_width, m_height));
	m_eventListeners.push_back(this);
}

void Game::render()
{
	//TODO
	//this is temporary
	m_renderEngine->step(m_gameObjectList);	
}

void Game::update()
{
	m_physEngine->step(1.f/60);

	for(size_t i = 0; i < m_gameObjectList.GetSize(); ++i)
	{
		m_gameObjectList.getNthGameObject(i)->update(0.f); 
	}
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
	Point_t camera(mX, mY);
	Point_t word = m_camera->camera2world(camera);
	
	m_gameObjectList.addGameObject(EntityPtr(new Entity_Base(word.x, word.y)));
}

CameraPtr Game::camera()
{
	return m_camera;
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
		if(m_camera)
			m_camera->setCameraFactor(m_camera->zoomFactorX() * 1.05, m_camera->zoomFactorY() * 1.05);
	}
	else if(sym == SDLK_e)
	{
		if(m_camera)
			m_camera->setCameraFactor(m_camera->zoomFactorX() / 1.05, m_camera->zoomFactorY() / 1.05);
	}

}
