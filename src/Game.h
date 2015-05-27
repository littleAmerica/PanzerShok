#ifndef _GAME_H_
#define _GAME_H_

#include <string>

#include "Texture.h"
#include "Event.h"

#include "RenderEngine.h"
#include "PhysEngine.h"

class Game : private Event
{
public:
	Game(const std::string& name, int xpos, int ypos, int height, int width);

	void run();

private:
	//Game routine
	void init();
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running();


	virtual void OnExit();
	virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod);

	bool			m_running;

	An<PhysEngine>	m_physEngine;
	An<RenderEngine> m_renderEngine;


	std::string		m_name;
	int				m_xpos;
	int				m_ypos;
	int				m_width;
	int				m_height;

	Texture		text;
};

#endif