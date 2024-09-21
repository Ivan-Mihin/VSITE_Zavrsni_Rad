#include "observer_score.h"

ObserverScore::ObserverScore()
{
    currentScore = 0;
}

void ObserverScore::update(int score)
{
    currentScore = score;
}