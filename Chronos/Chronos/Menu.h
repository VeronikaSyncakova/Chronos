#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"

class Menu
{
public:
	void initialise(sf::Font t_font);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);

private:
	sf::Text m_menuText;
	sf::Font m_font;
	//setup sprites needed for menu
	sf::Texture m_playTexture;
	sf::Sprite m_playSprite;
	sf::Texture m_insTexture;
	sf::Sprite m_insSprite;
	sf::Texture m_quitTexture;
	sf::Sprite m_quitSprite;
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
};