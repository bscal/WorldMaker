#pragma once

#include <SFML/Graphics.hpp>

#include "map/Tilemap.h"
#include "core/ObjectManager.h"

class Gamemode {
private:
	Tilemap map;
	ObjectManager objectManager;
public:
	Gamemode();
	~Gamemode();

	void update(const int& deltaTime);
	void render(sf::RenderWindow& window);
};