#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Gameplay {

    class Paddle
    {
    private:
        RectangleShape paddle_sprite;
        const float paddleSpeed = 0.5f;

        const float paddle_width = 20.0f;
        const float paddle_height = 140.0f;

        void movePaddle(bool move_up_key_pressed, bool move_down_key_pressed);

    public:
        Paddle(float position_x, float position_y);
        void update(bool move_up_key_pressed, bool move_down_key_pressed);
        void render(RenderWindow* game_window);

    };
    

}
