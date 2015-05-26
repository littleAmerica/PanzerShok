#ifndef _GAME_H_
#define _GAME_H_

#include <string>

#include "SDL.h"


#include "Texture.h"
#include "Event.h"

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

	//lower Game routine
	bool initSDL();
	bool initBox2D();


	virtual void OnExit();
	virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod);

	bool			m_running;

	SDL_Window*		m_pWindow;
	SDL_Renderer*	m_pRenderer;
	SDL_Surface*	m_Surface;

	std::string		m_name;
	int				m_xpos;
	int				m_ypos;
	int				m_width;
	int				m_height;

	Texture		text;
	b2World* m_world;
};

#endif