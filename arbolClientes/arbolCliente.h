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

nodoArbol * cargarClientesEnArbol(nodoArbol * arbol);

int calcularCantidadDeEstructuras(char nombreArchivo[], int tamañoEstructura);

nodoArbol *arregloAArbolBalanceado(stCliente arreglo[], int inicio, int fin, nodoArbol *arbol);

nodoArbol *cargarCuentasEnArbol(nodoArbol *arbol);

nodoArbol * buscarClienteEnArbol(nodoArbol * arbol, int nroCliente);

nodoArbol* cargarMovimientosArbol(nodoArbol *arbol);

nodoArbol *agregrarMovimientosAArbol(nodoArbol *arbol, stMovimiento movimientos[], int cantMovimientos);

int obtenerNuevoIdCliente (nodoArbol* arbol);