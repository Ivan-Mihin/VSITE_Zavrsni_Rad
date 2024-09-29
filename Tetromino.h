#pragma once
#include <functional>
#include <vector>
#include "audio.h"
#include "board.h"
#include "square.h"

enum class TetrominoShape
{
    Shape_I = 1,
    Shape_J = 2,
    Shape_L = 3,
    Shape_O = 4,
    Shape_S = 5,
    Shape_T = 6,
    Shape_Z = 7
};

enum class TetrominoColor
{
    Grey = 0,
    Red = 1,
    Orange = 2,
    Yellow = 3,
    Green = 4,
    Cyan = 5,
    Blue = 6,
    Purple = 7
};

class Tetromino 
{
private:
    TetrominoColor color;
    TetrominoShape shape;
    std::vector<std::vector<int>> shapeMatrix;
    std::vector<Square> squares;
    AudioMovement audioMovement;

    std::vector<std::vector<int>> rotateShapeMatrix();
    std::vector<Square> rotateSquaresPositions(std::vector<std::vector<Square>> temporarySquaresMatrix);
    std::vector<std::vector<Square>> setTemporarySquaresMatrix();

public:
    Tetromino() {}
    Tetromino(const Tetromino& tetrominoCopy);
    Tetromino& operator=(const Tetromino& other);

    TetrominoColor getColor() const;
    TetrominoShape getShape() const;
    std::vector<std::vector<int>> getShapeMatrix() const;
    std::vector<Square>& getSquares();

    void setColor(TetrominoColor color);
    void setShape(TetrominoShape shape);
    void setShapeMatrix(const std::vector<std::vector<int>>& shapeMatrix);
    void setSquares(const std::vector<Square>& squares);

    void hardDrop(std::function<bool(const std::vector<Square>&)> isValidPosition);
    void moveLeft();
    void moveRight();
    void rotate();
};