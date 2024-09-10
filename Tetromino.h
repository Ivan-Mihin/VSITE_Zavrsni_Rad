#pragma once

#include <vector>
#include <iostream>

enum class TetrominoShape
{
    Shape_I,
    Shape_J,
    Shape_L,
    Shape_O,
    Shape_S,
    Shape_T,
    Shape_Z
};

enum class TetrominoColor
{
    Red,
    Orange,
    Yellow,
    Green,
    Cyan,
    Blue,
    Purple,
    Grey
};

class Tetromino {
private:
    TetrominoShape shape;
    std::vector<std::vector<int>> shapeMatrix;
    TetrominoColor color;

public:
    TetrominoShape getShape() const;
    std::vector<std::vector<int>> getShapeMatrix() const;
    TetrominoColor getColor() const;

    void setShape(TetrominoShape shape);
    void setShapeMatrix(const std::vector<std::vector<int>>& shapeMatrix);
    void setColor(TetrominoColor color);
};

class TetrominoBuilder {
protected:
    Tetromino* tetromino;

public:
    virtual ~TetrominoBuilder() = default;

    void createNewTetromino();
    Tetromino* getTetromino();

    virtual void setShape() = 0;
    virtual void buildShapeMatrix() = 0;
    virtual void setColor() = 0;
};

class IShapeBuilder : public TetrominoBuilder 
{
public:
    void setShape() override;
    void buildShapeMatrix() override; 
    void setColor() override;
};

class JShapeBuilder : public TetrominoBuilder 
{
public:
    void setShape() override;
    void buildShapeMatrix() override;
    void setColor() override;
};

class LShapeBuilder : public TetrominoBuilder 
{
public:
    void setShape() override;
    void buildShapeMatrix() override;
    void setColor() override;
};

class OShapeBuilder : public TetrominoBuilder 
{
public:
    void setShape() override;
    void buildShapeMatrix() override;
    void setColor() override;
};

class SShapeBuilder : public TetrominoBuilder 
{
public:
    void setShape() override;
    void buildShapeMatrix() override;
    void setColor() override;
};

class TShapeBuilder : public TetrominoBuilder 
{
public:
    void setShape() override;
    void buildShapeMatrix() override;
    void setColor() override;
};

class ZShapeBuilder : public TetrominoBuilder 
{
public:
    void setShape() override;
    void buildShapeMatrix() override;
    void setColor() override;
};

class TetrominoDirector 
{
public:
    Tetromino* createTetromino(TetrominoBuilder& builder);
};