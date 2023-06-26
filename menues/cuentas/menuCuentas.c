#include "menuCuentas.h"
#include "../../interfaces/interfaces.h"
#include "../navegacion/navegacion.h"


int navegarMenuCuentas(){
    int posiciones[] = {28, 43, 58, 73, 88};
    return navegarMenu(posiciones,5,ESCAPE);
}

int menuCrearCuenta(){
    char arrayIdCliente[8];
    int tipoDeCuenta;

}

int menuCuentas() {
    int opcion = 0;
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                cargarMenuCuentas();
                opcion = navegarMenuCuentas();
                break;
            case 28:
            opcion = menuCrearCuenta();
                break;
            case 43:
//            opcion = buscarCuenta();
                break;
            case 58:
//            opcion = listarCuentas();
                break;
            case 73:
//            opcion = actualizarCuenta();
                break;
            case 88:
//            opcion = borrarCuenta();
                break;
        }
    }
    return 0;
}