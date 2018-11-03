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

	// Adds the object or faction into the game on next GameManager update.
	// 
	// Any object derived from Pawn can be added through this function.
	static void createObject(std::shared_ptr<Pawn> object);

	// Objects are removed during GameManager's update loop depending if they are
	// set to be living or not. Calling removeObject(...) will set isLiving to false.
	// Because of this it is faster to call Pawn's setLiving(false) manually.
	static void removeObject(const unsigned int& id);
	static void removeObject(const std::string& name);
	
	static std::shared_ptr<Pawn> getObject(const unsigned int& id);
	static std::shared_ptr<Pawn> getObject(const std::string& name);
	
	static std::shared_ptr<Faction> getFaction(const int& id);
	static std::shared_ptr<Faction> getFaction(const std::string& name);
	static std::shared_ptr<Faction> getFaction(const sf::Color& color);
	
	static unsigned int getNextID();
	static unsigned int getNextFactionID();

	static size_t getCurrentObjectID() { return m_objectIDCount; }
	static size_t getCurrentFactionID() { return m_factionIDCount; }
	static size_t getObjectCount() { return m_gameObjects.size(); }
	static size_t getFactionCount() { return m_factionList.size(); }
	static std::vector<std::shared_ptr<Pawn>> getGameObjects() { return m_gameObjects; }
	static std::vector<std::shared_ptr<Faction>> getFactionList() { return m_factionList; }
};

