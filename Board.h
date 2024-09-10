#pragma once
#include <vector>

const int WIDTH = 12;
const int HEIGHT = 25;
const int FRAMERATE = 60;

class Board
{
	const int width;
	const int height;

public:
	Board();
	~Board();

	std::vector<std::vector<int>> board;
};