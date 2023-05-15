#include "Splash.h"
#include "Game.h"

void Splash::initialise(sf::Font t_font)
{
	m_font = t_font;
	m_gameName.setFont(m_font);
	m_gameName.setFillColor(sf::Color::White);
	m_gameName.setCharacterSize(70U);
	m_gameName.setString("CHRONOS");
	m_gameName.setOrigin(m_gameName.getGlobalBounds().width / 2.0f, m_gameName.getGlobalBounds().height / 2.0f);
	m_gameName.setPosition(SCREEN_WIDTH / 2.0f, 100);

	//setup splash screen sprite
	if (!m_splashTexture.loadFromFile("ASSETS/IMAGES/splash.png"))
	{
		std::cout << "error with splash screen file";
	}
	m_splashSprite.setTexture(m_splashTexture);
	m_splashSprite.setScale(SCREEN_WIDTH/ 1200.0, SCREEN_HEIGHT / 1000.0);
}

void Splash::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_splashSprite);
	t_window.draw(m_gameName);
}

void Splash::update(sf::Time t_deltaTime)
{
	m_artTime += t_deltaTime;
	if (m_artTime.asSeconds() > 2.0f)
	{
		Game::s_currentMode = GameMode::Menu;
	}
}
