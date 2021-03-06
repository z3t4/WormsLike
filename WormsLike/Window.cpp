#include "Window.h"

#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <iostream>

#include "MenuWindow.h"
//#include "MapLoader.h"
//#include "Map.h"
#include "TestHero.h"

#include "DrawTestMap.h"

namespace Engine
{
	const Uint32 fps = 40;
	const Uint32 minframetime = 1000 / fps;
	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;

	//Window::Window() : window(new GameLogic::TestHero())
	Window::Window() : window(new GameLogic::DrawTestMap())
	{
		
	}

	Window::~Window()
	{
		if (window) delete window;
		if (mainRenderer) SDL_DestroyRenderer(mainRenderer);
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
			//EventPoll loop
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			 	window->onEvent(e);
			}
			window->draw(mainRenderer);
		}
		this->close();
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

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				status = 1;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}

			mainRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			//window->setWindowSettings(gWindow, mainRenderer);
			window->initDrawableElements(mainRenderer);
			
		}

		return status;
	}

	int Window::close()
	{
		//Destroy window
		SDL_DestroyRenderer(mainRenderer);
		mainRenderer = NULL;
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;

		//Quit SDL subsystems
		SDL_Quit();
		return 0;
	}
}

