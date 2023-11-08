#include <stdio.h>

#define ARCHIVO_CUENTAS "cuentas.dat"
#define ID_INICIAL_CUENTAS 60000000
#define STATUS_OK 200
#define STATUS_NO_ENCONTRADO 404
#define STATUS_ERROR 500

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

int obtenerNuevoIdCuenta();

int persistirCuentaNueva(stCuenta cuenta);

int implementarBusquedaPorCliente(FILE *archivo,int idCliente,stCuenta *cuentas);

stResultadoCuentas buscarCuentasPorIdCliente(int idCliente);

stResultadoCuentas listarCuentas();

int persistirCuentaEliminada(int idCliente);