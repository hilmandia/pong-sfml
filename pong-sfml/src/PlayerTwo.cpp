#include "PlayerTwo.h"
#include <SFML\Graphics.hpp>

PlayerTwo::PlayerTwo(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_PlayerTwoShape.setSize(sf::Vector2f(50, 5));
	m_PlayerTwoShape.setPosition(m_Position);
}

sf::FloatRect PlayerTwo::getPosition()
{
	return m_PlayerTwoShape.getGlobalBounds();
}

sf::RectangleShape PlayerTwo::getShape()
{
	return m_PlayerTwoShape;
}

void PlayerTwo::moveLeft()
{
	m_MoveLeft = true;
}

void PlayerTwo::stopLeft()
{
	m_MoveLeft = false;
}

void PlayerTwo::moveRight()
{
	m_MoveRight = true;
}

void PlayerTwo::stopRight()
{
	m_MoveRight = false;
}

void PlayerTwo::update(sf::Time dt)
{
	if (m_MoveLeft)
		m_Position.x += m_Speed * dt.asSeconds();
	if (m_MoveRight)
		m_Position.x -= m_Speed * dt.asSeconds();

	m_PlayerTwoShape.setPosition(m_Position);
}