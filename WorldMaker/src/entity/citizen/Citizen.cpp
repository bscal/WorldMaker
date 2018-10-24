#include "Citizen.h"





Citizen::Citizen(const sf::Vector2f& pos, const sf::Sprite& sprite, const int& faction)
	: Entity(std::string(), pos, sprite), m_faction(faction)
{
}

Citizen::Citizen(const std::string& name, const sf::Vector2f& pos, const sf::Sprite& sprite, const int& faction)
	: Entity(name, pos, sprite), m_faction(faction)
{
}

void Citizen::update(const int& deltaTime)
{
	processPathfinding();
	move();
}

sf::Vector2f Citizen::processPathfinding()
{
	return sf::Vector2f();
}

void Citizen::move()
{

}
