#ifndef _WINDOW_H
#define _WINDOW_H

#include "ScenarioWindow.h"

namespace Engine 
{
	class Window
	{
	public:
		Window();
		int start();
	private:
		int init();
		int close();
		ScenarioWindow& m_window;
	};
}

#endif