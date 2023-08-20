#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_BallShape.setRadius(5.f);
	m_BallShape.setPosition(m_Position);
}

sf::FloatRect Ball::getPosition()
{
	return m_BallShape.getGlobalBounds();
}

sf::CircleShape Ball::getShape()
{
	return m_BallShape;
}

float Ball::getXVelocity()
{
	return m_DirectionX;
}

void Ball::bounceSides()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::missTop()
{
	m_Position.x = 1280 / 2;
	m_Position.y = 360;
}

void Ball::missBottom()
{
	m_Position.x = 1280 / 2;
	m_Position.y = 360;
}

void Ball::hitBall()
{
	m_DirectionY = -m_DirectionY;
}

void Ball::update(sf::Time dt)
{
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();

	m_BallShape.setPosition(m_Position);
}