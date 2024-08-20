#include "figure.h"

void Figure::drawWith(std::function<void(int,int,char)> drawPixel){
    const Matrix<bool> &shape = shapeMap[fig];

    for (auto itR = shape.begin(); itR != shape.end(); ++itR) {
        for (auto itC = itR->begin(); itC != itR->end(); ++itC) {
            int i = std::distance(shape.begin(), itR);
            int j = std::distance(itR->begin(), itC);

            rotateVector(rotation, i, j);
            if (*itC){
                drawPixel(i + position.y, j + position.x, bodyChar);
            }
#ifdef FIG_DBG
            i = std::distance(shape.begin(), itR);
            j = std::distance(itR->begin(), itC);
            if (i == 0 && j == 0){
                rotateVector(rotation, i, j);
                drawPixel(i + position.y, j + position.x, '*');
            }
#endif//FIG_DBG

        }
    }
}

void Figure::draw(){
    drawWith( [&](int y, int x, char ch){mvaddch(y, x,ch | COLOR_PAIR(color));} );
}

void Figure::rotate(){
    ++rotation;
    if (checkCollision(position))
        --rotation;
}

void Figure::projection(){
    Figure *copy = new Figure(*this);
    while (copy->running){
        copy->step();
    }
    copy->drawWith( [](int y, int x, char ch)
            {
            mvaddch(y, x,ch|COLOR_PAIR(COLOR_WHITE));
            } );
    delete copy;
}

void Figure::rotateVector(int rotation, int& y, int& x){
    switch (rotation % 4){
        case 1:
            std::swap(y,x);
            x = -x;
            break;
        case 2:
            y = -y;
            x = -x;
            break;
        case 3:
            std::swap(y,x);
            y = -y;
            break;
    }
}

void Figure::step(){
    ++tick;
    if (tick < 8)
        return;
    tick = 0;

    Vector2<uint> newPos = position;
    ++newPos.y;
    if (checkCollision(newPos)){
        running = false; 
        return;
    }

    position = newPos;
}

void Figure::fall(){
    while (running){
        this->step();
    }
}

void Figure::move(Vector2<int> offset){
    uint newX = position.x + offset.x; 
    uint newY = position.y + offset.y; 

    if (!checkCollision({newX,newY}))
        position = {newX,newY};
}

bool Figure::checkCollision(Vector2<uint> newPos){
    const Matrix<bool> &shape = shapeMap[fig];
    int length = shape.size(); 
    int width = shape[0].size();
    rotateVector(rotation, length, width);
    //rotateVector(rotation, width,length, );
    //Borders
//    if (
//            newPos.x + width - 1 < 0        ||
//            newPos.x < 0                    ||
//            newPos.x + width - 1 >= COLS    ||
//            newPos.x >= COLS
//       ){
//        Log()<<"Collision Border X\n";
//        return true;
//    }
//
    if ((int) newPos.y + length - 1>= LINES || newPos.y >= LINES){
        Log()<<"Collision Border Y\n";
        return true;
    }
    //
    //Game objects
    for (auto itR = shape.begin(); itR != shape.end(); ++itR){
        for (auto itC = itR->begin(); itC != itR->end(); ++itC) {
            if (!*itC)
                continue;
            int i = std::distance(shape.begin(), itR);
            int j = std::distance(itR->begin(), itC);
            rotateVector(rotation,i,j);

            char ch = mvinch(i + newPos.y, j + newPos.x) & A_CHARTEXT;
            if (ch != 32 && ch!=-1 && ch != bodyChar && ch!='*'){
                Log()<<"Collision Game obj\n";
                return true;
            }

        }
    }
    return false;
}

void Figure::moveRight(){
    move({1,0});
}

void Figure::moveLeft(){
    move({-1,0});
}


