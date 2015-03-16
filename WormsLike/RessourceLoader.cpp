#include "RessourceLoader.h"

#include <SDL_image.h>
#include <iostream>

namespace Engine
{
	SDL_Texture* RessourceLoader::loadTexture(const std::string& name, SDL_Renderer* renderer)
	{
		SDL_Texture* newTexture = NULL;
		const std::string texturePath = "Textures/" + name + ".png";
		SDL_Surface* loadedSurface = IMG_Load(texturePath.c_str());

		if (loadedSurface == NULL)
		{
			std::cout << "Unable to load image " << texturePath.c_str() << "! SDL_image Error: " << IMG_GetError() << "\n" << std::endl;
		}
		else
		{
			// Convert surface to screen format
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (newTexture == NULL)
			{
				std::cout << "Unable to load image " << texturePath.c_str() << "! SDL_image Error: " << SDL_GetError() << "\n" << std::endl;
			}

			// Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
	}
}