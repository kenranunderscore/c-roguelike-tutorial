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

    draw_everything();

    while (ch = getch())
    {
        if (ch == 'q')
            break;

        handle_input(ch);
        draw_everything();
    }
}

void quit(void)
{
    endwin();
    free(player);
    free_map();
}
