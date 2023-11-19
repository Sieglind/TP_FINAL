#include <stdio.h>
#include "persistenciaMovimientos.h"

int persistirMovimientosIniciales(int vMovimientos, stMovimiento movimientos[vMovimientos]) {
    int result = 0;
    FILE *archivo = fopen(ARCHIVO_MOVIMIENTOS, "wb");
    if (archivo) {
        result = fwrite(movimientos, sizeof(stMovimiento), vMovimientos, archivo);
        fclose(archivo);
    }
    return result;
}