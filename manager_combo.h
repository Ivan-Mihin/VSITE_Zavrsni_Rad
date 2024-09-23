#pragma once
#include <vector>
#include "observer.h"

class ManagerCombo
{
private:
    int comboCount;
    std::vector<Observer*> observers;

public:
    ManagerCombo();

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();
    void increaseCombo(int value);
    void resetCombo();
    int getComboCount() const;
};