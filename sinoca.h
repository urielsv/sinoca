// Importante antes de pushear devuelta -> arreglar formato headerfile

#define CARD_ROWS   9
#define CARD_COLS   13
#define CARDS       5
#define LINE_SIZE   5
#define COL_SIZE    3

#define MAX_VAL     4
#define MIN_VAL     0

#define TER_SIZE_X 32
#define TER_SIZE_Y 64

#define MAX_USERNAME_SIZE   30
typedef enum deck {
    SLOT_3 = 0, 
    SLOT_K,
    SLOT_Q,
    SLOT_J,
    SLOT_A,
} deck;

extern const char card[CARDS][CARD_ROWS][CARD_COLS];
extern const char * rowBoard;

extern int max_row, max_col;
/* Back-end */

 /* Slot will initialize game */
int slot();

/* Randomizes possible values */
void slotRand(deck [LINE_SIZE][COL_SIZE]);

/* Points and rewards for the user */
int rewards(deck [LINE_SIZE][COL_SIZE], int *);
int validScreen(int, int);


/* Front-end */

int initUI();

void menu();

int loginCreds(char [], int *);

void board(deck [LINE_SIZE][COL_SIZE]);


//funcion que lee el numero que sale e imprime lo que salio en grande
void slotToBoard(deck [LINE_SIZE][COL_SIZE]);

// Funciones logicas:
// 1. Funcion de random en rango [0-4] (las cartas)
// 2. Funcion si todas las cartas del vector son iguales -> retorna ganaste (=1).
 
// Funciones de front:
// Tablero.
// Seguir haciendo el game si toca spacebar.
