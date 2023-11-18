#include <stdbool.h>

#define BACKSPACE 8
#define ENTER 13
#define ESCAPE 27
#define ESPACIO 32
#define IZQUIERDA 75
#define DERECHA 77
#define FINAL_STRING '\0'

int navegarMenu(int posiciones[], int validos, int valorDeEscape);

int navegarLista(int paginaActual, int paginas, int *opcion);

int solicitarString(int dimension, char string[dimension], int x, int y);