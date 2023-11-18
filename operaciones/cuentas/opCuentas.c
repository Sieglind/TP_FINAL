#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "opCuentas.h"
#include "../../utils/gotoxy.h"
#include "../../utils/utils.h"
#include "../../arbolClientes/arbolCliente.h"


int opInicializarCuentas(int vIdClientes, const int idClientes[vIdClientes], int nroCuentas[]) {
    float costoMensual[3] = {1000, 2000, 1500};
    stCuenta cuentas[3 * vIdClientes];
    int vCuentas = 0;
    stCuenta cuenta;
    for (int i = 0; i < vIdClientes; i++) {
        for (int j = 1; j <= 3; j++) {
            if (rand() % 2) {
                cuenta.id = vCuentas;
                cuenta.idCliente = idClientes[i];
                cuenta.nroCuenta = ID_INICIAL_CUENTAS + vCuentas;
                nroCuentas[vCuentas] = cuenta.nroCuenta;
                cuenta.tipoDeCuenta = j;
                cuenta.costoMensual = costoMensual[j - 1];
                cuenta.eliminada = 0;
                cuentas[vCuentas] = cuenta;
                gotoxy(25, 15);
                usleep(1000000 / 150);
                printf("%8d | %8d", cuenta.idCliente, cuenta.nroCuenta);
                vCuentas++;
            }
        }
    }
    return persistirCuentasIniciales(vCuentas, cuentas);
}

int opVerificarCliente(int arrayIdCliente[]){
    int idCliente = convertirArrayEnId(arrayIdCliente);
    return verificarClienteExiste(idCliente);
}

void opGuardarNuevaCuenta(int vCeldas, celda celdas[],int arrayIdCuenta[], int tipoDeCuenta){
    int idCliente =(int) convertirArrayEnId(arrayIdCuenta);
    float costoMensual[3] = {1000, 2000, 1500};
    int id = celdas[vCeldas-1].dato.id+1;
    stCuenta cuenta = {
            .id = id,
            .idCliente = idCliente,
            .nroCuenta = ID_INICIAL_CUENTAS + id,
            .tipoDeCuenta=tipoDeCuenta,
            .costoMensual=costoMensual[tipoDeCuenta - 1],
            .eliminada=0
    };
    celdas[vCeldas++] = crearCeldaCuenta(cuenta);
}

//stResultadoCuentas opBuscarCuentas(int arrayIdCliente[]){
//    int idCliente = (int) convertirIdClienteArrayAInt(arrayIdCliente);
//    return buscarCuentasPorIdCliente(idCliente);
//}
//
//stResultadoCuentas opListarCuentas(){
//    return listarCuentas();
//}
//
//int opBorrarCuenta(int arrayNroCuenta[]){
//    int nroCuenta =(int) convertirIdClienteArrayAInt(arrayNroCuenta);
//    return persistirCuentaEliminada(nroCuenta);
//}