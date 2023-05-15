#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"

class Instructions
{
public:
	void initialise(sf::Font t_font);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);

private:
	sf::Font m_font;
	sf::Text m_text;
	sf::RectangleShape m_button;
	sf::Texture m_menuTexture; //texture for menu button
	sf::Sprite m_menuButton; //menu button sprite

};
