#include "Present.h"
#include "Game.h"


void Present::initialise(sf::Font t_font)
{
	m_font = t_font;

	m_button.setSize(sf::Vector2f{ 60.0f,40.0f });
	m_button.setOrigin(30.0f, 20.0f);
	m_button.setFillColor(sf::Color::Red);
	m_button.setPosition(720.0f, 60.0f);

	m_leftTop.setSize(sf::Vector2f{ 525.0f,425.0f });
	m_leftTop.setOrigin(200.0f, 200.0f);
	m_leftTop.setFillColor(sf::Color::White);
	m_leftTop.setPosition(0.0f, 0.0f);

	m_rightTop.setSize(sf::Vector2f{ 525.0f,425.0f });
	m_rightTop.setOrigin(325.0f, 200.0f);
	m_rightTop.setFillColor(sf::Color::White);
	m_rightTop.setPosition(SCREEN_WIDTH,0.0f);

	m_leftBottom.setSize(sf::Vector2f{ 525.0f,425.0f });
	m_leftBottom.setOrigin(200.0f, 225.0f);
	m_leftBottom.setFillColor(sf::Color::White);
	m_leftBottom.setPosition(0.0f, SCREEN_HEIGHT);

	m_rightBottom.setSize(sf::Vector2f{ 525.0f,425.0f });
	m_rightBottom.setOrigin(325.0f, 225.0f);
	m_rightBottom.setFillColor(sf::Color::White);
	m_rightBottom.setPosition(SCREEN_WIDTH, SCREEN_HEIGHT);

	m_player.initialise();

	for (int i = 0; i < MAX_PORTALS; i++)
	{
		m_portals[i].initialise(i);
	}

	//setup background screen sprite
	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/movingScreen.png"))
	{
		std::cout << "error with present background screen file";
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(-200,-200);

	if (!m_menuTexture.loadFromFile("ASSETS\\IMAGES\\menu.png"))
	{
		std::cout << "problem with loading menu image" << std::endl;
	}
	m_menuButton.setTexture(m_menuTexture);
	m_menuButton.setOrigin(30.0f, 20.0f);
	m_menuButton.setPosition(720.0f, 60.0f);

}

void Present::update(sf::Time t_deltaTime)
{
	backgroundCollision();
	portalCollision();

	if (e_doorLocked == 1)
	{ //if user unlocked the door
		for (int i = 0; i < MAX_PORTALS; i++)
		{
			if (m_portals[i].getDoorLocked())
			{ //unlocks the next portals door
				m_portals[i].unlockDoors();
				e_doorLocked = 0;
				break;
			}
		}
	}
}

void Present::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);

	m_player.render(t_window);

	for (int i = 0; i < MAX_PORTALS; i++)
	{
		m_portals[i].render(t_window);
	}
	t_window.draw(m_menuButton);
}

void Present::processEvents(sf::Event t_event)
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

	if (sf::Event::KeyPressed == t_event.type)
	{
		if (sf::Keyboard::Up == t_event.key.code)
		{
			if (m_canMove)
			{
				moveUp();
			}
			else
			{
				m_canMove = true;
			}
		}
		if (sf::Keyboard::Down == t_event.key.code)
		{
			if (m_canMove)
			{
			moveDown();
			}
			else
			{
				m_canMove = true;
			}
		}
		if (sf::Keyboard::Left == t_event.key.code)
		{
			if (m_canMove)
			{
			moveLeft();
			}
			else
			{
				m_canMove = true;
			}
		}
		if (sf::Keyboard::Right == t_event.key.code)
		{
			if (m_canMove)
			{
			moveRight();
			}
			else
			{
				m_canMove = true;
			}
		}

		if (sf::Keyboard::W == t_event.key.code)
		{
			if (m_canMove)
			{
			moveUp();
			}
			else
			{
				m_canMove = true;
			}
		}
		if (sf::Keyboard::S == t_event.key.code)
		{
			if (m_canMove)
			{
			moveDown();
			}
			else
			{
				m_canMove = true;
			}
		}
		if (sf::Keyboard::A == t_event.key.code)
		{
			if (m_canMove)
			{
			moveLeft();
			}
			else
			{
				m_canMove = true;
			}
		}
		if (sf::Keyboard::D == t_event.key.code)
		{
			if (m_canMove)
			{
			moveRight();
			}
			else
			{
				m_canMove = true;
			}
		}
	}
	
}

void Present::moveUp()
{
	m_movement = { 0,2 };
	if (m_leftTop.getPosition().y < 200)
	{
		m_leftTop.setPosition(m_leftTop.getPosition() + m_movement);
		m_leftBottom.setPosition(m_leftBottom.getPosition() + m_movement);
		m_rightTop.setPosition(m_rightTop.getPosition() + m_movement);
		m_rightBottom.setPosition(m_rightBottom.getPosition() + m_movement);
		m_backgroundSprite.setPosition(m_backgroundSprite.getPosition() + m_movement);

		for (int i = 0; i < MAX_PORTALS; i++)
		{
			m_portals[i].changePosition(m_movement);
		}
	}
	else
	{
		m_player.moveUP();
	}

}

void Present::moveDown()
{
	m_movement = { 0,-2 };
	if (m_leftBottom.getPosition().y > 400)
	{
		m_leftTop.setPosition(m_leftTop.getPosition() + m_movement);
		m_leftBottom.setPosition(m_leftBottom.getPosition() + m_movement);
		m_rightTop.setPosition(m_rightTop.getPosition() + m_movement);
		m_rightBottom.setPosition(m_rightBottom.getPosition() + m_movement);
		m_backgroundSprite.setPosition(m_backgroundSprite.getPosition() + m_movement);

		for (int i = 0; i < MAX_PORTALS; i++)
		{
			m_portals[i].changePosition(m_movement);
		}
	}
	else
	{
		m_player.moveDown();
	}
}

void Present::moveRight()
{
	m_movement = { -2,0 };
	if (m_rightBottom.getPosition().x > 600)
	{
		m_leftTop.setPosition(m_leftTop.getPosition() + m_movement);
		m_leftBottom.setPosition(m_leftBottom.getPosition() + m_movement);
		m_rightTop.setPosition(m_rightTop.getPosition() + m_movement);
		m_rightBottom.setPosition(m_rightBottom.getPosition() + m_movement);
		m_backgroundSprite.setPosition(m_backgroundSprite.getPosition() + m_movement);

		for (int i = 0; i < MAX_PORTALS; i++)
		{
			m_portals[i].changePosition(m_movement);
		}
	}
	else
	{
		m_player.moveRight();
	}
}

void Present::portalCollision()
{
	for (int i = 0; i < MAX_PORTALS; i++)
	{
		if (m_portals[i].getDoorBody().getGlobalBounds().intersects(m_player.getBody().getGlobalBounds())&&m_portals[i].getDoorLocked())
		{ //if doors are locked and player cant get to the portal
			m_canMove = false;
			if (i == TOP)
			{
				m_player.adjustPosition({ 0.0f,1.0f });
			}
			else if (i == BOTTOM)
			{
				m_player.adjustPosition({ 0.0f,-1.0f });
			}
			else if (i == LEFT)
			{
				m_player.adjustPosition({ 1.0f,0.0f });
			}
			else if (i == RIGHT)
			{
				m_player.adjustPosition({ -1.0f,0.0f });
			}
		}
		else if (m_portals[i].getBody().getGlobalBounds().intersects(m_player.getBody().getGlobalBounds()))
		{//doors are unlocked and player goes thru portal
			if (m_portals[i].getSide() == LEFT)
			{
				Game::s_currentMode = GameMode::PuzzleOne;
				m_player.adjustPosition({ 50.0f,0.0f });
			}
			else if (m_portals[i].getSide() == RIGHT)
			{
				Game::s_currentMode = GameMode::PuzzleTwo;
				m_player.adjustPosition({ -50.0f,0.0f });
			}
			else if (m_portals[i].getSide() == TOP)
			{
				Game::s_currentMode = GameMode::PuzzleThree;
				m_player.adjustPosition({ 0.0f,70.0f });
			}
			else if (m_portals[i].getSide() == BOTTOM)
			{
				Game::s_currentMode = GameMode::FinalPuzzle;
				m_player.adjustPosition({ 0.0f,-70.0f });
			}
			e_portalUsed = 0;
		}
	}
}

void Present::backgroundCollision()
{
	if (m_leftTop.getGlobalBounds().intersects(m_player.getBody().getGlobalBounds()))
	{
		m_canMove = false;
		float rightBoundary = m_leftTop.getGlobalBounds().left+525.0f;
		float bottomBoundary = m_leftTop.getGlobalBounds().top + 425.0f;
		if (m_player.getPosition().x > rightBoundary)
		{
			m_player.adjustPosition({ 1.0f,0.0f });
		}
		else if (m_player.getPosition().y > bottomBoundary)
		{
			m_player.adjustPosition({ 0.0f,1.0f });
		}
		
	}
	else if (m_leftBottom.getGlobalBounds().intersects(m_player.getBody().getGlobalBounds()))
	{
		m_canMove = false;
		float rightBoundary = m_leftBottom.getGlobalBounds().left + 525.0f;
		float topBoundary = m_leftBottom.getGlobalBounds().top ;
		if (m_player.getPosition().x > rightBoundary)
		{
			m_player.adjustPosition({ 1.0f,0.0f });
		}
		else if (m_player.getPosition().y < topBoundary)
		{
			m_player.adjustPosition({ 0.0f,-1.0f });
		}
	}
	else if (m_rightTop.getGlobalBounds().intersects(m_player.getBody().getGlobalBounds()))
	{
		m_canMove = false;
		float leftBoundary = m_rightTop.getGlobalBounds().left ;
		float bottomBoundary = m_rightTop.getGlobalBounds().top + 425.0f;
		if (m_player.getPosition().x < leftBoundary)
		{
			m_player.adjustPosition({ -1.0f,0.0f });
		}
		else if (m_player.getPosition().y > bottomBoundary)
		{
			m_player.adjustPosition({ 0.0f,1.0f });
		}
	}
	else if (m_rightBottom.getGlobalBounds().intersects(m_player.getBody().getGlobalBounds()))
	{
		m_canMove = false;
		float leftBoundary = m_rightBottom.getGlobalBounds().left;
		float topBoundary = m_rightBottom.getGlobalBounds().top ;
		if (m_player.getPosition().x < leftBoundary)
		{
			m_player.adjustPosition({ -1.0f,0.0f });
		}
		else if (m_player.getPosition().y < topBoundary)
		{
			m_player.adjustPosition({ 0.0f,-1.0f });
		}
	}
}

void Present::moveLeft()
{
	m_movement = { 2,0 };
	if (m_leftBottom.getPosition().x < 200)
	{
		m_leftTop.setPosition(m_leftTop.getPosition() + m_movement);
		m_leftBottom.setPosition(m_leftBottom.getPosition() + m_movement);
		m_rightTop.setPosition(m_rightTop.getPosition() + m_movement);
		m_rightBottom.setPosition(m_rightBottom.getPosition() + m_movement);
		m_backgroundSprite.setPosition(m_backgroundSprite.getPosition() + m_movement);

		for (int i = 0; i < MAX_PORTALS; i++)
		{
			m_portals[i].changePosition(m_movement);
		}
	}
	else
	{
		m_player.moveLeft();
	}
}
