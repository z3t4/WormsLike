#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include <string>

namespace GameLogic
{

	class Hero : public Character
	{
	public : 
		Hero::Hero(int x, int y);
		virtual int moveCharacter(SDL_Event e);
		virtual void initDrawableElements();
		virtual void draw();
		void setHeroWindowSettings(SDL_Window* window, SDL_Renderer* renderer);
	private :
		std::string texturePath;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		SDL_Surface* m_surface;
		SDL_Window* m_window;
	};

}
#endif
