/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SolarFox
*/

#include "Nibler.hpp"
#include "../Games.hpp"

#define WIDTH 100
#define HEIGHT 40

void Nibler::random_fruit()
{
    std::srand(std::time(nullptr));
    int random_variable = std::rand();
    f.x = 2 + std::rand()%18;
    f.y = 2 + std::rand()%18;
    for (int i = 0; i < this->snake_size; i++) {
        if (f.x == s[0].x && f.y == s[0].y)
            random_fruit();
    }
}

Nibler::Nibler()
{
    game = new Games;
    game->name = "SolarFox";
    game->score = 0;
    game->posx = WIDTH / 2;
    game->posy = HEIGHT / 2;
    game->width = 20;
    game->height = 20;
    game->playerdirx = 0;
    game->playerdiry = -1;
    for (int i = 0; i < game->width; i++)
        for (int j = 0; j < game->height; j++) {
            if (i != 0 || j != 0)
                game->mat[j][i] = 1;
            else
                game->mat[j][i] = 5;
        }
            
    for (int i = 0; i < 400; i++) {
        s[i].x = 9;
        s[i].y = 9;
    }
    snake_size = 3;
    dir = 0;
    random_fruit();
    game->mat[f.y][f.x] = 3;
}

Nibler::~Nibler()
{
    delete game;
}


int Nibler::loop(int deltatime)
{
    if (deltatime % 4 ==0) {
        for (int i = 0; i < game->width; i++)
        {
            for (int j = 0; j < game->height; j++) {
                if (i != 0 && j != 0 && i != 19 && j != 19)
                    game->mat[j][i] = 1;
                else
                    game->mat[j][i] = 8;
            }
        }
        for (int i = 1; i < snake_size; i++)
        {
            s[i].x = s[i-1].x;
            s[i].y = s[i-1].y;
            if (i != snake_size && i != 0)
                game->mat[s[i].y][s[i].x] = 7;
        }
        if (dir == 3)
            s[0].x += 1;
        if (dir == 2)
            s[0].x -= 1;
        if (dir == 1)
            s[0].y -= 1;
        if (dir == 0)
            s[0].y += 1;
        game->mat[s[0].y][s[0].x] = 7;
        for(int i = 1; i < snake_size; i++)
        {
            if (s[0].x == s[i].x && s[0].y == s[i].y) {
                return 1;
            }
                
        }
        if (s[0].x == f.x && s[0].y == f.y) {
            random_fruit();
            game->score += 1;
            snake_size += 1;
        }
        game->mat[f.y][f.x] = 3;
        if (s[0].x == 0 || s[0].x == 19 || s[0].y == 0 || s[0].y == 19) {
            return 1;
        }
    }
    return 0;
}

void Nibler::key_event(int key)    // NEVER COLLIDES WITH 0 LAYER (WHICH IS WALLS)
{
    if (key == Event::UP) {
        if (dir != 0)
            dir = 1;
    }
    if (key == Event::DOWN) {
        if (dir != 1)
            dir = 0;
    }
    if (key == Event::LEFT) {
        if (dir != 3)
            dir = 2;
    }
    if (key == Event::RIGHT) {
        if (dir != 2)
            dir = 3;
    }
}

extern "C" Igames* create() {
    return new Nibler;
}

extern "C" void destroy(Igames* p) {
    delete p;
}