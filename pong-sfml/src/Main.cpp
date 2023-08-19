#include <iostream>
#include <SFML\Graphics.hpp>
#include "Ball.h"

int main()
{
	sf::VideoMode VM(1280, 720);
	sf::RenderWindow window(VM, "Pong SFML");
	sf::Clock clock;
	Ball playerBall(1280 / 2, 0);

	sf::Time dt;

	while (window.isOpen())
	{
		dt = clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		if (playerBall.getPosition().left < 0 || playerBall.getPosition().left + playerBall.getPosition().width > 1280)
		{
			playerBall.bounceSides();
		}

		if (playerBall.getPosition().top < 0)
		{
			playerBall.bounceTop();
		}

		if (playerBall.getPosition().top + playerBall.getPosition().height > 720)
		{
			playerBall.missBottom();
		}


		window.clear();
		playerBall.update(dt);
		window.draw(playerBall.getShape());	
		window.display();
	}
}