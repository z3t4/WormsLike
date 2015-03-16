#include "DrawTestMap.h"
#include "MapLoader.h"

#include <iostream>

namespace GameLogic
{
	DrawTestMap::DrawTestMap() :
		map(GameLogic::MapLoader::loadMap("C:\\Users\\jérome\\Documents\\git\\WormsLike\\WormsLike\\Maps\\TestMap.xml")),
		hero(Hero::Hero(200, 200))
	{

	}
	
	void DrawTestMap::initDrawableElements(SDL_Renderer* renderer)
	{
		map.initDrawableElements(renderer);
		hero.initDrawableElements(renderer);
	}

	void DrawTestMap::draw(SDL_Renderer* renderer)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		map.draw(renderer);
		hero.draw(renderer);
		SDL_RenderPresent(renderer);	
	}

	void DrawTestMap::onEvent(const SDL_Event& e)
	{
		hero.onEvent(e);
	}
} 