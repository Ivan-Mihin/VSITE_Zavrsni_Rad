#include "score_manager.h"

ScoreManager::ScoreManager()
{
    score = 0;
}

void ScoreManager::addObserver(Observer* observer)
{
    observers.push_back(observer);
}

void ScoreManager::removeObserver(Observer* observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ScoreManager::notifyObservers()
{
    for (Observer* observer : observers)
    {
        observer->update(score);
    }
}

void ScoreManager::increaseScore(int value) 
{
    score += value;
    notifyObservers();
}

int ScoreManager::getScore() const 
{
    return score;
}