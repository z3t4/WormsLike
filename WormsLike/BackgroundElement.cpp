#include "BackgroundElement.h"
#include <string>

namespace GameLogic
{
	BackgroundElement::BackgroundElement(BackgroundElement::Type type, int x, int y,
		int sizeX, int sizeY, const std::string& imagePath)
	{
		this->type = type;
		this->imagePath = imagePath;
		this->position.x = x;
		this->position.y = y;
		this->position.w = sizeX;
		this->position.h = sizeY;
		this->renderer = renderer;
	}

	BackgroundElement::~BackgroundElement()
	{
		if (texture) SDL_DestroyTexture(texture);
	}

	void BackgroundElement::initDrawableElements(SDL_Renderer* renderer)
	{
		SDL_Surface* loadingSurf = SDL_LoadBMP(imagePath.c_str());
		if (!loadingSurf) throw std::exception("Bad image : Surface not loaded");
		texture = SDL_CreateTextureFromSurface(renderer, loadingSurf);
		if (!texture) throw std::exception("Bad surface : Texture not loaded");
		SDL_FreeSurface(loadingSurf);
	}

	void BackgroundElement::draw(SDL_Renderer* renderer)
	{
		SDL_RenderCopy(renderer, texture, NULL, &position);
	}
}
