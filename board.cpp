#include "board.h"

Board::Board()
{
    board.assign(BOARD_ROWS, std::vector<int>(BOARD_COLUMNS, 0));

    outerRectangle.setPosition(210, 15);
    outerRectangle.setSize(sf::Vector2f(380, 770));
    outerRectangle.setFillColor(sf::Color::Black);

    texture.loadFromFile("Resources/Sprites/board.png");
    sprite.setTexture(texture);
    sprite.setPosition(220, 25);

    gameOverLineTexture.loadFromFile("Resources/Sprites/game_over_line.png");
    gameOverLineSprite.setTexture(gameOverLineTexture);
    gameOverLineSprite.setPosition(220, 85);

    lockDelayRectangleStartX = sprite.getPosition().x;
    lockDelayRectangleStartY = sprite.getPosition().y;
    lockDelayRectangleEndX = outerRectangle.getPosition().x;
    lockDelayRectangleEndY = outerRectangle.getPosition().y;
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height));
}

std::vector<std::vector<int>>& Board::getBoard()
{
    return board;
}

void Board::clearFullLines(ManagerScore* ms, ManagerCombo* mc, ObserverCombo* oc)
{
    bool noLinesCleared = true;

    for (int row = 0; row < BOARD_ROWS; ++row)
    {
        bool isFull = true;

        for (int column= 0; column < BOARD_COLUMNS; ++column)
        {
            if (!getBoard()[row][column])
            {
                isFull = false;
                break;
            }
        }

        if (isFull)
        {
            noLinesCleared = false;

            //audio.getSfxClearLine().play();
            ms->increaseScore(10);

            for (int i = row; i > 0; --i)
            {
                getBoard()[i] = getBoard()[i - 1];
            }

            getBoard()[0] = std::vector<int>(BOARD_COLUMNS, 0);
            --row;
        }
    }

    if (noLinesCleared)
    {
        mc->resetCombo();
    }
    else
    {
        mc->increaseCombo(1);
    }

    oc->playComboSound();
}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(outerRectangle);
    window.draw(lockDelayRectangle);
    window.draw(sprite);
    window.draw(gameOverLineSprite);
}

bool Board::isValidPosition(std::vector<Square> nextPosition)
{
    for (int i = 0; i < 4; ++i)
    {
        if (nextPosition[i].getX() < 0 || nextPosition[i].getX() >= BOARD_COLUMNS || nextPosition[i].getY() < 0 || nextPosition[i].getY() >= BOARD_ROWS)
        {
            return false;
        }
        else if (board[nextPosition[i].getY()][nextPosition[i].getX()])
        {
            return false;
        }
    }

    return true;
}

void Board::resetLockDelayRectangle()
{
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