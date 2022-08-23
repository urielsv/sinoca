#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_VAL     4
#define MIN_VAL     0
#define ARR_LEN     3

void slotRand(int arr[])
{
    srand(time(NULL));
    /* Values between 0 y 4 pseudo-randomly */
    for (int i=0; i < ARR_LEN; i++) {
       arr[i] = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    }
}

int slot() 
{
    /* Create the new line. */
    int line[3];
    int opt;

    int isPlaying = 1;
    while((opt = getchar()) != EOF && isPlaying) {
        sleep(2);
        slotRand(line);
        
        printf("| %d | %d | %d |\n", line[0], line[1], line[2]);
       
        /* Check if you made a line. */
        if (line[0] == line[1] && line[0] == line[2]) {
            // Llamar a funcion para mostrar el slot. 
            puts("Yay!");
        }

        // Agregar opciones para menu.
        if (opt == 'p') {   
            puts("Gracias por jugar al sinoca.");
            isPlaying = 0;
        } 
    }
    return 1;
}

#undef ARR_LEN
#undef MAX_VAL
#undef MIN_VAL
