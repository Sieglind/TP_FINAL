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

nodoArbol *crearArbolDesdeArchivos(nodoArbol *arbol) {
    FILE *archivoClientes = fopen(ARCHIVO_CLIENTES, "rb");
    FILE *archivoCuentas = fopen(ARCHIVO_CUENTAS, "rb");
    FILE *archivoMovimientos = fopen(ARCHIVO_MOVIMIENTOS, "rb");
    if (archivoClientes && archivoCuentas && archivoMovimientos) {
        stCliente cliente;
        int vCuentas;
        stCuenta *cuentas = (stCuenta *) malloc(0);
        while (fread(&cliente, sizeof(stCliente), 1, archivoClientes) > 0) {
            nodoArbol *nodoCliente = crearNodoArbol(cliente);
            vCuentas = implementarBusquedaPorCliente(archivoCuentas, cliente.nroCliente, cuentas);
            for (int i = 0; i < vCuentas; i++) {
                nodoCliente->cuentas[i] = crearCeldaCuenta(cuentas[i]);
                int vMovimientos;
                stMovimiento *movimientos = (stMovimiento *) malloc(0);
                vMovimientos = implementarBusquedaPorCuenta(archivoMovimientos,
                                                            cuentas[i].nroCuenta,
                                                            movimientos);
                for (int j = 0; j < vMovimientos; j++) {
                    nodoCliente->cuentas[i].listaMovimiento = agregarALPrincipio(
                            nodoCliente->cuentas[i].listaMovimiento,
                            nuevoNodoLista(movimientos[j])
                    );
                }
                free(movimientos);
            }
            arbol = agregarArbolCliente(arbol, nodoCliente);
        }
    }
    fclose(archivoClientes);
    fclose(archivoCuentas);
    fclose(archivoMovimientos);
    return arbol;
}