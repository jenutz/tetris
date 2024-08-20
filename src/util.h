#ifndef UTIL_H
#define UTIL_H

#include "logger.h"
#include <map>
#include <fstream>
#include <ctime>
#include <vector>
#include <list>
#include <ncurses.h>
#include <algorithm>
#include <unistd.h>

template<typename T>
using Matrix = std::vector<std::vector<T>>;

template<typename T>
struct Vector2{
    T x;
    T y;

    public:
    Vector2(T _x, T _y): x(_x),y(_y) {}
};


enum class FigureName {I, L, S, O, T};

namespace Shape {
    extern const Matrix<bool> I;
    extern const Matrix<bool> L;
    extern const Matrix<bool> S;
    extern const Matrix<bool> O;
    extern const Matrix<bool> T;
}

extern const std::map<FigureName, Matrix<bool>> shapeMap;

enum class Keyboard{
    DOWN    = 258, 
    UP      = 259,
    LEFT    = 260,
    RIGHT   = 261,
    A       = 97,
    D       = 100,
    S       = 115,
    W       = 119,
    R       = 114,
    Q       = 113
};

enum class Color{
    BLACK   =   0,
    RED     =   1,
    GREEN   =   2,
    YELLOW  =   3,
    BLUE    =   4,
    MAGENTA =   5,
    CYAN    =   6,
    WHITE   =   7
};

#endif //UTIL_H
