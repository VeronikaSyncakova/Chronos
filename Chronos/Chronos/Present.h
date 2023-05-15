#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Player.h"
#include"Portal.h"

class Present
{
public:
	void initialise(sf::Font t_font);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);
	void moveUp(); //moves the screen up
	void moveDown(); //moves the screen down
	void moveLeft(); //moves the screen to the left
	void moveRight(); //moves the screen to the right

	void portalCollision(); //collision check between portal,doors and player
	void backgroundCollision(); //collision check between background and player


private:
	sf::Font m_font;
	sf::Text m_text;
	sf::RectangleShape m_button; //return to menu button
	sf::RectangleShape m_leftTop;  //left top boundary
	sf::RectangleShape m_leftBottom; //left bottom boundary
	sf::RectangleShape m_rightTop; //right top boundar
	sf::RectangleShape m_rightBottom; //right bottom boundary
	sf::Vector2f m_movement; //movement for the background
	bool m_canMove; //if there is collision with boundary or not
	sf::Texture m_backgroundTexture; //setup background
	sf::Sprite m_backgroundSprite;

	Player m_player; //player
	Portal m_portals[MAX_PORTALS]; //portals array

	sf::Texture m_menuTexture; //menu button texture
	sf::Sprite m_menuButton; //menu button sprite

};
