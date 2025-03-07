// main.cpp

#include "../../Header/Core/GameWindowManager.h"
#include"../../Header/Event/EventManager.h"

int main() {
	// Create our window manager instance
	Core::GameWindowManager gameWindowManager;
	Event::EventManager eventManager;

	// Initialize the window
	gameWindowManager.initialize();

	while (gameWindowManager.isGameRunning()) {
		gameWindowManager.render();
		eventManager.pollEvents(gameWindowManager.getGameWindow());
		gameWindowManager.render();
	}
	
	return 0;
	
}