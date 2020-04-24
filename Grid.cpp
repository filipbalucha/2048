//
// Created by Filip Balucha on 23/04/2020.
//
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
    int numTiles = size*size/8;
    for(int i = 0; i < numTiles; i++) {
        insertTile();
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

bool Grid::insertTile() {
    std::vector<Tile*> available;
    for(auto& row : grid) {
        for(auto& tile : row) {
            if(tile.getValue() == 0) {
                available.push_back(&tile);
            }
        }
    }
    if(available.empty()) {
        return false;
    }
    int randIdx = rand() % available.size();
    available.at(randIdx)->makeVisible();
    return true;
}

bool Grid::moveTiles() {
    // TODO implement move
    insertTile();
    return true;
}

bool Grid::isWin() {
    for(auto& row : grid) {
        for(auto& tile : row) {
            if(tile.hasWinValue()) {
                return true;
            }
        }
    }
    return false;
}

bool Grid::isLose() {
    for(auto& row : grid) {
        for(auto& tile : row) {
            if(tile.isEmpty()) {
                return false;
            }
        }
    }
    return true;
}


