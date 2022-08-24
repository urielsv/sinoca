#include <ncurses.h>

#include "sinoca.h"

int validScreen(int x, int y) 
{
    if (x < TER_SIZE_X || y < TER_SIZE_Y) {
        endwin();
        fprintf(stderr, "Not a valid terminal size.");
        return 0;
    }
    return 1;
}

int initUI()
{
    if (!validScreen)
        return 0;
    
    int max_row, max_col;
    
    initscr();
    getmaxyx(stdscr, max_row, max_col);
    raw();
    noecho();

    return 1;
}

void board(int line[])
{
    clear();
    
    /* Block of slot */
    rowBoard();
    slotToBoard(line);
    rowBoard();
         
    printw("Debug values: %d, %d, %d\n", line[0], line[1], line[2]);
    refresh();
}

static void rowBoard(void)
{
    addstr("#############################################\n"
           "#############################################\n");
}

const char card[CARDS][CARD_ROWS][CARD_COLS] =
{       {
        "           ",
        "           ",
        "    @@@    ",
        "   @@ @@   ",
        "   @   @   ",
        "   @@@@@   ",
        "   @   @   ",
        "           ",
        "           ",
        }, 
        {
        "           ",
        "           ",
        "       @   ",
        "       @   ",
        "       @   ",
        "   @  @@   ",
        "    @@@    ",
        "           ",
        "           ",
        },
        {
        "           ",
        "           ",
        "    @@@    ",
        "   @   @   ",
        "   @ @ @   ",
        "    @@@@   ",
        "      @    ",
        "           ",
        "           ",
        },
        {
        "           ",
        "           ",
        "   @@@@    ",
        "       @   ",
        "   @@@@@   ",
        "       @   ",
        "   @@@@    ",
        "           ",
        "           ",
        },
        {
        "           ",
        "           ",
        "   @   @   ",
        "   @  @    ",
        "   @@@     ",
        "   @  @@   ",
        "   @   @   ",
        "           ",
        "           ",
        }
};

static void slotToBoard(int line[]) // slotToBoard(line, 3)
{
    int lineVal;
    for (int j = 0; j < CARD_ROWS; j++) { 
            addstr("###");
        for (int i = 0; i < LINE_SIZE; i++) {
            lineVal = line[i];
            printw("%s", card[lineVal][j]); // Primera linea de A
            if ( i < LINE_SIZE-1 )
                addstr("###");
            else
                addstr("###\n");
        }
    }
}
