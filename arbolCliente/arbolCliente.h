#include "../persistencias/clientes/persistenciaClientes.h"

typedef struct nodoArbol {
    stCliente dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
} nodoArbol;

nodoArbol *crearNodoArbol(stCliente cliente);

nodoArbol *crearNodoArbol(stCliente cliente);

nodoArbol *agregarArbolCliente(nodoArbol *arbol, nodoArbol *nuevo);