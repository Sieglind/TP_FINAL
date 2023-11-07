#include "../persistencias/clientes/persistenciaClientes.h"
#include <stdlib.h>

typedef struct nodoArbol {
    stCliente cliente;
    struct nodoArbol *izquierda;
    struct nodoArbol *derecha;
} nodoArbol;

nodoArbol *crearNodoArbol(stCliente cliente);

nodoArbol *crearNodoArbol(stCliente cliente);

nodoArbol *agregarArbolCliente(nodoArbol *arbol, nodoArbol *nuevo);