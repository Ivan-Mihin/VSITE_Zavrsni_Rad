#pragma once
#include "tetromino.h"

class TetrominoBuilder
{
protected:
    Tetromino* tetromino;

public:
    virtual ~TetrominoBuilder() = default;

    void buildSquares();
    void createNewTetromino();
    Tetromino* getTetromino();

    virtual void buildShapeMatrix() = 0;
    virtual void setColor() = 0;
    virtual void setShape() = 0;
};

class IShapeBuilder : public TetrominoBuilder
{
public:
    void buildShapeMatrix() override;
    void setColor() override;
    void setShape() override;
};

class JShapeBuilder : public TetrominoBuilder
{
public:
    void buildShapeMatrix() override;
    void setColor() override;
    void setShape() override;
};

class LShapeBuilder : public TetrominoBuilder
{
public:
    void buildShapeMatrix() override;
    void setColor() override;
    void setShape() override;
};

class OShapeBuilder : public TetrominoBuilder
{
public:
    void buildShapeMatrix() override;
    void setColor() override;
    void setShape() override;
};

class SShapeBuilder : public TetrominoBuilder
{
public:
    void buildShapeMatrix() override;
    void setColor() override;
    void setShape() override;
};

class TShapeBuilder : public TetrominoBuilder
{
public:
    void buildShapeMatrix() override;
    void setColor() override;
    void setShape() override;
};

class ZShapeBuilder : public TetrominoBuilder
{
public:
    void buildShapeMatrix() override;
    void setColor() override;
    void setShape() override;
};

class TetrominoDirector
{
public:
    Tetromino* createRandomTetromino();
    Tetromino* createTetromino(TetrominoBuilder& builder);
};