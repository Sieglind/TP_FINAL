//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include <stdio.h>
//#include "opMovimientos.h"
//#include "../../utils/gotoxy.h"
//
//#define DETALLES_POSITIVOS {"DEPOSITO EFECTIVO", "DEPOSITO CHEQUE", "TRANSFERENCIA RECIBIDA", "PAGO RECIBIDO", "INGRESO SALARIO", "INTERESES INVERSIONES", "DEPOSITO PLAZO FIJO", "INTERESES BONOS", "REEMBOLSO", "DEVOLUCION", "TRANSFERENCIA CUENTAS PROPIAS", "BONIFICACION"}
//#define DETALLES_NEGATIVOS {"RETIRO EN EFECTIVO", "PAGO DE SEGURO HOGAR", "PAGO DE SEGURO AUTOMOTOR", "DEBITO AUTOMATICO DE TARJETA DE CREDITO", "PAGO CON TARJETA DE DEBITO", "TRANSFERENCIA A OTRA CUENTA", "PAGO DE CHEQUE EMITIDO", "PERDIDA POR INVERSIONES", "COMPRA DE MONEDA EXTRANJERA", "GASTOS POR MANTENIMIENTO DE CUENTA", "PAGO SEGURO DE VIDA", "DEBITO AUTOMATICO DE SERVICIO"}
//
//int opInicializarMovimientos(int cantidadCuentas, int cuentas[cantidadCuentas]) {
//    int dias[] = {31, 28, 31, 30, 31};
//    char debitos[12][100] = DETALLES_NEGATIVOS;
//    char creditos[12][100] = DETALLES_POSITIVOS;
//    int vMovimientos = 0;
//    stMovimiento *movimientos = (stMovimiento *) malloc(sizeof(stMovimiento) * 1000);
//    for (int mes = 1; mes <= 5; mes++) {
//        for (int dia = 1; dia <= dias[mes - 1]; dia++) {
//            for (int cuenta = 0; cuenta < cantidadCuentas; cuenta++) {
//                for (int intento = 0; intento < 3; intento++) {
//                    if ((rand() % 30 == 0) && vMovimientos < 1000) {
//                        float importe = (float) ((rand() % 20000) - 10000);
//                        stMovimiento movimiento = {
//                                .id=ID_INICIAL_MOVIMIENTOS + vMovimientos,
//                                .idCuenta=cuentas[cuenta],
//                                .anio=2023,
//                                .mes=mes,
//                                .dia=dia,
//                                .importe=importe,
//                                .eliminado=0};
//                        strcpy(movimiento.detalle, importe <= 0 ? debitos[rand() % 13] : creditos[rand() % 13]);
//                        movimientos[vMovimientos++] = movimiento;
//                        gotoxy(25, 17);
//                        printf("%02d/%02d/%d - %8d | %8d",
//                               movimiento.dia,
//                               movimiento.mes,
//                               movimiento.anio,
//                               movimiento.idCuenta,
//                               movimiento.id);
//                    }
//                }
//            }
//        }
//    }
//    return persistirMovimientosIniciales(vMovimientos, movimientos);
//}
//
//double convertirIdArrayAInt(const int idCuenta[8]) {
//    double intIdCuenta = 0;
//    for (int i = 0; i<=7; i++) {
//        intIdCuenta = intIdCuenta + (double)idCuenta[i]*pow(10,7-i);
//    }
//    return intIdCuenta;
//}
//
//stResultadoMovimientos opBuscarMovimientosPorCuenta(int arrayIdCuenta[8]) {
//    int idCuenta =(int) convertirIdArrayAInt(arrayIdCuenta);
//    return buscarMovimientosPorCuenta(idCuenta);
//}