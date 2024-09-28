#include "manager_difficulty.h"

ManagerDifficulty::ManagerDifficulty() : scoreDifficulty("difficulty-score", 1) , timeDifficulty("difficulty-time", 1) {}

void ManagerDifficulty::addObserver(Observer* observer)
{
    observers.push_back(observer);
}

void ManagerDifficulty::removeObserver(Observer* observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ManagerDifficulty::notifyObservers()
{
    for (Observer* observer : observers)
    {
        observer->update(scoreDifficulty);
        observer->update(timeDifficulty);
    }
}

int ManagerDifficulty::getScoreDifficulty() const
{
    return scoreDifficulty.second;
}

int ManagerDifficulty::getTimeDifficulty() const
{
    return timeDifficulty.second;
}

void ManagerDifficulty::increaseScoreDifficulty()
{
    ++scoreDifficulty.second;
    notifyObservers();
}

void ManagerDifficulty::increaseTimeDifficulty()
{
    ++timeDifficulty.second;
    notifyObservers();
}