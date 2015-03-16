#ifndef _TESTHERO_H
#define _TESTHERO_H

#include "Hero.h"
#include "ScenarioWindow.h"

namespace GameLogic
{
	class TestHero : public Engine::ScenarioWindow
	{
	public:
		TestHero();
		virtual void onEvent(const SDL_Event& e);
		virtual void initDrawableElements(SDL_Renderer* renderer);
		virtual void draw(SDL_Renderer* renderer);
	
	private:
		GameLogic::Hero m_hero;
	};
}
#endif