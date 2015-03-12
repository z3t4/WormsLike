#include "Map.h"

namespace GameLogic
{
	Map::Map(const std::string& name, const std::string& backgroundPath, const std::vector<BackgroundElement*>& elements)
	{
		this->name = name;
		this->backgroundPath = backgroundPath;
		this->elements = elements;
	}

	Map::~Map()
	{
		for (BackgroundElement* element : this->elements)
		{
			delete element;
		}
	}

	void Map::initDrawableElements(SDL_Renderer* renderer)
	{
		for (BackgroundElement* element : this->elements)
		{
			element->initDrawableElements(renderer);
		}
	}

	void Map::draw(SDL_Renderer* renderer)
	{
		for (BackgroundElement* element : this->elements)
		{
			element->draw(renderer);
		}
	}
}