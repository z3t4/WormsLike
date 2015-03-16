#include "Hero.h"
#include <SDL_image.h>
#include <iostream>

namespace GameLogic 
{
	Hero::Hero(int x, int y)
	{
		texturePath = "Textures/heroSample.png";
		m_box.x = x;
		m_box.y = y;
		m_box.h = 30;
		m_box.w = 20;
	}

	int Hero::moveCharacter(SDL_Event e)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_d:
			{
				m_box.x += 3;
				return 0;
			}
			case SDLK_q:
			{
				m_box.x -= 3;
				return 0;
			}
			case SDLK_s:
			{
				m_box.y += 3;
				return 0;
			}
			case SDLK_z:
			{
				m_box.y -= 3;
				return 0;
			}
			default :
			{
				std::cout << "aucun mouvement détecté" << std::endl;
				return 1;
			}
		}
	}

	void Hero::initDrawableElements(SDL_Renderer* renderer)
	{
		SDL_Texture* newTexture = NULL;
		SDL_Surface* loadedSurface = IMG_Load(texturePath.c_str());

		if (loadedSurface == NULL)
		{
			std::cout << "Unable to load image " << texturePath.c_str() << "! SDL_image Error: " << IMG_GetError() << "\n" << std::endl;
		}
		else
		{
			//Convert surface to screen format
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (newTexture == NULL)
			{
				std::cout << "Unable to load image " << texturePath.c_str() << "! SDL_image Error: " << SDL_GetError() << "\n" << std::endl;
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}

		m_texture = newTexture;
	}
	void Hero::draw(SDL_Renderer* renderer)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, m_texture, NULL, &m_box);
		SDL_RenderDrawRect(renderer, &m_box);
		SDL_RenderPresent(renderer);
	}

	/*void Hero::setHeroWindowSettings(SDL_Window* window, SDL_Renderer* renderer)
	{
		m_window = window;
		m_renderer = renderer;
	}*/
}