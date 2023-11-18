#include "persistenciaClientes.h"

#include <stdio.h>

int persistirClientesIniciales(int vClientes, stCliente clientes[vClientes]) {
    int result = 0;
    FILE *archivo = fopen(ARCHIVO_CLIENTES, "wb");
    if (archivo) {
        result = fwrite(clientes, sizeof(stCliente), vClientes, archivo);
        fclose(archivo);
    }
    return result;
}