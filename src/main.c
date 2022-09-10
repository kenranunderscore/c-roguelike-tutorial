#include <rogue.h>

Entity *player;

int main(void)
{
    int ch;
    Position start_pos = { 10, 20 };

    initscr();
    noecho();
    curs_set(0);

    player = create_player(start_pos);
    mvaddch(player->pos.y, player->pos.x, player->ch);

    while (ch = getch())
    {
        if (ch == 'q')
            break;

        handle_input(ch);
        clear();
        mvaddch(player->pos.y, player->pos.x, player->ch);
    }

    endwin();

    return 0;
}
