/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Lib_arcade_ncurse
*/

#include "Lib_arcade_caca.hpp"
#include <string>
#include "Print_mat.cpp"
#include <caca.h>

Event Lib_arcade_caca::Keypressed(){
    assign_game(game);
    caca_event_t ev;

    caca_get_event(display, CACA_EVENT_KEY_PRESS, &ev, 25);

    if (caca_get_event_key_ch(&ev) == CACA_KEY_UP)
        return Event::UP;
    if (caca_get_event_key_ch(&ev) == CACA_KEY_DOWN)
        return Event::DOWN;
    if (caca_get_event_key_ch(&ev) == CACA_KEY_RIGHT)
        return Event::RIGHT;
    if (caca_get_event_key_ch(&ev) == CACA_KEY_LEFT)
        return Event::LEFT;

    if (caca_get_event_key_ch(&ev) == 'o')
        return Event::NEXT_GAME;
    if (caca_get_event_key_ch(&ev) == 'p')
        return Event::NEXT_GRAPH;

    if (caca_get_event_key_ch(&ev) == ' ')
        return Event::SHOOT;
    if (caca_get_event_key_ch(&ev) == 27)
        return Event::QUIT;

    return Event::ENTER;
}

void Lib_arcade_caca::init(int x, int y)
{
    canvas = caca_create_canvas(x, y);
    display = caca_create_display(canvas);
    if (!display)
        std::cout << "Cacalib : error creating display" << std::endl;
    caca_set_color_ansi(canvas, CACA_BLACK, CACA_WHITE);
    caca_refresh_display(display);
}

Lib_arcade_caca::Lib_arcade_caca()
{
    init(50, 50);
}

Lib_arcade_caca::~Lib_arcade_caca()
{
    destroy();
}

void Lib_arcade_caca::clear()
{

}

void Lib_arcade_caca::destroy()
{
    caca_free_display(display);
}

void Lib_arcade_caca::refresh(Games game)
{
    assign_game(game);
    if (game.name != "Select")
    {
        for (int i = 0; i < game.height; i++)
            for (int j = 0; j < game.width; j++)
                printlib(game.mat[i][j], i, j, canvas);
    }
}

void Lib_arcade_caca::endgame()
{
    /*
    sf::Font font;
    sf::Text text;
    sf::Event event;
    if (game.name == "Select")
        return;
    while (1)
    {
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
                return;
            }
        }
        window->clear();
        if (font.loadFromFile("lib/SFML/arial.ttf"))
        {
            //std::string Game: = "Game: " + game.name;
            std::string score = "Score: " + std::to_string(game.score);
            text.setString(score);
            text.setFont(font);
            text.setCharacterSize(150);
            text.setFillColor(sf::Color::Red);
            text.setPosition(50, 50);
            text.setStyle(sf::Text::Bold);
            window->draw(text);
        }
        window->draw(text);
        window->display();
    }
    */
}

extern "C" IgraphicLib* create() {
    return new Lib_arcade_caca;
}

extern "C" void destroy(IgraphicLib* p) {
    delete p;
}