//
// Created by moral on 18/11/2023.
//

#ifndef TP_FINAL_PERSISTENCIAMOVIMIENTOS_H
#define TP_FINAL_PERSISTENCIAMOVIMIENTOS_H

#include <stdio.h>

#define ARCHIVO_MOVIMIENTOS "movimientos.dat"
#define ID_INICIAL_MOVIMIENTOS 90000000
#define STATUS_OK 200
#define STATUS_NO_ENCONTRADO 404
#define STATUS_ERROR 500

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

//int implementarBusquedaPorCuenta(FILE *archivo, int idCuenta, stMovimiento *movimientos);
//
//stResultadoMovimientos buscarMovimientosPorCuenta(int idCuenta);
//
//void eliminarMovimientosPorCuenta(int idCuenta);

#endif //TP_FINAL_PERSISTENCIAMOVIMIENTOS_H