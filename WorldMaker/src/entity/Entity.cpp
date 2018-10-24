#include "Entity.h"



Entity::Entity()
{}

Entity::Entity(const std::string& name)
	: Entity(name, sf::Vector2f(0.f, 0.f))
{}

Entity::Entity(const std::string& name, const sf::Vector2f& pos)
	: Entity(name, pos, sf::Sprite())
{}

Entity::Entity(const std::string& name, const sf::Vector2f& pos, const sf::Sprite& sprite)
	: Pawn(name, pos), m_sprite(sprite), m_visible(true), m_velocity(sf::Vector2f(0.f, 0.f))
{}

void Entity::render(sf::RenderWindow& window)
{
	if (m_visible) {
		window.draw(m_sprite);
	}
}
