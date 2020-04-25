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

enum dirH {LEFT, RIGHT};
enum dirV {UP, DOWN};

class Grid {
private:
    int size;
    std::vector<std::vector<Tile*>*> grid;
    bool upAdd();
    bool upCollapse();
    bool downAdd();
    bool downCollapse();

    bool addH(dirH dir);
    bool collapseH(dirH dir);
    bool addV(dirV dir);
    bool collapseV(dirV dir);

public:
    explicit Grid(int size);
    virtual ~Grid();
    void display();
    void upMoveTiles();
    void downMoveTiles();
    bool insertTile();
    bool isWin();
    bool isLose();

    void moveH(dirH dir);
    void moveV(dirV dir);
};


#endif //INC_2048_GRID_HPP
