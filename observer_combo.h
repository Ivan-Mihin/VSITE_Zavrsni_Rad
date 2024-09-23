#pragma once
#include "observer.h"
#include "manager_combo.h"

class ObserverCombo : public Observer
{
private:
    int currentComboValue;

public:
    ObserverCombo();

    void update(int comboValue) override;
};