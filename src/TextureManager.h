#ifndef _TEXTURE_MANAGER_H
#define _TEXTURE_MANAGER_H

#include "Utils//Singleton.h"
#include "Texture.h"

#include <string>
#include <memory>
#include <map>

class RenderEngine;

class TextureManager
{
private:
	TextureManager();
public:
	static TextureManager& Instance();
	
	void LoadTexture(const std::string& path, TextureID ID);

	TexturePtr GetTexture(TextureID id);
private:
	An<RenderEngine> m_renderEngine;
 
	typedef std::map<TextureID, TexturePtr> Textures_t;
	typedef Textures_t::iterator Textures_Iter;
	Textures_t m_textures;
};


template<> void anFill<TextureManager>(An<TextureManager>& textureManager);

#endif