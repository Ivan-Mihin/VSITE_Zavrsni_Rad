#include "manager_score.h"

ManagerScore::ManagerScore()
{
    score = 0;
}

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
    return score;
}

void ManagerScore::increaseScore(int value)
{
    score += value;
    notifyObservers();
}