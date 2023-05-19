#include "FinalPuzzle.h"
#include "Game.h"

void FinalPuzzle::initialise(sf::Font t_font)
{
	m_font = t_font;
	m_npcMessage.setFont(m_font);
	m_npcMessage.setCharacterSize(24U);
	m_npcMessage.setFillColor(sf::Color::White);
	m_npcMessage.setString("Help!");
	m_npcMessage.setPosition({ 100.0f,400.0f });

	m_encryptedMessage.setFont(m_font);
	m_encryptedMessage.setCharacterSize(32U);
	m_encryptedMessage.setFillColor(sf::Color::White);
	m_encryptedMessage.setString("BEKHSO");
	m_encryptedMessage.setPosition(200.0f, 100.0f);

	m_decryptedMessage.setFont(m_font);
	m_decryptedMessage.setCharacterSize(32U);
	m_decryptedMessage.setFillColor(sf::Color::White);
	m_decryptedMessage.setString("Type here");
	m_decryptedMessage.setPosition(200.0f, 220.0f);

	m_answear.setFillColor(sf::Color::Transparent);
	m_answear.setOutlineColor(sf::Color::White);
	m_answear.setOutlineThickness(5.0f);
	m_answear.setSize({ m_decryptedMessage.getGlobalBounds().width+5,80.0f});
	m_answear.setPosition(200.0f, 200.0f);

	m_npc.setFillColor(sf::Color::Magenta);
	m_npc.setSize(sf::Vector2f{ 50.0f,70.0f });
	m_npc.setOrigin(25.0f, 35.0f);
	m_npc.setPosition(100.0f, 500.0f);

	m_player.initialise();
	m_player.setPosition(sf::Vector2f{ 600.0f,500.0f });

	m_portal.initialise(3);
	m_portal.setPosition(sf::Vector2f{ 700.0f,500.0f });

	if (!m_minusTexture.loadFromFile("ASSETS/IMAGES/minus.png"))
	{
		std::cout << "error with minus file";
	}
	if (!m_plusTexture.loadFromFile("ASSETS/IMAGES/plus.png"))
	{
		std::cout << "error with plus file";
	}

	float positionX = 500.0f;
	for (int i = 0; i < 6; i++)
	{
		m_numberBox[i].setFillColor(sf::Color::White);
		m_numberBox[i].setSize(sf::Vector2f{ 25.0f,35.0f });
		m_numberBox[i].setOrigin(12.5f, 17.5f);
		m_numberBox[i].setPosition(positionX, 117.5f);

		m_plus[i].setFillColor(sf::Color::White);
		m_plus[i].setSize(sf::Vector2f{ 20.0f,20.0f });
		m_plus[i].setOrigin(10.0f, 10.0f);
		m_plus[i].setPosition(positionX, 80.0f);
		m_plusSprite[i].setTexture(m_plusTexture);
		m_plusSprite[i].setOrigin(10.0f, 10.0f);
		m_plusSprite[i].setPosition(positionX, 80.0f);

		m_minus[i].setFillColor(sf::Color::White);
		m_minus[i].setSize(sf::Vector2f{ 20.0f,20.0f });
		m_minus[i].setOrigin(10.0f, 10.0f);
		m_minus[i].setPosition(positionX, 155.0f);
		m_minusSprite[i].setTexture(m_minusTexture);
		m_minusSprite[i].setOrigin(10.0f, 10.0f);
		m_minusSprite[i].setPosition(positionX, 155.0f);

		m_numbers[i].setFont(m_font);
		m_numbers[i].setCharacterSize(24U);
		m_numbers[i].setFillColor(sf::Color::Black);
		m_numbers[i].setString("0");
		m_numbers[i].setOrigin(m_numbers[i].getGlobalBounds().width / 2.0f, m_numbers[i].getGlobalBounds().height / 2.0f);
		m_numbers[i].setPosition({positionX,110.0f});

		m_intigers[i] = 0;

		positionX += 40.0f;
	}

	if (!m_npcTexture.loadFromFile("ASSETS\\IMAGES\\adolfKitler.png"))
	{
		std::cout << "problem with loading adolf kitler image" << std::endl;
	}
	m_npcSprite.setTexture(m_npcTexture);
	m_npcSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_npcSprite.setOrigin(25.0f, 35.0f);
	m_npcSprite.setPosition(100.0f, 500.0f);

	if (!m_npcDeadTexture.loadFromFile("ASSETS\\IMAGES\\adolfKitlerDead.png"))
	{
		std::cout << "problem with loading dead adolf kitler image" << std::endl;
	}
	m_npcDeadSprite.setTexture(m_npcDeadTexture);
	m_npcDeadSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_npcDeadSprite.setOrigin(25.0f, 35.0f);
	m_npcDeadSprite.setPosition(100.0f, 500.0f);

	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/puzzleBg1.png"))
	{
		std::cout << "error with final puzzle background file";
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);
}

void FinalPuzzle::update(sf::Time t_deltaTime)
{
	npcInteraction();
}

void FinalPuzzle::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	
	//different sprite drawn if kitler is alive and if kitler is dead
	if (m_hitlerAlive == true)
	{
		t_window.draw(m_npcSprite);
	}
	else
	{
		t_window.draw(m_npcDeadSprite);
	}
	m_portal.render(t_window);
	m_player.render(t_window);

	if (m_npcCanClick)
	{
		t_window.draw(m_npcMessage);
	}

	if (m_drawPuzzle && m_npcCanClick)
	{
		for (int i = 0; i < 6; i++)
		{
			t_window.draw(m_numberBox[i]);
			t_window.draw(m_plusSprite[i]);
			t_window.draw(m_minusSprite[i]);
			t_window.draw(m_numbers[i]);
			t_window.draw(m_answear);
			t_window.draw(m_encryptedMessage);
			t_window.draw(m_decryptedMessage);
		}
	}
}

void FinalPuzzle::processEvents(sf::Event t_event)
{
	if (!m_writing)
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
	}
	else
	{
		if (sf::Event::KeyReleased == t_event.type)
		{
			if (sf::Keyboard::A <= t_event.key.code && sf::Keyboard::Z >= t_event.key.code)
			{
				char letter = static_cast<char>(t_event.key.code - sf::Keyboard::A + 'A');
				letter = decryptLetter(letter);
				m_decryptedString += letter;
				m_decryptedMessage.setString(m_decryptedString);
				m_answear.setSize({ m_decryptedMessage.getGlobalBounds().width+5,80.0f});
				checkCorrectString(m_decryptedString);
			}
			else if (sf::Keyboard::BackSpace == t_event.key.code)
			{
				if (m_decryptedString.length() > 0)
				{
					m_decryptedString.pop_back();
					m_answear.setSize({ m_decryptedMessage.getGlobalBounds().width + 5,80.0f });
					m_decryptedMessage.setString(m_decryptedString);
				}
			}
		}
	}

	sf::Vector2f mouse;
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		mouse.x = t_event.mouseButton.x;
		mouse.y = t_event.mouseButton.y;
		if (m_npcCanClick)
		{
			if (m_npc.getGlobalBounds().contains(mouse))
			{
				if (!m_drawPuzzle)
				{
					m_drawPuzzle = true;
				}
				else
				{
					m_drawPuzzle = false;
				}
			}
		}
		if (m_drawPuzzle);
		{
			for (int i = 0; i < 6; i++)
			{
				if (m_plus[i].getGlobalBounds().contains(mouse))
				{//increasing number
					if (m_intigers[i] != 9)
					{
						m_intigers[i]++;
					}
					else
					{
						m_intigers[i] = 0;
					}
					m_numbers[i].setString(std::to_string(m_intigers[i]));
				}
				if (m_minus[i].getGlobalBounds().contains(mouse))
				{//decreasing number
					if (m_intigers[i] != 0)
					{
						m_intigers[i]--;
					}
					else
					{
						m_intigers[i] = 9;
					}
					m_numbers[i].setString(std::to_string(m_intigers[i]));
				}
			}
			
			if (!m_writing)
			{
				if (m_answear.getGlobalBounds().contains(mouse))
				{//activate writing window
					m_writing = true;
					m_npcMessage.setString("write the message. to stop writing click the box again");
					m_npcMessage.setCharacterSize(20u);
				}
			}
			else
			{
				if (m_answear.getGlobalBounds().contains(mouse))
				{//deactivate writing window
					m_writing = false;
					m_npcMessage.setString("Help!");
					m_npcMessage.setCharacterSize(24u);
				}
			}
		}
	}
}

void FinalPuzzle::portalCollision()
{//swithing screens by portal
	if (m_player.getBody().getGlobalBounds().intersects(m_portal.getBody().getGlobalBounds()))
	{
		if (m_correctMessage)
		{//player solved the puzzle
			Game::s_currentMode = GameMode::End;
		}
		else
		{//player did not solve the puzzle
			Game::s_currentMode = GameMode::Present;
		}
	}
}

void FinalPuzzle::npcInteraction()
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

bool FinalPuzzle::checkCorrectCode()
{//checks for right numerical code
	if (m_intigers[0] == 1 &&
		m_intigers[1] == 5 &&
		m_intigers[2] == 9 &&
		m_intigers[3] == 0 &&
		m_intigers[4] == 1 &&
		m_intigers[5] == 6)
	{
		return true;
	}
	else
	{
		return false;
	}
}

char FinalPuzzle::decryptLetter(char t_letter)
{//decrypt the letter, if the code is wrong it uses ceasar cypher, if the code is correct it gives the right answer
	if (checkCorrectCode())
	{
		if (t_letter == 'B')
		{
			t_letter = 'E';
		}
		else if (t_letter == 'E')
		{
			t_letter = 'N';
		}
		else if (t_letter == 'K')
		{
			t_letter = 'I';
		}
		else if (t_letter == 'H')
		{
			t_letter = 'G';
		}
		else if (t_letter == 'S')
		{
			t_letter = 'M';
		}
		else if (t_letter == 'O')
		{
			t_letter = 'A';
		}
		else
		{//random letter each time if user inputs wrong key
			int incriment = (rand() % 8) + 1;
			if (t_letter > ('Z' - incriment))
			{//looping from end to start of the alphabet
				int num = (incriment-1) - ('Z' - t_letter); //number that has to be added to A
				t_letter = 'A' + num;
			}
			else
			{
				t_letter += incriment;
			}
		}
	}
	else
	{//if code is not correct the letter will become letter 7 places further
		if (t_letter > ('Z' - 7))
		{//looping from end to start of the alphabet
			int num = 6-('Z' - t_letter) ; //number that has to be added to A, 6 because we have to substitute one for A
			t_letter = 'A' + num;
		}
		else
		{
			t_letter += 7;
		}
		
	}
	return t_letter;
}

void FinalPuzzle::checkCorrectString(std::string t_string)
{//if player solved the puzzle
	if (t_string == "ENIGMA")
	{
		m_correctMessage = true;
		m_hitlerAlive = false;
		m_npcMessage.setString("Correct answear!");
		m_writing = false;
	}
	
}
