#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

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
    int height;
    int width;
    Position pos;
    Position center;
} Room;

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

// room.c

Room create_room(int y, int x, int height, int width);
void add_room_to_map(Room room);
void connect_room_centers(Position center_one, Position center_two);

// map.c

Tile **create_map_tiles(void);
void free_map(void);
Position setup_map(void);

#endif
