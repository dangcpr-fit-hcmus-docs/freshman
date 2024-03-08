// Author: Mitch Barnett
// Created: April 2016

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "TrafficManager.h"
#include "TextItem.h"



// Calculates the score based on passed values
int calcScore(float fTime, int iMoves, int iLives)
{
	int iTimeScore = (int)(fTime);		// Converts the float time to and int score
	return (iTimeScore + iMoves - iLives * 5) + 1;	// Takes all values to return a score
}

// Controls the flow of the whole program
// First creates all the needed objects, then begins the gameloop
// In each loops objects positions updated then drawn to the screen
int main()
{
	srand((unsigned int)time(NULL));				// Seeds the random number generator

	sf::RenderWindow window(sf::VideoMode(800, 680), "Cross the street"); // creates the window
	window.setFramerateLimit(60);	// Limits framerate to 60fps
	Player player;					// Creates a player
	player.setPosition(sf::Vector2f(375, 625));	//sets the initial player position
	TrafficManager trafficManager;	// Manages all the traffic
	Background background;			// Sets up the background

	int score = 0;		// Tracks the players score
	float elapsed = 0.01f;	// Stores the value of the frame time
	bool cheatMode = false;

	TextItem textLives("Lives: ", player.getLivesLeft(), sf::Vector2f(0,650));	// Creates Lives UI item
	TextItem textMoves("Moves: ", player.getMovesTaken(), sf::Vector2f(675, 650));	// Creates Moves UI item
	TextItem textTime("Time: ", 0.0f, sf::Vector2f(300, 650));				// Creates Time UI item			
	TextItem textCheatMode("Cheatmode on", sf::Vector2f(0, 0), 50); // show text saying cheatmode is on

	sf::Clock gameClock;	// A clock to track how long the game has been running
	sf::Clock frameClock;	// Tracks how much time the last frame took
	
	

	// run the program as long as the window is open
	while (window.isOpen())
	{
		float gameTime = gameClock.getElapsedTime().asSeconds();
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			// Restart the game if the r key is pressed
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
			{
				player.reset();
				gameClock.restart();
			}

			// toggle cheat mode if the c key is pressed
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C)
			{
				cheatMode = !cheatMode;
			}
		}

		

		frameClock.restart();			// Restarts frame clock for new frame
		player.update(event, window);	// Check if the user has requested the player to move
		trafficManager.update(elapsed, gameTime);	// Updates traffic all trafic objects

		// Checks for a collision between the player and traffic objects
		if (trafficManager.checkCollision(player.getBounds()) && !cheatMode)
		{
			player.loseLife();	// Decrement the lives
			player.setPosition(sf::Vector2f(375, 625));
		}

		// Updates UI elements
		textLives.update("Lives: ", player.getLivesLeft());
		textTime.update("Time: ", gameClock.getElapsedTime().asSeconds());
		textMoves.update("Moves: ", player.getMovesTaken());


		// clear the window with black color for start of drawing a new frame
		window.clear(sf::Color::Black);

		// Draw game componenets to the screen
		background.draw(window);
		player.draw(window);
		trafficManager.draw(window);

		// Draw UI elements to the screen
		textLives.draw(window);
		textTime.draw(window);
		textMoves.draw(window);
		if (cheatMode)
		{
			textCheatMode.draw(window);
		}
		
		// Draw a the game over screen if game is lost
		if (player.getLivesLeft() <= 0)
		{
			window.clear(sf::Color::Black);
			TextItem gameOver("Game Over", sf::Vector2f(250, 200), 60);
			TextItem rToRestart("Press r to restart", sf::Vector2f(300, 400), 30);
			gameOver.draw(window);
			rToRestart.draw(window);
		}

		// Draw the game win screen is game is won
		else if (player.getBounds().intersects(background.m_rectTopPavement.getGlobalBounds())){
			// Calculate the score
			// Create UI items for the game over screen
			TextItem textGameWin("Congratulations", sf::Vector2f(200, 250), 60);
			TextItem textGameScore("Score:  ", score, sf::Vector2f(350, 320));
			TextItem textRestart("Press r to play again", sf::Vector2f(275, 400), 30);

			// Draw the game over message to the screen
			window.clear(sf::Color::Black);
			textGameWin.draw(window);
			textGameScore.draw(window);
			textRestart.draw(window);
		}
		else
		{
			// Calculate the score
			score = calcScore(gameTime, player.getMovesTaken(), player.getLivesLeft());
		}


		// Display the current frame
		window.display();

		// update elapsed value
		elapsed = frameClock.getElapsedTime().asSeconds();

	}

	return 0;
}