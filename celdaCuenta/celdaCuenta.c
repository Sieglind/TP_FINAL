#include "celdaCuenta.h"
#include "../utils/utils.h"

celda crearCeldaCuenta(stCuenta cuenta) {
    celda celdaCuenta;

    celdaCuenta.dato = cuenta;
    celdaCuenta.listaMovimiento = nuevaLista();

    return celdaCuenta;
}

void liberarMemoriaDeCelda(celda cuenta) {
    eliminarLista(cuenta.listaMovimiento);
}

int contarCuentasEnArchivo(){
    return calcularCantidadDeEstructuras(ARCHIVO_CUENTAS, sizeof(stCuenta));
}

void cargarCuentasEnArreglo(int cantidadCuentas, celda celdas[]) {
    stCuenta cuentas[cantidadCuentas];
    extraerCuentasDesdeArchivo(cantidadCuentas, cuentas);
    for (int i = 0; i < cantidadCuentas; i++) {
        celdas[i] = crearCeldaCuenta(cuentas[i]);
    }
}

void extraerCuentasDesdeArchivo(int cantidadCuentas, stCuenta cuentas[]) {
    FILE *archivoCuentas = fopen(ARCHIVO_CUENTAS, "rb");
    if (archivoCuentas) {
        fread(cuentas, sizeof(stCuenta), cantidadCuentas, archivoCuentas);
        fclose(archivoCuentas);
    }
}