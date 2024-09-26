#pragma once
#include <vector>
#include "observer.h"

class ManagerCombo
{
private:
    int combo;
    std::vector<Observer*> observers;

public:
    ManagerCombo();
    ~ManagerCombo();

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();

    int getCombo() const;
    void increaseCombo(int value);
    void resetCombo();
};