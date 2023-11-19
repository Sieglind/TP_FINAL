#ifndef TP_FINAL_LISTAMOVIMIENTOS_H
#define TP_FINAL_LISTAMOVIMIENTOS_H

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

nodoLista * cargarMovimientosEnLista(nodoLista * movimientos);

#endif //TP_FINAL_LISTAMOVIMIENTOS_H