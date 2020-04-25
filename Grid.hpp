//
// Created by Filip Balucha on 23/04/2020.
//

#ifndef INC_2048_GRID_HPP
#define INC_2048_GRID_HPP
#include "Tile.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

//TODO define type for row

class Grid {
private:
    int size;
    std::vector<std::vector<Tile*>*> grid;
public:
    explicit Grid(int size);

    virtual ~Grid();

    void display();
    bool moveTiles();

    void leftMoveTiles();
    bool leftAdd();
    bool leftCollapse();

    bool insertTile();
    bool isWin();
    bool isLose();
};


#endif //INC_2048_GRID_HPP
