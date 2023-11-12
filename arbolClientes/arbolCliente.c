#include <stdio.h>
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

nodoArbol *agregarArbolCliente(nodoArbol *arbol, nodoArbol *nuevo) {
    if (!arbol) {
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
        while (fread(&cliente, sizeof(stCliente), 1, archivoClientes) > 0) {
            nodoArbol *nodoCliente = crearNodoArbol(cliente);
            int vCuentas;
            stCuenta *cuentas = (stCuenta *) malloc(0);
            vCuentas = implementarBusquedaPorCliente(archivoCuentas, cliente.nroCliente, cuentas);
            for (int i = 0; i < vCuentas; i++) {
                nodoCliente->cuentas[i] = crearCeldaCuenta(cuentas[i]);
                int vMovimientos;
                stMovimiento *movimientos = (stMovimiento *) malloc(100 * sizeof(stMovimiento));
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
            free(cuentas);
            arbol = agregarArbolCliente(arbol, nodoCliente);
        }
    }
    fclose(archivoClientes);
    fclose(archivoCuentas);
    fclose(archivoMovimientos);
    return arbol;
}

nodoArbol *cargarClientesEnArbol(nodoArbol *arbol) {
    FILE *archivo = fopen(ARCHIVO_CLIENTES, "rb");
    if (archivo) {
        fseek(archivo, 0, SEEK_END);
        int cantidad = ftell(archivo) / sizeof(stCliente);
        stCliente clientes[cantidad];
        fseek(archivo, 0, SEEK_SET);
        for (int i = 0; i < cantidad; i++) {
            fread(&clientes[i], sizeof(stCliente), 1, archivo);
        }
        arbol= arregloToArbolBalanceado(clientes,0,cantidad-1,arbol);
        fclose(archivo);
    }
    return arbol;
}

void preOrder(nodoArbol * arbol)
{
    if(arbol)
    {
        printf("%d,",arbol->cliente.nroCliente -30000000 );
        preOrder(arbol->izquierda);
        preOrder(arbol->derecha);
    }
}

nodoArbol *arregloToArbolBalanceado(stCliente clientes[50], int inicio, int fin, nodoArbol *arbol) {
    if (inicio <= fin) {
        int posMedio = floor((inicio + fin) / 2);
        arbol = agregarArbolCliente(arbol, crearNodoArbol(clientes[posMedio]));
        arbol = arregloToArbolBalanceado(clientes, inicio, posMedio - 1, arbol);
        arbol = arregloToArbolBalanceado(clientes, posMedio + 1, fin, arbol);
    }
    return arbol;

}

nodoArbol * cargarCuentasEnClientes(nodoArbol * arbol){
    if(arbol) {
        arbol = cargarCuentasDeArchivo(arbol);
        arbol->izquierda = cargarCuentasEnClientes(arbol->izquierda);
        arbol->derecha = cargarCuentasEnClientes(arbol->derecha);
    }
    return arbol;
}

nodoArbol *  cargarCuentasDeArchivo(nodoArbol * arbol){
    stResultadoCuentas cuentas = buscarCuentasPorIdCliente(arbol->cliente.nroCliente);
    for (int i = 0;i<cuentas.cantidad;i++){
        if (cuentas.status == 200){
            arbol->cuentas[i] = crearCeldaCuenta(cuentas.resultados[i]);
        }
    }
    return arbol;
}

