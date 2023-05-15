#include "Player.h"

void Player::initialise()
{
	m_position = { SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
	m_body.setFillColor(sf::Color::Green);
	m_body.setSize(sf::Vector2f{ 50.0f,70.0f });
	m_body.setOrigin(25.0f, 35.0f);
	m_body.setPosition(m_position);

	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\player.png"))
	{
		std::cout << "problem with loading player image" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setTextureRect(sf::IntRect(0, 0, 50, 64));
	m_playerSprite.setOrigin(25.0f, 35.0f);
	m_playerSprite.setPosition(m_position);
}

void Player::update(sf::Time t_deltaTime)
{
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerSprite);
}

void Player::processEvents(sf::Event t_event)
{
}

void Player::moveUP()
{
	m_position.y -= m_speed;
	m_body.setPosition(m_position);
	m_playerSprite.setPosition(m_position);
}

void Player::moveDown()
{
	m_position.y += m_speed;
	m_body.setPosition(m_position);
	m_playerSprite.setPosition(m_position);
}

void Player::moveLeft()
{
	m_position.x -= m_speed;
	m_body.setPosition(m_position);
	m_playerSprite.setPosition(m_position);
}

void Player::moveRight()
{
	m_position.x += m_speed;
	m_body.setPosition(m_position);
	m_playerSprite.setPosition(m_position);
}

sf::Vector2f Player::getPosition()
{
	return m_position;
}

sf::RectangleShape Player::getBody()
{
	return m_body;
}

void Player::adjustPosition(sf::Vector2f t_vector)
{
	m_position += t_vector;
	m_body.setPosition(m_position);
	m_playerSprite.setPosition(m_position);
}

void Player::setPosition(sf::Vector2f t_position)
{
	m_position = t_position;
	m_body.setPosition(m_position);
	m_playerSprite.setPosition(m_position);
}
