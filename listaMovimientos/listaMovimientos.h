#include "../persistencias/movimientos/persistenciaMovimientos.h"
#include <stdlib.h>

typedef struct nodoLista {
    stMovimiento movimiento;
    struct nodoLista *siguiente;
} nodoLista;

nodoLista *nuevaLista();

nodoLista *nuevoNodoLista(stMovimiento movimiento);

nodoLista *agregarALPrincipio(nodoLista *lista, nodoLista *nodo);

int contarMovimientosEnArchivo();

void extraerMovimientosDesdeArchivo(int cantidadMovimientos, stMovimiento movimientos[]);

void eliminarLista(nodoLista * lista);