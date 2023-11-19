#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include "menuMovimientos.h"
#include "../navegacion/navegacion.h"
#include "../../interfaces/interfaces.h"
#include "../../utils/gotoxy.h"
#include "../../operaciones/movimientos/opMovimientos.h"

#define BREADCRUMB              "MOVIMIENTOS : Buscar : Ingrese el nuemero de cuenta : "
#define MENSAJE_NO_ENCONTRADO   "No se encontraron movimientos asociedos a dicho id de cuenta."
#define MENSAJE_ERROR           "Error desconocido."
#define PAGINA_ANTERIOR         "<-- Pagina Anterior"
#define PAGINA_SIGUIENTE        "Pagina Siguiente -->"

int navegarMenuMovimientos();

int menuIngresarIdCuenta(int arrayIdCuenta[], int status);

int obtenerIdCuenta(int arrayIdCuenta[]);

int menuResultadosMovimientos(stResultadoMovimientos resultado);

void mostrarPaginaMovimientos(stResultadoMovimientos resultado, int paginaActual, int paginas);

int menuMovimientos() {
    int opcion = 0;
    int arrayIdCuenta[8];
    nodoLista *movimientos = nuevaLista();
    movimientos = cargarMovimientosEnLista(movimientos);
    stResultadoMovimientos resultado;
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                opcion = navegarMenuMovimientos();
                break;
            case 52:
                opcion = menuIngresarIdCuenta(arrayIdCuenta, 200);
                break;
            case 54:
                resultado = opBuscarMovimientosPorCuenta(movimientos, arrayIdCuenta);
                opcion = resultado.status;
                break;
            case 200:
                opcion = menuResultadosMovimientos(resultado);
                free(resultado.resultados);
                break;
            case 404:
                opcion = menuIngresarIdCuenta(arrayIdCuenta, opcion);
                break;
//            case 500:
//                opcion = menuIngresarIdCuenta(arrayIdCuenta, opcion);
//                break;
        }
    }
    return 0;
}

int navegarMenuMovimientos() {
    cargarMenuMovimientos();
    int posiciones[] = {52};
    return navegarMenu(posiciones, 1, ESCAPE);
}

int menuIngresarIdCuenta(int arrayIdCuenta[], int status) {
    if (status == 200) {
        gotoxy(23, 2);
        printf("%s", BREADCRUMB);
    } else {
        gotoxy(77, 2);
        printf("%8s", " ");
        gotoxy(23, 3);
        printf("%-64s", status == 404 ? MENSAJE_NO_ENCONTRADO : MENSAJE_ERROR);
        gotoxy(77, 2);
    }
    return obtenerIdCuenta(arrayIdCuenta);
}

int obtenerIdCuenta(int arrayIdCuenta[]) {
    int digitos = 0;
    int digito;
    while (digitos < 8) {
        fflush(stdin);
        digito = getch();
        if ((48 <= digito) && (digito <= 57)) {
            printf("%c", digito);
            arrayIdCuenta[digitos] = digito - 48;
            digitos++;
        } else if (digito == ESCAPE) {
            return 0;
        }
    }
    return 54;
}

int menuResultadosMovimientos(stResultadoMovimientos resultado) {
    int paginas = (resultado.cantidad / 8) + (resultado.cantidad % 8 != 0 ? 1 : 0);
    int paginaActual = 0;
    int paginaDestino = 1;
    int opcion = 0;
    while (opcion != ESCAPE) {
        if (paginaDestino != paginaActual) {
            paginaActual = paginaDestino;
            mostrarPaginaMovimientos(resultado, paginaActual, paginas);
        }
        paginaDestino = navegarLista(paginaActual, paginas, &opcion);
    }
    return 0;
}

void mostrarPaginaMovimientos(stResultadoMovimientos resultado, int paginaActual, int paginas) {
    gotoxy(23, 3);
    printf("%-31s", 1 < paginaActual ? PAGINA_ANTERIOR : " ");
    printf("%02d", paginaActual);
    printf("%31s", paginaActual < paginas ? PAGINA_SIGUIENTE : " ");
    int inicio = resultado.cantidad - 1 - (8 * (paginaActual - 1));
    int final = paginaActual < paginas ? inicio - 8 : 0;
    int renglon = 5;
    for (int indice = inicio; indice > final; indice--) {
        gotoxy(2, renglon++);
        printf("Fecha: %02d/%02d/%d                                ",
               resultado.resultados[indice].dia,
               resultado.resultados[indice].mes,
               resultado.resultados[indice].anio);
        gotoxy(2, renglon++);
        printf("Detalle %-100s",
               resultado.resultados[indice].detalle);
        gotoxy(2, renglon++);
        printf("Importe: %d", (int) resultado.resultados[indice].importe);
    }
    int lineasUsadas = (inicio - final) * 3;
    for (int i = 24; lineasUsadas < i; i--) {
        gotoxy(2, renglon++);
        printf("%-116c", ' ');
    }
}