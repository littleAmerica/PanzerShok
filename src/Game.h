#ifndef _GAME_H_
#define _GAME_H_

#include <string>
#include <vector>

#include "Texture.h"
#include "EventListener.h"
#include "Singleton.h"
#include "EntityList.h"
#include "Camera.h"

class PhysEngine;
class RenderEngine;
class GameObjectLibrary;
class Screen;
class Player;

class Game : 
	public EventListener
{
public:
	Game(const std::string& name, int xpos, int ypos, int height, int width);

	void run();

	CameraPtr	camera();
	std::string	gameName();
	//we can consider getting rid of windows setting in Game class
	//maybe we should add window class to encapsulate this concepts (if needed)
	int			windowWidth();
	int			windowHeight();
	int			windowXpos();
	int			windowYpos();

private:
	//Game routine
	void init();
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running();

	//EventListener function
	virtual void OnExit();
	virtual void OnLButtonDown(int mX, int mY);
	virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod);

	
	bool			m_running;

	An<PhysEngine>	m_physEngine;
	An<RenderEngine> m_renderEngine;
	//An<GameObjectLibrary> m_gameObjectLibrary;

	//should we make own singleton class for listeners?
	std::vector<EventListener*> m_eventListeners;
	EntityList m_gameObjectList;

	CameraPtr			m_pCamera;
	Screen*				m_pScreen;
	Player*				player;

	std::string		m_name;
	int				m_xpos;
	int				m_ypos;
	int				m_width;
	int				m_height;
};

#endif