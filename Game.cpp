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
            std::cout << "You won!" << std::endl << "Continue? [y|n]" << std::endl;
            char answer;
            std::cin >> answer;
            if(answer != 'y') {
                std::cout << "Exiting..." << std::endl;
                return;
            }
        }
        char input;
        std::cout << "Press a key: ";
        std::cin >> input;
        switch(input) {
            case KEY_UP:
                std::cout << "KEY UP!" << std::endl;
                grid.moveTiles();
                break;
            case KEY_LEFT:
                std::cout << "KEY LEFT!" << std::endl;
                grid.moveTiles();
                break;
            case KEY_DOWN:
                std::cout << "KEY DOWN!" << std::endl;
                grid.moveTiles();
                break;
            case KEY_RIGHT:
                std::cout << "KEY RIGHT!" << std::endl;
                grid.moveTiles();
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
