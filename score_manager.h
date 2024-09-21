#pragma once
#include <vector>
#include "observer.h"

class ScoreManager 
{
private:
    int score;
    std::vector<Observer*> observers;

public:
    ScoreManager();

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();
    void increaseScore(int value);
    int getScore() const;
};