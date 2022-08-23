// Importante antes de pushear devuelta -> arreglar formato headerfile

typedef enum {
    SLOT_2 = 0, 
    SLOT_K = 1,
    SLOT_Q = 2,
    SLOT_J = 3,
    SLOT_A = 4,
} deck;

// Funcion para llamar todo el juego.
int slot();

// Funcion para generar las cartas randoms
void slotRand(int []);

// Funcion para checkear si hizo un 3-row (ganar).
int slotRow();


// Funciones logicas:
// 1. Funcion de random en rango [0-4] (las cartas)
// 2. Funcion si todas las cartas del vector son iguales -> retorna ganaste (=1).
 
// Funciones de front:
// Tablero.
// Seguir haciendo el game si toca spacebar.
