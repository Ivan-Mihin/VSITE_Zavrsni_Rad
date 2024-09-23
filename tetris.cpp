#include "tetris.h"

void Tetris::initialize()
{
    audio.getSfxTetrisThemeSong().setLoop(true);
    audio.getSfxTetrisThemeSong().setVolume(15);
    audio.getSfxTetrisThemeSong().play();

    background.loadFromFile("Resources/Sprites/main_menu_background.png");
    backgroundSprite.setTexture(background);
    backgroundSprite.setPosition(0, 0);

    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    // Board
    board.assign(BOARD_ROWS, std::vector<int>(BOARD_COLUMNS, 0));

    boardTexture.loadFromFile("Resources/Sprites/board.png");
    boardSprite.setTexture(boardTexture);
    boardSprite.setPosition(220, 25);

    boardGameOverLineTexture.loadFromFile("Resources/Sprites/game_over_line.png");
    boardGameOverLineSprite.setTexture(boardGameOverLineTexture);
    boardGameOverLineSprite.setPosition(220, 85);

    boardOuterRectangle.setPosition(210, 15);
    boardOuterRectangle.setSize(sf::Vector2f(380, 770));
    boardOuterRectangle.setFillColor(sf::Color::Black);

    // Tetromino
    fallingTetromino = director.createRandomTetromino();
    ghostTetromino = new Tetromino(*fallingTetromino);

	for (int i = 0; i < 7; ++i)
	{
		inventory.push_back(director.createRandomTetromino());
	}

    setTetrominoStartingPosition(fallingTetromino, 0, 4);
    setTetrominoStartingPosition(ghostTetromino, 0, 4);

    tetrominoTexture.loadFromFile("Resources/Sprites/tetromino.png");
    tetrominoSprite.setTexture(tetrominoTexture);
    tetrominoSprite.setTextureRect(sf::IntRect(0, 0, TEXTURE_SIZE, TEXTURE_SIZE));

    ghostTetrominoTexture.loadFromFile("Resources/Sprites/tetromino_ghost.png");
    ghostTetrominoSprite.setTexture(ghostTetrominoTexture);
    ghostTetrominoSprite.setTextureRect(sf::IntRect(0, 0, TEXTURE_SIZE, TEXTURE_SIZE));

    // Inventory Text Label
    inventoryTextLabelOuterRectangle.setPosition(610, 15);
    inventoryTextLabelOuterRectangle.setSize(sf::Vector2f(170, 80));
    inventoryTextLabelOuterRectangle.setFillColor(sf::Color::Black);

    inventoryTextLabelInnerRectangle.setPosition(inventoryTextLabelOuterRectangle.getPosition().x + 10, inventoryTextLabelOuterRectangle.getPosition().y + 10);
    inventoryTextLabelInnerRectangle.setSize(sf::Vector2f(150, 60));
    inventoryTextLabelInnerRectangle.setFillColor(innerRectangleColor);

    inventoryTextLabel.setFont(font);
    inventoryTextLabel.setCharacterSize(30);
    inventoryTextLabel.setFillColor(sf::Color::White);
    inventoryTextLabel.setString("Inventory");
    inventoryTextLabel.setOrigin(inventoryTextLabel.getLocalBounds().left + inventoryTextLabel.getLocalBounds().width / 2.0f,
        inventoryTextLabel.getLocalBounds().top + inventoryTextLabel.getLocalBounds().height / 2.0f);
    inventoryTextLabel.setPosition(inventoryTextLabelOuterRectangle.getPosition().x + inventoryTextLabelOuterRectangle.getLocalBounds().left + inventoryTextLabelOuterRectangle.getLocalBounds().width / 2.0f,
        inventoryTextLabelOuterRectangle.getPosition().y + inventoryTextLabelOuterRectangle.getLocalBounds().top + inventoryTextLabelOuterRectangle.getLocalBounds().height / 2.0f);

    // Inventory
    inventoryOuterRectangle.setPosition(610, 135);
    inventoryOuterRectangle.setSize(sf::Vector2f(170, 650));
    inventoryOuterRectangle.setFillColor(sf::Color::Black);

    inventoryNextTetrominoInnerRectangle.setPosition(inventoryOuterRectangle.getPosition().x + 10, inventoryOuterRectangle.getPosition().y + 10);
    inventoryNextTetrominoInnerRectangle.setSize(sf::Vector2f(150, 90));
    inventoryNextTetrominoInnerRectangle.setFillColor(innerRectangleColor);

    inventoryInnerRectangle.setPosition(inventoryOuterRectangle.getPosition().x + 10, inventoryOuterRectangle.getPosition().y + 10 + inventoryNextTetrominoInnerRectangle.getSize().y);
    inventoryInnerRectangle.setSize(sf::Vector2f(150, 540));
    inventoryInnerRectangle.setFillColor(innerRectangleColor);

    // Score
    scoreOuterRectangle.setPosition(20, 15);
    scoreOuterRectangle.setSize(sf::Vector2f(170, 140));
    scoreOuterRectangle.setFillColor(sf::Color::Black);

    scoreTextLabelInnerRectangle.setPosition(scoreOuterRectangle.getPosition().x + 10, scoreOuterRectangle.getPosition().y + 10);
    scoreTextLabelInnerRectangle.setSize(sf::Vector2f(150, 60));
    scoreTextLabelInnerRectangle.setFillColor(innerRectangleColor);

    scoreValueInnerRectangle.setPosition(scoreOuterRectangle.getPosition().x + 10, scoreOuterRectangle.getPosition().y + 10 + scoreTextLabelInnerRectangle.getSize().y);
    scoreValueInnerRectangle.setSize(sf::Vector2f(150, 60));
    scoreValueInnerRectangle.setFillColor(innerRectangleColor);

    scoreTextLabel.setFont(font);
    scoreTextLabel.setCharacterSize(30);
    scoreTextLabel.setFillColor(sf::Color::White);
    scoreTextLabel.setString("Score");
    scoreTextLabel.setOrigin(scoreTextLabel.getLocalBounds().left + scoreTextLabel.getLocalBounds().width / 2.0f,
        scoreTextLabel.getLocalBounds().top + scoreTextLabel.getLocalBounds().height / 2.0f);
    scoreTextLabel.setPosition(scoreTextLabelInnerRectangle.getPosition().x + scoreTextLabelInnerRectangle.getLocalBounds().left + scoreTextLabelInnerRectangle.getLocalBounds().width / 2.0f,
        scoreTextLabelInnerRectangle.getPosition().y + scoreTextLabelInnerRectangle.getLocalBounds().top + scoreTextLabelInnerRectangle.getLocalBounds().height / 2.0f);

    scoreValue.setFont(font);
    scoreValue.setCharacterSize(30);
    scoreValue.setFillColor(sf::Color::White);
    scoreValue.setString("0");
    scoreValue.setOrigin(scoreValue.getLocalBounds().left + scoreValue.getLocalBounds().width / 2.0f,
        scoreValue.getLocalBounds().top + scoreValue.getLocalBounds().height / 2.0f);
    scoreValue.setPosition(scoreValueInnerRectangle.getPosition().x + scoreValueInnerRectangle.getLocalBounds().left + scoreValueInnerRectangle.getLocalBounds().width / 2.0f,
        scoreValueInnerRectangle.getPosition().y + scoreValueInnerRectangle.getLocalBounds().top + scoreValueInnerRectangle.getLocalBounds().height / 2.0f);

    // Combo
    comboOuterRectangle.setPosition(20, 185);
    comboOuterRectangle.setSize(sf::Vector2f(170, 140));
    comboOuterRectangle.setFillColor(sf::Color::Black);

    comboTextLabelInnerRectangle.setPosition(comboOuterRectangle.getPosition().x + 10, comboOuterRectangle.getPosition().y + 10);
    comboTextLabelInnerRectangle.setSize(sf::Vector2f(150, 60));
    comboTextLabelInnerRectangle.setFillColor(innerRectangleColor);

    comboValueInnerRectangle.setPosition(comboOuterRectangle.getPosition().x + 10, comboOuterRectangle.getPosition().y + 10 + comboTextLabelInnerRectangle.getSize().y);
    comboValueInnerRectangle.setSize(sf::Vector2f(150, 60));
    comboValueInnerRectangle.setFillColor(innerRectangleColor);

    comboTextLabel.setFont(font);
    comboTextLabel.setCharacterSize(30);
    comboTextLabel.setFillColor(sf::Color::White);
    comboTextLabel.setString("Combo");
    comboTextLabel.setOrigin(comboTextLabel.getLocalBounds().left + comboTextLabel.getLocalBounds().width / 2.0f,
        comboTextLabel.getLocalBounds().top + comboTextLabel.getLocalBounds().height / 2.0f);
    comboTextLabel.setPosition(comboTextLabelInnerRectangle.getPosition().x + comboTextLabelInnerRectangle.getLocalBounds().left + comboTextLabelInnerRectangle.getLocalBounds().width / 2.0f,
        comboTextLabelInnerRectangle.getPosition().y + comboTextLabelInnerRectangle.getLocalBounds().top + comboTextLabelInnerRectangle.getLocalBounds().height / 2.0f);

    comboValue.setFont(font);
    comboValue.setCharacterSize(30);
    comboValue.setFillColor(sf::Color::White);
    comboValue.setString("0");
    comboValue.setOrigin(comboValue.getLocalBounds().left + comboValue.getLocalBounds().width / 2.0f,
        comboValue.getLocalBounds().top + comboValue.getLocalBounds().height / 2.0f);
    comboValue.setPosition(comboValueInnerRectangle.getPosition().x + comboValueInnerRectangle.getLocalBounds().left + comboValueInnerRectangle.getLocalBounds().width / 2.0f,
        comboValueInnerRectangle.getPosition().y + comboValueInnerRectangle.getLocalBounds().top + comboValueInnerRectangle.getLocalBounds().height / 2.0f);

    // Lock Delay
    isLockDelayActive = false;
    lockDelayDuration = 1.0f;
    lockDelaySizeIncreaseStartValue = 0.0f;
    lockDelaySizeIncreaseEndValue = 20.0f;

    lockDelayBoardRectangleStartX = boardSprite.getPosition().x;
    lockDelayBoardRectangleStartY = boardSprite.getPosition().y;
    lockDelayBoardRectangleEndX = boardOuterRectangle.getPosition().x;
    lockDelayBoardRectangleEndY = boardOuterRectangle.getPosition().y;
    lockDelayBoardRectangle.setPosition(sf::Vector2f(lockDelayBoardRectangleStartX, lockDelayBoardRectangleStartY));
    lockDelayBoardRectangle.setSize(sf::Vector2f(boardSprite.getLocalBounds().width, boardSprite.getLocalBounds().height));
    lockDelayBoardRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));

    lockDelayScoreRectangleStartX = scoreTextLabelInnerRectangle.getPosition().x;
    lockDelayScoreRectangleStartY = scoreTextLabelInnerRectangle.getPosition().y;
    lockDelayScoreRectangleEndX = scoreOuterRectangle.getPosition().x;
    lockDelayScoreRectangleEndY = scoreOuterRectangle.getPosition().y;
    lockDelayScoreRectangle.setPosition(sf::Vector2f(lockDelayScoreRectangleStartX, lockDelayScoreRectangleStartY));
    lockDelayScoreRectangle.setSize(sf::Vector2f(scoreTextLabelInnerRectangle.getLocalBounds().width, scoreTextLabelInnerRectangle.getLocalBounds().height + scoreValueInnerRectangle.getLocalBounds().height));
    lockDelayScoreRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));

    lockDelayComboRectangleStartX = comboTextLabelInnerRectangle.getPosition().x;
    lockDelayComboRectangleStartY = comboTextLabelInnerRectangle.getPosition().y;
    lockDelayComboRectangleEndX = comboOuterRectangle.getPosition().x;
    lockDelayComboRectangleEndY = comboOuterRectangle.getPosition().y;
    lockDelayComboRectangle.setPosition(sf::Vector2f(lockDelayComboRectangleStartX, lockDelayComboRectangleStartY));
    lockDelayComboRectangle.setSize(sf::Vector2f(comboTextLabelInnerRectangle.getLocalBounds().width, comboTextLabelInnerRectangle.getLocalBounds().height + comboValueInnerRectangle.getLocalBounds().height));
    lockDelayComboRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));
    isComboActive = false;

    lockDelayInventoryTextLabelRectangleStartX = inventoryTextLabelInnerRectangle.getPosition().x;
    lockDelayInventoryTextLabelRectangleStartY = inventoryTextLabelInnerRectangle.getPosition().y;
    lockDelayInventoryTextLabelRectangleEndX = inventoryTextLabelOuterRectangle.getPosition().x;
    lockDelayInventoryTextLabelRectangleEndY = inventoryTextLabelOuterRectangle.getPosition().y;
    lockDelayInventoryTextLabelRectangle.setPosition(sf::Vector2f(lockDelayInventoryTextLabelRectangleStartX, lockDelayInventoryTextLabelRectangleStartY));
    lockDelayInventoryTextLabelRectangle.setSize(sf::Vector2f(inventoryTextLabelInnerRectangle.getLocalBounds().width, inventoryTextLabelInnerRectangle.getLocalBounds().height));
    lockDelayInventoryTextLabelRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));

    lockDelayInventoryRectangleStartX = inventoryNextTetrominoInnerRectangle.getPosition().x;
    lockDelayInventoryRectangleStartY = inventoryNextTetrominoInnerRectangle.getPosition().y;
    lockDelayInventoryRectangleEndX = inventoryOuterRectangle.getPosition().x;
    lockDelayInventoryRectangleEndY = inventoryOuterRectangle.getPosition().y;
    lockDelayInventoryRectangle.setPosition(sf::Vector2f(lockDelayInventoryRectangleStartX, lockDelayInventoryRectangleStartY));
    lockDelayInventoryRectangle.setSize(sf::Vector2f(inventoryNextTetrominoInnerRectangle.getLocalBounds().width, inventoryNextTetrominoInnerRectangle.getLocalBounds().height + inventoryInnerRectangle.getLocalBounds().height));
    lockDelayInventoryRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));

    // Observer
    managerScore.addObserver(&observerScore);
    managerCombo.addObserver(&observerCombo);

    // Color
    colorChangeCycle = 2.0f;
    inventoryNextTetrominoInnerRectangleStartColor.r = 25;
    inventoryNextTetrominoInnerRectangleStartColor.g = 25;
    inventoryNextTetrominoInnerRectangleStartColor.b = 25;

    inventoryNextTetrominoInnerRectangleEndColor.r = 75;
    inventoryNextTetrominoInnerRectangleEndColor.g = 75;
    inventoryNextTetrominoInnerRectangleEndColor.b = 75;

    innerRectangleColor.r = 25;
    innerRectangleColor.g = 25;
    innerRectangleColor.b = 25;

    commandMoveDown = new CommandMoveDown(fallingTetromino);
    durationBeforeFallingTetrominoMovesDown = 0.5f;
    gameOver = false;
}

sf::Color Tetris::colorPicker(TetrominoColor color)
{
    switch (color)
    {
    case TetrominoColor::Red:
    {
        sf::Color temporaryColor(255, 0, 0);
        return temporaryColor;
    }
    case TetrominoColor::Orange:
    {
        sf::Color temporaryColor(255, 128, 0);
        return temporaryColor;
    }
    case TetrominoColor::Yellow:
    {
        sf::Color temporaryColor(255, 255, 0);
        return temporaryColor;
    }
    case TetrominoColor::Green:
    {
        sf::Color temporaryColor(0, 255, 0);
        return temporaryColor;
    }
    case TetrominoColor::Cyan:
    {
        sf::Color temporaryColor(0, 255, 255);
        return temporaryColor;
    }
    case TetrominoColor::Blue:
    {
        sf::Color temporaryColor(0, 0, 255);
        return temporaryColor;
    }
    case TetrominoColor::Purple:
    {
        sf::Color temporaryColor(255, 0, 255);
        return temporaryColor;
    }
    default:
    {
        return sf::Color::Black;
    }
    }
}

void Tetris::setTetrominoStartingPosition(Tetromino* tetromino, int startRow, int startColumn)
{
    std::vector<Square> squares;

    for (int i = 0; i < tetromino->getShapeMatrix().size(); ++i)
    {
        for (int j = 0; j < tetromino->getShapeMatrix()[i].size(); ++j)
        {
            if (tetromino->getShapeMatrix()[i][j] == 1)
            {
                if (tetromino->getShape() == TetrominoShape::Shape_O)
                {
                    squares.push_back(Square(j + startColumn + 1, i + startRow));
                }
                else
                {
                    squares.push_back(Square(j + startColumn, i + startRow));
                }
            }
        }
    }

    tetromino->setSquares(squares);
}

bool Tetris::isValidPosition(std::vector<Square> nextPosition)
{
    for (int i = 0; i < 4; i++)
    {
        if (nextPosition[i].getX() < 0 || nextPosition[i].getX() >= BOARD_COLUMNS || nextPosition[i].getY()  < 0 || nextPosition[i].getY() >= BOARD_ROWS)
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

void Tetris::lockTetromino()
{
    for (int i = 0; i < fallingTetromino->getSquares().size(); ++i) 
    {
        int x = fallingTetromino->getSquares()[i].getX();
        int y = fallingTetromino->getSquares()[i].getY();

        board[y][x] = static_cast<int>(fallingTetromino->getColor());
    }

    audio.getSfxFloor().play();
}

void Tetris::clearFullLines()
{
    bool noLinesCleared = true;

    for (int row = 0; row < BOARD_ROWS; ++row)
    {
        bool isFull = true;

        for (int col = 0; col < BOARD_COLUMNS; ++col)
        {
            if (!board[row][col])
            {
                isFull = false;
                break;
            }
        }

        if (isFull)
        {
            noLinesCleared = false;

            audio.getSfxClearLine().play();
            managerScore.increaseScore(10);

            for (int r = row; r > 0; --r)
            {
                board[r] = board[r - 1];
            }

            board[0] = std::vector<int>(BOARD_COLUMNS, 0);
            --row;
        }
    }
    
    if (noLinesCleared)
    {
        managerCombo.resetCombo();
    }
    else
    {
        managerCombo.increaseCombo(1);
    }

    comboCheck();
}

void Tetris::resetFallingTetromino()
{
    delete fallingTetromino;
    delete ghostTetromino;
    delete commandMoveDown;

    fallingTetromino = new Tetromino(*inventory[0]);
    ghostTetromino = new Tetromino(*inventory[0]);
    commandMoveDown = new CommandMoveDown(fallingTetromino);

    inventory.erase(inventory.begin());
    inventory.push_back(director.createRandomTetromino());
    setTetrominoStartingPosition(fallingTetromino, -1, 4);
    setTetrominoStartingPosition(ghostTetromino, -1, 4);

    lockDelayBoardRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));
    lockDelayScoreRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));
    lockDelayComboRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));
    lockDelayInventoryTextLabelRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));
    lockDelayInventoryRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));
}

void Tetris::hardDrop()
{
    std::vector<Square> nextPosition = fallingTetromino->getSquares();

    while (true)
    {
        for (int i = 0; i < 4; i++)
        {
            nextPosition[i].setY(fallingTetromino->getSquares()[i].getY() + 1);
        }

        if (isValidPosition(nextPosition))
        {
            fallingTetromino->setSquares(nextPosition);
        }
        else
        {
            break;
        }
    }

    audio.getSfxHardDrop().play();
}

bool Tetris::isGameOver()
{
    for (int column = 0; column < BOARD_COLUMNS; ++column)
    {
        if (board[2][column])
        {
            return true;
        }
    }

    return false;
}

void Tetris::lockDelayRectangleReset()
{
    lockDelayClock.restart();
    isLockDelayActive = false;

    lockDelayBoardRectangle.setPosition(sf::Vector2f(lockDelayBoardRectangleStartX, lockDelayBoardRectangleStartY));
    lockDelayBoardRectangle.setSize(sf::Vector2f(boardSprite.getLocalBounds().width, boardSprite.getLocalBounds().height));

    lockDelayScoreRectangle.setPosition(sf::Vector2f(lockDelayScoreRectangleStartX, lockDelayScoreRectangleStartY));
    lockDelayScoreRectangle.setSize(sf::Vector2f(scoreTextLabelInnerRectangle.getLocalBounds().width, scoreTextLabelInnerRectangle.getLocalBounds().height + scoreValueInnerRectangle.getLocalBounds().height));

    lockDelayComboRectangle.setPosition(sf::Vector2f(lockDelayComboRectangleStartX, lockDelayComboRectangleStartY));
    lockDelayComboRectangle.setSize(sf::Vector2f(comboTextLabelInnerRectangle.getLocalBounds().width, comboTextLabelInnerRectangle.getLocalBounds().height + comboValueInnerRectangle.getLocalBounds().height));

    lockDelayInventoryTextLabelRectangle.setPosition(sf::Vector2f(lockDelayInventoryTextLabelRectangleStartX, lockDelayInventoryTextLabelRectangleStartY));
    lockDelayInventoryTextLabelRectangle.setSize(sf::Vector2f(inventoryTextLabelInnerRectangle.getLocalBounds().width, inventoryTextLabelInnerRectangle.getLocalBounds().height));

    lockDelayInventoryRectangle.setPosition(sf::Vector2f(lockDelayInventoryRectangleStartX, lockDelayInventoryRectangleStartY));
    lockDelayInventoryRectangle.setSize(sf::Vector2f(inventoryInnerRectangle.getLocalBounds().width, inventoryInnerRectangle.getLocalBounds().height));
}

void Tetris::comboCheck()
{
    switch (managerCombo.getComboCount())
    {
    case 0:
    {
        isComboActive = false;
        break;
    }
    case 1:
    {
        isComboActive = false;
        //audio.getSfxCombo_1().play();
        break;
    }
    case 2:
    {
        isComboActive = true;
        audio.getSfxCombo_2().play();
        break;
    }
    case 3:
    {
        isComboActive = true;
        audio.getSfxCombo_3().play();
        break;
    }
    case 4:
    {
        isComboActive = true;
        audio.getSfxCombo_4().play();
        break;
    }
    case 5:
    {
        isComboActive = true;
        audio.getSfxCombo_5().play();
        break;
    }
    case 6:
    {
        isComboActive = true;
        audio.getSfxCombo_6().play();
        break;
    }
    case 7:
    {
        isComboActive = true;
        audio.getSfxCombo_7().play();
        break;
    }
    case 8:
    {
        isComboActive = true;
        audio.getSfxCombo_8().play();
        break;
    }
    case 9:
    {
        isComboActive = true;
        audio.getSfxCombo_9().play();
        break;
    }
    case 10:
    {
        isComboActive = true;
        audio.getSfxCombo_10().play();
        break;
    }
    case 11:
    {
        isComboActive = true;
        audio.getSfxCombo_11().play();
        break;
    }
    case 12:
    {
        isComboActive = true;
        audio.getSfxCombo_12().play();
        break;
    }
    case 13:
    {
        isComboActive = true;
        audio.getSfxCombo_13().play();
        break;
    }
    case 14:
    {
        isComboActive = true;
        audio.getSfxCombo_14().play();
        break;
    }
    case 15:
    {
        isComboActive = true;
        audio.getSfxCombo_15().play();
        break;
    }
    case 16:
    {
        isComboActive = true;
        audio.getSfxCombo_16().play();
        break;
    }
    }

    comboValue.setString(std::to_string(managerCombo.getComboCount()));
    comboValue.setOrigin(comboValue.getLocalBounds().left + comboValue.getLocalBounds().width / 2.0f,
        comboValue.getLocalBounds().top + comboValue.getLocalBounds().height / 2.0f);
    comboValue.setPosition(comboValueInnerRectangle.getPosition().x + comboValueInnerRectangle.getLocalBounds().left + comboValueInnerRectangle.getLocalBounds().width / 2.0f,
        comboValueInnerRectangle.getPosition().y + comboValueInnerRectangle.getLocalBounds().top + comboValueInnerRectangle.getLocalBounds().height / 2.0f);
}

void Tetris::handleInput(sf::Event event)
{
    if (!isGameOver())
    {
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
            {        
                CommandMoveLeft* commandMoveLeft = new CommandMoveLeft(fallingTetromino);
                std::vector<Square> nextPosition;
                nextPosition = fallingTetromino->getSquares();

                for (int i = 0; i < 4; i++)
                {
                    nextPosition[i].setX(fallingTetromino->getSquares()[i].getX() - 1);
                }

                if (isValidPosition(nextPosition))
                {
                    commandMoveLeft->execute();
                    audio.getSfxMove().play();
                }

                if (isLockDelayActive)
                {
                    lockDelayRectangleReset();
                }

                delete commandMoveLeft;
                break;
            }
            case sf::Keyboard::Right:
            {
                CommandMoveRight* commandMoveRight = new CommandMoveRight(fallingTetromino);
                std::vector<Square> nextPosition;
                nextPosition = fallingTetromino->getSquares();

                for (int i = 0; i < 4; i++)
                {
                    nextPosition[i].setX(fallingTetromino->getSquares()[i].getX() + 1);
                }

                if (isValidPosition(nextPosition))
                {
                    commandMoveRight->execute();
                    audio.getSfxMove().play();
                }

                if (isLockDelayActive)
                {
                    lockDelayRectangleReset();
                }

                delete commandMoveRight;
                break;
            }
            case sf::Keyboard::Up:
            {
                Tetromino* temporaryTetromino = new Tetromino(*fallingTetromino);
                CommandRotate* temporaryCommandRotate = new CommandRotate(temporaryTetromino);
                temporaryCommandRotate->execute();

                if (isValidPosition(temporaryTetromino->getSquares()))
                {
                    fallingTetromino->setShapeMatrix(temporaryTetromino->getShapeMatrix());
                    fallingTetromino->setSquares(temporaryTetromino->getSquares());

                    audio.getSfxRotate().play();
                }

                delete temporaryTetromino;
                delete temporaryCommandRotate;
                break;
            }
            case sf::Keyboard::Down:
            {
                hardDrop();

                if (!isLockDelayActive)
                {
                    lockDelayClock.restart();
                    isLockDelayActive = true;
                }
                else
                {
                    if (lockDelayClock.getElapsedTime().asSeconds() >= lockDelayDuration)
                    {
                        lockTetromino();
                        lockDelayRectangleReset();

                        if (isGameOver())
                        {
                            gameOver = true;

                            delete fallingTetromino;
                            delete ghostTetromino;

                            for (Tetromino* tetromino : inventory)
                            {
                                delete tetromino;
                            }
                        }
                        else
                        {
                            clearFullLines();
                            resetFallingTetromino();
                        }
                    }
                }

                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
}

void Tetris::update(float deltaTime)
{
    if (!isGameOver())
    {
        ghostTetromino->setSquares(fallingTetromino->getSquares());

        for (int i = 0; i < 4; i++)
        {
            while (isValidPosition(ghostTetromino->getSquares()))
            {
                for (int i = 0; i < 4; i++)
                {
                    ghostTetromino->getSquares()[i].setY(ghostTetromino->getSquares()[i].getY() + 1);
                }
            }

            for (int j = 0; j < 4; j++)
            {
                ghostTetromino->getSquares()[j].setY(ghostTetromino->getSquares()[j].getY() - 1);
            }
        }

        if (clockForFallingTetromino.getElapsedTime().asSeconds() >= durationBeforeFallingTetrominoMovesDown)
        {
            std::vector<Square> nextPosition;
            nextPosition = fallingTetromino->getSquares();

            for (int i = 0; i < 4; i++)
            {
                nextPosition[i].setY(fallingTetromino->getSquares()[i].getY() + 1);
            }

            if (isValidPosition(nextPosition))
            {
                commandMoveDown->execute();

                if (isLockDelayActive)
                {
                    lockDelayRectangleReset();
                }

                clockForFallingTetromino.restart();
            }
            else
            {
                if (!isLockDelayActive)
                {
                    lockDelayClock.restart();
                    isLockDelayActive = true;
                }
                else
                {
                    if (lockDelayClock.getElapsedTime().asSeconds() >= lockDelayDuration)
                    {
                        lockTetromino();
                        lockDelayRectangleReset();

                        if (isGameOver())
                        {
                            gameOver = true;

                            delete fallingTetromino;
                            delete ghostTetromino;

                            for (Tetromino* tetromino : inventory)
                            {
                                delete tetromino;
                            }
                        }
                        else
                        {
                            clearFullLines();
                            resetFallingTetromino();
                        }
                    }
                }
            }
        }

        scoreValue.setString(std::to_string(managerScore.getScore()));
        scoreValue.setOrigin(scoreValue.getLocalBounds().left + scoreValue.getLocalBounds().width / 2.0f,
            scoreValue.getLocalBounds().top + scoreValue.getLocalBounds().height / 2.0f);
        scoreValue.setPosition(scoreValueInnerRectangle.getPosition().x + scoreValueInnerRectangle.getLocalBounds().left + scoreValueInnerRectangle.getLocalBounds().width / 2.0f,
            scoreValueInnerRectangle.getPosition().y + scoreValueInnerRectangle.getLocalBounds().top + scoreValueInnerRectangle.getLocalBounds().height / 2.0f);

        if (isLockDelayActive)
        {
            float elapsed = lockDelayClock.getElapsedTime().asSeconds();

            if (elapsed <= lockDelayDuration)
            {
                float t = elapsed / lockDelayDuration;

                float currentLockDelayBoardRectangleSizeX = lockDelayBoardRectangleStartX + t * (lockDelayBoardRectangleEndX - lockDelayBoardRectangleStartX);
                float currentLockDelayBoardRectangleSizeY = lockDelayBoardRectangleStartY + t * (lockDelayBoardRectangleEndY - lockDelayBoardRectangleStartY);

                float currentLockDelayScoreRectangleSizeX = lockDelayScoreRectangleStartX + t * (lockDelayScoreRectangleEndX - lockDelayScoreRectangleStartX);
                float currentLockDelayScoreRectangleSizeY = lockDelayScoreRectangleStartY + t * (lockDelayScoreRectangleEndY - lockDelayScoreRectangleStartY);

                float currentLockDelayComboRectangleSizeX = lockDelayComboRectangleStartX + t * (lockDelayComboRectangleEndX - lockDelayComboRectangleStartX);
                float currentLockDelayComboRectangleSizeY = lockDelayComboRectangleStartY + t * (lockDelayComboRectangleEndY - lockDelayComboRectangleStartY);

                float currentLockDelayInventoryTextLabelRectangleSizeX = lockDelayInventoryTextLabelRectangleStartX + t * (lockDelayInventoryTextLabelRectangleEndX - lockDelayInventoryTextLabelRectangleStartX);
                float currentLockDelayInventoryTextLabelRectangleSizeY = lockDelayInventoryTextLabelRectangleStartY + t * (lockDelayInventoryTextLabelRectangleEndY - lockDelayInventoryTextLabelRectangleStartY);

                float currentLockDelayInventoryRectangleSizeX = lockDelayInventoryRectangleStartX + t * (lockDelayInventoryRectangleEndX - lockDelayInventoryRectangleStartX);
                float currentLockDelayInventoryRectangleSizeY = lockDelayInventoryRectangleStartY + t * (lockDelayInventoryRectangleEndY - lockDelayInventoryRectangleStartY);

                float currentLockDelaySizeIncreaseValue = lockDelaySizeIncreaseStartValue + t * (lockDelaySizeIncreaseEndValue - lockDelaySizeIncreaseStartValue);

                lockDelayBoardRectangle.setSize(sf::Vector2f(boardSprite.getLocalBounds().width + currentLockDelaySizeIncreaseValue,
                    boardSprite.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
                lockDelayBoardRectangle.setPosition(currentLockDelayBoardRectangleSizeX, currentLockDelayBoardRectangleSizeY);

                lockDelayScoreRectangle.setSize(sf::Vector2f(scoreTextLabelInnerRectangle.getLocalBounds().width + currentLockDelaySizeIncreaseValue,
                    scoreTextLabelInnerRectangle.getLocalBounds().height + scoreValueInnerRectangle.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
                lockDelayScoreRectangle.setPosition(currentLockDelayScoreRectangleSizeX, currentLockDelayScoreRectangleSizeY);

                lockDelayComboRectangle.setSize(sf::Vector2f(comboTextLabelInnerRectangle.getLocalBounds().width + currentLockDelaySizeIncreaseValue,
                    comboTextLabelInnerRectangle.getLocalBounds().height + comboValueInnerRectangle.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
                lockDelayComboRectangle.setPosition(currentLockDelayComboRectangleSizeX, currentLockDelayComboRectangleSizeY);

                lockDelayInventoryTextLabelRectangle.setSize(sf::Vector2f(inventoryTextLabelInnerRectangle.getLocalBounds().width + currentLockDelaySizeIncreaseValue,
                    inventoryTextLabelInnerRectangle.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
                lockDelayInventoryTextLabelRectangle.setPosition(currentLockDelayInventoryTextLabelRectangleSizeX, currentLockDelayInventoryTextLabelRectangleSizeY);

                lockDelayInventoryRectangle.setSize(sf::Vector2f(inventoryNextTetrominoInnerRectangle.getLocalBounds().width + currentLockDelaySizeIncreaseValue,
                    inventoryNextTetrominoInnerRectangle.getLocalBounds().height + inventoryInnerRectangle.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
                lockDelayInventoryRectangle.setPosition(currentLockDelayInventoryRectangleSizeX, currentLockDelayInventoryRectangleSizeY);
            }
            else
            {
                isLockDelayActive = false;
            }
        }

        float elapsed = colorClock.getElapsedTime().asSeconds();
        float progress = fmod(elapsed, colorChangeCycle) / colorChangeCycle;

        if (progress < 0.5f)
        {
            float t = progress * colorChangeCycle;
            sf::Uint8 r = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleStartColor.r + t * (inventoryNextTetrominoInnerRectangleEndColor.r - inventoryNextTetrominoInnerRectangleStartColor.r));
            sf::Uint8 g = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleStartColor.g + t * (inventoryNextTetrominoInnerRectangleEndColor.g - inventoryNextTetrominoInnerRectangleStartColor.g));
            sf::Uint8 b = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleStartColor.b + t * (inventoryNextTetrominoInnerRectangleEndColor.b - inventoryNextTetrominoInnerRectangleStartColor.b));
            inventoryNextTetrominoInnerRectangle.setFillColor(sf::Color(r, g, b));
        }
        else
        {
            float t = (progress - 0.5f) * colorChangeCycle;
            sf::Uint8 r = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleEndColor.r - t * (inventoryNextTetrominoInnerRectangleEndColor.r - inventoryNextTetrominoInnerRectangleStartColor.r));
            sf::Uint8 g = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleEndColor.g - t * (inventoryNextTetrominoInnerRectangleEndColor.g - inventoryNextTetrominoInnerRectangleStartColor.g));
            sf::Uint8 b = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleEndColor.b - t * (inventoryNextTetrominoInnerRectangleEndColor.b - inventoryNextTetrominoInnerRectangleStartColor.b));
            inventoryNextTetrominoInnerRectangle.setFillColor(sf::Color(r, g, b));
        }
    }
}

void Tetris::render(sf::RenderWindow& window)
{
    if (!isGameOver())
    {
        // Draw Background
        window.draw(backgroundSprite);

        // Draw Board
        window.draw(boardOuterRectangle);
        window.draw(lockDelayBoardRectangle);
        window.draw(boardSprite);
        window.draw(boardGameOverLineSprite);

        // Draw Score
        window.draw(scoreOuterRectangle);
        window.draw(lockDelayScoreRectangle);
        window.draw(scoreTextLabelInnerRectangle);
        window.draw(scoreValueInnerRectangle);
        window.draw(scoreTextLabel);
        window.draw(scoreValue);

        // Draw Combo
        if (isComboActive)
        {
            window.draw(comboOuterRectangle);
            window.draw(lockDelayComboRectangle);
            window.draw(comboTextLabelInnerRectangle);
            window.draw(comboValueInnerRectangle);
            window.draw(comboTextLabel);
            window.draw(comboValue);
        }

        // Draw Inventory
        window.draw(inventoryTextLabelOuterRectangle);
        window.draw(lockDelayInventoryTextLabelRectangle);
        window.draw(inventoryTextLabelInnerRectangle);
        window.draw(inventoryTextLabel);

        window.draw(inventoryOuterRectangle);
        window.draw(lockDelayInventoryRectangle);
        window.draw(inventoryNextTetrominoInnerRectangle);
        window.draw(inventoryInnerRectangle);

        // Draw Tetromino
        for (int index = 0; index < 4; index++)
        {
            tetrominoSprite.setTextureRect(sf::IntRect((int)fallingTetromino->getColor() * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE));
            tetrominoSprite.setPosition(fallingTetromino->getSquares()[index].getX() * TEXTURE_SIZE + 220, fallingTetromino->getSquares()[index].getY() * TEXTURE_SIZE + 25);
            window.draw(tetrominoSprite);
        }

        // Draw Ghost Tetromino
        for (int index = 0; index < 4; ++index)
        {
            ghostTetrominoSprite.setTextureRect(sf::IntRect((int)ghostTetromino->getColor() * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE));
            ghostTetrominoSprite.setPosition(ghostTetromino->getSquares()[index].getX() * TEXTURE_SIZE + 220, ghostTetromino->getSquares()[index].getY() * TEXTURE_SIZE + 25);
            window.draw(ghostTetrominoSprite);
        }

        // Draw Inventory Tetrominos
        for (int index = 0; index < inventory.size(); ++index)
        {
            for (int row = 0; row < inventory[index]->getShapeMatrix().size(); ++row)
            {
                for (int column = 0; column < inventory[index]->getShapeMatrix().size(); ++column)
                {
                    int offsetFromInventoryInnerRectangle = TEXTURE_SIZE / 2;
                    int additionalOffsetX = 0;
                    int additionalOffsetY = 0;

                    if (inventory[index]->getShapeMatrix()[column][row])
                    {
                        
                        if (inventory[index]->getShape() == TetrominoShape::Shape_I)
                        {
                            additionalOffsetY -= TEXTURE_SIZE / 2;
                        }
                        else if (inventory[index]->getShape() == TetrominoShape::Shape_O)
                        {
                            additionalOffsetX += TEXTURE_SIZE;
                        }
                        else
                        {
                            additionalOffsetX += TEXTURE_SIZE / 2;
                        }

                        tetrominoSprite.setTextureRect(sf::IntRect((int)inventory[index]->getColor() * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE));

                        tetrominoSprite.setPosition(inventoryNextTetrominoInnerRectangle.getGlobalBounds().left + offsetFromInventoryInnerRectangle + additionalOffsetX + TEXTURE_SIZE * row,
                            inventoryNextTetrominoInnerRectangle.getGlobalBounds().top + offsetFromInventoryInnerRectangle + additionalOffsetY + (3 * TEXTURE_SIZE * index) + TEXTURE_SIZE * column);

                        //tetrominoSprite.setPosition(605 + offsetFromBoardX + TEXTURE_SIZE * row, 84 + offsetFromBoardY + (90 * index) + TEXTURE_SIZE * column);
                        window.draw(tetrominoSprite);
                    }
                }
            }
        }

        // Draw Placed Tetrominos
        for (int row = 0; row < BOARD_ROWS; ++row)
        {
            for (int column = 0; column < BOARD_COLUMNS; ++column)
            {
                if (board[row][column] != 0)
                {
                    sf::RectangleShape block(sf::Vector2f(TEXTURE_SIZE, TEXTURE_SIZE));
                    tetrominoSprite.setPosition(boardSprite.getPosition().x + column * TEXTURE_SIZE, boardSprite.getPosition().y + row * TEXTURE_SIZE);
                    tetrominoSprite.setTextureRect(sf::IntRect(board[row][column] * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE));
                    window.draw(tetrominoSprite);
                }
            }
        }
    }
}