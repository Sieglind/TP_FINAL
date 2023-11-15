//#include <stdio.h>
//#include <unistd.h>
//#include <conio.h>
//#include <stdlib.h>
//#include "otros.h"
//#include "../../utils/gotoxy.h"
//#include "../movimientos/opMovimientos.h"
//#include "../clientes/opClientes.h"
//#include "../cuentas/opCuentas.h"
//
//#define CLIENTES    "Clientes"
//#define CUENTAS     "Cuentas"
//#define MOVIMIENTOS "Movimientos"
//
//int emitirError(char error[]) {
//    printf("Hubo un error en la inicializacion de %s.", error);
//    getch();
//    return 0;
//}
//
//int opInicializarDatos() {
//    gotoxy(25, 12);
//    printf("Creando clientes...");
//    int idClientes[50];
//    int vIdClientes = opInicializarClientes(idClientes);
//    if (vIdClientes == 50) {
//        gotoxy(25, 14);
//        printf("Creando cuentas...");
//        int nroCuentas[150];
//        int vNroCuentas = opInicializarCuentas(vIdClientes, idClientes, nroCuentas);
//        if (0 < vNroCuentas) {
//            gotoxy(25, 16);
//            printf("Creando movimientos...");
//            int idCuentas = opInicializarMovimientos(vNroCuentas, nroCuentas);
//            if (idCuentas != 0) {
//                gotoxy(25, 18);
//                printf("Inicializacion exitosa!...");
//            } else {
//                return emitirError(MOVIMIENTOS);
//            }
//        } else {
//            return emitirError(CUENTAS);
//        }
//    } else {
//        return emitirError(CLIENTES);
//    }
//    getch();
//    return 0;
//}