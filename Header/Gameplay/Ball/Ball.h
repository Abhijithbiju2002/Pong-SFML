#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Gameplay/Paddle/Paddle.h"
#include"../../Header/Gameplay/Utility/TimeService.h"
#include "../../Header/Sound/SoundManager.h"


using namespace sf;
using namespace std;
using namespace Utility;
using namespace Sound;

namespace Gameplay
{
    enum class BallState
    {
        Idle,
        Moving
    };
    class Ball
    {
    private:
        
        Texture pong_ball_texture;
        const string texture_path = "Assets/Textures/Ball.png";

        float delay_duration = 2.0f;
        float elapsed_delay_time = 0.0f;

        BallState current_state;

        Sprite pong_ball_sprite;

        float ball_speed = 0.5f;
        Vector2f velocity = Vector2f(ball_speed, ball_speed);

        void move(TimeService* time_service);
        void updateDelayTime(float deltaTime);

        const float scale_x = 0.2f;
        const float scale_y = 0.2f;

        const float position_x = 615.0f;
        const float position_y = 325.0f;

        bool had_left_collison = false;
        bool had_right_collison = false;

        void loadTexture();
        void initializeVariables();

    public:

        Ball();

        void update(Paddle* player1, Paddle* player2, TimeService* time_service);
        void render(RenderWindow* game_window);

        void handlePaddleCollision(Paddle* player1, Paddle* player2);
        void handleOutofBoundCollision();
        void reset();
        void onCollision(Paddle* player1, Paddle* player2);
        void handleBoudaryCollision();

        bool isLeftCollisionOccurred();
        void updateLeftCollisionState(bool value);

        bool isRightCollisionOccurred();
        void updateRightCollisionState(bool value);

        const float top_boundary = 20.0f;
        const float bottom_boundary = 700.0f;

        const float left_boundary = 0.0f;
        const float right_boundary = 1280.0f;

        //Center Position
        const float center_position_x = 615.0f;
        const float center_position_y = 325.0f;
    };
}