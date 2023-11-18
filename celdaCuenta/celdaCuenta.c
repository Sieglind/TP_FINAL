#include "celdaCuenta.h"
#include "../utils/utils.h"

void agregarMovimientosACeldas(int cantidadCeldas, celda celdas[]);

celda crearCeldaCuenta(stCuenta cuenta) {
    celda celdaCuenta;

    celdaCuenta.dato = cuenta;
    celdaCuenta.listaMovimiento = nuevaLista();

    return celdaCuenta;
}

void liberarMemoriaDeCelda(celda cuenta) {
    eliminarLista(cuenta.listaMovimiento);
}

int contarCuentasEnArchivo() {
    return calcularCantidadDeEstructuras(ARCHIVO_CUENTAS, sizeof(stCuenta));
}

void cargarCuentasEnArreglo(int cantidadCuentas, celda celdas[]) {
    stCuenta cuentas[cantidadCuentas];
    extraerCuentasDesdeArchivo(cantidadCuentas, cuentas);
    for (int i = 0; i < cantidadCuentas; i++) {
        celdas[i] = crearCeldaCuenta(cuentas[i]);
    }
    agregarMovimientosACeldas(cantidadCuentas, celdas);
}

void extraerCuentasDesdeArchivo(int cantidadCuentas, stCuenta cuentas[]) {
    FILE *archivoCuentas = fopen(ARCHIVO_CUENTAS, "rb");
    if (archivoCuentas) {
        fread(cuentas, sizeof(stCuenta), cantidadCuentas, archivoCuentas);
        fclose(archivoCuentas);
    }
}

void agregarMovimientosACeldas(int cantidadCeldas, celda celdas[]) {
    int cantidadMovimientos = contarMovimientosEnArchivo();
    stMovimiento movimientos[cantidadMovimientos];
    extraerMovimientosDesdeArchivo(cantidadMovimientos, movimientos);
    for (int i = 0; i < cantidadCeldas; i++) {
        for (int j = cantidadMovimientos - 1; 0 <= j; j--) {
            if (celdas[i].dato.nroCuenta == movimientos[j].idCuenta) {
                celdas[i].listaMovimiento = agregarALPrincipio(celdas[i].listaMovimiento,
                                                               nuevoNodoLista(movimientos[j]));
            }
        }
    }
}