#include "PlayerOne.h"
#include <SFML\Graphics.hpp>

PlayerOne::PlayerOne(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_PlayerOneShape.setSize(sf::Vector2f(50, 5));
	m_PlayerOneShape.setPosition(m_Position);
}

sf::FloatRect PlayerOne::getPosition()
{
	return m_PlayerOneShape.getGlobalBounds();
}

sf::RectangleShape PlayerOne::getShape()
{
	return m_PlayerOneShape;
}

void PlayerOne::moveLeft()
{
	m_MoveLeft = true;
}

void PlayerOne::stopLeft()
{
	m_MoveLeft = false;
}

void PlayerOne::moveRight()
{
	m_MoveRight = true;
}

void PlayerOne::stopRight()
{
	m_MoveRight = false;
}

void PlayerOne::update(sf::Time dt)
{
	if (m_MoveLeft)
		m_Position.x += m_Speed * dt.asSeconds();
	if (m_MoveRight)
		m_Position.x -= m_Speed * dt.asSeconds();

	m_PlayerOneShape.setPosition(m_Position);
}