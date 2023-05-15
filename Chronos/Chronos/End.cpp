#include "End.h"
#include "Game.h"

void End::initialise(sf::Font t_font)
{
	//setup text 
	m_font = t_font;
	m_endMessage.setFont(m_font);
	m_endMessage.setFillColor(sf::Color::White);
	m_endMessage.setOutlineColor(sf::Color::Black);
	m_endMessage.setOutlineThickness(2.1f);
	m_endMessage.setCharacterSize(60U);
	m_endMessage.setString("THE END");
	m_endMessage.setOrigin(m_endMessage.getGlobalBounds().width / 2.0f, m_endMessage.getGlobalBounds().height / 2.0f);
	m_endMessage.setPosition(SCREEN_WIDTH / 2.0f, 100);

	//setup end screen sprite
	if (!m_endTexture.loadFromFile("ASSETS/IMAGES/end.png"))
	{
		std::cout << "error with end screen file";
	}
	m_endSprite.setTexture(m_endTexture);

	if (!m_restartTexture.loadFromFile("ASSETS/IMAGES/menu.png"))
	{
		std::cout << "error with menu button file";
	}
	m_restart.setTexture(m_restartTexture);
	m_restart.setScale({ 2.0f,2.0f });
	m_restart.setPosition({ 600.0f,500.0f });
}

void End::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_endSprite);
	t_window.draw(m_endMessage);
	t_window.draw(m_restart);

}

void End::processEvents(sf::Event t_event)
{
	sf::Vector2f mouse;
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		mouse.x = t_event.mouseButton.x;
		mouse.y = t_event.mouseButton.y;

		if (m_restart.getGlobalBounds().contains(mouse))
		{ //plays the game
			Game::s_currentMode = GameMode::Menu;
			Game::s_restart = true;
		}
	}
}
