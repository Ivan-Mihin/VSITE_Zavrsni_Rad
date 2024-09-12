#pragma once
#include <vector>

const int WIDTH = 12;
const int HEIGHT = 25;
const int FRAMERATE = 60;
const int BOARD_POSITION_X = 200;
const int BOARD_POSITION_Y = 25;

class Board
{
	const int width;
	const int height;

public:
	Board();
	~Board();

	std::vector<std::vector<int>> board;
};