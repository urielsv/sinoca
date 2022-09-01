#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "sinoca.h"

int validScreen(int x, int y) 
{
    if (x < TER_SIZE_X || y < TER_SIZE_Y) {
        endwin();
        fprintf(stderr, "Not a valid terminal size.\n");
        abort();
    }
    return 1;
}

int max_row, max_col;

int initUI()
{     
    initscr();
    
    getmaxyx(stdscr, max_row, max_col);
    validScreen(max_row, max_col);
    raw();

    menu();
    return 1;
}

void board(deck line[LINE_SIZE][COL_SIZE])
{
    clear();
    noecho(); 

    /* Block of slot */
    addstr(rowBoard);
    slotToBoard(line);
    addstr(rowBoard); 
    refresh();
}

void menu()
{
    mvaddstr(4, (max_col/2)-11, "Welcome to THE SINOCA\n");
    mvaddstr(5, (max_col/2)-11, "To start, press ENTER\n");
    refresh();
}

// Arreglar esta funcion, mix de front y back.
int loginCreds(char username[], int * upoints) 
{
    if (getch() == '\n') {
        clear();

        mvaddstr(6, (max_col/2)-12, "THE SINOCA GAME");
        echo();
        mvaddstr(8, (max_col/2)-12, "Username: ");
        mvscanw(8, (max_col/2)-2, "%s", username); // Arreglar esto.
        
        do {
            refresh();
            mvaddstr(9, (max_col/2)-12, "Points to play: ");
            mvscanw(9, (max_col/2)+4, "%d", upoints);
        } while ( upoints < 0 ); // No esta funcionando.

        if (strlen(username) > MAX_USERNAME_SIZE) {
            fprintf(stderr, "Username length is out of scope.");
            abort();
        }
    }
    return *upoints;
}

const char * rowBoard = 
            "#########################################################################\n"
            "#########################################################################\n";


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

void slotToBoard(deck line[LINE_SIZE][COL_SIZE]) 
{
    int lineVal;
    for (int k = 0; k < COL_SIZE; k++) {
        for (int j = 0; j < CARD_ROWS; j++) { 
                addstr("###");
            for (int i = 0; i < LINE_SIZE; i++) {
                lineVal = line[i][k];
                printw("%s", card[lineVal][j]); // Primera linea de A
                if ( i < LINE_SIZE-1 )
                    addstr("###");
                else
                    addstr("###\n");
            }
        }
    }
}
