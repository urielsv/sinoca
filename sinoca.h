// Importante antes de pushear devuelta -> arreglar formato headerfile

#define CARD_ROWS   9
#define CARD_COLS   13
#define CARDS       5
#define LINE_SIZE   3

#define MAX_VAL     4
#define MIN_VAL     0

#define TER_SIZE_X 64
#define TER_SIZE_Y 32

typedef enum deck {
    SLOT_3 = 0, 
    SLOT_K,
    SLOT_Q,
    SLOT_J,
    SLOT_A,
} deck;

extern const char card[CARDS][CARD_ROWS][CARD_COLS];


/* Back-end */

 /* Slot will initialize game */
int slot();

/* Randomizes possible values */
void slotRand(deck []);

/* Points and rewards for the user */
int rewards(deck [], int *);
int validScreen(int, int);


/* Front-end */

int initUI();

void board(deck []);

void rowBoard();
//funcion que lee el numero que sale e imprime lo que salio en grande
void slotToBoard(deck []);

// Funciones logicas:
// 1. Funcion de random en rango [0-4] (las cartas)
// 2. Funcion si todas las cartas del vector son iguales -> retorna ganaste (=1).
 
// Funciones de front:
// Tablero.
// Seguir haciendo el game si toca spacebar.
