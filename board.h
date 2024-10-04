#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "audio.h"
#include "lock_delay.h"
#include "manager_difficulty.h"
#include "manager_score.h"
#include "square.h"

struct GameOverLine
{
	int row;
	sf::Texture texture;
	sf::Sprite sprite;

	int getRow() const;
	void setRow(ManagerDifficulty* managerDifficulty);
};

class Board
{
private:
	std::vector<std::vector<int>> board;

	// Draw
	sf::RectangleShape outerRectangle;
	sf::Texture texture_Board;
	sf::Sprite sprite_Board;

	GameOverLine gameOverLine;
	LockDelay lockDelay;
	AudioBoard audio_Board;
	AudioCombo audio_Combo;

public:
	Board();

	const int BOARD_ROWS = 25;
	const int BOARD_COLUMNS = 12;

	bool noLinesCleared;

	void allClearCheck(ManagerScore* managerScore);
	void clearFullLines(ManagerScore* managerScore);
	void draw(sf::RenderWindow& window);
	std::vector<std::vector<int>>& getBoard();
	bool isValidPosition(std::vector<Square> nextPosition);

	int getGameOverLineRow() const;
	void setGameOverLineRow(ManagerDifficulty* managerDifficulty);

	void resetLockDelayRectangle();
	void setLockDelayRectangle(float t, float currentValue);
	void setLockDelayColor(sf::Color color);
};