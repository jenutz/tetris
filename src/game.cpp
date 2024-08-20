#include "game.h"

Game::Game():
    gen(rd()),
    shaperN(0, shapeMap.size()-1),
    rotationN(0,3),
    colorN(1,6)
{
    const int GAME_LENGTH = 20;
    const int GAME_HEIGHT = 30;
    const int RAND_OFFSET = 5;

    border = new Border(GAME_LENGTH, GAME_HEIGHT,'|');
    pile = new Pile('#',GAME_LENGTH-1,GAME_HEIGHT,1);

    posX = std::uniform_int_distribution<>(GAME_LENGTH/2 - RAND_OFFSET,
            GAME_LENGTH/2 + RAND_OFFSET);
    fig = new Figure('@', (FigureName)shaperN(gen), {(uint) posX(gen),0}, 
            (uint) rotationN(gen),(Color)colorN(gen));

};

void Game::handleInput(){
    //initscr();
    int ch = getch();
    flushinp();
    //LOG<<ch<<std::endl;
    switch (static_cast<Keyboard>(ch)){
        case Keyboard::S:
        case Keyboard::DOWN:
            fig->fall();
            break;
        case Keyboard::A:
        case Keyboard::LEFT:
            fig->moveLeft();
            break;
        case Keyboard::D:
        case Keyboard::RIGHT:
            fig->moveRight();
            break;
        case Keyboard::W:
        case Keyboard::UP:
        case Keyboard::R:
            fig->rotate();
            break;
        case Keyboard::Q:
            this->stop();
            break;
    }
}

void Game::mainLoop()
{
    if (!fig->running){
        pile->expand(fig);
        delete fig;
        fig = new Figure('@', (FigureName)shaperN(gen), {(uint) posX(gen),0}, 
                (uint) rotationN(gen),(Color)colorN(gen));
    }

    if (!pile->running){
        this->running = false;
        return;
    }

    handleInput();

    pile->step();  
    fig->step();
    erase();
    border->draw();
    pile->draw();
    fig->draw();
    //fig->projection();
    refresh();
    usleep(frameRate);
};

void Game::start(){
    Log()<<"\nStart\n";
    //std::thread input(&Game::handleInput, this);

    while (running){
        mainLoop();
    }
    sleep(1);
}

void Game::stop(){
    running = false;
}

void Game::credits(){
    std::cout<<"GAME OVER.\nyour score: "<<pile->consumed*100<<std::endl;
}

Game::~Game(){
    credits();
    delete fig;
    delete pile;
}
