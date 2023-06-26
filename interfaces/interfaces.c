#include <stdio.h>
#include <process.h>
#include "interfaces.h"
#include "../utils/gotoxy.h"



#define MENU_PRINCIPAL      "../interfaces/menu-principal.txt"
#define MENU_CLIENTES       "../interfaces/clientes/menu-clientes.txt"
#define MENU_CUENTAS        "../interfaces/cuentas/menu-cuentas.txt"
#define MENU_MOVIMIENTOS    "../interfaces/movimientos/menu-movimientos.txt"
#define MENU_OTROS          "../interfaces/otros/menu-otros.txt"

void cargarMatrizUI(char matrizInterfaz[30][121], char interfaz[]) {
    FILE *menues = fopen(interfaz, "r");
    if (menues) {
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 121; j++) {
                matrizInterfaz[i][j] = fgetc(menues);
            }
        }
        fclose(menues);
    }
}

void cargarMenu(char menu[],int estilo) {
    hidecursor(0);
    system("cls");
    color(estilo);
    char interfaz[30][121];
    cargarMatrizUI(interfaz, menu);
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 121; j++) {
            if (interfaz[i][j] != EOF) printf("%c", interfaz[i][j]);
        }
    }
}

void cargarMenuPrincipal(){
    cargarMenu(MENU_PRINCIPAL,32);
}

void cargarMenuClientes(){
    cargarMenu(MENU_CLIENTES,96);
}

void cargarMenuCuentas(){
    cargarMenu(MENU_CUENTAS,128);
}

void cargarMenuMovimientos(){
    cargarMenu(MENU_MOVIMIENTOS,96);
}

void cargarMenuOtros(){
    cargarMenu(MENU_OTROS,128);
}