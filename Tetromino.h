#pragma once
#include <vector>
#include "Square.h"

class Tetromino
{
public:
    Tetromino();
    ~Tetromino();

    std::vector<Square> individual_squares;
};