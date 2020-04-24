//
// Created by Filip Balucha on 23/04/2020.
//

#ifndef INC_2048_GRID_HPP
#define INC_2048_GRID_HPP
#include "Tile.hpp"
#include <vector>

class Grid {
private:
    int size;
    std::vector<std::vector<Tile>> grid;
public:
    Grid(int size);

    void display();

    bool insertTile();
    bool checkWin();
};


#endif //INC_2048_GRID_HPP
