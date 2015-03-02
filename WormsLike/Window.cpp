#include "Window.h"

#include <SDL.h>

#include <cstdlib>
#include <iostream>

#include "MenuWindow.h"

namespace Engine
{
	const Uint32 fps = 40;
	const Uint32 minframetime = 1000 / fps;
	SDL_Window* gWindow = NULL;

	Window::Window() : m_window(MenuWindow())
	{

	}

	int Window::start()
	{
		// Init vars
		bool quit = false;
		SDL_Event e;

		init();

		// Main loop
		while (!quit)
		{

			//Create window 
			//EventPoll loop
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				m_window.onEvent(e);
			}

		}
		return 0;
	}

	int Window::init()
	{
		int status = 0;

		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			status = 1;
		}
		else
		{
			//Create window
			gWindow = SDL_CreateWindow("WormsLike", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
			if (gWindow == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
				status = 1;
			}
		}

		return status;
	}

	int Window::close()
	{
		//Destroy window
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;

		//Quit SDL subsystems
		SDL_Quit();
		return 0;
	}
}

