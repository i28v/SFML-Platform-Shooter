#include "../include/Game.h"

int main(int argc, char* argv[])
{
    Game* MAIN_THREAD = new Game();
    MAIN_THREAD->start();
    delete[] MAIN_THREAD;
    return 0;
}
