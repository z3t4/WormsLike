#ifndef _MENUWINDOW_H
#define _MENUWINDOW_H

#include "ScenarioWindow.h"

namespace Engine 
{
	class MenuWindow : public ScenarioWindow
	{
	public:
		MenuWindow();
		virtual void onEvent(const SDL_Event& e);
	};
}

#endif