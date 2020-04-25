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

    bool add(Tile* tile);
    int getValue();

    void setValue(int value);

    bool isEmpty();
    void erase();
    void makeVisible();
    bool hasWinValue();
};


#endif //INC_2048_TILE_H

// TODO
// implement move & collapse for other directions
// only add new tile if successful move

// for animation
// implement position struct (x,y)
// add previous and current position