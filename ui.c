#include <ncurses.h>

#include "sinoca.h"

int validScreen(int x, int y) 
{
    if (x < TER_SIZE_X || y < TER_SIZE_Y) {
        endwin();
        fprintf(stderr, "Not a valid terminal size.");
        return false;
    }
    return true;
}

int initUI()
{
    //if (!validScreen(x, y))
    //    return 0;
    
    int max_row, max_col;
    
    initscr();
    getmaxyx(stdscr, max_row, max_col);
    raw();
    noecho();

    return 1;
}

void board(deck line[])
{
    clear();
    
    /* Block of slot */
    rowBoard();
    slotToBoard(line);
    rowBoard();
         
    printw("Debug values: %d, %d, %d\n", line[0], line[1], line[2]);
    refresh();
}

void rowBoard()
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

void slotToBoard(deck line[]) // slotToBoard(line, 3)
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
