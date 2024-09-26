#define NOMINMAX
#include <windows.h>
#include "game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Game& game = Game::getInstance();
    game.run();
    Game::destroy();

    return 0;
}