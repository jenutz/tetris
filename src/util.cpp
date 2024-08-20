#include "util.h"


const Matrix<bool> Shape::I = { {1, 1, 1, 1} };

const Matrix<bool> Shape::L = {
    {0, 0, 0, 1},
    {1, 1, 1, 1}
};

const Matrix<bool> Shape::S = {
    {0, 1, 1},
    {1, 1, 0}
};

const Matrix<bool> Shape::O = {
    {1, 1},
    {1, 1}
};

const Matrix<bool> Shape::T = {
    {0, 1, 0},
    {1, 1, 1}
};

const std::map<FigureName, Matrix<bool>> shapeMap = {
    { FigureName::I, Shape::I },
    { FigureName::L, Shape::L },
    { FigureName::S, Shape::S },
    { FigureName::O, Shape::O },
    { FigureName::T, Shape::T }
};


