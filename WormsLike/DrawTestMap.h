#ifndef _DRAWTESTMAP_H
#define _DRAWTESTMAP_H

#include "Map.h"
#include "ScenarioWindow.h"

namespace GameLogic
{
	class DrawTestMap : public Engine::ScenarioWindow
	{
	public:
		DrawTestMap();
		virtual void onEvent(const SDL_Event& e);
		virtual void initDrawableElements(SDL_Renderer* renderer);
		virtual void draw(SDL_Renderer* renderer);
	private:
		GameLogic::Map m_map;
	};
}
#endif