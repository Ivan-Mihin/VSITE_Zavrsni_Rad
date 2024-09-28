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
    gameOverLineSprite.setPosition(220, 25);

    lockDelayRectangleStartX = sprite.getPosition().x;
    lockDelayRectangleStartY = sprite.getPosition().y;
    lockDelayRectangleEndX = outerRectangle.getPosition().x;
    lockDelayRectangleEndY = outerRectangle.getPosition().y;
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height));

    gameOverRow = 2;
}

std::vector<std::vector<int>>& Board::getBoard()
{
    return board;
}

int Board::getGameOverRow() const
{
    return gameOverRow;
}

void Board::setGameOverRow(int value)
{
    gameOverRow = value;
}

void Board::allClearCheck(ManagerScore* managerScore)
{
    bool isAllCleared = true;

    for (int row = BOARD_ROWS - 1; row >= 0; --row)
    {
        for (int column = 0; column < BOARD_COLUMNS; ++column)
        {
            if (getBoard()[row][column])
            {
                isAllCleared = false;
                break;
            }
        }

        if (!isAllCleared)
        {
            break;
        }
    }

    if (isAllCleared)
    {
        //audio.getSfxAllClear().play();
        managerScore->increaseScore(3000);
    }
}

void Board::clearFullLines(ManagerScore* managerScore, ManagerCombo* managerCombo, ObserverCombo* observerCombo)
{
    bool noLinesCleared = true;

    for (int row = 0; row < BOARD_ROWS; ++row)
    {
        bool isFull = true;

        for (int column = 0; column < BOARD_COLUMNS; ++column)
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
            managerScore->increaseScore(100);

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
        if (managerCombo->getCombo() >= 2)
        {
            managerScore->increaseScore(100 * managerCombo->getCombo() * managerCombo->getCombo() / 2);
        }
        
        managerCombo->resetCombo();
    }
    else
    {
        managerCombo->increaseCombo(1);
    }

    observerCombo->playComboSound();

    allClearCheck(managerScore);
}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(outerRectangle);
    window.draw(lockDelayRectangle);
    window.draw(sprite);

    gameOverLineSprite.setPosition(220, 25 + 30 * gameOverRow);
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