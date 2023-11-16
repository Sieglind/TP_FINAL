#include "menu.h"
#include "../interfaces/interfaces.h"
#include "navegacion/navegacion.h"
#include "clientes/menuClientes.h"
#include "cuentas/menuCuentas.h"
#include "movimientos/menuMovimientos.h"
#include "otros/menuOtros.h"


int navegarMenuPrincipal() {
    cargarMenuPrincipal();
    int posiciones[] = {18,38,79,99};
    return navegarMenu(posiciones, 4, ESCAPE);
}

void menuPrincipal(){
    int opcion = 0;
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                opcion = navegarMenuPrincipal();
                break;
            case 18:
                opcion = menuClientes();
                break;
//            case 38:
//                opcion = menuCuentas();
//                break;
//            case 79:
//                opcion = menuMovimientos();
//                break;
            case 99:
                opcion = menuOtros();
        }
    }
}