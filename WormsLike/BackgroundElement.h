#ifndef BACKGROUNDELEMENT_H
#define BACKGROUNDELEMENT_H

#include "Drawable.h"

#include <string>

namespace GameLogic
{

	class BackgroundElement : public Engine::Drawable
	{
	public:
		enum Type
		{
			Grabbable,
			UnGrabbable,
			Ennemy,
			Background
		};

		BackgroundElement(Type type, int x, int y, int sizeX, int sizeY, const std::string& textureName);
		~BackgroundElement();
		inline SDL_Rect getRect() const { return position; }
		inline Type getType() const { return type; }
		inline std::string getTextureName() const { return textureName; }
		virtual void initDrawableElements(SDL_Renderer* renderer);
		virtual void draw(SDL_Renderer* renderer);

	protected:
		SDL_Rect position;
		Type type;
		std::string textureName;
		SDL_Texture* texture;

	};

}

#endif