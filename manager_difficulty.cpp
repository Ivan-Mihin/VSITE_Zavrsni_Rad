#include "manager_difficulty.h"

ManagerDifficulty::ManagerDifficulty() : difficulty("difficulty", 1) {}

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
        observer->update(difficulty);
    }
}

int ManagerDifficulty::getDifficulty() const
{
    return difficulty.second;
}

void ManagerDifficulty::increaseDifficulty()
{
    ++difficulty.second;
    notifyObservers();
}