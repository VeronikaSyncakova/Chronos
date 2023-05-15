#include "Instructions.h"
#include "Game.h"

void Instructions::initialise(sf::Font t_font)
{
	m_font = t_font;
	m_text.setFont(m_font);
	m_text.setCharacterSize(40U);
	m_text.setFillColor(sf::Color::White);
	m_text.setString("INSTRUCTIONS");
	m_text.setOrigin(m_text.getGlobalBounds().width / 2.0f, m_text.getGlobalBounds().height / 2.0f);
	m_text.setPosition(SCREEN_WIDTH / 2.0f, 80.0f);

	m_button.setSize(sf::Vector2f{ 60.0f,40.0f });
	m_button.setOrigin(30.0f, 20.0f);
	m_button.setFillColor(sf::Color::Red);
	m_button.setPosition(720.0f, 60.0f);

	if (!m_menuTexture.loadFromFile("ASSETS\\IMAGES\\menu.png"))
	{
		std::cout << "problem with loading menu image" << std::endl;
	}

	m_menuButton.setTexture(m_menuTexture);
	m_menuButton.setOrigin(30.0f, 20.0f);
	m_menuButton.setPosition(720.0f, 60.0f);
}

void Instructions::update(sf::Time t_deltaTime)
{
}

void Instructions::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
	t_window.draw(m_menuButton);
}

void Instructions::processEvents(sf::Event t_event)
{
	sf::Vector2f mouse;
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		mouse.x = t_event.mouseButton.x;
		mouse.y = t_event.mouseButton.y;

		if (m_button.getGlobalBounds().contains(mouse))
		{ //plays the game
			Game::s_currentMode = GameMode::Menu;
		}
	}
}
