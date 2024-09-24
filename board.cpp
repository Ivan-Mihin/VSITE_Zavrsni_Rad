#include "board.h"

Board::Board()
{
    board.assign(BOARD_ROWS, std::vector<int>(BOARD_COLUMNS, 0));

    texture.loadFromFile("Resources/Sprites/board.png");
    sprite.setTexture(texture);
    sprite.setPosition(220, 25);

    gameOverLineTexture.loadFromFile("Resources/Sprites/game_over_line.png");
    gameOverLineSprite.setTexture(gameOverLineTexture);
    gameOverLineSprite.setPosition(220, 85);

    outerRectangle.setPosition(210, 15);
    outerRectangle.setSize(sf::Vector2f(380, 770));
    outerRectangle.setFillColor(sf::Color::Black);

    lockDelayRectangleStartX = sprite.getPosition().x;
    lockDelayRectangleStartY = sprite.getPosition().y;
    lockDelayRectangleEndX = outerRectangle.getPosition().x;
    lockDelayRectangleEndY = outerRectangle.getPosition().y;
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height));
}

void Board::setColor(sf::Color color)
{
    lockDelayRectangle.setFillColor(color);
}

void Board::setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue)
{
    float currentLockDelayRectangleSizeX = lockDelayRectangleStartX + t * (lockDelayRectangleEndX - lockDelayRectangleStartX);
    float currentLockDelayRectangleSizeY = lockDelayRectangleStartY + t * (lockDelayRectangleEndY - lockDelayRectangleStartY);

    lockDelayRectangle.setSize(sf::Vector2f(sprite.getLocalBounds().width + currentLockDelaySizeIncreaseValue,
        sprite.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
    lockDelayRectangle.setPosition(currentLockDelayRectangleSizeX, currentLockDelayRectangleSizeY);
}

void Board::resetLockDelayRectangle()
{
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height));
}

std::vector<std::vector<int>>& Board::getBoard()
{
    return board;
}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(outerRectangle);
    window.draw(lockDelayRectangle);
    window.draw(sprite);
    window.draw(gameOverLineSprite);
}