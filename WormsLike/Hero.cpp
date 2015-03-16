#include "Hero.h"
#include <SDL_image.h>
#include <iostream>
#include "RessourceLoader.h"

namespace GameLogic 
{
	Hero::Hero(int x, int y)
	{
		texturePath = "heroSample";
		m_box.x = x;
		m_box.y = y;
		m_box.h = 50;
		m_box.w = 30;
	}

	void Hero::onEvent(SDL_Event e)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_d:
			{
				m_box.x += 3;
				break;
			}
			case SDLK_q:
			{
				m_box.x -= 3;
				break;
			}
			case SDLK_s:
			{
				m_box.y += 3;
				break;
			}
			case SDLK_z:
			{
				m_box.y -= 3;
				break;
			}
			default :
			{
			}
		}
	}

	void Hero::initDrawableElements(SDL_Renderer* renderer)
	{
		m_texture = Engine::RessourceLoader::loadTexture(texturePath, renderer);
	}
	void Hero::draw(SDL_Renderer* renderer)
	{
		SDL_RenderCopy(renderer, m_texture, NULL, &m_box);
		SDL_RenderDrawRect(renderer, &m_box);
	}

	/*void Hero::setHeroWindowSettings(SDL_Window* window, SDL_Renderer* renderer)
	{
		m_window = window;
		m_renderer = renderer;
	}*/
}