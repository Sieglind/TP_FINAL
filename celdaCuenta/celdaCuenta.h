#ifndef TP_FINAL_CELDACUENTA_H
#define TP_FINAL_CELDACUENTA_H

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

void celdaCuentaToArchivo(celda celdas[],int vCeldas);

#endif //TP_FINAL_CELDACUENTA_H