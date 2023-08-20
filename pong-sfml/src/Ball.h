#pragma once
#include <SFML\Graphics.hpp>

class Ball
{
private:
	sf::Vector2f m_Position;
	sf::CircleShape m_BallShape;

	float m_Speed = 400;
	float m_DirectionX = 1.0f;
	float m_DirectionY = 1.0f;

public:
	Ball(float startX, float startY);

	sf::FloatRect getPosition();
	sf::CircleShape getShape();

	float getXVelocity();

	void bounceSides();
	
	void missTop();
	
	void missBottom();
	
	void hitBall();

	void update(sf::Time dt);

};

