#ifndef NCURSESWRAPPER_H
#define NCURSESWRAPPER_H
#include <ncurses.h>
class NcursesWrapper{
    public:
    NcursesWrapper(){
        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        curs_set(0);
        start_color();

        
        for (int i = 0; i < 8; ++i)
            init_pair(i,i,i);
    }

    ~NcursesWrapper(){
        endwin();
    }
};


#endif//NCURSESWRAPPER_H
