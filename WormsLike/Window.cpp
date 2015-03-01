#include "Window.h"

#include <SDL.h>

#include <cstdlib>
#include <iostream>

namespace Engine
{
	const Uint32 fps = 40;
    const Uint32 minframetime = 1000 / fps;
	
	Window::Window()
	{

	}

	int Window::start()
	{
		if (SDL_Init (SDL_INIT_VIDEO) != 0)
		{
			std::cout << "Error initializing SDL: " << SDL_GetError () << std::endl;
			return 1;
		}
		SDL_Quit();
		return 0;
	}
}