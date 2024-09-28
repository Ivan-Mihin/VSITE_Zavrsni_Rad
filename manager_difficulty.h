#pragma once
#include <string>
#include <utility>
#include <vector>
#include "observer.h"

class ManagerDifficulty
{
private:
    std::pair<std::string, int> scoreDifficulty;
    std::pair<std::string, int> timeDifficulty;
    std::vector<Observer*> observers;

public:
    ManagerDifficulty();

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();

    int getScoreDifficulty() const;
    int getTimeDifficulty() const;
    void increaseScoreDifficulty();
    void increaseTimeDifficulty();
};