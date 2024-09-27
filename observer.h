#pragma once

class Observer 
{
public:
    virtual ~Observer() {}
    virtual void update(std::pair<std::string, int> updateData) = 0;
};