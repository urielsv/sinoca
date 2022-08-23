#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <assert.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_VAL     4
#define MIN_VAL     0
#define ARR_LEN     3

static void slotRand(int arr[])
{
    /* Values between 0 y 4 pseudo-randomly */
    for (int i=0; i < ARR_LEN; i++) {
       arr[i] = (rand() % (MAX_VAL - MIN_VAL + 1));
    }
}

int slot() 
{
    /* Create the new line. */
    int line[3];
    char opt;
    
    srand(time(NULL));
    initscr();
    raw();
    noecho();

    int isPlaying = 1;
    while((opt = getch()) == ' ' && isPlaying) {

        sleep(0.3);
        
        slotRand(line);
        
        refresh();
        // Llamar a funcion para mostrar el slot. 
        printw("| %d | %d | %d |\n", line[0], line[1], line[2]);
       
        /* Check if you made a line. */
        if (line[0] == line[1] && line[0] == line[2]) {
            printw("Yay!\n");
            // Sumar puntos
        }

        // Agregar opciones para menu.
        if (opt == 'p') {   
            isPlaying = 0;
        } 
    }
    endwin();
    printf("Gracias por jugar al sinoca.\n");
    return 1;
}

#undef ARR_LEN
#undef MAX_VAL
#undef MIN_VAL
