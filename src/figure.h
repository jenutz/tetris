#ifndef FIGURE_H
#define FIGURE_H

#include "util.h"
#include <functional>

class Figure{
    char bodyChar;
    FigureName fig;
    Vector2<uint> position;
    uint rotation;

    public:
    bool running = true;

    public:
    Color color; 
    Figure(char _bodyChar,FigureName _fig, Vector2<uint> _position,
           uint _rotation, Color _color):
        bodyChar(_bodyChar), fig(_fig), position(_position), 
        rotation(_rotation), color(_color) {}

    int tick = 0;

    void drawWith(std::function<void(int,int,char)> drawPixel);
    void draw();
    void step();
    void rotate(); 

    void projection();
    void fall();
    void move(Vector2<int> offset);
    void moveRight();
    void moveLeft();
    

    bool checkCollision(Vector2<uint> newPos);
    void rotateVector(int rotation, int& y, int& x);

    std::map<FigureName,Matrix<bool>> shapeMap = {
    {FigureName::I,Shape::I},
    {FigureName::L,Shape::L},
    {FigureName::S,Shape::S},
    {FigureName::O,Shape::O},
    {FigureName::T,Shape::T}};

};

#endif // FIGURE_H
