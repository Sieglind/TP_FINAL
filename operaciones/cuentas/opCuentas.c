#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "opCuentas.h"
#include "../../utils/gotoxy.h"
#include "../../utils/utils.h"
#include "../../arbolClientes/arbolCliente.h"

int contarCuentasCliente(celda celdas[], int vCelda, int idCliente);

void cargarCuentasEnResultado(celda celda[], stCuenta *cuentas, int vCelda, int vCuenta, int idCLiente);

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

int opVerificarCliente(int arrayIdCliente[]) {
    int idCliente = convertirArrayEnId(arrayIdCliente);
    return verificarClienteExiste(idCliente);
}

int opGuardarNuevaCuenta(int vCeldas, celda celdas[], int arrayIdCuenta[], int tipoDeCuenta) {
    int idCliente = (int) convertirArrayEnId(arrayIdCuenta);
    float costoMensual[3] = {1000, 2000, 1500};
    int id = celdas[vCeldas - 1].dato.id + 1;
    stCuenta cuenta = {
            .id = id,
            .idCliente = idCliente,
            .nroCuenta = ID_INICIAL_CUENTAS + id,
            .tipoDeCuenta=tipoDeCuenta,
            .costoMensual=costoMensual[tipoDeCuenta - 1],
            .eliminada=0
    };
    celdas[vCeldas++] = crearCeldaCuenta(cuenta);
    return vCeldas;
}

stResultadoCuentas opBuscarCuentas(celda celda[], int vCelda, int arrayIdCliente[]) {
    int idCliente = convertirArrayEnId(arrayIdCliente);
    int cantCuentas = contarCuentasCliente(celda, vCelda, idCliente);
    stResultadoCuentas resultado;
    if (cantCuentas != 0) {
        stCuenta *resultados = (stCuenta *) malloc(sizeof(stCuenta) * cantCuentas);
        cargarCuentasEnResultado(celda, resultados, vCelda, cantCuentas, idCliente);
        resultado.resultados = resultados;
        resultado.status = 200;
    } else {
        resultado.status = 404;
    }
    resultado.cantidad = cantCuentas;
    return resultado;
}

int contarCuentasCliente(celda celdas[], int vCelda, int idCliente) {
    int cont = 0;
    for (int i = 0; i < vCelda; i++) {
        if (celdas[i].dato.idCliente == idCliente) {
            cont++;
        }
    }
    return cont;
}

void cargarCuentasEnResultado(celda celda[], stCuenta *cuentas, int vCelda, int vCuenta, int idCLiente) {
    int contarCuentas = 0;
    for (int i = 0; i < vCelda; i++) {
        if (celda[i].dato.idCliente == idCLiente) {
            cuentas[contarCuentas] = celda[i].dato;
            contarCuentas++;
        }
    }
}


stResultadoCuentas opListarCuentas(celda celdas[], int vCeldas) {
    stResultadoCuentas resultado;
    stCuenta *resultados = (stCuenta *) malloc(sizeof(stCuenta) * vCeldas);
    for (int i = 0; i < vCeldas; i++) {
        resultados[i] = celdas[i].dato;
    }
    resultado.resultados = resultados;
    resultado.cantidad = vCeldas;
    resultado.status = 200;
    return resultado;
}

//int opBorrarCuenta(int arrayNroCuenta[]){
//    int nroCuenta =(int) convertirIdClienteArrayAInt(arrayNroCuenta);
//    return persistirCuentaEliminada(nroCuenta);
//}