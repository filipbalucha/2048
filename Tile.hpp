//
// Created by Filip Balucha on 23/04/2020.
//
#ifndef INC_2048_TILE_H
#define INC_2048_TILE_H
#define EMPTY_VALUE 0
#define WIN_VALUE 2048;
#include <cstdlib>
#include <ctime>

class Tile {
private:
    int value;
public:
    Tile();

    Tile operator+ (const Tile& rhs);

    int getValue() const;
    bool isEmpty() const;
    void makeVisible();
    bool hasWinValue() const;
};


#endif //INC_2048_TILE_H
