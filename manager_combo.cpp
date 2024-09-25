#include "manager_combo.h"

ManagerCombo::ManagerCombo()
{
    combo = 0;
}

void ManagerCombo::addObserver(Observer* observer)
{
    observers.push_back(observer);
}

void ManagerCombo::removeObserver(Observer* observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ManagerCombo::notifyObservers()
{
    for (Observer* observer : observers)
    {
        observer->update(combo);
    }
}

int ManagerCombo::getCombo() const
{
    return combo;
}

void ManagerCombo::increaseCombo(int value)
{
    combo += value;
    notifyObservers();
}


void ManagerCombo::resetCombo() {
    combo = 0;
    notifyObservers();
}