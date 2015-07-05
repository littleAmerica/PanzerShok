#ifndef _SCREEN_
#define _SCREEN_

#include "Utils/Types.h"

class Texture;

struct SDL_Renderer;
struct SDL_Window;

class Screen
{
public:
	void init(SDL_Window*	pWindow, SDL_Renderer*	pRenderer);
	
	void clear();
	void renderImage(const Texture& image, const Rect_t& destination, float angle);
	void swapBuffer();

public:
	SDL_Window*		m_pWindow;
	SDL_Renderer*	m_pRenderer;
};

#endif