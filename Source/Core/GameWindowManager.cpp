#include "../../Header/Core/GameWindowManager.h"

namespace Core {

	void GameWindowManager::initialize() {
		// Allocate memory for the render window object
		game_window = new RenderWindow();
		// Set up the window with configured properties
		createGameWindow();
	}
	void GameWindowManager::createGameWindow() {
		// Create the window with specified dimensions and title
		game_window-> create(
			sf::VideoMode::getDesktopMode(),// Get screen resolution
			game_title ,   // Window title
		    sf::Style::Fullscreen   // Fullscreen mode
		);
		
	}
	bool GameWindowManager::isGameRunning() {
		// Return true if window is open, false if closed
		return game_window->isOpen();
	}
	void GameWindowManager::clearGameWindow() {

		// Clear window with orange color (R:200, G:50, B:50, A:255)
		game_window->clear();
		//draw shapes, sprites, etc 
	}
	void GameWindowManager::displayGameWindow() {

		// Display the changes
		game_window->display();
	}
	
	RenderWindow* GameWindowManager::getGameWindow() {
		return game_window;
	}

}