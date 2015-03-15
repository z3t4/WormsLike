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
		/*virtual void setBoxX(int x)
		{
			m_box= x;
		}
		virtual void setBoxY(int y)
		{

		}
		virtual void setBoxH(int h)
		{

		}
		virtual void setBoxW(int w)
		{

		} */

	private:

	protected:
		SDL_Rect m_box;
	};

}

#endif