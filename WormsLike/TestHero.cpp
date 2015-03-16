#include "TestHero.h"

namespace GameLogic
{

	TestHero::TestHero() :
		m_hero(Hero::Hero(200, 200))
	{
	}

	void TestHero::initDrawableElements(SDL_Renderer* renderer)
	{
		m_hero.initDrawableElements(renderer);
	}

	void TestHero::draw(SDL_Renderer* renderer)
	{
		m_hero.draw(renderer);
	}

	void TestHero::onEvent(const SDL_Event &e)
	{

		if (e.type == SDL_KEYDOWN)
		{
			m_hero.onEvent(e);
		}
	}
}