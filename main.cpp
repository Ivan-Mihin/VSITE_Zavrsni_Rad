#include "game.h"

int main()
{
    Game& game = Game::getInstance();
    game.run();

    return 0;
}


//std::srand(static_cast<unsigned int>(std::time(nullptr)));

//CommandMoveLeft moveLeftCmd(fallingTetromino);
//CommandMoveRight moveRightCmd(fallingTetromino);

//// Create the InputHandler
//InputHandler inputHandler(&moveLeftCmd, &moveRightCmd);


//delete fallingTetromino;

//for (int i = 0; i < inventory.size(); i++)
//{
//    delete inventory[i];
//}