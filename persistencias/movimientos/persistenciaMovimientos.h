#ifndef TP_FINAL_PERSISTENCIAMOVIMIENTOS_H
#define TP_FINAL_PERSISTENCIAMOVIMIENTOS_H

#include <stdio.h>

#define ARCHIVO_MOVIMIENTOS "movimientos.dat"
#define ID_INICIAL_MOVIMIENTOS 90000000

typedef struct {
    int id;
    int idCuenta;
    int anio;
    int mes;
    int dia;
    char detalle[100];
    float importe;
    int eliminado;
} stMovimiento;

typedef struct{
    int status;
    int cantidad;
    stMovimiento * resultados;
} stResultadoMovimientos;

int persistirMovimientosIniciales(int vMovimientos,stMovimiento movimientos[vMovimientos]);

#endif //TP_FINAL_PERSISTENCIAMOVIMIENTOS_H