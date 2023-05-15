#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"

class Splash
{
public:
	void initialise(sf::Font t_font);
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);

private:
	sf::Time m_artTime; //timer for the splashscreen
	sf::Text m_gameName;
	sf::Font m_font; 
	sf::Texture m_splashTexture; //splash screen texture
	sf::Sprite m_splashSprite; //sprite for splash screen
};
