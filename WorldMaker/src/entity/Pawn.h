#pragma once

#include <string>
#include <SFML/Graphics.hpp>

const std::string DEFAULT_NAME = "Pawn";

/// Pawn is the base class for anything Object
/// being placed into the game. Must be made with
/// std::shared_ptr. 
///
/// Pawn does not contain any render or visual functionality. 
/// For that use Entity.
///
/// To add the Object to a game you need to create the shared_ptr
/// and then call initilize when you want that object
/// to come alive the game world.
class Pawn {
protected:
	unsigned int m_id;
	std::string m_name;
	bool m_living;
	bool m_enabled;
	sf::Vector2f m_position;

public:
	Pawn();
	Pawn(const std::string& name);
	Pawn(const std::string& name, const sf::Vector2f& pos);
	
	// Call this when you want the Object to be placed into
	// the game and updated.
	virtual void initilize();

	virtual void update(const int& deltaTime);
	virtual void render(sf::RenderWindow& window);

	friend std::ostream& operator<<(std::ostream& os, const Pawn& pawn);

	unsigned int getID() const { return m_id; }
	std::string getName() const { return m_name; }
	bool isLiving() const { return m_living; }
	bool isEnabled() const { return m_enabled; }
	sf::Vector2f getPosition() const { return m_position; }

	void setID(const unsigned int& val) { m_id = val; }
	void setName(const std::string& val) { m_name = val; }
	void setLiving(const bool& val) { m_living = val; }
	void setEnabled(const bool& val) { m_enabled = val; }
	void setPosition(const sf::Vector2f& val) { m_position = val; }

};