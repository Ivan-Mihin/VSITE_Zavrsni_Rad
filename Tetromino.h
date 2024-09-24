#pragma once
#include <vector>

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

    std::vector<std::vector<Square>> setTemporarySquaresMatrix();
    std::vector<std::vector<int>> rotateShapeMatrix();
    std::vector<Square> rotateSquaresPositions(std::vector<std::vector<Square>> temporarySquaresMatrix);

public:
    Tetromino() {}
    Tetromino(const Tetromino& tetrominoCopy);

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
    void rotate();
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