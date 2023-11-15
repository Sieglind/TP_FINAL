#include <stdlib.h>
#include <time.h>
#include "menues/menu.h"

int main() {
    srand(time(NULL));

    menuPrincipal();

    system("pause");

    return 0;
}