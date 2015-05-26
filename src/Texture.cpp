#include "Texture.h"

#include <iostream>
#include <assert.h>

void Texture::loadImage(const std::string& path)
{
	assert(m_renderer);

	SDL_Surface* surface = loadSurface(path);
	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);

	SDL_FreeSurface(surface);

	SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
}


void Texture::render(int x, int y)
{
	assert(m_renderer);

	SDL_Rect origin = {0, 0, m_width, m_height};
	SDL_Rect dest = {x, y, m_width, m_height};
	SDL_RenderCopy(m_renderer, m_texture, &origin, &dest);
}


Texture::Texture()
	:m_texture(NULL),
	m_width(0),
	m_height(0)
{

}


SDL_Surface* loadSurface( const std::string& path, SDL_PixelFormat* format)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL)
	{
		std::cout << std::string("Unable to load image ") + path + "! SDL_image Error: " +  IMG_GetError() + "\n";
		//TODO it would be okay for now, but then we need to specify the exception
		throw std::exception();
	}
	if(format)
	{
		//The optimized image
		SDL_Surface* optimizedSurface = SDL_ConvertSurface( loadedSurface, format, NULL );

		if( optimizedSurface != NULL )
		{
			//Get rid of old loaded surface
			SDL_FreeSurface( loadedSurface );
			return optimizedSurface;
		}
		std::cout << "Unable to optimize image " + path + "! SDL Error: " + SDL_GetError() + "\n";
	}

	return loadedSurface;
}