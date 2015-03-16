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
		virtual void onEvent(SDL_Event e);
		virtual void initDrawableElements(SDL_Renderer* renderer);
		virtual void draw(SDL_Renderer* renderer);

	private :
		std::string texturePath;
	
		SDL_Texture* m_texture;
		SDL_Window* m_window;
	};

}
#endif
