#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"


class Portal
{
public:
	void initialise(int t_i);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);
	sf::RectangleShape getBody();
	void changePosition(sf::Vector2f t_movement); //moves portals and doors with screen
	sf::Vector2f getPosition();
	sf::RectangleShape getDoorBody();
	bool getDoorLocked();
	int getSide();
	void unlockDoors();
	void setPosition(sf::Vector2f t_position);

private:
	sf::RectangleShape m_body; //portal body
	sf::Vector2f m_position;
	int m_side; //which side of the screen is the portal on
	sf::RectangleShape m_door; //door body
	bool m_doorLocked; //if player can or can not pass thru
	sf::Vector2f m_doorPosition; //position of the door
	sf::Texture m_portalTexture; //setup portal sprite
	sf::Sprite m_portalSprite;
};
