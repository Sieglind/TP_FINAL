#include "../persistencias/clientes/persistenciaClientes.h"
#include "../celdaCuenta/celdaCuenta.h"
#include <stdlib.h>

typedef struct nodoArbol {
    stCliente cliente;
    struct nodoArbol *izquierda;
    struct nodoArbol *derecha;
    celda cuentas[3];
} nodoArbol;

nodoArbol *nuevoArbol();

nodoArbol *crearNodoArbol(stCliente cliente);

nodoArbol *agregarArbolCliente(nodoArbol *arbol, nodoArbol *nuevo);

nodoArbol *crearArbolDesdeArchivos(nodoArbol *arbol);

nodoArbol *cargarClientesEnArbol(nodoArbol *arbol);

nodoArbol *arregloToArbolBalanceado(stCliente clientes[], int inicio, int fin, nodoArbol *arbol);

nodoArbol * cargarCuentasEnClientes(nodoArbol * arbol);

nodoArbol *  cargarCuentasDeArchivo(nodoArbol * arbol);

void preOrder(nodoArbol * arbol);