#include "utils.h"

#include <sys/stat.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int calcularCantidadDeEstructuras(char nombreArchivo[], int tamanioEstructura) {
    struct stat status;
    if (stat(nombreArchivo, &status) == 0) {
        return status.st_size / tamanioEstructura;
    } else {
        return -1;
    }
}

int obtenerId(int arrayId[]) {
    int digitos = 0;
    int digito;
    while (digitos < 8) {
        fflush(stdin);
        digito = getch();
        if ((48 <= digito) && (digito <= 57)) {
            printf("%c", digito);
            arrayId[digitos] = digito - 48;
            digitos++;
        } else if (digito == 27) {
            return 27;
        }
    }
    return 1;
}

int convertirArrayEnId(int arrayId[]) {
    double id = 0;
    for (int i = 0; i <= 7; i++) {
        id = id + (double) arrayId[i] * pow(10, 7 - i);
    }
    return (int) id;
}
