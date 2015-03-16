#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL_events.h>
#include "Drawable.h"

namespace GameLogic
{

	class Character : public Engine::Drawable
	{

	public:
		virtual int moveCharacter(SDL_Event e) = 0;
		

	private:

	protected:
		SDL_Rect m_box;
	};

}

#endif