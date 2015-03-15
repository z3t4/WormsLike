#include "TestHero.h"

namespace GameLogic
{

	TestHero::TestHero() :
		m_hero(Hero::Hero(200, 200))
	{
	}

	void TestHero::initDrawableElements()
	{
		m_hero.initDrawableElements();
	}

	void TestHero::draw()
	{
		m_hero.draw();
	}

	void TestHero::setWindowSettings(SDL_Window* window, SDL_Renderer* renderer)
	{
		m_hero.setHeroWindowSettings(window, renderer);
	}

	void TestHero::onEvent(const SDL_Event &e)
	{

		if (e.type == SDL_KEYDOWN)
		{
			m_hero.moveCharacter(e);
		}
	}
}