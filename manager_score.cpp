#include "manager_score.h"
#include "observer_difficulty.h"

ManagerScore::ManagerScore() : score("score", 0) {}

void ManagerScore::addObserver(Observer* observer)
{
    observers.push_back(observer);
}

void ManagerScore::removeObserver(Observer* observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ManagerScore::notifyObservers()
{
    for (Observer* observer : observers)
    {
        observer->update(score);
    }
}

int ManagerScore::getScore() const
{
    return score.second;
}

void ManagerScore::increaseScore(int value)
{
    score.second += value;
    notifyObservers();
}