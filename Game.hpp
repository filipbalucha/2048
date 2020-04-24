//
// Created by Filip Balucha on 23/04/2020.
//

#ifndef INC_2048_GAME_HPP
#define INC_2048_GAME_HPP
#include "Grid.hpp"
#define KEY_UP 'w'
#define KEY_LEFT 'a'
#define KEY_DOWN 's'
#define KEY_RIGHT 'd'
#define KEY_EXIT 'e'

class Game {
private:
    Grid grid;
public:
    Game(int size);

    void play();
};


#endif //INC_2048_GAME_HPP
