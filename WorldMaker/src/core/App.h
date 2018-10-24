#pragma once

#include <SFML/Graphics.hpp>

#include "core/Gamemode.h"

using namespace sf;

class App {
public:
	// Time for updates in microseconds
	const Int64 m_delta = 1000000 / 20 - 1000;
	int m_updatesPerSec = 0, m_framesPerSec = 0;

private:
	// All the modules of features step from here
	RenderWindow* m_window;
	Gamemode* m_gamemode;

public:
	App();
	~App();

	// Starts the App. Main game loop
	void loop();
	void update(const int& deltaTime);
	void render();

	inline RenderWindow* getWindow() const { return m_window; }
	inline const Gamemode& getGamemode() const { return *m_gamemode; }

private:
	const bool initWindow();
	const bool initGamemode();
};