#pragma once

#include <SFML/Graphics.hpp>

class UIManager {
private:
	static bool m_initCalled;
public:
	static struct nk_context* m_nuklearContex;

	/* 
		Initializes the nuklear context with our current window context.
		Status will be set to 1 when init is called.
	*/
	static void init(sf::RenderWindow* window);

	/* Cleanups up the current nuklear context and free memory */
	static void cleanup();

	/* Gets the context safely */
	static nk_context* getNuklearContext();
};