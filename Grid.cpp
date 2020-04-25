//
// Created by Filip Balucha on 23/04/2020.
//
#include "Grid.hpp"

Grid::Grid(int size) : size(size) {
    grid.reserve(size);
    for(int y = 0; y < size; y++) {
        auto* row = new std::vector<Tile*>;
        row->reserve(size);
        for(int x = 0; x < size; x++) {
            Tile* tile = new Tile();
            row->push_back(tile);
//            delete tile;
        }
        grid.push_back(row);
    }

//    int numTiles = size*size/8;
    int numTiles = size*size - 1;
    for(int i = 0; i < numTiles; i++) {
        insertTile();
    }
}

void Grid::display() {
    std::stringstream ss;
    for (std::vector<Tile*>* row : grid) {
        ss << ' ';
        for (Tile* tile : *row) {
            ss << tile->getValue() << ' ';
        }
        ss << '\n';
    }
    std::cout << ss.str();
}

bool Grid::insertTile() {
    std::vector<Tile*> available;
    available.reserve(size*size);
    for(std::vector<Tile*>* row : grid) {
        for(Tile* tile : *row) {
            if(tile->isEmpty()) {
                available.push_back(tile);
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
//    insertTile();
    return true;
}

bool Grid::isWin() {
    for(std::vector<Tile*>* row : grid) {
        for(Tile* tile : *row) {
            if(tile->hasWinValue()) {
                return true;
            }
        }
    }
    return false;
}

bool Grid::isLose() {
    // TODO check for pairs of equal numbers vertically and horizontally
    for(std::vector<Tile*>* row : grid) {
        for(Tile* tile : *row) {
            if(tile->isEmpty()) {
                return false;
            }
        }
    }
    return true;
}

Grid::~Grid() {
    for(auto row : grid) {
        for(auto tile : *row) {
            delete tile;
        }
        delete row;
    }
}

void Grid::leftMoveTiles() {
    bool collapsedBefore = leftCollapse();
    bool added = leftAdd();
    bool collapsedAfter = leftCollapse();
    if(added || collapsedBefore || collapsedAfter) {
        insertTile();
    }
}

bool Grid::leftAdd() {
    bool addedAnyTwo = false;
    for(auto row : grid) {
        int x = 0;
        while(x < row->size() - 1) {
            Tile* left = row->at(x);
            Tile* right = row->at(x+1);
            bool added = left->add(right);
            if(added) {
                x += 2;
                addedAnyTwo = true;
            } else {
                x += 1;
            }
        }
    }
    return addedAnyTwo;
}

bool Grid::leftCollapse() {
    bool collapsed = false;
    for(std::vector<Tile*>* row : grid) {
        int x = 0;
        while(x < row->size() - 1) {
            if(row->at(x)->isEmpty()) {
                int x2 = x + 1;
                bool swapped = false;
                while(x2 < row->size() && !swapped) {
                    if(!row->at(x2)->isEmpty()) {
                        // Swap values
                        // TODO implement swap
                        int val = row->at(x2)->getValue();
                        row->at(x)->setValue(val);
                        row->at(x2)->erase();
                        swapped = true;
                        collapsed = true;
                    }
                    x2++;
                }
                x = x2;
            } else {
                x++;
            }
        }
    }
    return collapsed;
}