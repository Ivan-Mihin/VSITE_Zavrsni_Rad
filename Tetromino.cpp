#include "tetromino.h"

// Tetromino Class Implementation
void Tetromino::setShape(TetrominoShape shape) 
{
    this->shape = shape;
}

void Tetromino::setShapeMatrix(const std::vector<std::vector<int>>& shapeMatrix) 
{
    this->shapeMatrix = shapeMatrix;
}

TetrominoShape Tetromino::getShape() const 
{
    return shape;
}

std::vector<std::vector<int>> Tetromino::getShapeMatrix() const 
{
    return shapeMatrix;
}

void Tetromino::print() const 
{
    for (const auto& row : shapeMatrix) 
    {
        for (int cell : row) 
        {
            std::cout << (cell ? "#" : " ");
        }
        std::cout << std::endl;
    }
}

// TetrominoBuilder Class Implementation
void TetrominoBuilder::createNewTetromino() 
{
    tetromino = new Tetromino();
}

Tetromino* TetrominoBuilder::getTetromino() 
{
    return tetromino;
}

void IShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_I);
}

// IShapeBuilder Implementation
void IShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
        });
}

void JShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_L);
}

// JShapeBuilder Implementation
void JShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
        });
}

void LShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_L);
}

// LShapeBuilder Implementation
void LShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
        });
}

void OShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_O);
}

// OShapeBuilder Implementation
void OShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {1, 1},
        {1, 1}
        });
}

void SShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_S);
}

// SShapeBuilder Implementation
void SShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {0, 1, 1},
        {1, 1, 0},
        {0, 0, 0}
        });
}

void TShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_T);
}

// TShapeBuilder Implementation
void TShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 0}
        });
}

void ZShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_Z);
}

// ZShapeBuilder Implementation
void ZShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {1, 1, 0},
        {0, 1, 1},
        {0, 0, 0}
        });
}

// TetrominoDirector Implementation
Tetromino* TetrominoDirector::createTetromino(TetrominoBuilder& builder) 
{
    builder.createNewTetromino();
    builder.setShape();
    builder.buildShapeMatrix();
    return builder.getTetromino();
}