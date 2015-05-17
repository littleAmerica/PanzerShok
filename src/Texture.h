#ifndef _TEXTURE_
#define _TEXTURE_

#include "SDL.h"
#include "SDL_image.h"
#include <string>

class Texture
{
public:
	Texture();

	void SetRenderer(SDL_Renderer* renderer){m_renderer = renderer;}

	void loadImage(const std::string& path);

	void render( int x, int y);
	
	int getWidth(){return m_width;}
	int getHeight(){return m_height;}

private:
	//The actual hardware texture
	SDL_Texture* m_texture;

	SDL_Renderer* m_renderer;

	//Image dimensions
	int m_width;
	int m_height;
};

SDL_Surface* loadSurface( const std::string& path, SDL_PixelFormat* format = NULL);

#endif