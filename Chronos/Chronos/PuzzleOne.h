#pragma once
#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include "Player.h"
#include "Portal.h"

class PuzzleOne
{
	
	sf::Font m_font;
	sf::Text m_text;
	sf::RectangleShape m_npc;
	sf::RectangleShape m_answerBox;
	sf::Texture puzzleTexture;
	sf::Sprite puzzleSprite;
	sf::Texture m_npcTexture;
	sf::Sprite m_npcSprite;
	sf::Texture numTexture, numTexture2, numTexture3, numTexture4, numTexture5, numTexture6, numTexture7, numTexture8, numTexture9, numTexture0;
	sf::Sprite numSprite, numSprite2, numSprite3, numSprite4, numSprite5, numSprite6,numSprite7,numSprite8,numSprite9,numSprite0;
	sf::Text m_npcMessage;
	Player m_player;
	Portal m_portal;
	bool m_npcCanClick = false; //if player is within certain radius he can interact with npc
	bool m_drawPuzzle = false;
	bool m_correctNumberOne = false;
	bool m_correctNumberTwo = false;
	sf::Texture m_backgroundTexture; //setup background sprite
	sf::Sprite m_backgroundSprite;


public:
	void initialise(sf::Font t_font);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);
	void portalCollision();
	void npcInteraction();
	void checkAnswer();
	sf::Vector2f getPosition();
	sf::Vector2f getPosition2();
	sf::Vector2f getPosition3();
	sf::Vector2f getPosition4();
	sf::Vector2f getPosition5();
	sf::Vector2f getPosition6();
	sf::Vector2f getPosition7();
	sf::Vector2f getPosition8();
	sf::Vector2f getPosition9();
	sf::Vector2f getPosition0();
};