#ifndef _WINDOW_H
#define _WINDOW_H

#include "ScenarioWindow.h"

/*
 *	TODO:
 *		-Exception à la place de init
 */

namespace Engine 
{
	class Window
	{
	public:
		Window();
		~Window();
		int start();
	private:
		int init();
		int close();
		ScenarioWindow* window;
		SDL_Renderer* mainRenderer;
	};
}

#endif