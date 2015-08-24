#include "TextureManager.h"
#include "Utils/Asserts.h"
#include "SDL_platform.h"
#include "RenderEngine.h"

#include <iostream>

static SDL_Surface* loadSurface( const std::string& path, SDL_PixelFormat* format = NULL);

template<> void anFill<TextureManager>(An<TextureManager>& textureManager)
{
	TextureManager& tm = TextureManager::Instance();
	textureManager = &tm;
}

TextureManager::TextureManager()
{

}

TextureManager& TextureManager::Instance()
{
	static TextureManager tm;
	return tm;
}

void TextureManager::LoadTexture(const std::string& path, int ID)
{
	SDL_Surface* surface = loadSurface(path);
	TextureHandle textureHandle = SDL_CreateTextureFromSurface(m_renderEngine->renderer(), surface);

	SDL_FreeSurface(surface);
	int origWidth = 0;
	int origHeight = 0;
	SDL_QueryTexture(textureHandle, NULL, NULL, &origWidth, &origHeight);
	SDL_Rect size = {0, 0, origWidth, origHeight};
	TexturePtr texture(new Texture(textureHandle, size));

	m_textures[ID] = texture;
}

TexturePtr TextureManager::GetTexture(TextureID id)
{
	Textures_Iter iter = m_textures.find(id);
	ASSERT(iter != m_textures.end());
	return iter->second;
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