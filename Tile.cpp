//
// Created by Filip Balucha on 23/04/2020.
//

#include "Tile.hpp"


Tile::Tile() : value(EMPTY_VALUE){}

Tile Tile::operator+ (const Tile& rhs) {
    // TODO temp
    return *this;
}

int Tile::getValue() const {
    return value;
}

void Tile::makeVisible() {
    value = (double)rand() / RAND_MAX < 0.9 ? 2 : 4;
}

bool Tile::hasWinValue() const {
    return value == WIN_VALUE;
}

bool Tile::isEmpty() const {
    return value == EMPTY_VALUE;
}



