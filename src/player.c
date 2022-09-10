#include <rogue.h>

Entity *create_player(Position start_pos)
{
    Entity *new_player = calloc(1, sizeof(Entity));

    new_player->pos.y = start_pos.y;
    new_player->pos.x = start_pos.x;
    new_player->ch = '@';

    return new_player;
}

void handle_input(int input)
{
    switch (input) {
    case 'k':
        player->pos.y--;
        break;
    case 'j':
        player->pos.y++;
        break;
    case 'h':
        player->pos.x--;
        break;
    case 'l':
        player->pos.x++;
        break;
    default:
        break;
    }
}
