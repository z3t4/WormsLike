#include "BackgroundElement.h"
#include <string>
#include "RessourceLoader.h"

namespace GameLogic
{
	BackgroundElement::BackgroundElement(BackgroundElement::Type type, int x, int y,
		int sizeX, int sizeY, const std::string& textureName)
	{
		this->type = type;
		this->textureName = textureName;
		this->position.x = x;
		this->position.y = y;
		this->position.w = sizeX;
		this->position.h = sizeY;
	}

	BackgroundElement::~BackgroundElement()
	{
		if (texture) SDL_DestroyTexture(texture);
	}

	void BackgroundElement::initDrawableElements(SDL_Renderer* renderer)
	{
		texture = Engine::RessourceLoader::loadTexture(textureName, renderer);
	}

	void BackgroundElement::draw(SDL_Renderer* renderer)
	{
		SDL_RenderCopy(renderer, texture, NULL, &position);
		SDL_RenderDrawRect(renderer, &position);
	}
}
