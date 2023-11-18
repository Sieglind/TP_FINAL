#include "listaMovimientos.h"

nodoLista *nuevaLista() {
    return NULL;
}

nodoLista *nuevoNodoLista(stMovimiento movimiento) {
    nodoLista *nodo = (nodoLista *) malloc(sizeof(nodoLista));
    nodo->movimiento = movimiento;
    nodo->siguiente = nuevaLista();
    return nodo;
}

nodoLista *agregarALPrincipio(nodoLista *lista, nodoLista *nodo) {
    if (lista) nodo->siguiente = lista;
    return nodo;
}

void eliminarLista(nodoLista * lista){
    if(lista && lista->siguiente){
        eliminarLista(lista->siguiente);
    } else {
        free(lista);
    }
}