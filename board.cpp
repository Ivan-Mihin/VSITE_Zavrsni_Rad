#include "board.h"

int GameOverLine::getRow() const
{
    return row;
}

void GameOverLine::setRow(ManagerDifficulty* managerDifficulty)
{
    switch (managerDifficulty->getTimeDifficulty())
    {
    case 2: { row = 3; break; }
    case 3: { row = 4; break; }
    case 4: { row = 5; break; }
    case 5: { row = 6; break; }
    }
}

Board::Board() : lockDelay(360.0f, 750.0f)
{
    board.assign(BOARD_ROWS, std::vector<int>(BOARD_COLUMNS, 0));

    outerRectangle.setPosition(210, 15);
    outerRectangle.setSize(sf::Vector2f(380, 770));
    outerRectangle.setFillColor(sf::Color::Black);

    texture_Board.loadFromFile("Resources/Sprites/board.png");
    sprite_Board.setTexture(texture_Board);
    sprite_Board.setPosition(220, 25);

    lockDelay.start.x = sprite_Board.getPosition().x;
    lockDelay.start.y = sprite_Board.getPosition().y;
    lockDelay.end.x = outerRectangle.getPosition().x;
    lockDelay.end.y = outerRectangle.getPosition().y;
    lockDelay.rectangle.setPosition(sf::Vector2f(lockDelay.start.x, lockDelay.start.y));
    lockDelay.rectangle.setSize(sf::Vector2f(lockDelay.DEFAULT_WIDTH, lockDelay.DEFAULT_HEIGHT));

    gameOverLine.row = 2;
    gameOverLine.texture.loadFromFile("Resources/Sprites/game_over_line.png");
    gameOverLine.sprite.setTexture(gameOverLine.texture);
    gameOverLine.sprite.setPosition(220, 25);

    noLinesCleared = true;
}

std::vector<std::vector<int>>& Board::getBoard()
{
    return board;
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
        audio_Board.getSfxAllClear().play();
        managerScore->increaseScore(3000);
    }
}

void Board::clearFullLines(ManagerScore* managerScore)
{
    noLinesCleared = true;

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

            audio_Board.getSfxClearLine().play();
            managerScore->increaseScore(100);

            for (int i = row; i > 0; --i)
            {
                getBoard()[i] = getBoard()[i - 1];
            }

            getBoard()[0] = std::vector<int>(BOARD_COLUMNS, 0);
            --row;
        }
    }
}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(outerRectangle);
    window.draw(lockDelay.rectangle);
    window.draw(sprite_Board);

    gameOverLine.sprite.setPosition(220, 25 + 30 * gameOverLine.row);
    window.draw(gameOverLine.sprite);
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

int Board::getGameOverLineRow() const
{
    return gameOverLine.getRow();
}

void Board::setGameOverLineRow(ManagerDifficulty* managerDifficulty)
{
    gameOverLine.setRow(managerDifficulty);
}

void Board::resetLockDelayRectangle()
{
    lockDelay.resetRectangle();
}

void Board::setLockDelayRectangle(float t, float currentValue)
{
    lockDelay.setRectangle(t, currentValue);
}

void Board::setLockDelayColor(sf::Color color)
{
    lockDelay.setColor(color);
}