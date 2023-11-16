#include "menuOtros.h"
#include "../../interfaces/interfaces.h"
#include "../navegacion/navegacion.h"
#include "../../operaciones/otros/otros.h"

int navegarMenuOtros(){
    cargarMenuOtros();
    int posiciones[] = {59};
    return navegarMenu(posiciones,1,ESCAPE);
}

int menuOtros() {
    int opcion = 0;
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                opcion = navegarMenuOtros();
                break;
            case 59:
                opcion = opInicializarDatos();
                break;
        }
    }
    return 0;
}