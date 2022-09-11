#include <rogue.h>

Room create_room(int y, int x, int height, int width)
{
    Room new_room;

    new_room.pos.y = y;
    new_room.pos.x = x;
    new_room.height = height;
    new_room.width = width;
    new_room.center.y = y + (int)(height / 2);
    new_room.center.x = x + (int)(width / 2);

    return new_room;
}

void add_room_to_map(Room room)
{
    for (int y = room.pos.y; y < room.pos.y + room.height; y++)
    {
        for (int x = room.pos.x; x < room.pos.x + room.width; x++)
        {
            map[y][x].ch = '.';
            map[y][x].walkable = true;
        }
    }
}
