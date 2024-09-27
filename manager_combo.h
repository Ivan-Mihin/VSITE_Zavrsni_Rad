#pragma once
#include <string>
#include <utility>
#include <vector>
#include "observer.h"

class ManagerCombo
{
private:
    std::pair<std::string, int> combo;
    std::vector<Observer*> observers;

public:
    ManagerCombo();

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();

    int getCombo() const;
    void increaseCombo(int value);
    void resetCombo();
};