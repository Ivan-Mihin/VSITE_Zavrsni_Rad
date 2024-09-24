#include "observer_combo.h"

ObserverCombo::ObserverCombo()
{
    combo = 0;

    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    innerRectangleColor.r = 25;
    innerRectangleColor.g = 25;
    innerRectangleColor.b = 25;

    outerRectangle.setPosition(20, 185);
    outerRectangle.setSize(sf::Vector2f(170, 140));
    outerRectangle.setFillColor(sf::Color::Black);

    textLabelInnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10);
    textLabelInnerRectangle.setSize(sf::Vector2f(150, 60));
    textLabelInnerRectangle.setFillColor(innerRectangleColor);

    valueInnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10 + textLabelInnerRectangle.getSize().y);
    valueInnerRectangle.setSize(sf::Vector2f(150, 60));
    valueInnerRectangle.setFillColor(innerRectangleColor);

    comboTextLabel.setFont(font);
    comboTextLabel.setCharacterSize(30);
    comboTextLabel.setFillColor(sf::Color::White);
    comboTextLabel.setString("Combo");
    comboTextLabel.setOrigin(comboTextLabel.getLocalBounds().left + comboTextLabel.getLocalBounds().width / 2.0f,
        comboTextLabel.getLocalBounds().top + comboTextLabel.getLocalBounds().height / 2.0f);
    comboTextLabel.setPosition(textLabelInnerRectangle.getPosition().x + textLabelInnerRectangle.getLocalBounds().left + textLabelInnerRectangle.getLocalBounds().width / 2.0f,
        textLabelInnerRectangle.getPosition().y + textLabelInnerRectangle.getLocalBounds().top + textLabelInnerRectangle.getLocalBounds().height / 2.0f);

    comboValue.setFont(font);
    comboValue.setCharacterSize(30);
    comboValue.setFillColor(sf::Color::White);
    comboValue.setString("0");
    comboValue.setOrigin(comboValue.getLocalBounds().left + comboValue.getLocalBounds().width / 2.0f,
        comboValue.getLocalBounds().top + comboValue.getLocalBounds().height / 2.0f);
    comboValue.setPosition(valueInnerRectangle.getPosition().x + valueInnerRectangle.getLocalBounds().left + valueInnerRectangle.getLocalBounds().width / 2.0f,
        valueInnerRectangle.getPosition().y + valueInnerRectangle.getLocalBounds().top + valueInnerRectangle.getLocalBounds().height / 2.0f);

    lockDelayRectangleStartX = textLabelInnerRectangle.getPosition().x;
    lockDelayRectangleStartY = textLabelInnerRectangle.getPosition().y;
    lockDelayRectangleEndX = outerRectangle.getPosition().x;
    lockDelayRectangleEndY = outerRectangle.getPosition().y;
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(textLabelInnerRectangle.getLocalBounds().width, textLabelInnerRectangle.getLocalBounds().height + valueInnerRectangle.getLocalBounds().height));
}

void ObserverCombo::setColor(sf::Color color)
{
    lockDelayRectangle.setFillColor(color);
}

void ObserverCombo::setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue)
{
    float currentLockDelayRectangleSizeX = lockDelayRectangleStartX + t * (lockDelayRectangleEndX - lockDelayRectangleStartX);
    float currentLockDelayRectangleSizeY = lockDelayRectangleStartY + t * (lockDelayRectangleEndY - lockDelayRectangleStartY);

    lockDelayRectangle.setSize(sf::Vector2f(textLabelInnerRectangle.getLocalBounds().width + currentLockDelaySizeIncreaseValue,
        textLabelInnerRectangle.getLocalBounds().height + valueInnerRectangle.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
    lockDelayRectangle.setPosition(currentLockDelayRectangleSizeX, currentLockDelayRectangleSizeY);
}

void ObserverCombo::resetLockDelayRectangle()
{
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(textLabelInnerRectangle.getLocalBounds().width, textLabelInnerRectangle.getLocalBounds().height + valueInnerRectangle.getLocalBounds().height));
}

void ObserverCombo::playComboSound()
{
    if (combo >= 2)
    {
        switch (combo)
        {
        case 2:  audio.getSfxCombo_2().play(); break;
        case 3:  audio.getSfxCombo_3().play(); break;
        case 4:  audio.getSfxCombo_4().play(); break;
        case 5:  audio.getSfxCombo_5().play(); break;
        case 6:  audio.getSfxCombo_6().play(); break;
        case 7:  audio.getSfxCombo_7().play(); break;
        case 8:  audio.getSfxCombo_8().play(); break;
        case 9:  audio.getSfxCombo_9().play(); break;
        case 10: audio.getSfxCombo_10().play(); break;
        case 11: audio.getSfxCombo_11().play(); break;
        case 12: audio.getSfxCombo_12().play(); break;
        case 13: audio.getSfxCombo_13().play(); break;
        case 14: audio.getSfxCombo_14().play(); break;
        case 15: audio.getSfxCombo_15().play(); break;
        case 16: audio.getSfxCombo_16().play(); break;
        }
    }
}

void ObserverCombo::update(int combo)
{
    this->combo = combo;
    comboValue.setString(std::to_string(this->combo));
    comboValue.setOrigin(comboValue.getLocalBounds().left + comboValue.getLocalBounds().width / 2.0f,
        comboValue.getLocalBounds().top + comboValue.getLocalBounds().height / 2.0f);
    comboValue.setPosition(valueInnerRectangle.getPosition().x + valueInnerRectangle.getLocalBounds().left + valueInnerRectangle.getLocalBounds().width / 2.0f,
        valueInnerRectangle.getPosition().y + valueInnerRectangle.getLocalBounds().top + valueInnerRectangle.getLocalBounds().height / 2.0f);
}

void ObserverCombo::draw(sf::RenderWindow& window)
{
    if (combo >= 2)
    {
        window.draw(outerRectangle);
        window.draw(lockDelayRectangle);
        window.draw(textLabelInnerRectangle);
        window.draw(valueInnerRectangle);
        window.draw(comboTextLabel);
        window.draw(comboValue);
    }
}