#include <rogue.h>

void curses_setup(void)
{
    initscr();
    noecho();
    curs_set(0);
}

void game_loop(void)
{
    int ch;

    mvaddch(player->pos.y, player->pos.x, player->ch);

    while (ch = getch())
    {
        if (ch == 'q')
            break;

        handle_input(ch);
        clear();
        mvaddch(player->pos.y, player->pos.x, player->ch);
    }
}

void quit(void)
{
    endwin();
    free(player);
}
