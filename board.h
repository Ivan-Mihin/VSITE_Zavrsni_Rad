#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "audio.h"
#include "manager_score.h"
#include "manager_combo.h"
#include "manager_difficulty.h"
#include "observer_combo.h"
#include "square.h"

class Board
{
private:
	std::vector<std::vector<int>> board;

	sf::RectangleShape outerRectangle;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Texture gameOverLineTexture;
	sf::Sprite gameOverLineSprite;

	float lockDelayRectangleStartX, lockDelayRectangleStartY, lockDelayRectangleEndX, lockDelayRectangleEndY;
	sf::RectangleShape lockDelayRectangle;

	int gameOverRow;

	AudioBoard audioBoard;
	AudioCombo audioCombo;

public:
	Board();

	int BOARD_ROWS = 25;
	int BOARD_COLUMNS = 12;

	std::vector<std::vector<int>>& getBoard();
	int getGameOverRow() const;
	void setGameOverRow(int value);

	void allClearCheck(ManagerScore* managerScore);
	void clearFullLines(ManagerScore* ms, ManagerCombo* mc, ObserverCombo* oc);
	void draw(sf::RenderWindow& window);
	bool isValidPosition(std::vector<Square> nextPosition);
	void resetLockDelayRectangle();
	void setColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void setGameOverRowBasedOnTime(ManagerDifficulty* managerDifficulty);
};