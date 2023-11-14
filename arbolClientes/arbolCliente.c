#include <stdio.h>
#include <sys/stat.h>
#include <math.h>
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

nodoArbol *cargarClientesEnArbol(nodoArbol *arbol) {
    int cantidadClientes = calcularCantidadDeEstructuras(ARCHIVO_CLIENTES, sizeof(stCliente));
    stCliente clientes[cantidadClientes];
    FILE *archivoCLientes = fopen(ARCHIVO_CLIENTES, "rb");
    if (archivoCLientes) {
        fread(clientes, sizeof(stCliente), cantidadClientes, archivoCLientes);
        fclose(archivoCLientes);
    }
    arbol = arregloAArbolBalanceado(clientes, 0, cantidadClientes - 1, arbol);
    return arbol;
}

int calcularCantidadDeEstructuras(char nombreArchivo[], int tamanioEstructura) {
    struct stat status;
    if (stat(nombreArchivo, &status) == 0) {
        return status.st_size / tamanioEstructura;
    } else {
        return -1;
    }
}

nodoArbol *arregloAArbolBalanceado(stCliente arreglo[], int inicio, int fin, nodoArbol *arbol) {
    if (inicio <= fin) {
        int posMedio = floor((inicio + fin) / 2);
        arbol = agregarClienteAlArbol(arbol, crearNodoArbol(arreglo[posMedio]));
        arbol = arregloAArbolBalanceado(arreglo, inicio, posMedio - 1, arbol);
        arbol = arregloAArbolBalanceado(arreglo, posMedio + 1, fin, arbol);
    }
    return arbol;

}