#ifndef _MAP_H
#define _MAP_H

#include <vector>
#include <string>
#include <SDL.h>

#include "Drawable.h"
#include "BackgroundElement.h"

/*    TODO
 *		- CameraPosition (vector x y )
 *		
 */

namespace GameLogic
{
	class Map : public Engine::Drawable
	{
	public:
		Map(const std::string& name, const std::string& backgroundPath, const std::vector<BackgroundElement*>& elements);
		~Map();
		inline std::string getName() const { return name; }
		virtual void initDrawableElements(SDL_Renderer* renderer);
		virtual void draw(SDL_Renderer* renderer);
	private:
		std::string name;
		std::string backgroundPath;
		std::vector<BackgroundElement*> elements;
		SDL_Texture* textureMap;
	};
}

#endif