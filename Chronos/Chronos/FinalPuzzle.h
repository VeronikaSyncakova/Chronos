#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Player.h"
#include"Portal.h"
#include<iostream>

class FinalPuzzle
{
public:
	void initialise(sf::Font t_font);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);

	void portalCollision();
	void npcInteraction();
	bool checkCorrectCode();
	char decryptLetter(char t_letter);
	void checkCorrectString(std::string t_string);

private:
	sf::RectangleShape m_npc; 
	Player m_player;
	Portal m_portal;
	sf::Text m_npcMessage; // help message from npc
	sf::Font m_font;
	bool m_npcCanClick = false; //if player is within certain radius he can interact with npc
	bool m_drawPuzzle = false; //if the puzzle can be drawn

	sf::Text m_encryptedMessage; //the coded message
	sf::Text m_decryptedMessage; //message that would be decrypted

	sf::RectangleShape m_numberBox[6]; //number boxes
	sf::RectangleShape m_plus[6]; //plus for adding numbers
	sf::RectangleShape m_minus[6]; //minus for decreasing numbers
	sf::Text m_numbers[6]; //string numbers in a box
	int m_intigers[6]; //numbers in a box
	sf::RectangleShape m_answear; //box for users decrypted code
	bool m_writing = false; //if writing or not

	bool m_correctMessage = false; //if user inputed correct code
	std::string m_decryptedString = "";

	sf::Texture m_npcTexture; //texture for npc
	sf::Sprite m_npcSprite; //sprite for npc
	sf::Texture m_npcDeadTexture;
	sf::Sprite m_npcDeadSprite; 

	sf::Texture m_backgroundTexture; //setup background sprite
	sf::Sprite m_backgroundSprite;

	sf::Texture m_minusTexture;
	sf::Texture m_plusTexture;
	sf::Sprite m_plusSprite[6];
	sf::Sprite m_minusSprite[6];

	bool m_hitlerAlive = true; //if hitler is alive
};