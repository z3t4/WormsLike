#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include <SDL.h>

namespace Engine
{
	class Drawable
	{
	public: 
		virtual void initDrawableElements() =0;
		virtual void draw() =0;
	};
}
#endif