//
// Created by Filip Balucha on 23/04/2020.
//

#include <iostream>
#include <sstream>
#include "Grid.hpp"

Grid::Grid(int size) : size(size) {
    grid.reserve(size);
    for(int y = 0; y < size; y++) {
        std::vector<Tile> row;
        row.reserve(size);
        for(int x = 0; x < size; x++) {
            row.emplace_back();
        }
        grid.push_back(row);
    }
}

void Grid::display() {
    std::stringstream ss;
    for (auto& row : grid) {
        ss << ' ';
        for (auto& tile : row) {
            ss << tile.getValue() << ' ';
        }
        ss << '\n';
    }
    std::cout << ss.str();
}

