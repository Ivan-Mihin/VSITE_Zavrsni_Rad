#include "tetromino.h"

Tetromino::Tetromino(const Tetromino& tetrominoCopy)
{
    shape = tetrominoCopy.shape;
    shapeMatrix = tetrominoCopy.shapeMatrix;
    squares = tetrominoCopy.squares;
    color = tetrominoCopy.color;
}

std::vector<std::vector<int>> Tetromino::rotateShapeMatrix() 
{
    std::vector<std::vector<int>> rotatedMatrix(shapeMatrix.size(), std::vector<int>(shapeMatrix.size()));

    for (int i = 0; i < shapeMatrix.size(); i++) 
    {
        for (int j = 0; j < shapeMatrix[i].size(); j++)
        {
            rotatedMatrix[j][i] = shapeMatrix[i][j];
        }
    }

    for (int i = 0; i < rotatedMatrix.size(); ++i)
    {
        reverse(rotatedMatrix[i].begin(), rotatedMatrix[i].end());
    }
   
    return rotatedMatrix;
}

std::vector<Square> Tetromino::rotateSquaresPositions(std::vector<std::vector<Square>> temporarySquaresMatrix)
{
    std::vector<Square> rotatedSquares;

    for (int row = 0; row < shapeMatrix.size(); ++row)
    {
        for (int col = 0; col < shapeMatrix.size(); ++col)
        {
            if (shapeMatrix[row][col])
            {
                rotatedSquares.push_back(Square(temporarySquaresMatrix[row][col].getX(), temporarySquaresMatrix[row][col].getY()));
            }
        }
    }

    return rotatedSquares;
}

std::vector<std::vector<Square>> Tetromino::setTemporarySquaresMatrix()
{
    std::vector<std::vector<Square>> temporarySquaresMatrix(shapeMatrix.size(), std::vector<Square>(shapeMatrix[0].size(), Square(99, 99)));
    int index = 0;

    for (int row = 0; row < shapeMatrix.size(); ++row)
    {
        for (int col = 0; col < shapeMatrix.size(); ++col)
        {
            if (shapeMatrix[row][col])
            {
                temporarySquaresMatrix[row][col].setX(squares[index].getX());
                temporarySquaresMatrix[row][col].setY(squares[index].getY());

                index++;
            }
        }
    }

    int minX = 0;
    int minY = 0;

    if (shape == TetrominoShape::Shape_I)
    {
        if (temporarySquaresMatrix[1][1].getX() != 99 && temporarySquaresMatrix[1][1].getY() != 99)
        {
            minX = temporarySquaresMatrix[1][1].getX() - 1;
            minY = temporarySquaresMatrix[1][1].getY() - 1;
        }
        else if (temporarySquaresMatrix[1][2].getX() != 99 && temporarySquaresMatrix[1][2].getY() != 99)
        {
            minX = temporarySquaresMatrix[1][2].getX() - 2;
            minY = temporarySquaresMatrix[1][2].getY() - 1;
        }
        else if (temporarySquaresMatrix[2][2].getX() != 99 && temporarySquaresMatrix[2][2].getY() != 99)
        {
            minX = temporarySquaresMatrix[2][2].getX() - 2;
            minY = temporarySquaresMatrix[2][2].getY() - 2;
        }
        else if (temporarySquaresMatrix[2][1].getX() != 99 && temporarySquaresMatrix[2][1].getY() != 99)
        {
            minX = temporarySquaresMatrix[2][1].getX() - 1;
            minY = temporarySquaresMatrix[2][1].getY() - 2;
        }
    }
    else
    {
        minX = temporarySquaresMatrix[1][1].getX() - 1;
        minY = temporarySquaresMatrix[1][1].getY() - 1;
    }

    for (int row = 0; row < shapeMatrix.size(); ++row)
    {
        for (int col = 0; col < shapeMatrix.size(); ++col)
        {
            if (temporarySquaresMatrix[row][col].getX() == 99 && temporarySquaresMatrix[row][col].getY() == 99)
            {
                temporarySquaresMatrix[row][col].setX(minX + col);
                temporarySquaresMatrix[row][col].setY(minY + row);
            }
        }
    }

    return temporarySquaresMatrix;
}

TetrominoColor Tetromino::getColor() const
{
    return color;
}

TetrominoShape Tetromino::getShape() const
{
    return shape;
}

std::vector<std::vector<int>> Tetromino::getShapeMatrix() const
{
    return shapeMatrix;
}

std::vector<Square>& Tetromino::getSquares()
{
    return squares;
}

void Tetromino::setColor(TetrominoColor color)
{
    this->color = color;
}

void Tetromino::setShape(TetrominoShape shape) 
{
    this->shape = shape;
}

void Tetromino::setShapeMatrix(const std::vector<std::vector<int>>& shapeMatrix) 
{
    this->shapeMatrix = shapeMatrix;
}

void Tetromino::setSquares(const std::vector<Square>& squares) 
{
    this->squares = squares;
}

void Tetromino::hardDrop(Board board)
{
    std::vector<Square> nextPosition = squares;

    while (true)
    {
        for (int i = 0; i < 4; i++)
        {
            nextPosition[i].setY(squares[i].getY() + 1);
        }

        if (board.isValidPosition(nextPosition))
        {
            audioMovement.getSfxHardDrop().play();
            squares = nextPosition;
        }
        else
        {
            break;
        }
    }
}

void Tetromino::moveLeft() 
{
    for (int i = 0; i < 4; i++)
    {
        squares[i].setX(squares[i].getX() - 1);
    }
}

void Tetromino::moveRight() 
{
    for (int i = 0; i < 4; i++) 
    {
        squares[i].setX(squares[i].getX() + 1);
    }
}

void Tetromino::rotate()
{
    std::vector<std::vector<Square>> temporarySquaresMatrix = setTemporarySquaresMatrix();
    setShapeMatrix(rotateShapeMatrix());
    setSquares(rotateSquaresPositions(temporarySquaresMatrix));
}