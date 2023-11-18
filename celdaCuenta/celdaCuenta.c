#include "celdaCuenta.h"

celda crearCeldaCuenta(stCuenta cuenta) {
    celda celdaCuenta;

    celdaCuenta.dato = cuenta;
    celdaCuenta.listaMovimiento = nuevaLista();

    return celdaCuenta;
}

void liberarMemoriaDeCelda(celda cuenta) {
    eliminarLista(cuenta.listaMovimiento);
}