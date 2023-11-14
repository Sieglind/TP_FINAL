#include "../persistencias/clientes/persistenciaClientes.h"
#include "../celdaCuenta/celdaCuenta.h"
#include <stdlib.h>

typedef struct nodoArbol {
    stCliente cliente;
    struct nodoArbol *izquierda;
    struct nodoArbol *derecha;
    int vCuentas;
    celda cuentas[3];
} nodoArbol;

nodoArbol *nuevoArbol();

nodoArbol *crearNodoArbol(stCliente cliente);

nodoArbol *agregarClienteAlArbol(nodoArbol *arbol, nodoArbol *nuevo);