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
    Position new_pos = { player->pos.y, player->pos.x };

    switch (input) {
    case 'k':
        new_pos.y--;
        break;
    case 'j':
        new_pos.y++;
        break;
    case 'h':
        new_pos.x--;
        break;
    case 'l':
        new_pos.x++;
        break;
    default:
        break;
    }

    move_player(new_pos);
}

void move_player(Position new_pos)
{
    if (map[new_pos.y][new_pos.x].walkable)
    {
        player->pos.y = new_pos.y;
        player->pos.x = new_pos.x;
    }
}
