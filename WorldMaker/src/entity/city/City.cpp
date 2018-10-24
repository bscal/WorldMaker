#include "City.h"



City::City(const std::string& name, const sf::Vector2f& pos, const sf::Sprite& sprite)
	: Entity(name, pos, sprite)
{
}

void City::update(const int& deltaTime)
{

}

std::ostream& operator<<(std::ostream& os, const City& city)
{
	os << city.getName() << " / " << city.getPopulation();
	return os;
}
