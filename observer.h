#pragma once

class Observer 
{
public:
    virtual ~Observer() {}
    virtual void update(int score) = 0;
};