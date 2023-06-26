#include <stdio.h>
#include "persistenciaCuentas.h"

int persistirCuentasIniciales(int vCuentas, stCuenta cuentas[vCuentas]) {
    int result;
    FILE * archivo = fopen(ARCHIVO_CUENTAS,"wb");
    if (archivo){
        result = fwrite(cuentas, sizeof(stCuenta),vCuentas,archivo);
        fclose(archivo);
    }
    return result;
}
