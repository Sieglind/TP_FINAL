#include "../persistencias/cuentas/persistenciaCuentas.h"
#include "../listaMovimientos/listaMovimientos.h"

typedef struct {
    stCuenta dato;
    nodoLista *listaMovimiento;
} celda;

celda crearCeldaCuenta(stCuenta cuenta);

void liberarMemoriaDeCelda(celda cuenta);