#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include<iostream>

class Player
{
public:
	void initialise();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);

	void moveUP(); //moves player ut
	void moveDown(); //moves player down
	void moveLeft(); //moves player to the left
	void moveRight(); //moves player to the right

	sf::Vector2f getPosition();
	sf::RectangleShape getBody();
	void adjustPosition(sf::Vector2f t_vector); //can reposition player with certain vector
	void setPosition(sf::Vector2f t_position);

private:
	sf::RectangleShape m_body;
	sf::Vector2f m_position; //position of player
	float m_speed = 4.0f; //speed of the player movement

	sf::Texture m_playerTexture; //player spritesheet
	sf::Sprite m_playerSprite; //player sprite

};