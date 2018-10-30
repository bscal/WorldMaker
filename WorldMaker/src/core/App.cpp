#include "App.h"

#include <iostream>
#include <SFML/OpenGL.hpp>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_SFML_GL2_IMPLEMENTATION
#include "nuklear/nuklear.h"
#include "nuklear/nuklear_sfml_gl2.h"

#define DEBUG_CONSOLE 1


App::App()
{
	// Creates RenderWindow
	initWindow();

	// Starts Gamemode
	initGamemode();
}

App::~App()
{
	nk_sfml_shutdown();
	delete m_gamemode;
	delete m_window;
}

void App::loop()
{
	sf::Clock deltaClock;
	sf::Clock perSecondClock;

	/* Stores a reference to m_window so we do not need to dereference constantly */
	sf::RenderWindow& windowReference = *m_window;

	/* Setup and Initialization of Nuklear SFML library */
	m_nuklearContex = nk_sfml_init(m_window);
	/* Load Fonts: if none of these are loaded a default font will be used  */
	/* Load Cursor: if you uncomment cursor loading please hide the cursor */
	struct nk_font_atlas *atlas;
	nk_sfml_font_stash_begin(&atlas);
	nk_sfml_font_stash_end();

	while (windowReference.isOpen()) {
		sf::Event event;
		nk_input_begin(m_nuklearContex);
		while (windowReference.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				windowReference.close();
				//TODO event handler
			nk_sfml_handle_event(&event);
		}
		nk_input_end(m_nuklearContex);

		if (deltaClock.getElapsedTime().asMicroseconds() > m_DELTA)
			update(deltaClock.restart().asMilliseconds());

		if (perSecondClock.getElapsedTime().asSeconds() > 1) {
			m_updatesPerSec = m_updatesCount;
			m_framesPerSec = m_framesCount;
			m_updatesCount = m_framesCount = 0;
			perSecondClock.restart();
		}

		render(windowReference);
	}
}

void App::update(const int& deltaTime)
{
	m_updatesCount++;
	m_gamemode->update(deltaTime);
}

void App::render(sf::RenderWindow& windowReference)
{
	windowReference.clear();

	/*
	* ===================
	*  Render Calls Here 
	* ===================
	*/

	showPreformance();

	// Renders all objects
	m_gamemode->render(windowReference);
	// Saves GLState for GUI rendering
	windowReference.pushGLStates();
	// Renders Nuklear GUI
	nk_sfml_render(NK_ANTI_ALIASING_ON);
	// Restores State
	windowReference.popGLStates();

	windowReference.display();

	m_framesCount++;
}

bool App::initWindow()
{
	m_window = new RenderWindow(sf::VideoMode(1200, 700), "SFML works!");
	m_window->setVerticalSyncEnabled(false);
	m_window->setFramerateLimit(60);
	return true;
}

bool App::initGamemode()
{
	m_gamemode = new Gamemode();
	return true;
}

void App::showPreformance()
{
#if DEBUG_CONSOLE
	if (nk_begin(m_nuklearContex, "Debug", nk_rect(50, 50, 230, 250),
		NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_TITLE)) {
		nk_layout_row_static(m_nuklearContex, 30, 180, 1);
		std::string updates("Updates/Sec: " + std::to_string(m_updatesPerSec));
		std::string renders("Frames/Sec: " + std::to_string(m_framesPerSec));
		std::string msPerFrame("MS/Frame: " + std::to_string((float) 1000.0f / m_framesPerSec));

		nk_label(m_nuklearContex, updates.c_str(), NK_TEXT_LEFT);
		nk_label(m_nuklearContex, renders.c_str(), NK_TEXT_LEFT);
		nk_label(m_nuklearContex, msPerFrame.c_str(), NK_TEXT_LEFT);
	}
	nk_end(m_nuklearContex);
#endif // DEBUG
}
