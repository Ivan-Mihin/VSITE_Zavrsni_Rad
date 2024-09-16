#include "game.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Game& game = Game::getInstance();
    game.run();

    return 0;
}

//delete fallingTetromino;

//for (int i = 0; i < inventory.size(); i++)
//{
//    delete inventory[i];
//}