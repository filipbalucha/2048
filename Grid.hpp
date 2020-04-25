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

using Row = std::vector<Tile*>;
enum dirH {LEFT, RIGHT};
enum dirV {UP, DOWN};

class Grid {
private:
    int size;
    std::vector<Row*> grid;

    bool addH(dirH dir);
    bool addV(dirV dir);

    bool collapseH(dirH dir);
    bool collapseV(dirV dir);

public:
    explicit Grid(int size);
    virtual ~Grid();

    void display();

    bool insertTile();

    bool isWin();
    bool isLose();

    void moveH(dirH dir);
    void moveV(dirV dir);
};


#endif //INC_2048_GRID_HPP
