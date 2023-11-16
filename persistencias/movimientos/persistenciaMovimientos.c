#include <stdio.h>
#include "persistenciaMovimientos.h"

int persistirMovimientosIniciales(int vMovimientos, stMovimiento movimientos[vMovimientos]) {
    int result = 0;
    FILE *archivo = fopen(ARCHIVO_MOVIMIENTOS, "wb");
    if (archivo) {
        result = fwrite(movimientos, sizeof(stMovimiento), vMovimientos, archivo);
        fclose(archivo);
    }
    return result;
}

//int implementarBusquedaPorCuenta(FILE *archivo, int idCuenta, stMovimiento *movimientos) {
//    int vMovimientos = 0;
//    stMovimiento movimiento;
//    while (fread(&movimiento, sizeof(stMovimiento), 1, archivo) == 1) {
//        if (movimiento.idCuenta == idCuenta) vMovimientos++;
//    }
//    realloc(movimientos, vMovimientos * sizeof(stMovimiento));
//    fseek(archivo, 0, SEEK_SET);
//    int i = 0;
//    while (fread(&movimiento, sizeof(stMovimiento), 1, archivo) == 1) {
//        if (movimiento.idCuenta == idCuenta) {
//            movimientos[i] = movimiento;
//            i++;
//        }
//    }
//    return vMovimientos;
//}
//
//stResultadoMovimientos buscarMovimientosPorCuenta(int idCuenta) {
//    FILE *archivo = fopen(ARCHIVO_MOVIMIENTOS, "rb");
//    stResultadoMovimientos resultado;
//    if (archivo) {
//        stMovimiento *movimientos = (stMovimiento *) malloc(0);
//        int vMovimientos = implementarBusquedaPorCuenta(archivo, idCuenta, movimientos);
//        fclose(archivo);
//        if (0 < vMovimientos) {
//            resultado.status = STATUS_OK;
//            resultado.cantidad = vMovimientos;
//            resultado.resultados = movimientos;
//            return resultado;
//        } else {
//            resultado.status = STATUS_NO_ENCONTRADO;
//            return resultado;
//        }
//    } else {
//        resultado.status = STATUS_ERROR;
//        return resultado;
//    }
//}
//
//void persistirCambios(FILE *archivo, int vMovimientos, stMovimiento *movimientos) {
//    for (int i = 0; i < vMovimientos; ++i) {
//        fseek(archivo, movimientos[i].id * sizeof(stMovimiento), SEEK_SET);
//        fwrite(&movimientos[i], sizeof(stMovimiento), 1, archivo);
//    }
//}
//
//void eliminarMovimientosPorCuenta(int idCuenta) {
//    FILE *archivo = fopen(ARCHIVO_MOVIMIENTOS, "rb");
//    if (archivo) {
//        stMovimiento *movimientos = (stMovimiento *) malloc(0);
//        int vMovimientos = implementarBusquedaPorCuenta(archivo, idCuenta, movimientos);
//        for (int i = 0; i < vMovimientos; i++) {
//            movimientos[i].eliminado = 1;
//        }
//        persistirCambios(archivo, vMovimientos, movimientos);
//        fclose(archivo);
//    }
//}