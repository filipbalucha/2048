//
// Created by Filip Balucha on 23/04/2020.
//
#include <iostream>
#include "Game.hpp"

void Game::play() {
    while(true) {
        grid.display();
        if(grid.isLose()) {
            std::cout << "You lost!" << std::endl;
            return;
        }
        if(grid.isWin()) {
            std::cout << "You won!" << std::endl;
        }
        char input;
        std::cout << "Press a key: ";
        std::cin >> input;
        switch(input) {
            case KEY_UP:
                grid.moveV(UP);
                break;
            case KEY_LEFT:
                grid.moveH(LEFT);
                break;
            case KEY_DOWN:
                grid.moveV(DOWN);
                break;
            case KEY_RIGHT:
                grid.moveH(RIGHT);
                break;
            case KEY_EXIT:
                std::cout << "Exiting..." << std::endl;
                return;
            default:
                std::cout << "Unknown key pressed: " << input << std::endl;
        }
    }
}

Game::Game(int size) : grid(size) {
}
