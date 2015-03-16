#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include <SDL.h>

namespace Engine
{
	class Drawable
	{
	public: 
		virtual void initDrawableElements(SDL_Renderer* renderer) = 0;
		virtual void draw(SDL_Renderer* renderer) = 0;
	};
}
#endif