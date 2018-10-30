#include "Gamemode.h"

#include <iostream>

Gamemode::Gamemode()
	: map("assets/map.png"), objectManager()
{
	auto p0 = std::make_shared<Pawn>("Pawn 1");
	auto p1 = std::make_shared<Pawn>("Pawn 2");
	auto p2 = std::make_shared<Pawn>("Pawn 3");
	p0->initilize();
	p1->initilize();
	p2->initilize();

	auto f0 = std::make_shared<Faction>("Romans");
	f0->initilize();

	//std::cout << *f0 << std::endl;
}

Gamemode::~Gamemode()
{

}

void Gamemode::update(const int& deltaTime)
{
	map.update(deltaTime);
	objectManager.update(deltaTime);
	//std::cout << ObjectManager::getGameObjects().size() << std::endl;
}

void Gamemode::render(sf::RenderWindow& window)
{
	map.render(window);
	objectManager.render(window);
}
