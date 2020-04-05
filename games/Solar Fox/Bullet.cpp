/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Bullet
*/

#include "Bullet.hpp"

Bullet::Bullet(int tox, int toy, int px, int py, int enemy)
{
    dirx = tox;
    diry = toy;
    posx = px;
    posy = py;
    lifespan = 4;
    FromEnemy = enemy;

};
int Bullet::move(int id)
{
    if (!FromEnemy) 
    {
        if (lifespan == 0)
            return 1;

        if (id == 0 || id == 3)
            return 1;

        lifespan--;
        posx += dirx;
        posy += diry;
    }
    else
    {
        if (id == 1)
            return 2;
        if (id == 0 || id == 3 || id == 5 || id == 4 || id == 6)
            return 1;
        if (slow == 10) {
            posx += dirx;
            posy += diry;
            slow = 0;
        }
        else
            slow++;
    }
    return 0;
};
Bullet::~Bullet()
{
}
