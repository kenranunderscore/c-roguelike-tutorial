#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct
{
    int y;
    int x;

} Position;

typedef struct
{
    char ch;
    bool walkable;
} Tile;

typedef struct
{
    Position pos;
    char ch;
} Entity;

// externs

extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Tile **map;
extern Entity *player;

// draw.c

void draw_map(void);
void draw_entity(Entity *entity);
void draw_everything(void);

// engine.c

void curses_setup(void);
void game_loop(void);
void quit(void);

// player.c

Entity *create_player(Position start_pos);
void handle_input(int input);
void move_player(Position new_pos);

// map.c

Tile **create_map_tiles(void);
void free_map(void);
Position setup_map(void);

#endif
