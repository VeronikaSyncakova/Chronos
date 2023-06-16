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

	m_instructionsText.setFont(m_font);
	m_instructionsText.setCharacterSize(32U);
	m_instructionsText.setFillColor(sf::Color::White);
	m_instructionsText.setString("Your mission is to kill Kittler.\nYou have to unlock all portals by solving the puzzles.\nOnce you found him, you have to solve the final\npuzzle to kill him.\nA,S,W,D or arrows for movement\ninteract with npc's when they need your help!");
	m_instructionsText.setPosition(20.0f, 140.0f);

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
	t_window.draw(m_instructionsText);
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
			m_menuButton.setColor(sf::Color::White);
			m_menuButton.setScale({ 1.0f,1.0f });
		}
	}
	if (sf::Event::MouseMoved == t_event.type)
	{
		mouse.x = t_event.mouseMove.x;
		mouse.y = t_event.mouseMove.y;
		if (m_menuButton.getGlobalBounds().contains(mouse))
		{
			m_menuButton.setColor({ 155u,155u,155u,255u });
			m_menuButton.setScale({ 1.5f, 1.5f });
		}
		else
		{
			m_menuButton.setColor(sf::Color::White);
			m_menuButton.setScale({ 1.0f,1.0f });
		}
	}
}
