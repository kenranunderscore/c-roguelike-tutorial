#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Position;

typedef struct
{
    Position pos;
    char ch;
} Entity;

Entity *create_player(Position start_pos);

void handle_input(int input);

extern Entity *player;

#endif
