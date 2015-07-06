#include "Screen.h"
#include "SDL.h"
#include "Texture.h"


static SDL_Rect Rect2SDL_Rect(Rect_t rect);
static double Radian2Degree(double degree);

void Screen::init(SDL_Window* pWindow, SDL_Renderer* pRenderer)
{
	m_pRenderer = pRenderer;
	m_pWindow = pWindow;
}

void Screen::renderImage(const Texture& text_, const Rect_t& destination, float angle)
{
	if (!m_pRenderer)
		throw "Screen isn't initialized";
	SDL_Rect dest = Rect2SDL_Rect(destination);
	SDL_RenderCopyEx(m_pRenderer, text_.textureHandle(), &text_.rect()/*origin*/, &dest, Radian2Degree(angle), NULL, SDL_FLIP_NONE);
}

void Screen::clear()
{
	SDL_RenderClear(m_pRenderer);
}

void Screen::swapBuffer()
{
	SDL_RenderPresent(m_pRenderer);
	SDL_GL_SwapWindow(m_pWindow);
}

double Radian2Degree(double degree)
{
	return degree * 180.0 / M_PI;
}

SDL_Rect Rect2SDL_Rect(Rect_t rect)
{
	SDL_Rect sdl_rect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
	return sdl_rect;
}