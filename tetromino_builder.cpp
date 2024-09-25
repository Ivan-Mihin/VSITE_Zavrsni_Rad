#include "tetromino_builder.h"

void TetrominoBuilder::buildSquares()
{
    std::vector<Square> squares;
    std::vector<std::vector<int>> shapeMatrix = tetromino->getShapeMatrix();

    for (int i = 0; i < shapeMatrix.size(); ++i)
    {
        for (int j = 0; j < shapeMatrix[i].size(); ++j)
        {
            if (shapeMatrix[i][j] == 1)
            {
                squares.push_back(Square(j, i));
            }
        }
    }

    tetromino->setSquares(squares);
}

void TetrominoBuilder::createNewTetromino()
{
    tetromino = new Tetromino();
}

Tetromino* TetrominoBuilder::getTetromino()
{
    return tetromino;
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

void IShapeBuilder::setShape()
{
    tetromino->setShape(TetrominoShape::Shape_I);
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

void JShapeBuilder::setShape()
{
    tetromino->setShape(TetrominoShape::Shape_J);
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

void LShapeBuilder::setShape()
{
    tetromino->setShape(TetrominoShape::Shape_L);
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

void OShapeBuilder::setShape()
{
    tetromino->setShape(TetrominoShape::Shape_O);
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

void SShapeBuilder::setShape()
{
    tetromino->setShape(TetrominoShape::Shape_S);
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

void TShapeBuilder::setShape()
{
    tetromino->setShape(TetrominoShape::Shape_T);
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

void ZShapeBuilder::setShape()
{
    tetromino->setShape(TetrominoShape::Shape_Z);
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
        iBuilder.buildSquares();
        break;
    }
    case 1:
    {
        JShapeBuilder jBuilder;
        tetromino = createTetromino(jBuilder);
        jBuilder.buildSquares();
        break;
    }
    case 2:
    {
        LShapeBuilder lBuilder;
        tetromino = createTetromino(lBuilder);
        lBuilder.buildSquares();
        break;
    }
    case 3:
    {
        OShapeBuilder oBuilder;
        tetromino = createTetromino(oBuilder);
        oBuilder.buildSquares();
        break;
    }
    case 4:
    {
        SShapeBuilder sBuilder;
        tetromino = createTetromino(sBuilder);
        sBuilder.buildSquares();
        break;
    }
    case 5:
    {
        TShapeBuilder tBuilder;
        tetromino = createTetromino(tBuilder);
        tBuilder.buildSquares();
        break;
    }
    case 6:
    {
        ZShapeBuilder zBuilder;
        tetromino = createTetromino(zBuilder);
        zBuilder.buildSquares();
        break;
    }
    }

    return tetromino;
}

Tetromino* TetrominoDirector::createTetromino(TetrominoBuilder& builder)
{
    builder.createNewTetromino();
    builder.setShape();
    builder.buildShapeMatrix();
    builder.setColor();
    return builder.getTetromino();
}