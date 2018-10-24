#include "Pawn.h"

#include <core/ObjectManager.h>

Pawn::Pawn()
{
}

Pawn::Pawn(const std::string& name)
	: Pawn(name, sf::Vector2f())
{}

Pawn::Pawn(const std::string& name, const sf::Vector2f& pos)
	: m_name(name), m_living(true), m_enabled(true), m_position(pos)
{}

void Pawn::initilize()
{
	m_id = ObjectManager::getNextID();
	ObjectManager::createObject(std::make_shared<Pawn>(*this));
}

void Pawn::update(const int& deltaTime)
{

}

void Pawn::render(sf::RenderWindow& window)
{

}

void Pawn::remove()
{
	ObjectManager::removeObject(m_id);
}

std::ostream& operator<<(std::ostream& os, const Pawn& pawn)
{
	os << "Pawn: " << pawn.getName() << " / " << pawn.getID() << " / " <<
		pawn.getPosition().x << ", " << pawn.getPosition().y << " / " << pawn.isEnabled();
	return os;
}
