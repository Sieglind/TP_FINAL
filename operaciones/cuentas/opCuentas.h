#include "../../celdaCuenta/celdaCuenta.h"

int opInicializarCuentas(int vClientes, const int idClientes[vClientes], int cuentas[]);

int opVerificarCliente(int arrayIdCliente[]);

int opGuardarNuevaCuenta(int vCeldas, celda celdas[],int arrayIdCuenta[], int tipoDeCuenta);

stResultadoCuentas opBuscarCuentas(celda celda[],int vCelda,int arrayIdCliente[]);

stResultadoCuentas opListarCuentas(celda celdas[],int vCuentas);

int opBorrarCuenta(celda celdas[],int * vCeldas, int arrayNroCuenta[]);