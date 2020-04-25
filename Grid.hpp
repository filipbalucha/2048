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
    bool leftAdd();
    bool leftCollapse();
    bool rightAdd();
    bool rightCollapse();
    bool upAdd();
    bool upCollapse();
    bool downAdd();
    bool downCollapse();

public:
    explicit Grid(int size);
    virtual ~Grid();
    void display();
    void leftMoveTiles();
    void rightMoveTiles();
    void upMoveTiles();
    void downMoveTiles();
    bool insertTile();
    bool isWin();
    bool isLose();
};


#endif //INC_2048_GRID_HPP
