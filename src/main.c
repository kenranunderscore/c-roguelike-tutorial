#include <rogue.h>

Entity *player;

int main(void)
{
    curses_setup();

    Position start_pos = { 10, 20 };
    player = create_player(start_pos);

    game_loop();

    quit();

    return 0;
}
