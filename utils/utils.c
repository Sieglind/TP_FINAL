#include "utils.h"

#include <sys/stat.h>

int calcularCantidadDeEstructuras(char nombreArchivo[], int tamanioEstructura) {
    struct stat status;
    if (stat(nombreArchivo, &status) == 0) {
        return status.st_size / tamanioEstructura;
    } else {
        return -1;
    }
}