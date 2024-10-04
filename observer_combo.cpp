#include "observer_combo.h"

ObserverCombo::ObserverCombo() : lockDelay(150.0f, 120.0f)
{
    combo = 0;

    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    innerRectangleColor.r = 25;
    innerRectangleColor.g = 25;
    innerRectangleColor.b = 25;

    outerRectangle.setPosition(20, 645);
    outerRectangle.setSize(sf::Vector2f(170, 140));
    outerRectangle.setFillColor(sf::Color::Black);

    textLabelInnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10);
    textLabelInnerRectangle.setSize(sf::Vector2f(150, 60));
    textLabelInnerRectangle.setFillColor(innerRectangleColor);

    valueInnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10 + textLabelInnerRectangle.getSize().y);
    valueInnerRectangle.setSize(sf::Vector2f(150, 60));
    valueInnerRectangle.setFillColor(innerRectangleColor);

    textLabel.setFont(font);
    textLabel.setCharacterSize(30);
    textLabel.setFillColor(sf::Color::White);
    textLabel.setString("Combo");
    textLabel.setOrigin(textLabel.getLocalBounds().left + textLabel.getLocalBounds().width / 2.0f,
        textLabel.getLocalBounds().top + textLabel.getLocalBounds().height / 2.0f);
    textLabel.setPosition(textLabelInnerRectangle.getPosition().x + textLabelInnerRectangle.getLocalBounds().left + textLabelInnerRectangle.getLocalBounds().width / 2.0f,
        textLabelInnerRectangle.getPosition().y + textLabelInnerRectangle.getLocalBounds().top + textLabelInnerRectangle.getLocalBounds().height / 2.0f);

    value.setFont(font);
    value.setCharacterSize(30);
    value.setFillColor(sf::Color::White);
    value.setString("0");
    value.setOrigin(value.getLocalBounds().left + value.getLocalBounds().width / 2.0f,
        value.getLocalBounds().top + value.getLocalBounds().height / 2.0f);
    value.setPosition(valueInnerRectangle.getPosition().x + valueInnerRectangle.getLocalBounds().left + valueInnerRectangle.getLocalBounds().width / 2.0f,
        valueInnerRectangle.getPosition().y + valueInnerRectangle.getLocalBounds().top + valueInnerRectangle.getLocalBounds().height / 2.0f);

    lockDelay.start.x = textLabelInnerRectangle.getPosition().x;
    lockDelay.start.y = textLabelInnerRectangle.getPosition().y;
    lockDelay.end.x = outerRectangle.getPosition().x;
    lockDelay.end.y = outerRectangle.getPosition().y;
    lockDelay.rectangle.setPosition(sf::Vector2f(lockDelay.start.x, lockDelay.start.y));
    lockDelay.rectangle.setSize(sf::Vector2f(lockDelay.DEFAULT_WIDTH, lockDelay.DEFAULT_HEIGHT));
}

void ObserverCombo::draw(sf::RenderWindow& window)
{
    if (combo >= 2)
    {
        window.draw(outerRectangle);
        window.draw(lockDelay.rectangle);
        window.draw(textLabelInnerRectangle);
        window.draw(valueInnerRectangle);

        setTextColor(&textLabel);
        window.draw(textLabel);

        value.setString(std::to_string(combo));
        value.setOrigin(value.getLocalBounds().left + value.getLocalBounds().width / 2.0f, value.getLocalBounds().top + value.getLocalBounds().height / 2.0f);
        value.setPosition(valueInnerRectangle.getPosition().x + valueInnerRectangle.getLocalBounds().left + valueInnerRectangle.getLocalBounds().width / 2.0f,
            valueInnerRectangle.getPosition().y + valueInnerRectangle.getLocalBounds().top + valueInnerRectangle.getLocalBounds().height / 2.0f);
        setTextColor(&value);
        window.draw(value);
    }
    else 
    {
        clockForChangingColor.restart();
    }
}

void ObserverCombo::playComboSound()
{
    if (combo >= 2)
    {
        switch (combo)
        {
        case 2:  audioCombo.getSfxCombo_2().play();  break;
        case 3:  audioCombo.getSfxCombo_3().play();  break;
        case 4:  audioCombo.getSfxCombo_4().play();  break;
        case 5:  audioCombo.getSfxCombo_5().play();  break;
        case 6:  audioCombo.getSfxCombo_6().play();  break;
        case 7:  audioCombo.getSfxCombo_7().play();  break;
        case 8:  audioCombo.getSfxCombo_8().play();  break;
        case 9:  audioCombo.getSfxCombo_9().play();  break;
        case 10: audioCombo.getSfxCombo_10().play(); break;
        case 11: audioCombo.getSfxCombo_11().play(); break;
        case 12: audioCombo.getSfxCombo_12().play(); break;
        case 13: audioCombo.getSfxCombo_13().play(); break;
        case 14: audioCombo.getSfxCombo_14().play(); break;
        case 15: audioCombo.getSfxCombo_15().play(); break;
        case 16: audioCombo.getSfxCombo_16().play(); break;
        }
    }
}

void ObserverCombo::setTextColor(sf::Text* text) 
{
    float elapsedTime = clockForChangingColor.getElapsedTime().asSeconds();
    float intensity = (std::sin((elapsedTime * 3.141592f) - 3.141592f / 2.0f) + 1.0f) / 2.0f * 230.0f + 25.0f;
    sf::Color color(intensity, intensity, intensity);
    text->setFillColor(color);
}

void ObserverCombo::update(std::pair<std::string, int> updateData)
{
    combo = updateData.second;
}

void ObserverCombo::resetLockDelayRectangle()
{
    lockDelay.resetRectangle();
}

void ObserverCombo::setLockDelayRectangle(float t, float currentValue)
{
    lockDelay.setRectangle(t, currentValue);
}

void ObserverCombo::setLockDelayColor(sf::Color color)
{
    lockDelay.setColor(color);
}