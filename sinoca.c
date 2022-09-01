#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <assert.h>

#include "sinoca.h"

void slotRand(deck line[LINE_SIZE][COL_SIZE])
{
    /* Values between 0 y 4 pseudo-randomly */
    for (int i=0; i < LINE_SIZE; i++) {
        for (int j=0; j < COL_SIZE; j++) {
            line[i][j] = (rand() % (MAX_VAL - MIN_VAL + 1));
        }
    }
}

int slot() 
{
    deck line[LINE_SIZE][COL_SIZE];
    char opt;
    int points = 0;
    int isPlaying = 1;
    char username[MAX_USERNAME_SIZE]; 
    
    srand(time(NULL));
    initUI();
    loginCreds(username, &points);
    do {  
        slotRand(line);
        board(line);
        
        rewards(line, &points);
        printw("asd %d\n", points); // POR QUE NO PRINTEA?!?!?

        /* Give user points if made a line. */ 
        
        // Agregar opciones para menu. 
    } while ((opt = getchar()) == ' ');

    endwin();

    printf("Gracias por jugar al sinoca.\n");
    printf("%d, %d", max_row, max_col);
    return 1;
}

// Hacer un csv que lea con un strtok 


// Modularizar esta macro. Esta horrible pero era para testear.
#define IS_LINE     (line[0][0] == line[1][0] && line[0][0] == line[2][0] && line[0][0] == line[3][0] \
                              && line[0][0] == line[4][0])
int rewards(deck line[LINE_SIZE][COL_SIZE], int * points)
{
    if (IS_LINE) {
        *points += 50; 
    }
    return *points;
}
#undef IS_LINE
