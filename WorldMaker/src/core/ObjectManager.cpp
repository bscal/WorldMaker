#include "ObjectManager.h"

#include <iostream>

unsigned int ObjectManager::m_objectIDCount;

unsigned int ObjectManager::m_factionIDCount;

std::vector<std::shared_ptr<Pawn>> ObjectManager::m_gameObjects;

std::vector<std::shared_ptr<Pawn>> ObjectManager::m_createList;

std::vector<std::shared_ptr<Faction>> ObjectManager::m_factionList;

void ObjectManager::initFactionList(const std::string& factionConfigPath)
{

}

/*
	Update
*/
void ObjectManager::update(const int& deltaTime)
{
	// Creates new entities needing to be added.
	if (m_createList.size() > 0) {
		for (auto pawn : m_createList) {
			m_gameObjects.push_back(pawn);
		}
		m_createList.shrink_to_fit();
	}

	// Deletes any entities that are not living.
	for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
		if (!m_gameObjects.at(i).get()->isLiving())
			m_gameObjects.erase(m_gameObjects.begin() + i);
	}

	// Updates the currently list of entities.
	for (auto pawn : m_gameObjects) {
		pawn->update(deltaTime);
	}
}

/*
	Render
*/
void ObjectManager::render(sf::RenderWindow& window)
{
	for (auto pawn : m_gameObjects) {
		pawn->render(window);
	}
}

void ObjectManager::createObject(std::shared_ptr<Pawn> object)
{
	auto factionObject = std::dynamic_pointer_cast<Faction>(object);
	if (factionObject != nullptr) {
		std::cout << "Faction made" << std::endl;
		m_factionList.push_back(factionObject);
	}
	else {
		std::cout << "Object made" << std::endl;
		m_createList.push_back(object);
	}
}

void ObjectManager::removeObject(const unsigned int& id)
{
	for (auto pawn : m_gameObjects) {
		if (pawn->getID() == id)
			pawn->setLiving(false);
	}
}

void ObjectManager::removeObject(const std::string& name)
{
	for (auto pawn : m_gameObjects) {
		if (pawn->getName() == name)
			pawn->setLiving(false);
	}
}


std::shared_ptr<Pawn> ObjectManager::getObject(const unsigned int& id)
{
	for (auto pawn : m_gameObjects) {
		if (pawn->getID() == id)
			return pawn;
	}
	return nullptr;
}

std::shared_ptr<Pawn> ObjectManager::getObject(const std::string& name)
{
	for (auto pawn : m_gameObjects) {
		if (pawn->getName() == name)
			return pawn;
	}
	return nullptr;
}

std::shared_ptr<Faction> ObjectManager::getFaction(const int& id)
{
	for (auto faction : m_factionList) {
		if (faction->getID() == id)
			return faction;
	}
	return nullptr;
}

std::shared_ptr<Faction> ObjectManager::getFaction(const std::string& name)
{
	for (auto faction : m_factionList) {
		if (faction->getName() == name)
			return faction;
	}
	return nullptr;
}

std::shared_ptr<Faction> ObjectManager::getFaction(const sf::Color& color)
{
	for (auto faction : m_factionList) {
		if (faction->getFactionColor() == color)
			return faction;
	}
	return nullptr;
}

unsigned int ObjectManager::getIDCount()
{
	return m_objectIDCount;
}

unsigned int ObjectManager::getNextID()
{
	return m_objectIDCount++;
}

unsigned int ObjectManager::getNextFactionID()
{
	return m_factionIDCount++;
}
