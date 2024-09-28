#include "held_tetromino.h"

HeldTetromino::HeldTetromino()
{
    texture.loadFromFile("Resources/Sprites/tetromino.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));

    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    innerRectangleColor.r = 25;
    innerRectangleColor.g = 25;
    innerRectangleColor.b = 25;

    outerRectangle.setPosition(20, 185);
    outerRectangle.setSize(sf::Vector2f(170, 170));
    outerRectangle.setFillColor(sf::Color::Black);

    textLabelInnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10);
    textLabelInnerRectangle.setSize(sf::Vector2f(150, 60));
    textLabelInnerRectangle.setFillColor(innerRectangleColor);

    tetrominoInnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10 + textLabelInnerRectangle.getSize().y);
    tetrominoInnerRectangle.setSize(sf::Vector2f(150, 90));
    tetrominoInnerRectangle.setFillColor(innerRectangleColor);

    textLabel.setFont(font);
    textLabel.setCharacterSize(30);
    textLabel.setFillColor(sf::Color::White);
    textLabel.setString("Hold");
    textLabel.setOrigin(textLabel.getLocalBounds().left + textLabel.getLocalBounds().width / 2.0f, textLabel.getLocalBounds().top + textLabel.getLocalBounds().height / 2.0f);
    textLabel.setPosition(textLabelInnerRectangle.getPosition().x + textLabelInnerRectangle.getLocalBounds().left + textLabelInnerRectangle.getLocalBounds().width / 2.0f,
        textLabelInnerRectangle.getPosition().y + textLabelInnerRectangle.getLocalBounds().top + textLabelInnerRectangle.getLocalBounds().height / 2.0f);

    noHeldTetromino.setFont(font);
    noHeldTetromino.setCharacterSize(30);
    noHeldTetromino.setFillColor(sf::Color::White);
    noHeldTetromino.setString("Empty");
    noHeldTetromino.setOrigin(noHeldTetromino.getLocalBounds().left + noHeldTetromino.getLocalBounds().width / 2.0f, noHeldTetromino.getLocalBounds().top + noHeldTetromino.getLocalBounds().height / 2.0f);
    noHeldTetromino.setPosition(tetrominoInnerRectangle.getPosition().x + tetrominoInnerRectangle.getLocalBounds().left + tetrominoInnerRectangle.getLocalBounds().width / 2.0f,
        tetrominoInnerRectangle.getPosition().y + tetrominoInnerRectangle.getLocalBounds().top + tetrominoInnerRectangle.getLocalBounds().height / 2.0f);

    lockDelayRectangleStartX = textLabelInnerRectangle.getPosition().x;
    lockDelayRectangleStartY = textLabelInnerRectangle.getPosition().y;
    lockDelayRectangleEndX = outerRectangle.getPosition().x;
    lockDelayRectangleEndY = outerRectangle.getPosition().y;
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(textLabelInnerRectangle.getLocalBounds().width, textLabelInnerRectangle.getLocalBounds().height + tetrominoInnerRectangle.getLocalBounds().height));

    isTetrominoHeld = false;
}

HeldTetromino::~HeldTetromino()
{
    delete tetromino;
}

void HeldTetromino::draw(sf::RenderWindow& window)
{
    window.draw(outerRectangle);
    window.draw(lockDelayRectangle);
    window.draw(textLabelInnerRectangle);
    window.draw(tetrominoInnerRectangle);
    window.draw(textLabel);
    if (!isTetrominoHeld)
    {
        window.draw(noHeldTetromino);
    }

    if (isTetrominoHeld)
    {
        for (int row = 0; row < tetromino->getShapeMatrix().size(); ++row)
        {
            for (int column = 0; column < tetromino->getShapeMatrix().size(); ++column)
            {
                int offsetFromInventoryInnerRectangle = 15;
                int additionalOffsetX = 0;
                int additionalOffsetY = 0;

                if (tetromino->getShapeMatrix()[column][row])
                {

                    if (tetromino->getShape() == TetrominoShape::Shape_I)
                    {
                        additionalOffsetY -= 15;
                    }
                    else if (tetromino->getShape() == TetrominoShape::Shape_O)
                    {
                        additionalOffsetX += 30;
                    }
                    else
                    {
                        additionalOffsetX += 15;
                    }

                    sprite.setTextureRect(sf::IntRect((int)tetromino->getColor() * 30, 0, 30, 30));
                    sprite.setPosition(textLabelInnerRectangle.getGlobalBounds().left + offsetFromInventoryInnerRectangle + additionalOffsetX + 30 * row,
                        textLabelInnerRectangle.getGlobalBounds().top + offsetFromInventoryInnerRectangle + additionalOffsetY + (2 * 30) + 30 * column);
                    window.draw(sprite);
                }
            }
        }
    }
}

void HeldTetromino::drawNoHeldTetrominoText()
{
    sf::Time elapsed = clock.getElapsedTime();
    float time = elapsed.asSeconds();
    float intensity = (std::sin(time * 2.0f) + 1.0f) / 2.0f * 230.0f + 25.0f;
    sf::Color color(intensity, intensity, intensity);
    noHeldTetromino.setFillColor(color);
}

Tetromino* HeldTetromino::getTetromino()
{
    return tetromino;
}

void HeldTetromino::resetLockDelayRectangle()
{
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(textLabelInnerRectangle.getLocalBounds().width, textLabelInnerRectangle.getLocalBounds().height + tetrominoInnerRectangle.getLocalBounds().height));
}

void HeldTetromino::setLockDelayColor(sf::Color color)
{
    lockDelayRectangle.setFillColor(color);
}

void HeldTetromino::setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue)
{
    float currentLockDelayRectangleSizeX = lockDelayRectangleStartX + t * (lockDelayRectangleEndX - lockDelayRectangleStartX);
    float currentLockDelayRectangleSizeY = lockDelayRectangleStartY + t * (lockDelayRectangleEndY - lockDelayRectangleStartY);

    lockDelayRectangle.setSize(sf::Vector2f(textLabelInnerRectangle.getLocalBounds().width + currentLockDelaySizeIncreaseValue,
        textLabelInnerRectangle.getLocalBounds().height + tetrominoInnerRectangle.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
    lockDelayRectangle.setPosition(currentLockDelayRectangleSizeX, currentLockDelayRectangleSizeY);
}

void HeldTetromino::setTetromino(Tetromino* tetromino)
{
    this->tetromino = tetromino;
}