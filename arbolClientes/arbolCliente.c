#include <stdio.h>
#include "arbolCliente.h"

nodoArbol *nuevoArbol() {
    return NULL;
}

nodoArbol *crearNodoArbol(stCliente cliente) {
    nodoArbol *nuevo = (nodoArbol *) malloc(sizeof(nodoArbol));

    nuevo->cliente = cliente;
    nuevo->izquierda = nuevoArbol();
    nuevo->derecha = nuevoArbol();

    return nuevo;
}

nodoArbol *agregarClienteAlArbol(nodoArbol *arbol, nodoArbol *nuevo) {
    if (!arbol) {
        arbol = nuevo;
    } else {
        if (nuevo->cliente.nroCliente > arbol->cliente.nroCliente) {
            arbol->derecha = agregarClienteAlArbol(arbol->derecha, nuevo);
        } else {
            arbol->izquierda = agregarClienteAlArbol(arbol->izquierda, nuevo);
        }
    }
    return arbol;
}
