#pragma once

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