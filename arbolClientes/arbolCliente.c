#include "arbolCliente.h"

#include <stdio.h>
#include <math.h>

#include "../utils/utils.h"

void extraerClientesDeArchivo(int cantidadClientes, stCliente clientes[]);

nodoArbol *arregloAArbolBalanceado(stCliente arreglo[], int inicio, int fin, nodoArbol *arbol);

nodoArbol *agregrarMovimientosAArbol(nodoArbol *arbol, stMovimiento movimientos[], int cantMovimientos);

int contarNodosArbol(nodoArbol *arbol);

void cargarArbolEnArreglo(nodoArbol *arbol, int *posicion, stCliente *clientes);

nodoArbol *nodoMasDerecho(nodoArbol *nodo);

nodoArbol *nodoMasIzquierdo(nodoArbol *nodo);

int esHoja(nodoArbol *nodo);

void liberarMemoriaDeNodo(nodoArbol *nodo);

nodoArbol *nuevoArbol() {
    return NULL;
}

nodoArbol *crearNodoArbol(stCliente cliente) {
    nodoArbol *nuevo = (nodoArbol *) malloc(sizeof(nodoArbol));

    nuevo->cliente = cliente;
    nuevo->vCuentas = 0;
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
    int cantidadClientes = calcularCantidadDeEstructuras(ARCHIVO_CLIENTES,
                                                         sizeof(stCliente));
    stCliente clientes[cantidadClientes];
    extraerClientesDeArchivo(cantidadClientes, clientes);
    arbol = arregloAArbolBalanceado(clientes, 0, cantidadClientes - 1, arbol);
    return arbol;
}

void extraerClientesDeArchivo(int cantidadClientes, stCliente clientes[]) {
    FILE *archivoCLientes = fopen(ARCHIVO_CLIENTES, "rb");
    if (archivoCLientes) {
        fread(clientes, sizeof(stCliente), cantidadClientes, archivoCLientes);
        fclose(archivoCLientes);
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

nodoArbol *cargarCuentasEnArbol(nodoArbol *arbol) {
    int cantidadDeCuentas = calcularCantidadDeEstructuras(ARCHIVO_CUENTAS,
                                                          sizeof(stCuenta));
    stCuenta cuentas[cantidadDeCuentas];

    extraerCuentasDesdeArchivo(cantidadDeCuentas,cuentas);

    for (int i = 0; i < cantidadDeCuentas; i++) {
        nodoArbol *cliente = buscarClienteEnArbol(arbol, cuentas[i].idCliente);
        if (cliente) {
            celda cuentaCliente = crearCeldaCuenta(cuentas[i]);
            cliente->cuentas[cliente->vCuentas] = cuentaCliente;
            cliente->vCuentas = cliente->vCuentas + 1;
        }
    }
    return arbol;
}

nodoArbol *buscarClienteEnArbol(nodoArbol *arbol, int nroCliente) {
    if (arbol) {
        if (arbol->cliente.nroCliente == nroCliente) {
            return arbol;
        } else {
            nodoArbol *auxIzquierda = buscarClienteEnArbol(arbol->izquierda, nroCliente);
            nodoArbol *auxDerecha = buscarClienteEnArbol(arbol->derecha, nroCliente);
            if (auxIzquierda) {
                return auxIzquierda;
            } else if (auxDerecha) {
                return auxDerecha;
            } else return NULL;
        }
    } else {
        return NULL;
    }
}

nodoArbol *cargarMovimientosArbol(nodoArbol *arbol) {
    int cantMovimientos = calcularCantidadDeEstructuras(ARCHIVO_MOVIMIENTOS,
                                                        sizeof(stMovimiento));
    stMovimiento movimientos[cantMovimientos];
    FILE *archi = fopen(ARCHIVO_MOVIMIENTOS, "rb");

    if (archi) {
        fread(movimientos, sizeof(stMovimiento), cantMovimientos, archi);
        fclose(archi);
    }

    arbol = agregrarMovimientosAArbol(arbol, movimientos, cantMovimientos);

    return arbol;
}

nodoArbol *agregrarMovimientosAArbol(nodoArbol *arbol, stMovimiento movimientos[], int cantMovimientos) {
    if (arbol) {
        for (int i = 0; i < arbol->vCuentas; i++) {
            for (int j = 0; j < cantMovimientos; j++) {
                if (arbol->cuentas[i].dato.nroCuenta == movimientos[j].idCuenta) {
                    arbol->cuentas[i].listaMovimiento = agregarALPrincipio(arbol->cuentas[i].listaMovimiento,
                                                                           nuevoNodoLista(movimientos[j]));
                }
            }
        }
        arbol->izquierda = agregrarMovimientosAArbol(arbol->izquierda, movimientos, cantMovimientos);
        arbol->derecha = agregrarMovimientosAArbol(arbol->derecha, movimientos, cantMovimientos);
    }
    return arbol;
}

int obtenerNuevoIdCliente(nodoArbol *arbol) {
    if (arbol) {
        if (arbol->derecha == NULL)
            return arbol->cliente.id + 1;
        else {
            return obtenerNuevoIdCliente(arbol->derecha);
        }
    }
    return 0;
}

stResultadoClientes listarClientes(nodoArbol *arbol) {
    int cantidad = contarNodosArbol(arbol);
    stCliente *resultados = (stCliente *) malloc(sizeof(stCliente) * cantidad);
    int posicion = 0;
    cargarArbolEnArreglo(arbol, &posicion, resultados);
    stResultadoClientes resultado;
    resultado.resultados = resultados;
    resultado.cantidad = cantidad;
    resultado.status = 200;
    return resultado;
}

int contarNodosArbol(nodoArbol *arbol) {
    if (arbol) {
        return 1 + contarNodosArbol(arbol->izquierda) + contarNodosArbol(arbol->derecha);
    } else {
        return 0;
    }
}

void cargarArbolEnArreglo(nodoArbol *arbol, int *posicion, stCliente *clientes) {
    if (arbol) {
        cargarArbolEnArreglo(arbol->izquierda, posicion, clientes);
        clientes[*posicion] = arbol->cliente;
        *posicion = *posicion + 1;
        cargarArbolEnArreglo(arbol->derecha, posicion, clientes);

    }
}

nodoArbol *eliminarClienteDeArbol(nodoArbol *arbol, int nroCliente) {
    if (arbol) {
        if (nroCliente == arbol->cliente.nroCliente) {
            if (arbol->izquierda) {
                nodoArbol *masDerecho = nodoMasDerecho(arbol->izquierda);
                arbol->cliente.nroCliente = masDerecho->cliente.nroCliente;
                arbol->izquierda = eliminarClienteDeArbol(arbol->izquierda, masDerecho->cliente.nroCliente);
            } else {
                if (arbol->derecha) {
                    nodoArbol *masIzquierdo = nodoMasIzquierdo(arbol->derecha);
                    arbol->cliente.nroCliente = masIzquierdo->cliente.nroCliente;
                    arbol->derecha = eliminarClienteDeArbol(arbol->derecha, masIzquierdo->cliente.nroCliente);
                } else {
                    if (esHoja(arbol) == 1) {
                        liberarMemoriaDeNodo(arbol);
                        arbol = nuevoArbol();
                    }
                }
            }
        } else if (nroCliente > arbol->cliente.nroCliente) {
            arbol->derecha = eliminarClienteDeArbol(arbol->derecha, nroCliente);
        } else if (nroCliente < arbol->cliente.nroCliente) {
            arbol->izquierda = eliminarClienteDeArbol(arbol->izquierda, nroCliente);
        }
    }
    return arbol;
}

nodoArbol *nodoMasDerecho(nodoArbol *nodo) {
    if (nodo && nodo->derecha) nodo = nodoMasDerecho(nodo->derecha);
    return nodo;
}

nodoArbol *nodoMasIzquierdo(nodoArbol *nodo) {
    if (nodo && nodo->izquierda) nodo = nodoMasIzquierdo(nodo->izquierda);
    return nodo;
}

int esHoja(nodoArbol *nodo) {
    return !nodo->derecha && !nodo->izquierda;
}

void liberarMemoriaDeNodo(nodoArbol *nodo) {
    for (int i = 0; i < nodo->vCuentas; i++) {
        liberarMemoriaDeCelda(nodo->cuentas[i]);
    }
}