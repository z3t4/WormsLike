#ifndef _GAMEWINDOW_H
#define _GAMEWINDOW_H

#include "ScenarioWindow.h"

namespace Engine  
{
	class GameWindow : public ScenarioWindow
	{
	public:
		virtual void onEvent(const SDL_Event& e);
	};
}

#endif