#include <rogue.h>

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Entity *player;
Tile **map;

int main(void)
{
    curses_setup();

    map = create_map_tiles();
    Position start_pos = setup_map();
    player = create_player(start_pos);

    game_loop();

    quit();

    return 0;
}
