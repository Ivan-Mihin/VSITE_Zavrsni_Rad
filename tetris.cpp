#include "tetris.h"

void Tetris::initialize()
{
    innerRectangleColor.r = 25;
    innerRectangleColor.g = 25;
    innerRectangleColor.b = 25;

    audio.getSfxTetrisThemeSong().setLoop(true);
    audio.getSfxTetrisThemeSong().setVolume(15);
    audio.getSfxTetrisThemeSong().play();

    background.loadFromFile("Resources/Sprites/main_menu_background.png");
    backgroundSprite.setTexture(background);
    backgroundSprite.setPosition(0, 0);

    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    // Tetromino
    fallingTetromino = director.createRandomTetromino();
    ghostTetromino = new Tetromino(*fallingTetromino);
    heldTetromino = new HeldTetromino();
    heldTetromino->setLockDelayColor(colorPicker(fallingTetromino->getColor()));

	for (int i = 0; i < 7; ++i)
	{
		inventory.push_back(director.createRandomTetromino());
	}

    setTetrominoPosition(fallingTetromino, 0, 4);
    setTetrominoPosition(ghostTetromino, 0, 4);

    board.setColor(colorPicker(fallingTetromino->getColor()));

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

    // Lock Delay
    isLockDelayActive = false;
    lockDelayDuration = 1.0f;
    lockDelaySizeIncreaseStartValue = 0.0f;
    lockDelaySizeIncreaseEndValue = 20.0f;

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
    observerScore.setLockDelayColor(colorPicker(fallingTetromino->getColor()));
    observerCombo.setLockDelayColor(colorPicker(fallingTetromino->getColor()));

    // Color
    colorChangeCycle = 2.0f;
    inventoryNextTetrominoInnerRectangleStartColor.r = 25;
    inventoryNextTetrominoInnerRectangleStartColor.g = 25;
    inventoryNextTetrominoInnerRectangleStartColor.b = 25;

    inventoryNextTetrominoInnerRectangleEndColor.r = 75;
    inventoryNextTetrominoInnerRectangleEndColor.g = 75;
    inventoryNextTetrominoInnerRectangleEndColor.b = 75;

    durationBeforeFallingTetrominoMovesDown = 0.5f;

    gameOver = false;
}

sf::Color Tetris::colorPicker(TetrominoColor color)
{
    switch (color)
    {
    case TetrominoColor::Red:   { sf::Color temporaryColor(255, 0, 0);    return temporaryColor; }
    case TetrominoColor::Orange:{ sf::Color temporaryColor(255, 128, 0);  return temporaryColor; }
    case TetrominoColor::Yellow:{ sf::Color temporaryColor(255, 255, 0);  return temporaryColor; }
    case TetrominoColor::Green: { sf::Color temporaryColor(0, 255, 0);    return temporaryColor; }
    case TetrominoColor::Cyan:  { sf::Color temporaryColor(0, 255, 255);  return temporaryColor; }
    case TetrominoColor::Blue:  { sf::Color temporaryColor(0, 0, 255);    return temporaryColor; }
    case TetrominoColor::Purple:{ sf::Color temporaryColor(255, 0, 255);  return temporaryColor; }
    }
}

bool Tetris::isGameOver()
{
    for (int column = 0; column < board.BOARD_COLUMNS; ++column)
    {
        if (board.getBoard()[2][column])
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

    board.resetLockDelayRectangle();
    observerScore.resetLockDelayRectangle();
    heldTetromino->resetLockDelayRectangle();
    observerCombo.resetLockDelayRectangle();

    lockDelayInventoryTextLabelRectangle.setPosition(sf::Vector2f(lockDelayInventoryTextLabelRectangleStartX, lockDelayInventoryTextLabelRectangleStartY));
    lockDelayInventoryTextLabelRectangle.setSize(sf::Vector2f(inventoryTextLabelInnerRectangle.getLocalBounds().width, inventoryTextLabelInnerRectangle.getLocalBounds().height));

    lockDelayInventoryRectangle.setPosition(sf::Vector2f(lockDelayInventoryRectangleStartX, lockDelayInventoryRectangleStartY));
    lockDelayInventoryRectangle.setSize(sf::Vector2f(inventoryInnerRectangle.getLocalBounds().width, inventoryInnerRectangle.getLocalBounds().height));
}

void Tetris::lockTetromino()
{
    for (int i = 0; i < fallingTetromino->getSquares().size(); ++i)
    {
        int x = fallingTetromino->getSquares()[i].getX();
        int y = fallingTetromino->getSquares()[i].getY();

        board.getBoard()[y][x] = static_cast<int>(fallingTetromino->getColor());
    }

    audio.getSfxFloor().play();
}

void Tetris::resetColors()
{
    board.setColor(colorPicker(fallingTetromino->getColor()));
    observerScore.setLockDelayColor(colorPicker(fallingTetromino->getColor()));
    heldTetromino->setLockDelayColor(colorPicker(fallingTetromino->getColor()));
    observerCombo.setLockDelayColor(colorPicker(fallingTetromino->getColor()));
    lockDelayInventoryTextLabelRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));
    lockDelayInventoryRectangle.setFillColor(colorPicker(fallingTetromino->getColor()));
}

void Tetris::resetFallingTetromino()
{
    delete fallingTetromino;
    delete ghostTetromino;

    fallingTetromino = new Tetromino(*inventory[0]);
    ghostTetromino = new Tetromino(*inventory[0]);
    inventory.erase(inventory.begin());
    inventory.push_back(director.createRandomTetromino());

    setTetrominoPosition(fallingTetromino, 0, 4);
    setTetrominoPosition(ghostTetromino, 0, 4);
    resetColors();

    clockForFallingTetromino.restart();
}

void Tetris::setTetrominoPosition(Tetromino* tetromino, int startRow, int startColumn)
{
    std::vector<Square> squares;

    for (int i = 0; i < tetromino->getShapeMatrix().size(); ++i)
    {
        for (int j = 0; j < tetromino->getShapeMatrix()[i].size(); ++j)
        {
            if (tetromino->getShapeMatrix()[i][j])
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

void Tetris::handleInput(sf::Event event)
{
    if (!isGameOver())
    {
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
            case sf::Keyboard::A:
            {        
                CommandMoveLeft* commandMoveLeft = new CommandMoveLeft(fallingTetromino);
                std::vector<Square> nextPosition;
                nextPosition = fallingTetromino->getSquares();

                for (int i = 0; i < 4; ++i)
                {
                    nextPosition[i].setX(fallingTetromino->getSquares()[i].getX() - 1);
                }

                if (board.isValidPosition(nextPosition))
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
            case sf::Keyboard::D:
            {
                CommandMoveRight* commandMoveRight = new CommandMoveRight(fallingTetromino);
                std::vector<Square> nextPosition;
                nextPosition = fallingTetromino->getSquares();

                for (int i = 0; i < 4; ++i)
                {
                    nextPosition[i].setX(fallingTetromino->getSquares()[i].getX() + 1);
                }

                if (board.isValidPosition(nextPosition))
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
            case sf::Keyboard::W:
            {
                Tetromino* temporaryTetromino = new Tetromino(*fallingTetromino);
                CommandRotate* temporaryCommandRotate = new CommandRotate(temporaryTetromino);
                temporaryCommandRotate->execute();

                if (board.isValidPosition(temporaryTetromino->getSquares()))
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
            case sf::Keyboard::S:
            {
                CommandHardDrop* commandHardDrop = new CommandHardDrop(fallingTetromino, board);
                commandHardDrop->execute();

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
                            board.clearFullLines(&managerScore, &managerCombo, &observerCombo);
                            resetFallingTetromino();
                        }
                    }
                }

                break;
            }
            case sf::Keyboard::Space:
            {
                if (!heldTetromino->isTetrominoHeld)
                {
                    heldTetromino->isTetrominoHeld = true;

                    switch (fallingTetromino->getShape())
                    {
                    case TetrominoShape::Shape_I:
                    {
                        IShapeBuilder iShapeTetromino;
                        heldTetromino->setTetromino(director.createTetromino(iShapeTetromino));
                        break;
                    }
                    case TetrominoShape::Shape_J:
                    {
                        JShapeBuilder jShapeTetromino;
                        heldTetromino->setTetromino(director.createTetromino(jShapeTetromino));
                        break;
                    }
                    case TetrominoShape::Shape_L:
                    {
                        LShapeBuilder lShapeTetromino;
                        heldTetromino->setTetromino(director.createTetromino(lShapeTetromino));
                        break;
                    }
                    case TetrominoShape::Shape_O:
                    {
                        OShapeBuilder oShapeTetromino;
                        heldTetromino->setTetromino(director.createTetromino(oShapeTetromino));
                        break;
                    }
                    case TetrominoShape::Shape_S:
                    {
                        SShapeBuilder sShapeTetromino;
                        heldTetromino->setTetromino(director.createTetromino(sShapeTetromino));
                        break;
                    }
                    case TetrominoShape::Shape_T:
                    {
                        TShapeBuilder tShapeTetromino;
                        heldTetromino->setTetromino(director.createTetromino(tShapeTetromino));
                        break;
                    }
                    case TetrominoShape::Shape_Z:
                    {
                        ZShapeBuilder zShapeTetromino;
                        heldTetromino->setTetromino(director.createTetromino(zShapeTetromino));
                        break;
                    }
                    }

                    resetFallingTetromino();
                }
                else
                {
                    Tetromino* temporaryTetromino;

                    switch (fallingTetromino->getShape())
                    {
                    case TetrominoShape::Shape_I:
                    {
                        IShapeBuilder iShapeTetromino;
                        temporaryTetromino = director.createTetromino(iShapeTetromino);
                        break;
                    }
                    case TetrominoShape::Shape_J:
                    {
                        JShapeBuilder jShapeTetromino;
                        temporaryTetromino = director.createTetromino(jShapeTetromino);
                        break;
                    }
                    case TetrominoShape::Shape_L:
                    {
                        LShapeBuilder lShapeTetromino;
                        temporaryTetromino = director.createTetromino(lShapeTetromino);
                        break;
                    }
                    case TetrominoShape::Shape_O:
                    {
                        OShapeBuilder oShapeTetromino;
                        temporaryTetromino = director.createTetromino(oShapeTetromino);
                        break;
                    }
                    case TetrominoShape::Shape_S:
                    {
                        SShapeBuilder sShapeTetromino;
                        temporaryTetromino = director.createTetromino(sShapeTetromino);
                        break;
                    }
                    case TetrominoShape::Shape_T:
                    {
                        TShapeBuilder tShapeTetromino;
                        temporaryTetromino = director.createTetromino(tShapeTetromino);
                        break;
                    }
                    case TetrominoShape::Shape_Z:
                    {
                        ZShapeBuilder zShapeTetromino;
                        temporaryTetromino = director.createTetromino(zShapeTetromino);
                        break;
                    }
                    default:
                    {
                        IShapeBuilder iShapeTetromino;
                        temporaryTetromino = director.createTetromino(iShapeTetromino);
                        break;
                    }
                    }

                    fallingTetromino = new Tetromino(*heldTetromino->getTetromino());
                    heldTetromino->setTetromino(new Tetromino(*temporaryTetromino));

                    setTetrominoPosition(fallingTetromino, 0, 4);
                    ghostTetromino->setColor(fallingTetromino->getColor());
                    resetColors();

                    delete temporaryTetromino;
                }
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

        for (int i = 0; i < 4; ++i)
        {
            while (board.isValidPosition(ghostTetromino->getSquares()))
            {
                for (int i = 0; i < 4; ++i)
                {
                    ghostTetromino->getSquares()[i].setY(ghostTetromino->getSquares()[i].getY() + 1);
                }
            }

            for (int j = 0; j < 4; ++j)
            {
                ghostTetromino->getSquares()[j].setY(ghostTetromino->getSquares()[j].getY() - 1);
            }
        }

        if (clockForFallingTetromino.getElapsedTime().asSeconds() >= durationBeforeFallingTetrominoMovesDown)
        {
            std::vector<Square> nextPosition;
            nextPosition = fallingTetromino->getSquares();

            for (int i = 0; i < 4; ++i)
            {
                nextPosition[i].setY(fallingTetromino->getSquares()[i].getY() + 1);
            }

            if (board.isValidPosition(nextPosition))
            {
                for (int i = 0; i < 4; ++i)
                {
                    fallingTetromino->getSquares()[i].setY(fallingTetromino->getSquares()[i].getY() + 1);
                }

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
                            delete heldTetromino;

                            for (Tetromino* tetromino : inventory)
                            {
                                delete tetromino;
                            }
                        }
                        else
                        {
                            board.clearFullLines(&managerScore, &managerCombo, &observerCombo);
                            resetFallingTetromino();
                        }
                    }
                }
            }
        }

        if (isLockDelayActive)
        {
            float elapsed = lockDelayClock.getElapsedTime().asSeconds();

            if (elapsed <= lockDelayDuration)
            {
                float t = (1 - std::cos((elapsed / lockDelayDuration) * 3.14159265358979323846)) / 2;

                float currentLockDelayInventoryTextLabelRectangleSizeX = lockDelayInventoryTextLabelRectangleStartX + t * (lockDelayInventoryTextLabelRectangleEndX - lockDelayInventoryTextLabelRectangleStartX);
                float currentLockDelayInventoryTextLabelRectangleSizeY = lockDelayInventoryTextLabelRectangleStartY + t * (lockDelayInventoryTextLabelRectangleEndY - lockDelayInventoryTextLabelRectangleStartY);

                float currentLockDelayInventoryRectangleSizeX = lockDelayInventoryRectangleStartX + t * (lockDelayInventoryRectangleEndX - lockDelayInventoryRectangleStartX);
                float currentLockDelayInventoryRectangleSizeY = lockDelayInventoryRectangleStartY + t * (lockDelayInventoryRectangleEndY - lockDelayInventoryRectangleStartY);

                float currentLockDelaySizeIncreaseValue = lockDelaySizeIncreaseStartValue + t * (lockDelaySizeIncreaseEndValue - lockDelaySizeIncreaseStartValue);

                board.setLockDelayRectangle(t, currentLockDelaySizeIncreaseValue);
                observerScore.setLockDelayRectangle(t, currentLockDelaySizeIncreaseValue);
                heldTetromino->setLockDelayRectangle(t, currentLockDelaySizeIncreaseValue);
                observerCombo.setLockDelayRectangle(t, currentLockDelaySizeIncreaseValue);

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
            float t = progress * 2;
            sf::Uint8 r = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleStartColor.r + t * (inventoryNextTetrominoInnerRectangleEndColor.r - inventoryNextTetrominoInnerRectangleStartColor.r));
            sf::Uint8 g = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleStartColor.g + t * (inventoryNextTetrominoInnerRectangleEndColor.g - inventoryNextTetrominoInnerRectangleStartColor.g));
            sf::Uint8 b = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleStartColor.b + t * (inventoryNextTetrominoInnerRectangleEndColor.b - inventoryNextTetrominoInnerRectangleStartColor.b));
            inventoryNextTetrominoInnerRectangle.setFillColor(sf::Color(r, g, b));
        }
        else
        {
            float t = (progress - 0.5f) * 2;
            sf::Uint8 r = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleEndColor.r - t * (inventoryNextTetrominoInnerRectangleEndColor.r - inventoryNextTetrominoInnerRectangleStartColor.r));
            sf::Uint8 g = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleEndColor.g - t * (inventoryNextTetrominoInnerRectangleEndColor.g - inventoryNextTetrominoInnerRectangleStartColor.g));
            sf::Uint8 b = static_cast<sf::Uint8>(inventoryNextTetrominoInnerRectangleEndColor.b - t * (inventoryNextTetrominoInnerRectangleEndColor.b - inventoryNextTetrominoInnerRectangleStartColor.b));
            inventoryNextTetrominoInnerRectangle.setFillColor(sf::Color(r, g, b));
        }

        if (!heldTetromino->isTetrominoHeld)
        {
            heldTetromino->drawNoHeldTetrominoText();
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
        board.draw(window);

        // Draw Score
        observerScore.draw(window);

        // Draw Held Tetromino
        heldTetromino->draw(window);

        // Draw Combo
        observerCombo.draw(window);

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
                        window.draw(tetrominoSprite);
                    }
                }
            }
        }

        // Draw Placed Tetrominos
        for (int row = 0; row < board.BOARD_ROWS; ++row)
        {
            for (int column = 0; column < board.BOARD_COLUMNS; ++column)
            {
                if (board.getBoard()[row][column] != 0)
                {
                    sf::RectangleShape block(sf::Vector2f(TEXTURE_SIZE, TEXTURE_SIZE));
                    tetrominoSprite.setPosition(220 + column * TEXTURE_SIZE, 25 + row * TEXTURE_SIZE);
                    tetrominoSprite.setTextureRect(sf::IntRect(board.getBoard()[row][column] * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE));
                    window.draw(tetrominoSprite);
                }
            }
        }
    }
}