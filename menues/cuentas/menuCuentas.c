#include "menuCuentas.h"

#include <stdio.h>
#include <conio.h>

#include "../../interfaces/interfaces.h"
#include "../navegacion/navegacion.h"
#include "../../utils/gotoxy.h"
#include "../../utils/utils.h"
#include "../../operaciones/cuentas/opCuentas.h"


#define BREADCRUM_CREAR         "CUENTAS : Crear    : Ingrese el numero de cliente al que crearle una cuenta      : "
#define BREADCRUMB_BUSCAR       "CUENTAS : Buscar   : Ingrese el numero de cliente del cual quiere buscar cuentas : "
#define BREADCRUMB_ELIMINAR     "CUENTAS : Eliminar : Ingrese un numero de cuenta para borrar                     : "
#define MENSAJE_NO_ENCONTRADO   "No se encontro una cuenta ascoiada a dicho numero de cuenta."
#define MENSAJE_ERROR           "Error desconocido."
#define PAGINA_ANTERIOR         "<-- Pagina Anterior"
#define PAGINA_SIGUIENTE        "Pagina Siguiente -->"

int navegarMenuCuentas();

int menuCrearCuenta(int vCeldas, celda celdas[]);

int menuIngresarIdCliente(int arrayNroCliente[8], int status, char breadcrumb[]);

int menuBuscarCuentas(celda celdas[], int vCeldas);

int menuResultadoCuentas(stResultadoCuentas resultado);

void mostrarPaginaCuentas(stResultadoCuentas resultado, int paginaActual, int paginas);

int menuListarCuentas(celda celdas[], int vCeldas);

int menuBorrarCuenta(celda celda[], int vCelda);

int menuCuentas() {
    int opcion = 0;
    int vCeldas = contarCuentasEnArchivo();
    celda celdas[vCeldas * 2];
    cargarCuentasEnArreglo(vCeldas, celdas);
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                cargarMenuCuentas();
                opcion = navegarMenuCuentas();
                break;
            case 39:
                vCeldas = menuCrearCuenta(vCeldas, celdas);
                opcion = 0;
                break;
            case 59:
                opcion = menuBuscarCuentas(celdas, vCeldas);
                break;
            case 79:
                opcion = menuListarCuentas(celdas, vCeldas);
                break;
            case 99:
                opcion = menuBorrarCuenta(celdas, vCeldas);
                break;
        }
    }
    celdaCuentaToArchivo(celdas,vCeldas);
    return 0;
}

int navegarMenuCuentas() {
    int posiciones[] = {39, 59, 79, 99};
    return navegarMenu(posiciones, 4, ESCAPE);
}

int menuCrearCuenta(int vCeldas, celda celdas[]) {
    int arrayIdCliente[8];
    int tipoDeCuenta = 0;
    int paso = 0;
    int y = 12;
    while (paso != ESCAPE) {
        switch (paso) {
            case 0:
                paso = menuIngresarIdCliente(arrayIdCliente, 200, BREADCRUM_CREAR);
                break;
            case 1:
                paso = opVerificarCliente(arrayIdCliente);
                break;
            case 200:
                gotoxy(33, y++);
                printf("Que tipo de cuenta desea crear?:");
                gotoxy(33, y++);
                printf("1 - Caja de ahorro en pesos.");
                gotoxy(33, y++);
                printf("2 - Caja de ahorro en dolares.");
                gotoxy(33, y++);
                printf("3 - Cuenta corriente en pesos.");
                gotoxy(whereX() + 3, whereX() - 4);
                do {
                    fflush(stdin);
                    tipoDeCuenta = getch();
                } while (!(48 < tipoDeCuenta && tipoDeCuenta < 52) && tipoDeCuenta != ESCAPE);
                paso = (tipoDeCuenta == ESCAPE) ? ESCAPE : 2;
                break;
            case 404:
                paso = menuIngresarIdCliente(arrayIdCliente, 404, BREADCRUM_CREAR);
                break;
            case 500:
                paso = menuIngresarIdCliente(arrayIdCliente, 500, BREADCRUM_CREAR);
                break;
            case 2:
                vCeldas = opGuardarNuevaCuenta(vCeldas, celdas, arrayIdCliente, tipoDeCuenta - 48);
                gotoxy(33, y);
                printf("CUENTA CREADA CORRECTAMENTE...");
                paso = ESCAPE;
                getch();
                fflush(stdin);
                break;
        }
    }
    return vCeldas;
}

int menuIngresarIdCliente(int arrayNroCliente[8], int status, char breadcrumb[]) {
    if (status == 200) {
        gotoxy(19, 2);
        printf("%-90s", breadcrumb);
        gotoxy(whereX() - 8, whereY());
    } else {
        gotoxy(whereX() - 8, 2);
        printf("%8s", " ");
        gotoxy(19, 3);
        printf("%-61s", status == 404 ? MENSAJE_NO_ENCONTRADO : MENSAJE_ERROR);
        gotoxy(102, 2);
    }
    return obtenerId(arrayNroCliente);
}

int menuBuscarCuentas(celda celdas[], int vCeldas) {
    int arrayIdCliente[8];
    stResultadoCuentas resultado;
    int opcion = 0;
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                opcion = menuIngresarIdCliente(arrayIdCliente, 200, BREADCRUMB_BUSCAR);
                break;
            case 1:
                resultado = opBuscarCuentas(celdas, vCeldas, arrayIdCliente);
                opcion = resultado.status;
                break;
            case 200:
                opcion = menuResultadoCuentas(resultado);
                free(resultado.resultados);
                break;
            case 404:
                opcion = menuIngresarIdCliente(arrayIdCliente, 404, BREADCRUMB_BUSCAR);
                break;
//            case 500:
//                opcion = menuIngresarIdCliente(arrayIdCliente, 500, BREADCRUMB_BUSCAR);
//                break;
        }
    }
    return 0;
}

int menuResultadoCuentas(stResultadoCuentas resultado) {
    int paginas = (resultado.cantidad / 24) + (resultado.cantidad % 24 != 0 ? 1 : 0);
    int paginaActual = 0;
    int paginaDestino = 1;
    int opcion = 0;
    while (opcion != ESCAPE) {
        if (paginaDestino != paginaActual) {
            paginaActual = paginaDestino;
            mostrarPaginaCuentas(resultado, paginaActual, paginas);
        }
        paginaDestino = navegarLista(paginaActual, paginas, &opcion);
    }
    return 0;
}

void mostrarPaginaCuentas(stResultadoCuentas resultado, int paginaActual, int paginas) {
    gotoxy(23, 3);
    printf("%-31s", 1 < paginaActual ? PAGINA_ANTERIOR : " ");
    printf("%02d", paginaActual);
    printf("%31s", paginaActual < paginas ? PAGINA_SIGUIENTE : " ");
    int inicio = (24 * (paginaActual - 1));
    int final = paginaActual < paginas ? inicio + 24 : resultado.cantidad;
    int renglon = 5;
    char tipoDeCuenta[3][27] = {"Caja de ahorro en pesos.", "Caja de ahorro en dolares.", "Cuenta corriente en pesos."};
    for (int indice = inicio; indice < final; indice++) {
        gotoxy(2, renglon++);
        printf("Nro. de CLiente: %d | Nro. de Cuenta: %d | Tipo: %-26s | Mantenimiento: $%.2f",
               resultado.resultados[indice].idCliente,
               resultado.resultados[indice].nroCuenta,
               tipoDeCuenta[resultado.resultados[indice].tipoDeCuenta - 1],
               resultado.resultados[indice].costoMensual);
    }
    int lineasUsadas = final - inicio;
    for (int i = 24; lineasUsadas < i; i--) {
        gotoxy(2, renglon++);
        printf("%-116c", ' ');
    }
}

int menuListarCuentas(celda celdas[], int vCeldas) {
    stResultadoCuentas resultado = opListarCuentas(celdas, vCeldas);
    switch (resultado.status) {
        case 200:
            menuResultadoCuentas(resultado);
            free(resultado.resultados);
            break;
        case 404:
            gotoxy(23, 3);
            printf("%-80s", "No se encontraron registros");
            getch();
            break;
        case 500:
            gotoxy(23, 3);
            printf("%-80s", "Error desconocido");
            getch();
            break;
    }
    return 0;
}

int menuBorrarCuenta(celda celda[], int vCelda) {
    int arrayNroCuenta[8];
    int opcion = 0;
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                opcion = menuIngresarIdCliente(arrayNroCuenta, 200, BREADCRUMB_ELIMINAR);
                break;
            case 1:
                opcion = opBorrarCuenta(celda, &vCelda, arrayNroCuenta);
                break;
            case 200:
                gotoxy(25, 3);
                printf("%-80s", "Cuenta correctamente eliminada.");
                opcion = 0;
                getch();
                break;
            case 404:
                opcion = menuIngresarIdCliente(arrayNroCuenta, 404, BREADCRUMB_ELIMINAR);
                break;
//            case 500:
//                opcion = menuIngresarIdCliente(arrayNroCuenta, 500, BREADCRUMB_ELIMINAR);
//                break;
        }
    }
    return 0;
}