#include "Tilemap.h"

#include <iostream>

using namespace sf;

Tilemap::Tilemap(const std::string& filename)
	: m_image(sf::Image()), m_texture(sf::Texture()), m_tileList()
{
	// Loads map from file to Image
	if (!m_image.loadFromFile(filename)) {
		std::cout << "Error: Image could not be loaded from file -> " << filename << std::endl;
	}

	// Sets width height from loaded Image
	m_width = m_image.getSize().x;
	m_height = m_image.getSize().y;

	// Creates texture for map in game from Image
	if (!m_texture.loadFromImage(m_image)) {
		std::cout << "Error: Texture could not be created from Image" << std::endl;
	}

	// Creates Tile List
	m_tileList.reserve(m_width * m_height);

	// THIS IS A TEST TO MAKE SURE EACH TILE IS WORKING REMOVE LATER
	int i = 0;

	int pixelType = 0;
	int factionID = 0;

	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			sf::Color pixelColor = m_image.getPixel(x, y);
			if (pixelColor == WATER) {
				pixelType = 1;
			}
			else {
				pixelType = 2;
				if (pixelColor != LAND) {
					factionID = 0; //TODO get Faction ID by color;
				}
			}
			m_tileList.push_back(Tile(i++));
		}
	}

	m_texture.update(m_image);
	// Creates Sprite
	m_sprite = sf::Sprite(m_texture, sf::IntRect(0, 0, m_width, m_height));
}

void Tilemap::parseImage()
{
	
}

void Tilemap::render(sf::RenderWindow& window) {
	window.draw(m_sprite);
}

Tile Tilemap::getTile(const int& x, const int& y) const
{
	return m_tileList[x + y * m_width];
}

void Tilemap::setTile(const int& x, const int& y, const Tile& tile)
{
	m_tileList[x + y * m_width] = tile;
}

void Tilemap::update(const int& deltaTime) {

}

