#include "UIManager.h"

#include <iostream>
#include <SFML/OpenGL.hpp>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT

/* Implementation are defined here once */
#define NK_IMPLEMENTATION
#define NK_SFML_GL2_IMPLEMENTATION
#include "nuklear/nuklear.h"
#include "nuklear/nuklear_sfml_gl2.h"

bool UIManager::m_initCalled = false;

struct nk_context* UIManager::m_nuklearContex;

void UIManager::init(sf::RenderWindow* window)
{
	/* Setup and Initialization of Nuklear SFML library */
	m_nuklearContex = nk_sfml_init(window);
	/* Load Fonts: if none of these are loaded a default font will be used  */
	/* Load Cursor: if you uncomment cursor loading please hide the cursor */
	struct nk_font_atlas *atlas;
	nk_sfml_font_stash_begin(&atlas);
	nk_sfml_font_stash_end();

	m_initCalled = true;
}

void UIManager::cleanup()
{
	nk_sfml_shutdown();
}

nk_context* UIManager::getNuklearContext()
{
	if (m_nuklearContex != nullptr && m_initCalled) {
		return m_nuklearContex;
	}
	std::cout << "Nuklear Context not initialized." << std::endl;
	return nullptr;
}
