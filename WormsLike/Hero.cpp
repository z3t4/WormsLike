#include "Hero.h"
#include <iostream>

namespace GameLogic 
{
	Hero::Hero(int x, int y)
	{
		setPosX(x);
		setPosY(y);
	}
	int Hero::moveCharacter(SDL_Event e)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_d:
			{
				setPosX(getPosX() + 3);
				return 0;
			}
			case SDLK_q:
			{
				setPosX(getPosX() - 3);
				return 0;
			}
			case SDLK_s:
			{
				setPosY(getPosY() - 3);
				return 0;
			}
			case SDLK_z:
			{
				setPosY(getPosY() + 3);
				return 0;
			}
			default :
			{
				std::cout << "aucun mouvement détecté" << std::endl;
				return 1;
			}
		}
	}
}