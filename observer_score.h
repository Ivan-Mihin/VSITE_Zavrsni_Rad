#pragma once
#include <SFML/Graphics.hpp>
#include "observer.h"
#include "score_manager.h"

class ObserverScore : public Observer 
{
private:
    int currentScore;

public:
    ObserverScore();

    void update(int score) override;
};