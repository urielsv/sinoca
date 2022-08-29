#include <ncurses.h>
#include <string.h>
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

int max_row, max_col;

int initUI()
{
    //if (!validScreen(x, y))
    //    return 0;
    
    
    initscr();
    getmaxyx(stdscr, max_row, max_col);
    raw();

    menu();
    return 1;
}

void board(deck line[])
{
    clear();
    noecho(); 
    /* Block of slot */
    addstr(rowBoard);
    slotToBoard(line);
    addstr(rowBoard);
         
    printw("Debug values: %d, %d, %d\n", line[0], line[1], line[2]);
    refresh();
}

void menu()
{
    mvaddstr(4, (max_col/2)-11, "Welcome to THE SINOCA\n");
    mvaddstr(5, (max_col/2)-11, "To start, press ENTER\n");
    refresh();
}

int loginCreds(char username[], int * points) 
{
    if (getch() == '\n') {
        clear();

        mvaddstr(6, (max_col/2)-12, "THE SINOCA GAME");
        echo();
        mvaddstr(8, (max_col/2)-12, "Username: ");
        mvscanw(8, (max_col/2)-2, "%s", username); // Arreglar esto.
        mvaddstr(9, (max_col/2)-12, "Points to play: ");
        mvscanw(9, (max_col/2)+4, "%d", points); 
    }
    return *points;
}

const char * rowBoard = 
            "#############################################\n"
            "#############################################\n";


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
