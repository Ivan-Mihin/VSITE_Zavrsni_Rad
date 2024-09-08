#include "Board.h"

Board::Board() : width(WIDTH), height(HEIGHT)
{
    board.resize(height, std::vector<int>(width, 0));
}

Board::~Board() {}