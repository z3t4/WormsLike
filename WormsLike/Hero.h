#ifndef HERO_H
#define HERO_H

#include "Character.h"

namespace GameLogic
{

	class Hero : public Character
	{
	public : 
		Hero::Hero(int x, int y);
		virtual int moveCharacter(SDL_Event e);
	};

}
#endif
