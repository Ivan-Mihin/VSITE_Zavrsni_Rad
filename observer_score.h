#pragma once
#include "observer.h"
#include "manager_score.h"

class ObserverScore : public Observer 
{
private:
    int currentScore;

public:
    ObserverScore();

    void update(int score) override;
};