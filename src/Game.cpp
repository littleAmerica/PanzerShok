#include "Game.h"

#include <exception>
#include <iostream>

#include "RenderEngine.h"
#include "Entities/Player.h"
#include "Physics/PhysEngine.h"
#include "GameObjectLibrary.h"
#include "TextureManager.h"

#include "Entities/Entity.h"
#include "States.h"
#include "Timer.h"
#include "Utils/Resources.h"
#include "Utils/Asserts.h"

Game::Game(const std::string& name, int xpos, int ypos, int height, int width)
    : m_running(false),
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

		update(1.f / FRAMES_PER_SECOND);

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
	m_cameraManager->setActiveCamara(CameraPtr(new Camera(m_width, m_height)));
	camera()->setCameraFactor(1.5f, 1.5f);
	
	m_pScreen = m_renderEngine->screen();

	m_running = true;
					
	player = new Player(100, 100);
	m_eventListeners.push_back(player);
	m_gameObjectList = &EntityList::instance();
	m_gameObjectList->addGameObject(player->entity());

	//TODO move to resource manager
	m_textureManager->LoadTexture(kResourceFolder + "tank1.png", 1);
	m_textureManager->LoadTexture(kResourceFolder + "turret1.png", 2);
	m_textureManager->LoadTexture(kResourceFolder + "bullet1.png", 3);

	m_eventListeners.push_back(this);
}

void Game::render()
{
	//m_pCamera->setCenter(player->center());

	m_pScreen->clear();
	m_gameObjectList->draw(m_pScreen, m_cameraManager->activeCamera().get());
	m_pScreen->swapBuffer();
}

void Game::update(float timeStep)
{
	m_physEngine->step(1.f/60);

	m_gameObjectList->update(timeStep); 
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
	m_eventListeners.clear();
	m_gameObjectList->clear();
	
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

CameraPtr Game::camera()
{
	CameraPtr _camera = m_cameraManager->activeCamera();
	ASSERT(_camera);
	return _camera;
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
		camera()->setCameraFactor(camera()->zoomFactorX() * 1.01f, camera()->zoomFactorY() * 1.01f);
	}
	else if(sym == SDLK_e)
	{
		camera()->setCameraFactor(camera()->zoomFactorX() / 1.01f, camera()->zoomFactorY() / 1.01f);
	}

}

void Game::OnLButtonDown(int mX, int mY)
{
	//Vec2 word = camera()->camera2world(Vec2(mX, mY));

	//Entity_Info info = {Entity_Info::eKinematic, Rect_t(0, 0, 32, 32), 1};
	//m_gameObjectList->addGameObject(EntityPtr(new Entity_Base(Vec2(mX, mY), &info)));
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
