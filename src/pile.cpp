#include "pile.h"

void Pile::expand(Figure *fig){
    try{
        fig->drawWith([&](int y, int x, char ch)
                {
                    this->shape.at(shape.size()-y).at(x-lmargin) = (int)fig->color;
                });
    }
    catch (const std::out_of_range &e){
        running = false;
    }
}

void Pile::consume(){
    int consumed = 0;
    for (auto it = shape.begin(); it != shape.end(); ++it){
        auto row = *it;
        if (std::all_of(row.begin(),row.end(), [](int e){ return e!=-1;})){
            it = shape.erase(it);
            ++consumed;
            shape.push_back(std::vector<int>(length,-1));
            usleep(500000);
        }
    }

}

void Pile::step(){
   consume();
}

void Pile::draw(){
    for (auto itR = shape.begin(); itR != shape.end(); ++itR){
        for (auto itC = itR->begin(); itC != itR->end(); ++itC){
            int j = std::distance(shape.begin(), itR);
            int i = std::distance(itR->begin(), itC) + lmargin;
            if (*itC!=-1)
                mvaddch(shape.size()-j,i,'#'| COLOR_PAIR(*itC));
#ifdef PILE_DBG
            else 
                mvaddch(shape.size()-j,i,' '| COLOR_PAIR(Color::RED));
#endif//PILE_DBG
        }
    }
}

