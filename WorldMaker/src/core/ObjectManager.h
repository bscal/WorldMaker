#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "entity/Pawn.h"
#include "entity/faction/Faction.h"

class ObjectManager {
private:
	static unsigned int m_objectIDCount;
	static unsigned int m_factionIDCount;

	static std::vector<std::shared_ptr<Pawn>> m_gameObjects;
	static std::vector<std::shared_ptr<Pawn>> m_createList;
	
	static std::vector<std::shared_ptr<Faction>> m_factionList;

public:
	void initFactionList(const std::string& factionConfigPath);

	void update(const int& deltaTime);
	void render(sf::RenderWindow& window);

	// Adds the object into the game on next GameManager update.
	// 
	// Any object derived from Pawn can be added through this function.
	static void createObject(std::shared_ptr<Pawn> object);

	// Removes object on next GameManager update.
	static void removeObject(const unsigned int& id);
	static void removeObject(const std::string& name);

	static std::shared_ptr<Pawn> getObject(const unsigned int& id);
	static std::shared_ptr<Pawn> getObject(const std::string& name);

	static std::shared_ptr<Faction> getFaction(const int& id);
	static std::shared_ptr<Faction> getFaction(const std::string& name);
	static std::shared_ptr<Faction> getFaction(const sf::Color& color);

	static unsigned int getIDCount();
	static unsigned int getNextID();
	static unsigned int getNextFactionID();
	static std::vector<std::shared_ptr<Pawn>> getGameObjects() { return m_gameObjects; }
	static std::vector<std::shared_ptr<Faction>> getFactionList() { return m_factionList; }
};

