#pragma once

#include "entity/Entity.h"

class City : public Entity {
private:
	unsigned int m_level;
	unsigned int m_population;

public:
	City(const std::string& name, const sf::Vector2f& pos, const sf::Sprite& sprite);

	virtual void update(const int& deltaTime) override;

	unsigned int getLevel() const { return m_level; }
	unsigned int getPopulation() const { return m_population; }

	void setLevel(unsigned int val) { m_level = val; }
	void setPopulation(unsigned int val) { m_population = val; }

	friend std::ostream& operator<<(std::ostream& os, const City& city);
};