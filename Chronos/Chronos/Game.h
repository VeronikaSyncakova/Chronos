/// <summary>
/// authors Freya Prananta, Veronika Syncakova, Jack Sweeny, Conor Flynn
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include "End.h"
#include"Instructions.h"
#include "Menu.h"
#include "Present.h"
#include "Splash.h"
#include "PuzzleOne.h"
#include "FinalPuzzle.h"
#include "End.h"
#include "PuzzleTwo.h"
#include"PuzzleThree.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

	static GameMode s_currentMode; //game mode the game is in
	static bool s_exitGame; //used to exit game
	static bool s_restart; //if player restarted the game

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();
	void restartGame();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Font m_pixelFont; //pixel font
	sf::Text m_welcomeMessage; // text used for message on screen
	bool m_exitGame; // control exiting game
	Splash m_splash; //splash screen
	Menu m_menu; //menu screen
	Instructions m_instructions; //instruction screen
	Present m_present; //game play present screen 
	PuzzleOne m_puzzle; //First Puzzle screen
	FinalPuzzle m_finalPuzzle; //last puzzle screen
	End m_end; //end game screen
	PuzzleTwo m_puzzleTwo; //second puzzle screen
	PuzzleThree m_puzzleThree; //third puzzle screenpuzzle
};

#endif // !GAME_HPP

