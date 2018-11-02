#pragma once

#include <SFML/Graphics.hpp>

#include "core/Gamemode.h"

class App {
public:
	// Time for updates in microseconds
	const sf::Int64 m_DELTA = 1000000 / 20 - 2000;
	int m_updatesPerSec = 0, m_framesPerSec = 0;

private:
	sf::RenderWindow* m_window;
	Gamemode* m_gamemode;

	int m_updatesCount = 0, m_framesCount = 0;
public:
	App();
	~App();

	// Starts the App. Main game loop
	void loop();
	void update(const int& deltaTime);
	void render(sf::RenderWindow& windowReference);

	sf::RenderWindow& getWindow() const { return *m_window; }
	Gamemode* getGamemode() const { return m_gamemode; }

private:
	bool initWindow();
	bool initGamemode();

	void showPreformance();
};