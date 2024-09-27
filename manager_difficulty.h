#pragma once
#include <string>
#include <utility>
#include <vector>
#include "observer.h"

class ManagerDifficulty
{
private:
    std::pair<std::string, int> difficulty;
    std::vector<Observer*> observers;

public:
    ManagerDifficulty();

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();

    int getDifficulty() const;
    void increaseDifficulty();
};