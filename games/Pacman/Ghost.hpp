/*
** EPITECH PROJECT, 2020
** OOP_arcade
** File description:
** Pacman
*/

#ifndef GHOST_HPP_
#define GHOST_HPP_

#include "Ghost.hpp"
#include "Pacman.hpp"
#include <iostream>

struct int_x4;

class Ghost {
    public:
        Ghost(int, int);
        ~Ghost();
        void move(int_x4, int);
        int get_x();
        int get_y();
        char get_last_path();

    protected:
        int posx;
        int posy;
        int dirx;
        int diry;
        char last_path;
};

#endif /* !GHOST_HPP_ */