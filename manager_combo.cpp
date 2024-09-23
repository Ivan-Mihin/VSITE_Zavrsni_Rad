#include "manager_combo.h"

ManagerCombo::ManagerCombo()
{
    comboCount = 0;
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
        observer->update(comboCount);
    }
}

void ManagerCombo::increaseCombo(int value)
{
    comboCount += value;
    notifyObservers();
}


void ManagerCombo::resetCombo() {
    comboCount = 0;
    notifyObservers();
}

int ManagerCombo::getComboCount() const
{
    return comboCount;
}