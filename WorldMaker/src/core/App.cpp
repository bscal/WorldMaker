#include "App.h"

#include <iostream>

App::App()
{
	// Creates RenderWindow
	initWindow();

	// Starts Gamemode
	initGamemode();
}

App::~App()
{
	delete m_gamemode;
	delete m_window;
}

void App::loop()
{
	sf::Clock deltaClock;
	sf::Clock perSecondClock;

	while (m_window->isOpen()) {
		sf::Event event;
		while (m_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				m_window->close();
				//TODO event handler
		}

		if (deltaClock.getElapsedTime().asMicroseconds() > m_delta) {
			update(deltaClock.restart().asMilliseconds());
		}

		if (perSecondClock.getElapsedTime().asSeconds() > 1) {
			std::cout << "~~~ Updates/Sec: " << m_updatesPerSec << " Frames/Sec: " << m_framesPerSec << " ~~~" << std::endl;
			m_updatesPerSec = m_framesPerSec = 0;
			perSecondClock.restart();
		}

		render();
		
		m_framesPerSec++;
	}
}

void App::update(const int& deltaTime)
{
	m_updatesPerSec++;
	m_gamemode->update(deltaTime);
}

void App::render()
{
	m_window->clear();
	// Put render calls here
	m_gamemode->render(*m_window);
	m_window->display();
}

const bool App::initWindow()
{
	m_window = new sf::RenderWindow(sf::VideoMode(1200, 700), "SFML works!");
	m_window->setFramerateLimit(60);
	return true;
}

const bool App::initGamemode()
{
	m_gamemode = new Gamemode();
	return true;
}
