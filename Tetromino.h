#pragma once

#include <vector>
#include <iostream>

// Enum for Tetromino Types
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

// Class to represent the Tetromino piece
class Tetromino {
private:
    TetrominoShape shape;
    std::vector<std::vector<int>> shapeMatrix;    

public:
    Tetromino();
    ~Tetromino();

    TetrominoShape getShape() const;
    std::vector<std::vector<int>> getShapeMatrix() const;

    void setShape(TetrominoShape shape);
    void setShapeMatrix(const std::vector<std::vector<int>>& shapeMatrix);
    void print() const; // To display the tetromino for testing/debugging purposes
};

// Abstract Builder for Tetrominos
class TetrominoBuilder {
protected:
    Tetromino* tetromino;

public:
    TetrominoBuilder();
    virtual ~TetrominoBuilder() = default;

    void createNewTetromino();
    Tetromino* getTetromino();

    virtual void setShape() = 0;
    virtual void buildShapeMatrix() = 0;
};

// Concrete Builders for each type of Tetromino
class IShapeBuilder : public TetrominoBuilder 
{
public:
    IShapeBuilder();
    ~IShapeBuilder();

    void setShape() override;
    void buildShapeMatrix() override; 
};

class JShapeBuilder : public TetrominoBuilder 
{
public:
    JShapeBuilder();
    ~JShapeBuilder();

    void setShape() override;
    void buildShapeMatrix() override;
};

class LShapeBuilder : public TetrominoBuilder 
{
public:
    LShapeBuilder();
    ~LShapeBuilder();

    void setShape() override;
    void buildShapeMatrix() override;
};

class OShapeBuilder : public TetrominoBuilder 
{
public:
    OShapeBuilder();
    ~OShapeBuilder();

    void setShape() override;
    void buildShapeMatrix() override;
};

class SShapeBuilder : public TetrominoBuilder 
{
public:
    SShapeBuilder();
    ~SShapeBuilder();

    void setShape() override;
    void buildShapeMatrix() override;
};

class TShapeBuilder : public TetrominoBuilder 
{
public:
    TShapeBuilder();
    ~TShapeBuilder();

    void setShape() override;
    void buildShapeMatrix() override;
};

class ZShapeBuilder : public TetrominoBuilder 
{
public:
    ZShapeBuilder();
    ~ZShapeBuilder();

    void setShape() override;
    void buildShapeMatrix() override;
};

// Director Class
class TetrominoDirector 
{
public:
    Tetromino* createTetromino(TetrominoBuilder& builder);
};