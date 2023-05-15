#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"

class End
{
public:
	void initialise(sf::Font t_font);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);
private:
	sf::Text m_endMessage; //thank you message
	sf::Font m_font; //font used
	sf::Texture m_endTexture; //end screen texture
	sf::Sprite m_endSprite; //sprite for end screen
	sf::Texture m_restartTexture; 
	sf::Sprite m_restart; //restart button
};