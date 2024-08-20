#include "border.h"
#include "util.h"

Border::Border(int length_, int height_, char bodyChar_)
    :length(length_), height(height_), bodyChar(bodyChar_) {};

void Border::draw(){
    for (int y = 0; y < height; ++y){
        mvaddch(LINES-y, 0, bodyChar | COLOR_PAIR(Color::WHITE));
        mvaddch(LINES-y, length, bodyChar | COLOR_PAIR(Color::WHITE));
    }
};
