#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <assert.h>

#include "sinoca.h"

void slotRand(deck line[])
{
    /* Values between 0 y 4 pseudo-randomly */
    for (int i=0; i < LINE_SIZE; i++) {
       line[i] = (rand() % (MAX_VAL - MIN_VAL + 1));
    }
}

int slot() 
{
    deck line[3];
    char opt;

    srand(time(NULL));
    initUI();
    int isPlaying = 1;
    int points = 0;
    while((opt = getch()) == ' ' && isPlaying) {
        
        slotRand(line);
        board(line);

        /* Give user points if made a line. */ 
                                                // Preguntar -> Como puedo
                                                // guardar info de users?
        printw("%d", rewards(line, &points));
        
        // Agregar opciones para menu. 
    }

    endwin();
    printf("Gracias por jugar al sinoca.\n");
    return 1;
}

// Hacer un csv que lea con un strtok
int rewards(deck line[], int * points)
{
    if (line[0] == line[1] && line[0] == line[2]) {
            printw("Yay!\n");
            *points += 50; 
    }
    return *points;
}
