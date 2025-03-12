#include"../../Header/UI/UIService.h"


using namespace UI;

namespace UI {

	void UIService::loadFontTexture()
	{
		font.loadFromFile(texture_path);
	}
	void UIService::createLeftScoreText()
	{
		left_score_text.setFont(font);
		left_score_text.setString(initial_string);
		left_score_text.setCharacterSize(font_size);
		left_score_text.setFillColor(font_color);
		left_score_text.setPosition(left_score_postion_x, left_score_postion_y);
	}
	void UIService::render(RenderWindow* game_window)
	{
		game_window->draw(left_score_text);
	}
	string UIService::formatScore(int score)
	{
		return (score < 10 ? "0" : "") + to_string(score);
	}
	void UIService::incrementPlayer1Score()
	{
		player1_score++;
	}

	void UIService::incrementPlayer2Score()
	{
		player2_score++;
	}
	void UIService::update()
	{
		left_score_text.setString(formatScore(player1_score));
		right_score_text.setString(formatScore(player2_score));
	}
}