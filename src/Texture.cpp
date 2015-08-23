#include "Texture.h"

#include <iostream>
#include <assert.h>
#include "RenderEngine.h"

Texture::Texture()
	:m_texture(NULL),
	m_rect()
{

}

Texture::Texture(TextureHandle handle, SDL_Rect rect)
	:m_texture(handle),
	m_rect(rect)
{
}

int Texture::width() const
{
	return m_rect.w;
}

int Texture::height() const
{
	return m_rect.h;
}

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


