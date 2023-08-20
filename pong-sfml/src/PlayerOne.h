#pragma once
#include <SFML\Graphics.hpp>

class PlayerOne
{
private:
	sf::Vector2f m_Position;
	sf::RectangleShape m_PlayerOneShape;

	float m_Speed = 1000;
	bool m_MoveLeft = false;
	bool m_MoveRight = false;

public:
	PlayerOne(float startX, float startY);

	sf::RectangleShape getShape();
	sf::FloatRect getPosition();

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	
	void update(sf::Time dt);

};

