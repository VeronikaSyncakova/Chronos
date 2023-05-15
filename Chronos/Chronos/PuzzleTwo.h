#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Player.h"
#include"Portal.h"

class PuzzleTwo
{
public:
	void initialise(sf::Font t_font);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);

	void portalCollision();
	void npcInteraction();
	void checkCorrectCode();

private:
	sf::RectangleShape m_npc;
	Player m_player;
	Portal m_portal;
	sf::Text m_npcMessage; // help message from npc
	sf::Font m_font;
	bool m_npcCanClick = false; //if player is within certain radius he can interact with npc
	bool m_drawPuzzle = false; //if the puzzle can be drawn

	sf::Text m_mathRiddle; //text of the puzzle
	sf::RectangleShape m_numberBox[2]; //number boxes
	sf::RectangleShape m_plus[2]; //plus for adding numbers
	sf::RectangleShape m_minus[2]; //minus for decreasing numbers
	sf::Text m_numbers[2]; //string numbers in a box
	int m_intigers[2]; //numbers in a box

	sf::Texture m_npcTexture; //setup npc ssprite
	sf::Sprite m_npcSprite;
	sf::Texture m_backgroundTexture; //setup background sprite
	sf::Sprite m_backgroundSprite;
	sf::Texture m_minusTexture;
	sf::Texture m_plusTexture;
	sf::Sprite m_plusSprite[2];
	sf::Sprite m_minusSprite[2];
};