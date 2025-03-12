#include "../../Header/Gameplay/GameplayManager.h"


using namespace sf;
using namespace Gameplay;

namespace Gameplay {

	GameplayManager::GameplayManager(EventManager* manager) {

		time_service = new TimeService();
		time_service->initialize();// Start our time tracking

		event_manager = manager;
		boundary = new Boundary();
	}
	
	void GameplayManager::initialize() {
		
		ball = new Ball();
		player1 = new Paddle(player1_position_x, player1_position_y);
		player2 = new Paddle(player2_postion_x, player2_postion_y);
	}
	void GameplayManager::update() {
		
		    time_service->update();

		    ball->update(player1,player2);  // Call Ball's update function

			player1->update(event_manager->isKeyPressed(Keyboard::W),
				event_manager->isKeyPressed(Keyboard::S));

			player2->update(event_manager->isKeyPressed(Keyboard::Up),
				event_manager->isKeyPressed(Keyboard::Down));

	
	}
	void GameplayManager::render(RenderWindow* game_window)
	{
	
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
	}

}