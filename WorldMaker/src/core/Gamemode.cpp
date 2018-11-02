#include "Gamemode.h"

#include <iostream>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#include "nuklear/nuklear.h"
#include "nuklear/nuklear_sfml_gl2.h"

#include "ui/UIManager.h"

Gamemode::Gamemode()
	: map("assets/map.png"), objectManager()
{
	auto p0 = std::make_shared<Pawn>("Pawn 1");
	auto p1 = std::make_shared<Pawn>("Pawn 2");
	auto p2 = std::make_shared<Pawn>("Pawn 3");
	p0->initilize();
	p1->initilize();
	p2->initilize();

	auto f0 = std::make_shared<Faction>("Romans");
	f0->initilize();

	//std::cout << *f0 << std::endl;
}

Gamemode::~Gamemode()
{

}

void Gamemode::update(const int& deltaTime)
{
	map.update(deltaTime);
	objectManager.update(deltaTime);
	//std::cout << ObjectManager::getGameObjects().size() << std::endl;
}

void Gamemode::render(sf::RenderWindow& window)
{
	map.render(window);
	objectManager.render(window);

	if (nk_begin(UIManager::m_nuklearContex, "Debug1", nk_rect(50, 50, 230, 250),
		NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_TITLE)) {
		nk_window* win = nk_window_find(UIManager::m_nuklearContex, "Debug");
		nk_label(UIManager::m_nuklearContex, "Test", NK_TEXT_LEFT);
	}
	nk_end(UIManager::m_nuklearContex);
}
