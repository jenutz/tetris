#include <csignal>
#include "game.h"

void sigint_handler(int i)
{
    endwin();
    exit(0);
}

int main(){
    std::signal(SIGINT, sigint_handler);
    Game game;
    game.start();
    endwin();
};
