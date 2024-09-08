#pragma once
#include <vector>
#include "BoardInformation.h"

class Board
{
	const int width;
	const int height;

public:
	Board();
	~Board();

	std::vector<std::vector<int>> board;
};