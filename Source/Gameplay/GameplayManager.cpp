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
		
		    UpdateScore();
		    time_service->update();

		    ball->update(player1,player2 ,time_service);  // Call Ball's update function

			player1->update(event_manager->isKeyPressed(Keyboard::W),
				event_manager->isKeyPressed(Keyboard::S), time_service);

			player2->update(event_manager->isKeyPressed(Keyboard::Up),
				event_manager->isKeyPressed(Keyboard::Down), time_service);

	
	}
	void GameplayManager::render(RenderWindow* game_window)
	{
	
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
		ui_service->render(game_window);
	}
	void GameplayManager::UpdateScore() {
		// Left side out - Player 2 scores!
		if (ball->isLeftCollisionOccurred()) {
			ui_service->incrementPlayer2Score();
			ball->updateLeftCollisionState(false);
			resetPlayers();  // You'll implement it next
		}

		// Right side out - Player 1 scores!
		if (ball->isRightCollisionOccurred()) {
			ui_service->incrementPlayer1Score();
			ball->updateRightCollisionState(false);
			resetPlayers();  // You'll implement it next
		}
	}
	void GameplayManager::resetPlayers() {
		player1->reset(player1_position_x, player1_position_y);
		player2->reset(player2_postion_x, player2_postion_y);
	}

}