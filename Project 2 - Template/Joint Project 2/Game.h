#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "MainMenu.h"
#include "Player.h"


class Game
{
	
	sf::Font m_ariblkFont; // font shape for font

	sf::RenderWindow m_Window;  // console window
	
	MainMenu m_mainMenu; // object used to display main menu


	sf::Text m_message; 	//  message string for instructions

	int gameMode;   // to represent the different modes in the game, for  
					// example game instruction mode and game play mode


	// Put your game objects here - player, dealer etc.



public:
	Game();
	void	run();	
	void	update();
	void	draw();
	void	loadContent();
	void	gameInstructions();
	
			
};
