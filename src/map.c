#include <rogue.h>

Tile **create_map_tiles(void)
{
    Tile **tiles = calloc(MAP_HEIGHT, sizeof(Tile*));

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            tiles[y][x].ch = '#';
            tiles[y][x].walkable = false;
        }
    }

    return tiles;
}

Position setup_map(void)
{
    int n_rooms = (rand() % 11) + 5;
    Room *rooms = calloc(n_rooms, sizeof(Room));

    int y, x, height, width;
    for (int i = 0; i < n_rooms; i++)
    {
        y = (rand() % (MAP_HEIGHT - 10)) + 1;
        x = (rand() % (MAP_WIDTH - 20)) + 1;
        height = (rand() % 7) + 3;
        width = (rand() % 15) + 5;
        rooms[i] = create_room(y, x, height, width);
        add_room_to_map(rooms[i]);

        if (i > 0)
        {
            connect_room_centers(rooms[i - 1].center, rooms[i].center);
        }
    }

    Position start_pos;
    start_pos.y = rooms[0].center.y;
    start_pos.x = rooms[0].center.x;

    free(rooms);

    return start_pos;
}

void free_map(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(map[y]);
    }
    free(map);
}

void connect_room_centers(Position center_one, Position center_two)
{
    Position tmp = { center_one.y, center_one.x };

    while (true)
    {
        if (abs((tmp.x - 1) - center_two.x) < abs(tmp.x - center_two.x))
            tmp.x--;
        else if (abs((tmp.x + 1) - center_two.x) < abs(tmp.x - center_two.x))
            tmp.x++;
        else if (abs((tmp.y - 1) - center_two.y) < abs(tmp.y - center_two.y))
            tmp.y--;
        else if (abs((tmp.y + 1) - center_two.y) < abs(tmp.y - center_two.y))
            tmp.y++;
        else
            break;

        map[tmp.y][tmp.x].ch = '.';
        map[tmp.y][tmp.x].walkable = true;
    }
}
