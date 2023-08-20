#include <iostream>
#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "PlayerOne.h"
#include "PlayerTwo.h"

int main()
{
	sf::VideoMode VM(1280, 720);
	sf::RenderWindow window(VM, "Pong SFML");
	sf::Clock clock;
	Ball playerBall(1280 / 2, 0);
	PlayerOne playerOne(1280 / 2, 700);
	PlayerTwo playerTwo(1280 / 2, 20);

	sf::Time dt;

	while (window.isOpen())
	{
		dt = clock.restart();
		
		//Window
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		//Collision
		if (playerBall.getPosition().intersects(playerOne.getPosition()))
		{
			playerBall.hitBall();
		}
		if (playerBall.getPosition().intersects(playerTwo.getPosition()))
		{
			playerBall.hitBall();
		}

		//PlayerBall
		if (playerBall.getPosition().left < 0 || playerBall.getPosition().left + playerBall.getPosition().width > 1280)
		{
			playerBall.bounceSides();
		}

		if (playerBall.getPosition().top < 0)
		{
			playerBall.missTop();
		}

		if (playerBall.getPosition().top + playerBall.getPosition().height > 720)
		{
			playerBall.missBottom();
		}

		//PlayerOne
		if (playerOne.getPosition().left < 0 || playerOne.getPosition().left + playerOne.getPosition().width > 1280)
		{
			playerOne(playerOne.getPosition().x, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			playerOne.moveLeft();
		}
		else
		{
			playerOne.stopLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			playerOne.moveRight();
		}
		else
		{
			playerOne.stopRight();
		}

		//PlayerTwo
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			playerTwo.moveLeft();
		}
		else
		{
			playerTwo.stopLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			playerTwo.moveRight();
		}
		else
		{
			playerTwo.stopRight();
		}

		window.clear();

		playerBall.update(dt);
		playerOne.update(dt);
		playerTwo.update(dt);

		window.draw(playerBall.getShape());
		window.draw(playerOne.getShape());
		window.draw(playerTwo.getShape());
		
		window.display();
	}
}