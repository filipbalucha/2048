//
// Created by Filip Balucha on 23/04/2020.
//

#include "Tile.hpp"


Tile::Tile() : value(EMPTY_VALUE){}



int Tile::getValue() {
    return value;
}

void Tile::makeVisible() {
    value = (double)rand() / RAND_MAX < 0.9 ? 2 : 4;
}

bool Tile::hasWinValue() {
    return value == WIN_VALUE;
}

bool Tile::isEmpty() {
    return value == EMPTY_VALUE;
}

bool Tile::add(Tile *other) {
    if(isEmpty()) {
        return false;
    }
    if(value != other->getValue()) {
        return false;
    }
    value *= 2;
    other->erase();
    return true;
}

void Tile::erase() {
    value = EMPTY_VALUE;
}

void Tile::setValue(int value) {
    Tile::value = value;
}

