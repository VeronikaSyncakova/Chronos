#include "PuzzleOne.h"
#include "Game.h"
#include <iostream>

void PuzzleOne::initialise(sf::Font t_font)
{
	m_font = t_font;
	m_npcMessage.setFont(m_font);
	m_npcMessage.setCharacterSize(24U);
	m_npcMessage.setFillColor(sf::Color::White);
	m_npcMessage.setString("Help!");
	m_npcMessage.setPosition({ 50.0f,400.0f });

	m_npc.setFillColor(sf::Color::Magenta);
	m_npc.setSize(sf::Vector2f{ 50.0f,70.0f });
	m_npc.setOrigin(25.0f, 35.0f);
	m_npc.setPosition(100.0f, 500.0f);

	m_answerBox.setFillColor(sf::Color::Cyan);
	m_answerBox.setSize(sf::Vector2f{100.0f, 50.0f});
	m_answerBox.setOrigin(200.0f, 35.0f);
	m_answerBox.setPosition(850.0f, 100.0f);

	m_npcCanClick = false; 
	m_drawPuzzle = false;
	m_correctNumberOne = false;
	m_correctNumberTwo = false;

	m_circle.setFillColor(sf::Color::Red);
	m_circle.setRadius(10.0f);
	m_circle.setOrigin(5.0f,5.0f);
	m_circle.setPosition(750.0f, 35.0f);

	if (!puzzleTexture.loadFromFile("ASSETS/IMAGES/puzzleBox.png"))
	{
		std::cout << "error with puzzle box file";
	}

	puzzleSprite.setTexture(puzzleTexture);
	puzzleSprite.setOrigin(200.0f, 35.0f);
	puzzleSprite.setPosition(400.0f, 70.0f);
	
		if (!numTexture.loadFromFile("ASSETS/IMAGES/numbers/one.png"))
		{
			std::cout << "error with number file";
		}

	
		numSprite.setTexture(numTexture);
		numSprite.setOrigin(200.0f, 35.0f);
		numSprite.setPosition(250.0f, 350.0f);

		if (!numTexture2.loadFromFile("ASSETS/IMAGES/numbers/two.png"))
		{
			std::cout << "error with number file";
		}
		numSprite2.setTexture(numTexture2);
		numSprite2.setOrigin(200.0f, 35.0f);
		numSprite2.setPosition(300.0f, 350.0f);

		if (!numTexture3.loadFromFile("ASSETS/IMAGES/numbers/three.png"))
		{
			std::cout << "error with number file";
		}
		numSprite3.setTexture(numTexture3);
		numSprite3.setOrigin(200.0f, 35.0f);
		numSprite3.setPosition(350.0f, 350.0f);

		if (!numTexture4.loadFromFile("ASSETS/IMAGES/numbers/four.png"))
		{
			std::cout << "error with number file";
		}
		numSprite4.setTexture(numTexture4);
		numSprite4.setOrigin(200.0f, 35.0f);
		numSprite4.setPosition(400.0f, 350.0f);

		if (!numTexture5.loadFromFile("ASSETS/IMAGES/numbers/five.png"))
		{
			std::cout << "error with number file";
		}
		numSprite5.setTexture(numTexture5);
		numSprite5.setOrigin(200.0f, 35.0f);
		numSprite5.setPosition(450.0f, 350.0f);


		if (!numTexture6.loadFromFile("ASSETS/IMAGES/numbers/six.png"))
		{
			std::cout << "error with number file";
		}
		numSprite6.setTexture(numTexture6);
		numSprite6.setOrigin(200.0f, 35.0f);
		numSprite6.setPosition(500.0f, 350.0f);

		if (!numTexture7.loadFromFile("ASSETS/IMAGES/numbers/seven.png"))
		{
			std::cout << "error with number file";
		}
		numSprite7.setTexture(numTexture7);
		numSprite7.setOrigin(200.0f, 35.0f);
		numSprite7.setPosition(550.0f, 350.0f);

		if (!numTexture8.loadFromFile("ASSETS/IMAGES/numbers/eight.png"))
		{
			std::cout << "error with number file";
		}
		numSprite8.setTexture(numTexture8);
		numSprite8.setOrigin(200.0f, 35.0f);
		numSprite8.setPosition(600.0f, 350.0f);

		if (!numTexture9.loadFromFile("ASSETS/IMAGES/numbers/nine.png"))
		{
			std::cout << "error with number file";
		}
		numSprite9.setTexture(numTexture9);
		numSprite9.setOrigin(200.0f, 35.0f);
		numSprite9.setPosition(650.0f, 350.0f);

		if (!numTexture0.loadFromFile("ASSETS/IMAGES/numbers/zero.png"))
		{
			std::cout << "error with number file";
		}
		numSprite0.setTexture(numTexture0);
		numSprite0.setOrigin(200.0f, 35.0f);
		numSprite0.setPosition(700.0f, 350.0f);




	

	if (!m_npcTexture.loadFromFile("ASSETS/IMAGES/npc1.png"))
	{
		std::cout << "error with npc 1 image file";
	}

	m_npcSprite.setTexture(m_npcTexture);
	m_npcSprite.setOrigin(25.0f, 35.0f);
	m_npcSprite.setPosition(100.0f, 500.0f);
	
	m_player.initialise();
	m_player.setPosition(sf::Vector2f{ 600.0f,500.0f });

	m_portal.initialise(3);
	m_portal.setPosition(sf::Vector2f{ 700.0f,500.0f });
	
	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/puzzleBg.png"))
	{
		std::cout << "error with puzzle one background file";
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);
}

void PuzzleOne::update(sf::Time t_deltaTime)
{
	npcInteraction();
	checkAnswer();
}

void PuzzleOne::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_npcSprite);
	if (m_drawPuzzle)
	{
		t_window.draw(puzzleSprite);
		t_window.draw(m_answerBox);
		t_window.draw(numSprite);
		t_window.draw(numSprite2);
		t_window.draw(numSprite3);
		t_window.draw(numSprite4);
		t_window.draw(numSprite5);
		t_window.draw(numSprite6);
		t_window.draw(numSprite7);
		t_window.draw(numSprite8);
		t_window.draw(numSprite9);
		t_window.draw(numSprite0);
		t_window.draw(m_circle);
	}

	
	

	if (m_npcCanClick)
	{
		t_window.draw(m_npcMessage);
	}

	m_portal.render(t_window);
	m_player.render(t_window);
}

void PuzzleOne::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		if (sf::Keyboard::Left == t_event.key.code || sf::Keyboard::A == t_event.key.code)
		{
			if (m_player.getPosition().x > 170.0f)
			{
				m_player.moveLeft();
			}
		}
		else if (sf::Keyboard::Right == t_event.key.code || sf::Keyboard::D == t_event.key.code)
		{
			m_player.moveRight();
			portalCollision();
		}
}

	sf::Vector2f mouse;
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		mouse.x = t_event.mouseButton.x;
		mouse.y = t_event.mouseButton.y;
		if (m_npcCanClick)
		{
			if (m_npcSprite.getGlobalBounds().contains(mouse))
			{
				if (!m_drawPuzzle)
				{
					m_drawPuzzle = true;
					m_npcMessage.setString("Count the number of white squares. Click the two numbers you want to go into the answer box.");
					m_npcMessage.setCharacterSize(18u);
				}
				else
				{
					m_drawPuzzle = false;
					m_npcMessage.setString("Help!");
					m_npcMessage.setCharacterSize(20U);
				}
			}
		}
		if (numSprite.getPosition().x < 800)
		{
			if (numSprite.getGlobalBounds().contains(mouse))
			{
				numSprite.setPosition(850.0f, 100.0f);
			}
		}
		else if(numSprite.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
		{
			if (numSprite.getGlobalBounds().contains(mouse))
			{
				numSprite.setPosition(250.0f, 350.0f);
			}
		}

		if (numSprite2.getPosition().x < 800)
		{
			if (numSprite2.getGlobalBounds().contains(mouse))
			{
				numSprite2.setPosition(900.0f, 100.0f);
			}
		}
		else if (numSprite2.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
		{
			if (numSprite2.getGlobalBounds().contains(mouse))
			{
				numSprite2.setPosition(300.0f, 350.0f);
			}
		}

		if (numSprite3.getPosition().x < 800)
		{
			if (numSprite3.getGlobalBounds().contains(mouse))
			{
				numSprite3.setPosition(900.0f, 100.0f);
			}
		}
		else if (numSprite3.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
		{
			if (numSprite3.getGlobalBounds().contains(mouse))
			{
				numSprite3.setPosition(350.0f, 350.0f);
			}
		}

		if (numSprite4.getPosition().x < 800)
		{
			if (numSprite4.getGlobalBounds().contains(mouse))
			{
				numSprite4.setPosition(900.0f, 100.0f);
			}
		}
		else if (numSprite4.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
		{
			if (numSprite4.getGlobalBounds().contains(mouse))
			{
				numSprite4.setPosition(400.0f, 350.0f);
			}
		}

		if (numSprite5.getPosition().x < 800)
		{
			if (numSprite5.getGlobalBounds().contains(mouse))
			{
				numSprite5.setPosition(900.0f, 100.0f);
			}
		}
		else if (numSprite5.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
		{
			if (numSprite5.getGlobalBounds().contains(mouse))
			{
				numSprite5.setPosition(450.0f, 350.0f);
			}
		}


		if (numSprite6.getPosition().x < 800)
		{
			if (numSprite6.getGlobalBounds().contains(mouse))
			{
				numSprite6.setPosition(900.0f, 100.0f);
			}
		}
		else if (numSprite6.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
		{
			if (numSprite6.getGlobalBounds().contains(mouse))
			{
				numSprite6.setPosition(500.0f, 350.0f);
			}
		}


		if (numSprite7.getPosition().x < 800)
		{
			if (numSprite7.getGlobalBounds().contains(mouse))
			{
				numSprite7.setPosition(900.0f, 100.0f);
			}
		}
		else if (numSprite7.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
		{
			if (numSprite7.getGlobalBounds().contains(mouse))
			{
				numSprite7.setPosition(550.0f, 350.0f);
			}
		}


		if (numSprite8.getPosition().x < 800)
		{
		if (numSprite8.getGlobalBounds().contains(mouse))
			{
				numSprite8.setPosition(900.0f, 100.0f);
			}
		}
		else if (numSprite8.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
		
			if (numSprite8.getGlobalBounds().contains(mouse))
			{
				numSprite8.setPosition(600.0f, 350.0f);
			}
		}


		if (numSprite9.getPosition().x < 800)
		{
			if (numSprite9.getGlobalBounds().contains(mouse))
			{
				numSprite9.setPosition(900.0f, 100.0f);
			}
		}
		else if (numSprite9.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
		{
			if (numSprite9.getGlobalBounds().contains(mouse))
			{
				numSprite9.setPosition(650.0f, 350.0f);
			}
		}


		if (numSprite0.getPosition().x < 800)
		{
			if (numSprite0.getGlobalBounds().contains(mouse))
			{
				numSprite0.setPosition(900.0f, 100.0f);
			}
		}
		else if (numSprite0.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
		{
			if (numSprite0.getGlobalBounds().contains(mouse))
			{
				numSprite0.setPosition(700.0f, 350.0f);
			}
		}

	
	

}

void PuzzleOne::portalCollision()
{
	if (m_player.getBody().getGlobalBounds().intersects(m_portal.getBody().getGlobalBounds()))
	{
		Game::s_currentMode = GameMode::Present;
	}
	
}

void PuzzleOne::npcInteraction()
{
	if (m_player.getPosition().x < 350.0f)
	{ //if player is close to npc he can interact with him
		m_npcCanClick = true;
	}
	else
	{
		m_npcCanClick = false;
	}
}

void PuzzleOne::checkAnswer()
{
	if (numSprite.getGlobalBounds().intersects(m_answerBox.getGlobalBounds())) 
	{
		m_correctNumberOne = true;
	}
	if (numSprite5.getGlobalBounds().intersects(m_answerBox.getGlobalBounds()))
	{
		m_correctNumberTwo = true;
	}
	if (m_correctNumberOne == true && m_correctNumberTwo == true)
	{
		m_circle.setFillColor(sf::Color::Green);
		e_doorLocked = 1;

		m_npcMessage.setString("You did it! Move on to the next portal!");
		m_npcMessage.setCharacterSize(20u);
	}
}

sf::Vector2f PuzzleOne::getPosition()
{
	return numSprite.getPosition();
}

sf::Vector2f PuzzleOne::getPosition2()
{
	return numSprite2.getPosition();
}

sf::Vector2f PuzzleOne::getPosition3()
{
	return numSprite3.getPosition();
}

sf::Vector2f PuzzleOne::getPosition4()
{
	return numSprite4.getPosition();
}

sf::Vector2f PuzzleOne::getPosition5()
{
	return numSprite5.getPosition();
}

sf::Vector2f PuzzleOne::getPosition6()
{
	return numSprite6.getPosition();
}

sf::Vector2f PuzzleOne::getPosition7()
{
	return numSprite7.getPosition();
}

sf::Vector2f PuzzleOne::getPosition8()
{
	return numSprite8.getPosition();
}

sf::Vector2f PuzzleOne::getPosition9()
{
	return numSprite9.getPosition();
}

sf::Vector2f PuzzleOne::getPosition0()
{
	return numSprite0.getPosition();
}



