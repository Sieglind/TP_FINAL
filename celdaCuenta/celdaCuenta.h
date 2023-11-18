#include "../persistencias/cuentas/persistenciaCuentas.h"
#include "../listaMovimientos/listaMovimientos.h"

typedef struct {
    stCuenta dato;
    nodoLista *listaMovimiento;
} celda;

celda crearCeldaCuenta(stCuenta cuenta);

void liberarMemoriaDeCelda(celda cuenta);

int contarCuentasEnArchivo();

void cargarCuentasEnArreglo(int cantidadCuentas, celda celdas[]);

void extraerCuentasDesdeArchivo(int cantidadCuentas, stCuenta cuentas[]);