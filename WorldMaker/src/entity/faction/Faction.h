#pragma once

#include <string>
#include "SFML/Graphics.hpp"

#include "entity/Pawn.h"

class Faction : public Pawn {
private:
	sf::Color m_factionColor;

public:
	unsigned int m_population;
	unsigned int m_cityCount;

public:
	Faction(const std::string& name);

	virtual void update(const int& deltaTime) override;
	
	sf::Color getFactionColor() const { return m_factionColor; }
	void setFactionColor(const sf::Color& color) { m_factionColor = color; }

	friend std::ostream& operator<<(std::ostream& os, const Faction& faction);
};