//
// Created by Filip Balucha on 23/04/2020.
//

#include "Tile.hpp"
#define DEFAULT_VALUE 0

Tile::Tile() : value(DEFAULT_VALUE){}

Tile Tile::operator+ (const Tile& rhs) {
    // TODO temp
    return *this;
}

int Tile::getValue() const {
    return value;
}

void Tile::setValue(int value) {
    Tile::value = value;
}


