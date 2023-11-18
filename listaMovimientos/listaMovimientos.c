#include "listaMovimientos.h"
#include "../utils/utils.h"

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

int contarMovimientosEnArchivo(){
    return calcularCantidadDeEstructuras(ARCHIVO_MOVIMIENTOS, sizeof(stMovimiento));
}

void extraerMovimientosDesdeArchivo(int cantidadMovimientos, stMovimiento movimientos[]){
    FILE *archivoMovimientos = fopen(ARCHIVO_MOVIMIENTOS, "rb");
    if (archivoMovimientos) {
        fread(movimientos, sizeof(stMovimiento), cantidadMovimientos, archivoMovimientos);
        fclose(archivoMovimientos);
    }
}

void eliminarLista(nodoLista * lista){
    if(lista && lista->siguiente){
        eliminarLista(lista->siguiente);
    } else {
        free(lista);
    }
}