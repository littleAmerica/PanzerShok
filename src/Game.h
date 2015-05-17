#ifndef _GAME_H_
#define _GAME_H_

#include <string>

#include "SDL.h"

class Game
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


	bool			m_running;

	SDL_Window*		m_pWindow;
	SDL_Renderer*	m_pRenderer;
	SDL_GLContext	 m_context;

	std::string		m_name;
	int				m_xpos;
	int				m_ypos;
	int				m_width;
	int				m_height;

};

#endif