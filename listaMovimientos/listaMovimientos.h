#include "../persistencias/movimientos/persistenciaMovimientos.h"
#include <stdlib.h>

typedef struct nodoLista {
    stMovimiento movimiento;
    struct nodoLista *siguiente;
} nodoLista;

nodoLista *nuevalista();

nodoLista *nuevoNodoLista(stMovimiento movimiento);

nodoLista *agregarALPrincipio(nodoLista *lista, nodoLista *nodo);