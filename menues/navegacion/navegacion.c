#include <conio.h>
#include <stdio.h>
#include "../../utils/gotoxy.h"
#include "navegacion.h"
#include "../../interfaces/interfaces.h"

int navegarMenu(int posiciones[], int validos, int valorDeEscape) {
    gotoxy(posiciones[0], 2);
    int posicionActual = 0;
    char teclaPresionada = 0;
    while (teclaPresionada != ENTER && teclaPresionada != ESCAPE) {
        teclaPresionada = getch();
        switch (teclaPresionada) {
            case 75:
                if (0 < posicionActual) {
                    gotoxy(posiciones[posicionActual], 2);
                    printf("-");
                    posicionActual--;
                    gotoxy(posiciones[posicionActual], 2);
                    printf("@");
                }
                break;
            case 77:
                if (posicionActual < validos - 1) {
                    gotoxy(posiciones[posicionActual], 2);
                    printf("-");
                    posicionActual++;
                    gotoxy(posiciones[posicionActual], 2);
                    printf("@");
                }
                break;
        }
    }
    return teclaPresionada == ESCAPE ? valorDeEscape : posiciones[posicionActual];
}

int navegarLista(int paginaActual, int paginas, int *opcion) {
    int teclaPresionada = 0;
    int paginaDestino = paginaActual;
    while (teclaPresionada != ESCAPE && teclaPresionada != IZQUIERDA && teclaPresionada != DERECHA) {
        teclaPresionada = getch();
        switch (teclaPresionada) {
            case IZQUIERDA:
                if (1 < paginaActual) paginaDestino--;
                break;
            case DERECHA:
                if (paginaActual < paginas) paginaDestino++;
                break;
            case ESCAPE:
                *opcion = teclaPresionada;
                break;
        }
    }
    return paginaDestino;
}

int aceptarCaracter(int cantidadDeLetras, int teclaPresionada, char string[]) {
    string[cantidadDeLetras++] = teclaPresionada;
    string[cantidadDeLetras] = FINAL_STRING;
    printf("%c", teclaPresionada);
    return cantidadDeLetras;
}

int solicitarString(int dimension, char string[dimension], int x, int y) {
    gotoxy(x, y);
    printf("%s", "                                             ");
    gotoxy(x, y);
    hidecursor(1);
    int teclaPresionada = 0;
    int maximoLetras = dimension - 1;
    int cantidadDeLetras = 0;

    while (teclaPresionada != ESCAPE && teclaPresionada != ENTER) {
        teclaPresionada = getch();
        switch (teclaPresionada) {
            case BACKSPACE:
                if (0 < cantidadDeLetras) {
                    string[cantidadDeLetras] = FINAL_STRING;
                    cantidadDeLetras--;
                    gotoxy(whereX() - 1, y);
                    printf("%c", ESPACIO);
                    gotoxy(whereX() - 1, y);
                }
                break;
            case ESPACIO:
                if ((cantidadDeLetras < maximoLetras) && string[cantidadDeLetras - 1] != ESPACIO) {
                    cantidadDeLetras = aceptarCaracter(cantidadDeLetras, teclaPresionada, string);
                }
                break;
            case 46 ... 57:
                if (cantidadDeLetras < maximoLetras) {
                    cantidadDeLetras = aceptarCaracter(cantidadDeLetras, teclaPresionada, string);
                }
                break;
            case 64 ... 90:
                if (cantidadDeLetras < maximoLetras) {
                    cantidadDeLetras = aceptarCaracter(cantidadDeLetras, teclaPresionada, string);
                }
                break;
            case 97 ... 122:
                if (cantidadDeLetras < maximoLetras) {
                    cantidadDeLetras = aceptarCaracter(cantidadDeLetras, teclaPresionada, string);
                }
                break;
            case 224:
                getch();
                break;
        }
    }
    hidecursor(0);
    return (teclaPresionada == ESCAPE) ? ESCAPE : ENTER;
}