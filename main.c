#include <stdlib.h>
#include <time.h>
#include "menues/menu.h"
#include "arbolClientes/arbolCliente.h"

int main() {
    srand(time(NULL));

    nodoArbol *arbol = nuevoArbol();

    arbol = cargarClientesEnArbol(arbol);

    menuPrincipal();

    system("pause");

    return 0;
}