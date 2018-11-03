#include "Faction.h"

#include "core/ObjectManager.h"


Faction::Faction(const std::string& name)
	: Pawn(name), m_population(20), m_cityCount(1)
{
}

void Faction::initilize()
{
	m_id = ObjectManager::getNextFactionID();
	ObjectManager::createObject(std::make_shared<Faction>(*this));
}

void Faction::update(const int& deltaTime)
{
}

std::ostream& operator<<(std::ostream& os, const Faction& faction)
{
	os << faction.m_name << " / " << faction.m_population
		<< " / " << faction.m_cityCount;
	return os;
}
