#pragma once

#include <SFML/Graphics.hpp>

#include "entity/Entity.h"

enum Goal {
	None, Travel, Settle, Explore, Work
};

class Citizen : public Entity {
public:
	int m_age = 1;
	float m_speed = 1.0f;

private:
	int m_faction;
	Goal m_goal;

public:
	Citizen(const sf::Vector2f& pos, const sf::Sprite& sprite, const int& faction);
	Citizen(const std::string& name, const sf::Vector2f& pos, const sf::Sprite& sprite, const int& faction);

	virtual void update(const int& deltaTime) override;

	inline int getGoal() const { return m_goal; }
	inline int getAge() const { return m_age; }

private:
	sf::Vector2f processPathfinding();
	void move();
};