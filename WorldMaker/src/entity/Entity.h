#pragma once

#include <SFML/Graphics.hpp>

#include "entity/Pawn.h"

/*
	Entity is meant to expand Pawn to include
	visual and rendering functions. Not to be used
	to create own GameObjects or Pawns.

	Has basic physics.
*/
class Entity : public Pawn {
private:
	sf::Sprite m_sprite;
	sf::Color m_color;
	bool m_visible;
	sf::Vector2f m_velocity;

public:
	Entity();
	Entity(const std::string& name);
	Entity(const std::string& name, const sf::Vector2f& pos);
	Entity(const std::string& name, const sf::Vector2f& pos, const sf::Sprite& sprite);

	virtual void render(sf::RenderWindow& window) override;

	sf::Sprite getSprite() const { return m_sprite; }
	sf::Color getColor() const { return m_color; }
	bool isVisible() const { return m_visible; }
	sf::Vector2f getVelocity() const { return m_velocity; }
	
	void setSprite(sf::Sprite val) { m_sprite = val; }
	void setColor(sf::Color val) { m_color = val; }
	void setVisibility(bool val) { m_visible = val; }
	void setVelocity(sf::Vector2f val) { m_velocity = val; }
};