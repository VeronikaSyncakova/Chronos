#include "Portal.h"
#include "Game.h"

void Portal::initialise(int t_i)
{
	m_body.setSize(sf::Vector2f{ 50.0f,70.0f });
	m_body.setFillColor(sf::Color::Blue);
	m_body.setOrigin(25.0f, 35.0f);

	m_door.setSize({ 20.0f,100.0f });
	m_door.setFillColor(sf::Color::Cyan);
	m_door.setOrigin(10.0f, 50.0f);

	//setup portal screen sprite
	if (!m_portalTexture.loadFromFile("ASSETS/IMAGES/portal.png"))
	{
		std::cout << "error with portal file";
	}
	m_portalSprite.setTexture(m_portalTexture);
	m_portalSprite.setOrigin(25.0f, 35.0f);

	m_side = t_i;
	if (m_side == TOP)
	{
		m_door.setSize({ 150.0f,20.0f });
		m_door.setOrigin(75.0f, 10.0f);
		m_position = sf::Vector2f{ SCREEN_WIDTH / 2.0f,-130.0f };
		m_doorPosition = { SCREEN_WIDTH / 2.0f, -70.0f };
		m_doorLocked = true; //should be true

	}
	else if (m_side == BOTTOM)
	{
		m_door.setSize({ 150.0f,20.0f });
		m_door.setOrigin(75.0f, 10.0f);
		m_position = sf::Vector2f{ SCREEN_WIDTH / 2.0f,730.0f };
		m_doorPosition = { SCREEN_WIDTH / 2.0f, 670.0f };
		m_doorLocked = true; //should be true, this is just for testing

	}
	else if (m_side == LEFT)

	{
		m_door.setSize({ 20.0f,150.0f });
		m_door.setOrigin(10.0f, 75.0f);
		m_position = sf::Vector2f{ -150.0f,SCREEN_HEIGHT/2.0f };
		m_doorPosition = { -100.0f, SCREEN_HEIGHT / 2.0f };
		m_doorLocked = false;

	}
	else if (m_side == RIGHT)

	{
		m_door.setSize({ 20.0f,150.0f });
		m_door.setOrigin(10.0f, 75.0f);
		m_position = sf::Vector2f{ 950.0f,SCREEN_HEIGHT / 2.0f };
		m_doorPosition = { 900.0f, SCREEN_HEIGHT / 2.0f };
		m_doorLocked = true; //should be true

	}

	m_body.setPosition(m_position);
	m_door.setPosition(m_doorPosition);
	m_portalSprite.setPosition(m_position);
}

void Portal::update(sf::Time t_deltaTime)
{
}

void Portal::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_portalSprite);
	if (m_doorLocked)
	{
		t_window.draw(m_door);
	}
}

void Portal::processEvents(sf::Event t_event)
{
}

sf::RectangleShape Portal::getBody()
{
	return m_body;
}

void Portal::changePosition(sf::Vector2f t_movement)
{
	m_position += t_movement;
	m_body.setPosition(m_position);
	m_doorPosition += t_movement;
	m_door.setPosition(m_doorPosition);
	m_portalSprite.setPosition(m_position);
}

sf::Vector2f Portal::getPosition()
{
	return m_position;
}

sf::RectangleShape Portal::getDoorBody()
{
	return m_door;
}

bool Portal::getDoorLocked()
{
	return m_doorLocked;
}

int Portal::getSide()
{
	return m_side;
}

void Portal::unlockDoors()
{
	m_doorLocked = false;
}

void Portal::setPosition(sf::Vector2f t_position)
{
	m_position = t_position;
	m_body.setPosition(m_position);
	m_portalSprite.setPosition(m_position);
}
