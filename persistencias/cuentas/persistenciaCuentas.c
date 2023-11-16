#include <stdio.h>
#include "persistenciaCuentas.h"

int persistirCuentasIniciales(int vCuentas, stCuenta cuentas[vCuentas]) {
    int result = 0;
    FILE *archivo = fopen(ARCHIVO_CUENTAS, "wb");
    if (archivo) {
        result = fwrite(cuentas, sizeof(stCuenta), vCuentas, archivo);
        fclose(archivo);
    }
    return result;
}

//int obtenerNuevoIdCuenta() {
//    struct stat status;
//    if (stat(ARCHIVO_CUENTAS, &status) == 0) {
//        return status.st_size / sizeof(stCuenta);
//    } else {
//        return -1;
//    }
//}
//
//int persistirCuentaNueva(stCuenta cuenta) {
//    FILE *archivo = fopen(ARCHIVO_CUENTAS, "ab");
//    if (archivo) {
//        fwrite(&cuenta, sizeof(stCuenta), 1, archivo);
//        fclose(archivo);
//        return 200;
//    } else {
//        return 500;
//    }
//}
//
//int implementarBusquedaPorCliente(FILE *archivo,int idCliente,stCuenta *cuentas){
//    int vCuentas = 0;
//    stCuenta cuenta;
//    while (fread(&cuenta, sizeof(stCuenta), 1, archivo) == 1) {
//        if ((cuenta.idCliente == idCliente) && (cuenta.eliminada == 0)) vCuentas++;
//    }
//    realloc(cuentas, vCuentas * sizeof(stCuenta));
//    fseek(archivo, 0, SEEK_SET);
//    int i = 0;
//    while (fread(&cuenta, sizeof(stCuenta), 1, archivo) == 1) {
//        if (cuenta.idCliente == idCliente) {
//            cuentas[i] = cuenta;
//            i++;
//        }
//    }
//    return vCuentas;
//}
//
//stResultadoCuentas buscarCuentasPorIdCliente(int idCliente){
//    FILE *archivo = fopen(ARCHIVO_CUENTAS, "rb");
//    stResultadoCuentas resultado;
//    if (archivo) {
//        stCuenta *cuentas = (stCuenta *) malloc(0);
//        int vCuentas = implementarBusquedaPorCliente(archivo, idCliente, cuentas);
//        fclose(archivo);
//        if (0 < vCuentas) {
//            resultado.status = STATUS_OK;
//            resultado.cantidad = vCuentas;
//            resultado.resultados = cuentas;
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
//stResultadoCuentas listarCuentas(){
//    stResultadoCuentas resultado;
//    int cantidad = obtenerNuevoIdCuenta();
//    if (cantidad != 0) {
//        FILE *archivo = fopen(ARCHIVO_CUENTAS, "rb");
//        if (archivo) {
//            stCuenta *clientes = (stCuenta *) malloc(sizeof(stCuenta) * cantidad);
//            stCuenta cliente;
//            int noEliminados = 0;
//            for (int i = 0; i < cantidad; i++) {
//                fread(&cliente, sizeof(stCuenta), 1, archivo);
//                if (cliente.eliminada == 0) clientes[noEliminados++] = cliente;
//            }
//            fclose(archivo);
//            resultado.status = STATUS_OK;
//            resultado.cantidad = noEliminados;
//            resultado.resultados = clientes;
//            return resultado;
//        } else {
//            resultado.status = STATUS_ERROR;
//            return resultado;
//        }
//    } else {
//        resultado.status = STATUS_NO_ENCONTRADO;
//        return resultado;
//    }
//}
//
//stCuenta implementarBusquedaId(FILE * archivo,int nroCuenta){
//    stCuenta cuenta;
//    int encontrado = 0;
//    while (encontrado == 0 && fread(&cuenta, sizeof(stCuenta), 1, archivo) == 1) {
//        if (cuenta.nroCuenta == nroCuenta && cuenta.eliminada == 0) encontrado = 1;
//    }
//    if (encontrado == 0) cuenta.id = -1;
//    return cuenta;
//}
//
//int persistirCuentaEliminada(int nroCuenta){
//    FILE *archivo = fopen(ARCHIVO_CUENTAS, "r+b");
//    if (archivo) {
//        stCuenta cuenta = implementarBusquedaId(archivo, nroCuenta);
//        if (cuenta.id != -1) {
//            cuenta.eliminada = 1;
//            fseek(archivo, cuenta.id * sizeof(stCuenta), SEEK_SET);
//            if (fwrite(&cuenta, sizeof(stCuenta), 1, archivo) == 1){
//                fclose(archivo);
//                return 200;
//            }
//        } else {
//            fclose(archivo);
//            return 404;
//        }
//    } else {
//        return 500;
//    }
//}