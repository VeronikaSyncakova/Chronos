/// <summary>
/// authors Freya Prananta, Veronika Syncakova, Jack Sweeny, Conor Flynn
/// @date March 2023
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>
#include<cstdlib>
#include<ctime>


GameMode Game::s_currentMode = GameMode::Splash;



bool Game::s_exitGame = false;
bool Game::s_restart = false;

/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "Chronos" },
	m_exitGame{false} //when true game will exit
{
	srand(time(nullptr));
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	m_splash.initialise(m_pixelFont);
	m_menu.initialise(m_pixelFont);
	m_instructions.initialise(m_pixelFont);
	m_present.initialise(m_pixelFont);
	m_puzzle.initialise(m_pixelFont);
	m_finalPuzzle.initialise(m_pixelFont);
	m_end.initialise(m_pixelFont);
	m_puzzleTwo.initialise(m_pixelFont);
	m_puzzleThree.initialise(m_pixelFont);
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{

	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (s_exitGame) // window message
		{
			m_exitGame = true;
		}
		switch (s_currentMode)
		{
		case GameMode::None:
			break;
		case GameMode::Splash:
			break;
		case GameMode::Menu:
			m_menu.processEvents(newEvent);
			break;
		case GameMode::Instructions:
			m_instructions.processEvents(newEvent);
			break;
		case GameMode::Present:
			m_present.processEvents(newEvent);
			break;
		case GameMode::PuzzleOne:
			m_puzzle.processEvents(newEvent);
			break;
		case GameMode::PuzzleTwo:
			m_puzzleTwo.processEvents(newEvent);
			break;
		case GameMode::PuzzleThree:
			m_puzzleThree.processEvents(newEvent);
			break;
		case GameMode::FinalPuzzle:
			m_finalPuzzle.processEvents(newEvent);
			break;
		case GameMode::End:
			m_end.processEvents(newEvent);
			break;
		default:
			break;
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (s_exitGame)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	switch (s_currentMode)
	{
	case GameMode::None:
		break;
	case GameMode::Splash:
		m_splash.update(t_deltaTime);
		break;
	case GameMode::Menu:
		if (Game::s_restart)
		{
			restartGame();
		}
		break;
	case GameMode::Instructions:
		break;
	case GameMode::Present:
		m_present.update(t_deltaTime);
		break;
	case GameMode::PuzzleOne:
		m_puzzle.update(t_deltaTime);
		break;
	case GameMode::PuzzleTwo:
		m_puzzleTwo.update(t_deltaTime);
		break;
	case GameMode::PuzzleThree:
		m_puzzleThree.update(t_deltaTime);
		break;
	case GameMode::FinalPuzzle:
		m_finalPuzzle.update(t_deltaTime);
		break;
	case GameMode::End:
		break;
	default:
		break;
	}
}


/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	switch (s_currentMode)
	{
	case GameMode::None:
		break;
	case GameMode::Splash:
		m_splash.render(m_window);
		break;
	case GameMode::Menu:
		m_menu.render(m_window);
		break;
	case GameMode::Instructions:
		m_instructions.render(m_window);
		break;
	case GameMode::Present:
		m_present.render(m_window);
		break;
	case GameMode::PuzzleOne:
		m_puzzle.render(m_window);
		break;
	case GameMode::PuzzleTwo:
		m_puzzleTwo.render(m_window);
		break;
	case GameMode::PuzzleThree:
		m_puzzleThree.render(m_window);
		break;
	case GameMode::FinalPuzzle:
		m_finalPuzzle.render(m_window);
		break;
	case GameMode::End:
		m_end.render(m_window);
		break;
	default:
		break;
	}
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_pixelFont.loadFromFile("ASSETS\\FONTS\\pixel.ttf"))
	{
		std::cout << "problem loading pixel font" << std::endl;
		m_pixelFont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf");
	}
	m_welcomeMessage.setFont(m_pixelFont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	
}

void Game::restartGame()
{//restarts the game
	m_present.initialise(m_pixelFont);
	m_puzzle.initialise(m_pixelFont);
	m_finalPuzzle.initialise(m_pixelFont);
	m_puzzleTwo.initialise(m_pixelFont);
	m_puzzleThree.initialise(m_pixelFont);
	
	Game::s_restart = false;
}
