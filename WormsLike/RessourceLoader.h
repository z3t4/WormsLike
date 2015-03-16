#ifndef _RESSOURCELOADER_H
#define _RESSOURCELOADER_H

#include <SDL.h>
#include <string>

namespace Engine
{
	class RessourceLoader
	{
	public:
		static SDL_Texture* loadTexture(const std::string& textureName, SDL_Renderer* renderer);
	};
}

#endif