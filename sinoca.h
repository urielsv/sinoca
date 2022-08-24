// Importante antes de pushear devuelta -> arreglar formato headerfile

#define CARD_ROWS   9
#define CARD_COLS   13
#define CARDS       5
#define LINE_SIZE   3

#define MAX_VAL     4
#define MIN_VAL     0

#define TER_SIZE_X 64
#define TER_SIZE_Y 32

typedef enum {
    SLOT_2 = 0, 
    SLOT_K = 1,
    SLOT_Q = 2,
    SLOT_J = 3,
    SLOT_A = 4,
} deck;

extern const char card[CARDS][CARD_ROWS][CARD_COLS];


/* Back-end */

 /* Slot will initialize game */
int slot();

/* Randomizes possible values */
static void slotRand(int []);

/* Points and rewards for the user */
int rewards(int [], int *);
static int validScreen(int, int);


/* Front-end */

int initUI();

void board(int []);
static void rowBoard(void);

//funcion que lee el numero que sale e imprime lo que salio en grande
static void slotToBoard(int []);

// Funciones logicas:
// 1. Funcion de random en rango [0-4] (las cartas)
// 2. Funcion si todas las cartas del vector son iguales -> retorna ganaste (=1).
 
// Funciones de front:
// Tablero.
// Seguir haciendo el game si toca spacebar.
