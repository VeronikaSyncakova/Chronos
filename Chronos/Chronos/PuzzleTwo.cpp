#include "PuzzleTwo.h"
#include "Game.h"

void PuzzleTwo::initialise(sf::Font t_font)
{
	m_npcCanClick = false; 
	m_drawPuzzle = false;

	m_circle.setFillColor(sf::Color::Red);
	m_circle.setRadius(10.0f);
	m_circle.setOrigin(5.0f, 5.0f);
	m_circle.setPosition(580.0f, 200.0f);

	m_font = t_font;
	m_npcMessage.setFont(m_font);
	m_npcMessage.setCharacterSize(24U);
	m_npcMessage.setFillColor(sf::Color::White);
	m_npcMessage.setString("Help!");
	m_npcMessage.setPosition({ 100.0f,400.0f });

	m_npc.setFillColor(sf::Color::Magenta);
	m_npc.setSize(sf::Vector2f{ 50.0f,70.0f });
	m_npc.setOrigin(25.0f, 35.0f);
	m_npc.setPosition(100.0f, 500.0f);

	m_player.initialise();
	m_player.setPosition(sf::Vector2f{ 600.0f,500.0f });

	m_portal.initialise(3);
	m_portal.setPosition(sf::Vector2f{ 700.0f,500.0f });

	m_mathRiddle.setFont(m_font);
	m_mathRiddle.setCharacterSize(32U);
	m_mathRiddle.setFillColor(sf::Color::White);
	m_mathRiddle.setString("8=72\n2=6\n5=30\n9=?");
	m_mathRiddle.setPosition({ 350.0f,100.0f });

	if (!m_minusTexture.loadFromFile("ASSETS/IMAGES/minus.png"))
	{
		std::cout << "error with minus file";
	}
	if (!m_plusTexture.loadFromFile("ASSETS/IMAGES/plus.png"))
	{
		std::cout << "error with plus file";
	}

	float positionX = 500.0f;
	for (int i = 0; i < 2; i++)
	{
		m_numberBox[i].setFillColor(sf::Color::White);
		m_numberBox[i].setSize(sf::Vector2f{ 25.0f,35.0f });
		m_numberBox[i].setOrigin(12.5f, 17.5f);
		m_numberBox[i].setPosition(positionX, 230.0f);

		m_plus[i].setFillColor(sf::Color::White);
		m_plus[i].setSize(sf::Vector2f{ 20.0f,20.0f });
		m_plus[i].setOrigin(10.0f, 10.0f);
		m_plus[i].setPosition(positionX, 190.0f);
		m_plusSprite[i].setTexture(m_plusTexture);
		m_plusSprite[i].setOrigin(10.0f, 10.0f);
		m_plusSprite[i].setPosition(positionX, 190.0f);

		m_minus[i].setFillColor(sf::Color::White);
		m_minus[i].setSize(sf::Vector2f{ 20.0f,20.0f });
		m_minus[i].setOrigin(10.0f, 10.0f);
		m_minus[i].setPosition(positionX, 270.0f);
		m_minusSprite[i].setTexture(m_minusTexture);
		m_minusSprite[i].setOrigin(10.0f, 10.0f);
		m_minusSprite[i].setPosition(positionX, 270.0f);

		m_numbers[i].setFont(m_font);
		m_numbers[i].setCharacterSize(24U);
		m_numbers[i].setFillColor(sf::Color::Black);
		m_numbers[i].setString("0");
		m_numbers[i].setOrigin(m_numbers[i].getGlobalBounds().width / 2.0f, m_numbers[i].getGlobalBounds().height / 2.0f);
		m_numbers[i].setPosition({ positionX,220.0f });

		m_intigers[i] = 0;

		positionX += 40.0f;
	}

	if (!m_npcTexture.loadFromFile("ASSETS/IMAGES/npc2.png"))
	{
		std::cout << "error with npc 2 image file";
	}
	m_npcSprite.setTexture(m_npcTexture);
	m_npcSprite.setOrigin(25.0f, 35.0f);
	m_npcSprite.setPosition(100.0f, 500.0f);

	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/puzzleBg1.png"))
	{
		std::cout << "error with final puzzle background file";
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);
}

void PuzzleTwo::update(sf::Time t_deltaTime)
{
	npcInteraction();
	checkCorrectCode();
}

void PuzzleTwo::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_npcSprite);
	m_portal.render(t_window);
	m_player.render(t_window);

	if (m_npcCanClick)
	{
		t_window.draw(m_npcMessage);
	}

	if (m_drawPuzzle && m_npcCanClick)
	{
		t_window.draw(m_mathRiddle);
		for (int i = 0; i < 2; i++)
		{
			t_window.draw(m_numberBox[i]);
			t_window.draw(m_plusSprite[i]);
			t_window.draw(m_minusSprite[i]);
			t_window.draw(m_numbers[i]);
		}
		t_window.draw(m_circle);
	}
}

void PuzzleTwo::processEvents(sf::Event t_event)
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
			for (int i = 0; i < 2; i++)
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
			m_npcMessage.setString("Help me solve the puzzle, use the + and -");
		}
	}
}

void PuzzleTwo::portalCollision()
{//swithing screens by portal
	if (m_player.getBody().getGlobalBounds().intersects(m_portal.getBody().getGlobalBounds()))
	{
		Game::s_currentMode = GameMode::Present;
		e_portalUsed = 1;
	}
}

void PuzzleTwo::npcInteraction()
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

void PuzzleTwo::checkCorrectCode()
{
	if (m_intigers[0] == 9 && m_intigers[1] == 0)
	{ //unlocking the doors
		m_circle.setFillColor(sf::Color::Green);
		e_doorLocked = 1;
		m_npcMessage.setString("Correct answer, you can go to next puzzle!");
	}
}
