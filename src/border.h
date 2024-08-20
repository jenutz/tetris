#ifndef BORDER_H
#define BORDER_H

class Border{
    const int length;
    const int height;
    const char bodyChar;

    public:
    Border(int lenght_, int height_, char bodyChar);
    void draw();
};



#endif//BORDER_H
