//
// Created by Filip Balucha on 23/04/2020.
//

#ifndef INC_2048_TILE_H
#define INC_2048_TILE_H

class Tile {
private:
    int x;
    int y;
    int value;
public:
    Tile();

    Tile operator+ (const Tile& rhs);

    int getValue() const;

    void setValue(int value);
};


#endif //INC_2048_TILE_H
