#include"Menu.h"
#include "Game.h"

void Menu::initialise(sf::Font t_font)
{
	m_font = t_font;
	m_menuText.setFont(m_font);
	m_menuText.setCharacterSize(40U);
	m_menuText.setFillColor(sf::Color::White);
	m_menuText.setString("MENU");
	m_menuText.setOrigin(m_menuText.getGlobalBounds().width / 2.0f, m_menuText.getGlobalBounds().height / 2.0f);
	m_menuText.setPosition(SCREEN_WIDTH / 2.0f, 100.0f);

	

	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/menuScreen.png"))
	{
		std::cout << "error with menu background file";
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);

	if (!m_playTexture.loadFromFile("ASSETS/IMAGES/play.png"))
	{
		std::cout << "error with play button file";
	}
	m_playSprite.setTexture(m_playTexture);
	m_playSprite.setOrigin(50.0f, 50.0f);
	m_playSprite.setPosition(200.0f, SCREEN_HEIGHT / 2.0f);

	if (!m_quitTexture.loadFromFile("ASSETS/IMAGES/quit.png"))
	{
		std::cout << "error with quit button file";
	}
	m_quitSprite.setTexture(m_quitTexture);
	m_quitSprite.setOrigin(50.0f, 50.0f);
	m_quitSprite.setPosition(400.0f, 500.0f);

	if (!m_insTexture.loadFromFile("ASSETS/IMAGES/instruction.png"))
	{
		std::cout << "error with instruction button file";
	}
	m_insSprite.setTexture(m_insTexture);
	m_insSprite.setOrigin(50.0f, 50.0f);
	m_insSprite.setPosition(600.0f, SCREEN_HEIGHT / 2.0f);
	
	
}

void Menu::update(sf::Time t_deltaTime)
{

}

void Menu::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_menuText);
	t_window.draw(m_playSprite);
	t_window.draw(m_quitSprite);
	t_window.draw(m_insSprite);
}

void Menu::processEvents(sf::Event t_event)
{
	sf::Vector2f mouse;
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		mouse.x = t_event.mouseButton.x;
		mouse.y = t_event.mouseButton.y;

		if (m_playSprite.getGlobalBounds().contains(mouse))
		{ //plays the game
			Game::s_currentMode = GameMode::Present;
			m_playSprite.setColor(sf::Color::White);
			m_playSprite.setScale({ 1.0f, 1.0f });
		}
		else if (m_insSprite.getGlobalBounds().contains(mouse))
		{ //displays instructions
			Game::s_currentMode = GameMode::Instructions;
			m_insSprite.setColor(sf::Color::White);
			m_insSprite.setScale({ 1.0f,1.0f });
		}
		else if (m_quitSprite.getGlobalBounds().contains(mouse))
		{
			Game::s_exitGame = true;
		}
	}
	
	if (sf::Event::MouseMoved == t_event.type)
	{
		mouse.x = t_event.mouseMove.x;
		mouse.y = t_event.mouseMove.y;
		if (m_playSprite.getGlobalBounds().contains(mouse))
		{
			m_playSprite.setColor({ 155u,155u,155u,255u });
			m_playSprite.setScale({ 1.5f, 1.5f });
		}
		else if (m_insSprite.getGlobalBounds().contains(mouse))
		{
			m_insSprite.setColor({ 155u,155u,155u,255u });
			m_insSprite.setScale({ 1.5f,1.5f });
		}
		else if (m_quitSprite.getGlobalBounds().contains(mouse))
		{
			m_quitSprite.setColor({ 155u,155u,155u,255u });
			m_quitSprite.setScale({ 1.5f,1.5f });
		}
		else
		{
			m_playSprite.setColor(sf::Color::White);
			m_insSprite.setColor(sf::Color::White);
			m_quitSprite.setColor(sf::Color::White);
			m_playSprite.setScale({ 1.0f, 1.0f });
			m_insSprite.setScale({ 1.0f,1.0f });
			m_quitSprite.setScale({ 1.0f,1.0f });
		}
	}
}
