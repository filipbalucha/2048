//
// Created by Filip Balucha on 23/04/2020.
//
#include <iostream>
#include "Game.hpp"

void Game::play() {
    bool exit = false;
    while(!exit) {
        char input;
        std::cout << "Press a key: ";
        std::cin >> input;
        switch(input) {
            case KEY_UP:
                std::cout << "KEY UP!" << std::endl;
                grid.display();
                break;
            case KEY_LEFT:
                std::cout << "KEY LEFT!" << std::endl;
                grid.display();
                break;
            case KEY_DOWN:
                std::cout << "KEY DOWN!" << std::endl;
                grid.display();
                break;
            case KEY_RIGHT:
                std::cout << "KEY RIGHT!" << std::endl;
                grid.display();
                break;
            case KEY_EXIT:
                std::cout << "Exiting..." << std::endl;
                exit = true;
                break;
            default:
                std::cout << "Unknown key pressed: " << input << std::endl;
        }
    }
}

Game::Game(int size) : grid(size) {
}
