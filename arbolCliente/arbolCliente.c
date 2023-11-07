

#include "arbolCliente.h"
nodoArbol *inicArbol() {
    return NULL;
}

nodoArbol *crearNodoArbol(stCliente cliente) {
    nodoArbol *nuevo = (nodoArbol *) malloc(sizeof(nodoArbol));

    nuevo->dato = cliente;
    nuevo->izq = inicArbol();
    nuevo->der = inicArbol();

    return nuevo;
}

nodoArbol *agregarArbolCliente(nodoArbol *arbol, nodoArbol *nuevo) {
    if (arbol) {
        arbol = nuevo;
    } else {
        if (nuevo->dato.nroCliente > arbol->dato.nroCliente) {
            arbol->der = agregarArbolCliente(arbol->der, nuevo);
        } else {
            arbol->izq = agregarArbolCliente(arbol->izq, nuevo);
        }
    }
    return arbol;
}