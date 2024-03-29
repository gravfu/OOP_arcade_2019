/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Lib_arcade_ncurse
*/

#include "Lib_arcade_ncurse.hpp"
//#include "../../games/Solar Fox/Bullet.cpp"
//#include "../../games/Games.hpp"
#include "../../games/Select/SelectScreen.hpp"
#include <string>
#include "Print_mat.cpp"


#define LEFTMARGINE 40


void Lib_arcade_ncurse::printInColor(int index) {


    if (!has_colors()) {
        printw("terminal doesn't support colors");
        getch();
    }
    start_color();
    printlib(index, game);
}

void ref(){ refresh();}

Event Lib_arcade_ncurse::Keypressed(){
    assign_game(game);
    int key = getch();
    timeout(25);
    if (key == KEY_UP)
        return Event::UP;
    if (key == 'o')
        return Event::NEXT_GAME;
    if (key == 'p')
        return Event::NEXT_GRAPH;
    if (key == 'l')
        return Event::PREV_GAME;
    if (key == 'm')
        return Event::PREV_GRAPH;
    if (key == KEY_DOWN)
        return Event::DOWN;
    if (key == KEY_LEFT)
        return Event::LEFT;
    if (key == KEY_RIGHT)
        return Event::RIGHT;
    if (key == ' ')
        return Event::SHOOT;
    if (key == 27)
        return Event::QUIT;
    return Event::ENTER;
}

void Lib_arcade_ncurse::destroy(){ endwin();}
void Lib_arcade_ncurse::init(int x, int y){(void)x; (void)y; wind = initscr();}
Lib_arcade_ncurse::Lib_arcade_ncurse(){ init(0, 0); keypad(stdscr, TRUE); noecho(); nodelay(wind, TRUE); }
Lib_arcade_ncurse::~Lib_arcade_ncurse(){ destroy();}
void Lib_arcade_ncurse::clear(){ erase();}

void Lib_arcade_ncurse::refresh(Games game)
{
    clear();
    assign_game(game);
    if (game.name != "Select") 
    {
        for (int i = 0; i < game.height; i++)    {
            for (int j = 0; j < game.width; j++) {
                move(5+i, LEFTMARGINE+j);
                printInColor(game.mat[i][j]);
            }
        }
        move(45, (LEFTMARGINE/2) + 64);
        printw("Score : ");
        printw(std::to_string(game.score).data());
    }
    else
    {
        printSelect(game);
    }
    ref();
}

#include <iostream>
#include <fstream>

void Lib_arcade_ncurse::endgame(std::string name)
{
    if (game.name == "Select")
        return;
    while (getch() != 27)
    {
        std::ifstream ifs("./playerprofile/" + name, std::ifstream::out | std::ifstream::in);
        clear();
        move(30, (LEFTMARGINE/2) + 64);
        printw("GAME OVER");
        move(32, (LEFTMARGINE/2) + 64);
        printw("Score : ");
        move(33, (LEFTMARGINE/2) + 66);
        printw((name + " : " + std::to_string(game.score)).data());
    
        move(35, ((LEFTMARGINE/2) + 64));
        printw(("Top " + game.name + " Score : ").data());
        move(36, (LEFTMARGINE/2) + 66);
        std::string thescore;
        int line = 0;
        int currentline = 0;
        if (game.name == "Pacman")
            line = 1;
        if (game.name == "Nibbler")
            line = 2;
        while (line != currentline)
            getline(ifs, thescore);
        getline(ifs, thescore);
        if (thescore == "")
            thescore = "0";
        printw((name + " : " + thescore).data());
        ifs.close();
    }
}

extern "C" IgraphicLib* create() {
    return new Lib_arcade_ncurse;
}

extern "C" void destroy(IgraphicLib* p) {
    delete p;
}