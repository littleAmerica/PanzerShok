#ifndef _TEXTURE_
#define _TEXTURE_

#include "Utils/Singleton.h"

#include <string>
#include <memory>

#include "Utils/SDL_platform.h"


class Texture;
class RenderEngine;
class TextureManager;

typedef std::shared_ptr<Texture> TexturePtr;
typedef SDL_Texture* TextureHandle; 
typedef int TextureID;

class Texture
{
public:
	Texture();
	~Texture();

	SDL_Rect	rect() const; 
	TextureHandle textureHandle() const;

	int width() const;
	int height() const;

private:
	Texture(TextureHandle handle, SDL_Rect rect);

	friend class TextureManager;
	//The actual hardware texture
	TextureHandle m_texture;

	An<RenderEngine> m_renderEngine;
	SDL_Rect m_rect;
};



#endif
