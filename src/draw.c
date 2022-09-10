#include <rogue.h>

void draw_map(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            mvaddch(y, x, map[y][x].ch);
        }
    }
}

void draw_entity(Entity *entity)
{
    mvaddch(entity->pos.y, entity->pos.x, entity->ch);
}

void draw_everything(void)
{
    clear();
    draw_map();
    draw_entity(player);
}
