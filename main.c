#include <stdlib.h>
#include <time.h>
#include "menues/menu.h"
#include "arbolClientes/arbolCliente.h"

int main() {
    srand(time(NULL));

    nodoArbol * arbol = nuevoArbol();

    menuPrincipal();

    system("pause");

    return 0;
}