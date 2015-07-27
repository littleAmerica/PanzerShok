#include "Texture.h"

#include <iostream>
#include <assert.h>
//#include "SDL2_rotozoom.h"

void Texture::loadImage(const std::string& path)
{
	assert(m_renderer);
	//SDL_Rect rect = {0, 0, 0, 0};
	//m_rect = rect;

	SDL_Surface* surface = loadSurface(path);
	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);

	SDL_FreeSurface(surface);

	SDL_QueryTexture(m_texture, NULL, NULL, &m_rect.w, &m_rect.h);
}


//void Texture::render(int x, int y)
//{
//	assert(m_renderer);
//
//	SDL_Rect origin = {0, 0, m_width, m_height};
//	SDL_Rect dest = {x, y, m_width, m_height};
//	SDL_RenderCopy(m_renderer, m_texture, &origin, &dest);
//}


Texture::Texture()
	:m_texture(NULL),
	m_rect()
{

}

Texture::Texture(TextureHandle texture, int w /*= 0*/, int h /*= 0*/)
	:m_texture(texture),
	m_rect()
{
	if(w == 0)
		SDL_QueryTexture(m_texture, NULL, NULL, &m_rect.w, NULL);
	else
		m_rect.w = w;

	if(h == 0)
		SDL_QueryTexture(m_texture, NULL, NULL, &m_rect.h, NULL);
	else
		m_rect.h = h;
}

void Texture::SetRenderer(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

int Texture::width() const
{
	return m_rect.w;
}

int Texture::height() const
{
	return m_rect.h;
}

//TexturePtr Texture::scaleTexture(int new_width, int new_heigh)
//{
//	return TexturePtr(new Texture(m_texture, new_width, new_heigh));
//}

TextureHandle Texture::textureHandle() const
{
	return m_texture;
}

SDL_Rect Texture::rect() const
{
	return m_rect;
}

Texture::~Texture()
{
	SDL_DestroyTexture(m_texture);	
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
