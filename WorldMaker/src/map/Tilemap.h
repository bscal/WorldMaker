#pragma once

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

using namespace sf;

struct Tile {
	int id, faction;

	Tile(const int& id = 0, const int& faction = 0)
	: id(id), faction(faction) {}
};

class Tilemap {
public:
	const Color LAND = Color::White;
	const Color WATER = Color::Blue;
private:
	Sprite m_sprite;
	Texture m_texture;

	Image m_image;

	std::vector<Tile> m_tileList;

	const int m_tileWidth = 1, m_tileHeight = 1;
	int m_width, m_height;
public:
	Tilemap(const std::string& filename);

	void parseImage();

	void update(const int& deltaTime);
	void render(sf::RenderWindow& window);

	Tile getTile(const int& x, const int& y) const;
	void setTile(const int& x, const int& y, const Tile& tile);

	inline const Image getImage() const { return m_image; }
	inline const int getWidth() const { return m_width; }
	inline const int getHeight() const { return m_height; }
};