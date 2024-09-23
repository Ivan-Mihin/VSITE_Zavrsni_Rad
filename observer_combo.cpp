#include "observer_combo.h"

ObserverCombo::ObserverCombo()
{
    currentComboValue = 0;
}

void ObserverCombo::update(int comboValue)
{
    currentComboValue = comboValue;
}