// Name: 
// Login: 
// Date: 
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description: Project 2 - TEMPLATE
// ---------------------------------------------------------------------------
// Known Bugs:
// ?

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "Game.h"



int main()
{ 
	Game game; 
	game.run(); 
}

 
/// <summary>
/// main game constructor creating the render window with settings
/// </summary>
Game::Game() : m_Window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Project 2 - BlackJack",sf::Style::Default)
{			
	gameMode = 1;
	loadContent();
	m_Window.setKeyRepeatEnabled(false);
}

/// <summary>
/// load the font and initialise everything else.
/// </summary>
void Game::loadContent()
{
	if (!m_ariblkFont.loadFromFile("ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "error with font file file";
	}

	m_message.setFont(m_ariblkFont);  // set the font for the text
	m_message.setCharacterSize(24);
	m_message.setFillColor(sf::Color::White);
	m_message.setPosition(50, 100);

	m_mainMenu.initialise(m_ariblkFont);
}

/// <summary>
/// main game loop.
/// </summary>
void Game::run()
{
	srand(time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (m_Window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (m_Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_Window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

/// <summary>
/// call the update function corresponding to the current game mode
/// </summary>
void Game::update()
{
	if (gameMode == MENU)
	{
		m_mainMenu.update(m_Window, gameMode);
	}
	else if (gameMode == INSTRUCTIONS)
	{
		gameInstructions();
	}
	else if (gameMode == GAME_PLAY)
	{
		m_message.setString("Game Play");
	}
}

/// <summary>
/// call the draw function for the current game mode
/// </summary>
void Game::draw()
{
	m_Window.clear();

	if (gameMode == MENU)
	{
		m_mainMenu.draw(m_Window);
	}
	else if (gameMode == INSTRUCTIONS)
	{
		m_Window.draw(m_message);
	}
	else if (gameMode == GAME_PLAY)
	{
		m_Window.draw(m_message);
	}

	m_Window.display();
}

/// <summary>
/// Setup game instructions here
/// </summary>
void Game::gameInstructions()
{
	m_message.setString("Game Instructions here");
}