#include "../../persistencias/movimientos/persistenciaMovimientos.h"

/**
 * @brief Genera para cada cuenta, identificada por su id de cuenta, entre 0 y 4 movimientos aleatorios y los persiste
 * @param cantidadCuentas Cantidad de cuentas en las que generar los movimientos
 * @param cuentas Arreglo que contiene los id de cuenta a los que generar movimientos
 * @return La cantidad de cuentas a las que se les genero movimientos exitosamente
 */
int opInicializarMovimientos(int cantidadCuentas, int cuentas[cantidadCuentas]);

stResultadoMovimientos opBuscarMovimientosPorCuenta(int arrayIdCuenta[8]);