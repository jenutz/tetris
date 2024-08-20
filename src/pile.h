#ifndef PILE_H
#define PILE_H

#include "util.h"
#include "figure.h"
class Pile{
    int length;
    int height;
    int lmargin;

    char bodyChar;
    std::vector<std::vector<int>> shape;  
   
    public:
    int consumed = 0;
    bool running = true;
    void expand(Figure* fig);
    void consume();
    
    Pile(char ch, int length_, int height_, int lmargin_): 
        bodyChar(ch), length(length_), height(height_), lmargin(lmargin_),
        shape(height_, std::vector<int>(length_,-1)){}

    void step();
    void draw();
};

#endif // PILE_H
