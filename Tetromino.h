#pragma once
#include <vector>

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

class Square
{
private:
    int x;
    int y;

public:
    Square(int x, int y);

    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);
};

class Tetromino 
{
private:
    TetrominoShape shape;
    std::vector<std::vector<int>> shapeMatrix;
    std::vector<Square> squares;
    TetrominoColor color;

public:
    TetrominoShape getShape() const;
    std::vector<std::vector<int>> getShapeMatrix() const;
    std::vector<Square>& getSquares();
    TetrominoColor getColor() const;

    void setShape(TetrominoShape shape);
    void setShapeMatrix(const std::vector<std::vector<int>>& shapeMatrix);
    void setSquares(const std::vector<Square>& squares);
    void setColor(TetrominoColor color);
    void moveLeft();
    void moveRight();
};

class TetrominoBuilder 
{
protected:
    Tetromino* tetromino;

public:
    virtual ~TetrominoBuilder() = default;

    void createNewTetromino();
    Tetromino* getTetromino();
    void buildSquares();

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
    Tetromino* createRandomTetromino();
};