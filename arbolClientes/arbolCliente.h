#include "../persistencias/clientes/persistenciaClientes.h"
#include "../celdaCuenta/celdaCuenta.h"

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

nodoArbol * cargarClientesEnArbol(nodoArbol * arbol);

nodoArbol *cargarCuentasEnArbol(nodoArbol *arbol);

nodoArbol * buscarClienteEnArbol(nodoArbol * arbol, int nroCliente);

nodoArbol* cargarMovimientosArbol(nodoArbol *arbol);

int obtenerNuevoIdCliente (nodoArbol* arbol);

stResultadoClientes listarClientes(nodoArbol * arbol);

nodoArbol * eliminarClienteDeArbol(nodoArbol *arbol, int nroCliente);