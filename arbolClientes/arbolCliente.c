

#include "arbolCliente.h"
nodoArbol *inicArbol() {
    return NULL;
}

nodoArbol *crearNodoArbol(stCliente cliente) {
    nodoArbol *nuevo = (nodoArbol *) malloc(sizeof(nodoArbol));

    nuevo->cliente = cliente;
    nuevo->izquierda = inicArbol();
    nuevo->derecha = inicArbol();

    return nuevo;
}

nodoArbol *agregarArbolCliente(nodoArbol *arbol, nodoArbol *nuevo) {
    if (arbol) {
        arbol = nuevo;
    } else {
        if (nuevo->cliente.nroCliente > arbol->cliente.nroCliente) {
            arbol->derecha = agregarArbolCliente(arbol->derecha, nuevo);
        } else {
            arbol->izquierda = agregarArbolCliente(arbol->izquierda, nuevo);
        }
    }
    return arbol;
}