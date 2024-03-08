// Author: Mitch Barnett
// Created: April 2016

#include "Player.h"

// Creates a player object that can be controlled by a user
Player::Player()
{
	// Set initial values
	m_iMoves = 0;
	m_iLivesLeft = 3;
	m_rectBox.setSize(sf::Vector2f(50, 50));

	// Load the player texture
	texPlayerTexture.loadFromFile("assets/textures/frog.png");
	m_rectBox.setTexture(&texPlayerTexture);

	// Set the origin to the center of the player for rotation purposes
	m_rectBox.setOrigin(m_rectBox.getSize().x / 2, m_rectBox.getSize().y / 2);
}

int Player::getLivesLeft() {return m_iLivesLeft;}

int Player::getMovesTaken() {return m_iMoves;}

void Player::loseLife() {m_iLivesLeft--;}


void Player::moveLeft()
{
	setPosition(getPosition()+ sf::Vector2f(-50,0));
	m_rectBox.setRotation(270);
}
void Player::moveRight()
{
	setPosition(getPosition() + sf::Vector2f(50, 0));
	m_rectBox.setRotation(90);
}
void Player::moveUp()
{
	setPosition(getPosition() + sf::Vector2f(0, -50));
	m_rectBox.setRotation(0);
}
void Player::moveDown()
{
	setPosition(getPosition() + sf::Vector2f(0, 50));
	m_rectBox.setRotation(180);
}

// Check if there is a key input corisponding to a movement (arrow keys)
// Check that the is not an active cooldown
// Check that after performing the move the player will be compltyly on the screen
// if all are true perform the move, increment the move counter variable, start the cooldown
void Player::checkMovement(sf::Event& event, sf::RenderWindow& window)
{
	sf::Time cooldown = sf::seconds(0.25f); // cooldown of 0.25 seconds
	if (event.type == sf::Event::KeyPressed &&  moveCooldownClock.getElapsedTime() > cooldown) // check for keypress and cooldown

	{
		if (event.key.code == sf::Keyboard::Left && onScreen(window, sf::Vector2f(-50, 0)))
		{
			moveLeft();
			moveCooldownClock.restart();
			m_iMoves++;
		}
		else if (event.key.code == sf::Keyboard::Right && onScreen(window, sf::Vector2f(50, 0)))
		{
			moveRight();
			moveCooldownClock.restart();
			m_iMoves++;
		}
		else if (event.key.code == sf::Keyboard::Up && onScreen(window, sf::Vector2f(0, -50)))
		{
			moveUp();
			moveCooldownClock.restart();
			m_iMoves++;
		}
		else if (event.key.code == sf::Keyboard::Down && onScreen(window, sf::Vector2f(0, 50)))
		{
			moveDown();
			moveCooldownClock.restart();
			m_iMoves++;
		}
	}
}

// Updates the players position
void Player::update(sf::Event& event, sf::RenderWindow& window)
{
	checkMovement(event, window);
}

//reset to inital values for game restart
void Player::reset()
{
	m_iLivesLeft = 3;
	m_iMoves = 0;
	setPosition(sf::Vector2f(375, 625));
	m_rectBox.setRotation(0);
}
