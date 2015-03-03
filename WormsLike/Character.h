#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL_events.h>

namespace GameLogic
{

	class Character 
	{

	public:
		virtual int moveCharacter(SDL_Event e) = 0;
		void setPosX(int x)
		{
			char_x = x;
		}
		void setPosY(int y)
		{
			char_y = y;
		}
		int getPosX()
		{
			return char_x;
		}
		int getPosY()
		{
			return char_y;
		}
	private:

	protected:
		int char_x;
		int char_y;
	};

}

#endif