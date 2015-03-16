#ifndef _SCENARIOWINDOW_H
#define _SCENARIOWINDOW_H

#include <SDL.h>

#include "Drawable.h"

namespace Engine 
{
	class ScenarioWindow : public Drawable
	{
	public:
		virtual void onEvent(const SDL_Event& e) =0;
		virtual void initDrawableElements(SDL_Renderer* renderer) = 0;
		virtual void draw(SDL_Renderer* renderer) = 0;

	};
}

#endif