#ifndef TP_FINAL_PERSISTENCIACUENTAS_H
#define TP_FINAL_PERSISTENCIACUENTAS_H

#include <stdio.h>

#define ARCHIVO_CUENTAS "cuentas.dat"
#define ID_INICIAL_CUENTAS 60000000

typedef struct {
    int id;
    int idCliente;
    int nroCuenta;
    int tipoDeCuenta;
    float costoMensual;
    int eliminada;
} stCuenta;

typedef struct {
    int status;
    int cantidad;
    stCuenta * resultados;
} stResultadoCuentas;

int persistirCuentasIniciales(int vCuentas,stCuenta cuentas[vCuentas]);

#endif //TP_FINAL_PERSISTENCIACUENTAS_H