#ifndef GAME_H
#define GAME_H

#include <sys/ioctl.h>
#include <iostream>
#include <random>
#include "figure.h"
#include "pile.h"
#include "border.h"
#include "ncurseswrapper.h"

class Game{
    NcursesWrapper ncurses;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> shaperN;
    std::uniform_int_distribution<> posX;
    std::uniform_int_distribution<> charN;
    std::uniform_int_distribution<> rotationN;
    std::uniform_int_distribution<> colorN;

    int frameRate = 100000; 
    bool running = true;
    uint score = 0;

    Figure* fig = nullptr; 
    Pile* pile = nullptr;
    Border* border = nullptr;
    
    void handleInput();
    void mainLoop();

    public:
    Game();
    void init();

    void start();
    void stop();
    void credits();

    ~Game();
};

#endif // GAME_H
