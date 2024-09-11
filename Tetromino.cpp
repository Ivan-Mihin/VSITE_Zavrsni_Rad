#include "tetromino.h"

void Tetromino::setShape(TetrominoShape shape) 
{
    this->shape = shape;
}

void Tetromino::setShapeMatrix(const std::vector<std::vector<int>>& shapeMatrix) 
{
    this->shapeMatrix = shapeMatrix;
}

void Tetromino::setColor(TetrominoColor color)
{
    this->color = color;
}

TetrominoShape Tetromino::getShape() const 
{
    return shape;
}

std::vector<std::vector<int>> Tetromino::getShapeMatrix() const 
{
    return shapeMatrix;
}

TetrominoColor Tetromino::getColor() const
{
    return color;
}

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

void IShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
        });
}

void IShapeBuilder::setColor()
{
    tetromino->setColor(TetrominoColor::Red);
}

void JShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_J);
}

void JShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
        });
}

void JShapeBuilder::setColor()
{
    tetromino->setColor(TetrominoColor::Orange);
}

void LShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_L);
}

void LShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
        });
}

void LShapeBuilder::setColor()
{
    tetromino->setColor(TetrominoColor::Yellow);
}

void OShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_O);
}

void OShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {1, 1},
        {1, 1}
        });
}

void OShapeBuilder::setColor()
{
    tetromino->setColor(TetrominoColor::Green);
}

void SShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_S);
}

void SShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {0, 1, 1},
        {1, 1, 0},
        {0, 0, 0}
        });
}

void SShapeBuilder::setColor()
{
    tetromino->setColor(TetrominoColor::Cyan);
}

void TShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_T);
}

void TShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 0}
        });
}

void TShapeBuilder::setColor()
{
    tetromino->setColor(TetrominoColor::Blue);
}

void ZShapeBuilder::setShape() 
{
    tetromino->setShape(TetrominoShape::Shape_Z);
}

void ZShapeBuilder::buildShapeMatrix() 
{
    tetromino->setShapeMatrix({
        {1, 1, 0},
        {0, 1, 1},
        {0, 0, 0}
        });
}

void ZShapeBuilder::setColor()
{
    tetromino->setColor(TetrominoColor::Purple);
}

Tetromino* TetrominoDirector::createTetromino(TetrominoBuilder& builder) 
{
    builder.createNewTetromino();
    builder.setShape();
    builder.buildShapeMatrix();
    builder.setColor();
    return builder.getTetromino();
}

Tetromino* TetrominoDirector::createRandomTetromino() 
{
    Tetromino* tetromino = nullptr;
    int randomNumber = rand() % 7;

    switch (randomNumber) 
    {
        case 0: 
        {
            IShapeBuilder iBuilder;
            tetromino = createTetromino(iBuilder);
            break;
        }
        case 1: 
        {
            JShapeBuilder jBuilder;
            tetromino = createTetromino(jBuilder);
            break;
        }
        case 2: 
        {
            LShapeBuilder lBuilder;
            tetromino = createTetromino(lBuilder);
            break;
        }
        case 3: 
        {
            OShapeBuilder oBuilder;
            tetromino = createTetromino(oBuilder);
            break;
        }
        case 4: 
        {
            SShapeBuilder sBuilder;
            tetromino = createTetromino(sBuilder);
            break;
        }
        case 5: 
        {
            TShapeBuilder tBuilder;
            tetromino = createTetromino(tBuilder);
            break;
        }
        case 6: 
        {
            ZShapeBuilder zBuilder;
            tetromino = createTetromino(zBuilder);
            break;
        }
    }

    return tetromino;
}