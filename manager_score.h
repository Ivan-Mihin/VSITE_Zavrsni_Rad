#pragma once
#include <vector>
#include "observer.h"

class ManagerScore
{
private:
    int score;
    std::vector<Observer*> observers;

public:
    ManagerScore();

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();

    int getScore() const;
    void increaseScore(int value);
};