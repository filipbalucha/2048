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
        int col = 0;
        while(col < row->size() - 1) {
            Tile* left = row->at(col);
            Tile* right = row->at(col + 1);
            bool added = left->add(right);
            if(added) {
                col += 2;
                addedAnyTwo = true;
            } else {
                col += 1;
            }
        }
    }
    return addedAnyTwo;
}

bool Grid::leftCollapse() {
    bool collapsed = false;
    for(std::vector<Tile*>* row : grid) {
        int col = 0;
        while(col < row->size() - 1) {
            if(row->at(col)->hasValue()) {
                col++;
                continue;
            }
            int colNext = col + 1;
            while(colNext < row->size()) {
                if(row->at(colNext)->hasValue()) {
                    // Swap values
                    int val = row->at(colNext)->getValue();
                    row->at(col)->setValue(val);
                    row->at(colNext)->erase();
                    collapsed = true;
                    break;
                }
                colNext++;
            }
            col = colNext;
        }
    }
    return collapsed;
}

void Grid::rightMoveTiles() {
    bool collapsedBefore = rightCollapse();
    bool added = rightAdd();
    bool collapsedAfter = rightCollapse();
    if(added || collapsedBefore || collapsedAfter) {
        insertTile();
    }
}

bool Grid::rightAdd() {
    bool addedAnyTwo = false;
    for(auto row : grid) {
        int col = row->size() - 1;
        while(0 < col) {
            Tile* left = row->at(col - 1);
            Tile* right = row->at(col);
            bool added = right->add(left);
            if(added) {
                col -= 2;
                addedAnyTwo = true;
            } else {
                col -= 1;
            }
        }
    }
    return addedAnyTwo;
}

bool Grid::rightCollapse() {
    bool collapsed = false;
    for(std::vector<Tile*>* row : grid) {
        int col = row->size() - 1;
        while(0 < col) {
            if(row->at(col)->hasValue()) {
                col--;
                continue;
            }
            int colNext = col - 1;
            while(0 <= colNext) {
                if(row->at(colNext)->hasValue()) {
                    // Swap values
                    int val = row->at(colNext)->getValue();
                    row->at(col)->setValue(val);
                    row->at(colNext)->erase();
                    collapsed = true;
                    break;
                }
                colNext--;
            }
            col = colNext;
        }
    }
    return collapsed;
}

void Grid::upMoveTiles() {
    bool collapsedBefore = upCollapse();
    bool added = upAdd();
    bool collapsedAfter = upCollapse();
    if(added || collapsedBefore || collapsedAfter) {
        insertTile();
    }
}

bool Grid::upAdd() {
    bool addedAnyTwo = false;
    for(int col = 0; col < size; col++) {
        int row = 0;
        while(row < size - 1) {
            Tile* up = grid.at(row)->at(col);
            Tile* down = grid.at(row + 1)->at(col);
            bool added = up->add(down);
            if(added) {
                row += 2;
                addedAnyTwo = true;
            } else {
                row += 1;
            }
        }
    }
    return addedAnyTwo;
}

bool Grid::upCollapse() {
    bool collapsed = false;
    for(int col = 0; col < size; col++) {
        int row = 0;
        while(row < size - 1) {
            if(grid.at(row)->at(col)->hasValue()) {
                row++;
                continue;
            }
            int rowNext = row + 1;
            while(rowNext < size) {
                if(grid.at(rowNext)->at(col)->hasValue()) {
                    // Swap values
                    int val = grid.at(rowNext)->at(col)->getValue();
                    grid.at(row)->at(col)->setValue(val);
                    grid.at(rowNext)->at(col)->erase();
                    collapsed = true;
                    break;
                }
                rowNext++;
            }
            row = rowNext;
        }
    }
    return collapsed;
}

void Grid::downMoveTiles() {
    bool collapsedBefore = downCollapse();
    bool added = downAdd();
    bool collapsedAfter = downCollapse();
    if(added || collapsedBefore || collapsedAfter) {
        insertTile();
    }
}

bool Grid::downAdd() {
    bool addedAnyTwo = false;
    for(int col = 0; col < size; col++) {
        int row = size - 1;
        while(row > 0) {
            Tile* up = grid.at(row)->at(col);
            Tile* down = grid.at(row - 1)->at(col);
            bool added = down->add(up);
            if(added) {
                row -= 2;
                addedAnyTwo = true;
            } else {
                row -= 1;
            }
        }
    }
    return addedAnyTwo;
}

bool Grid::downCollapse() {
    bool collapsed = false;
    for(int col = 0; col < size; col++) {
        int row = size - 1;
        while(row > 0) {
            if(grid.at(row)->at(col)->hasValue()) {
                row--;
                continue;
            }
            int rowNext = row - 1;
            while(rowNext >= 0) {
                if(grid.at(rowNext)->at(col)->hasValue()) {
                    // Swap values
                    int val = grid.at(rowNext)->at(col)->getValue();
                    grid.at(row)->at(col)->setValue(val);
                    grid.at(rowNext)->at(col)->erase();
                    collapsed = true;
                    break;
                }
                rowNext--;
            }
            row = rowNext;
        }
    }
    return collapsed;
}