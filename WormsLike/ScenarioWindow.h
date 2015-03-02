#ifndef _SCENARIOWINDOW_H
#define _SCENARIOWINDOW_H

#include <SDL.h>

namespace Engine 
{
	class ScenarioWindow
	{
	public:
		virtual void onEvent(const SDL_Event& e) =0;
	};
}

#endif