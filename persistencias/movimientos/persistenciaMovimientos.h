#define ARCHIVO_MOVIMIENTOS "movimientos.dat"
#define ID_INICIAL_MOVIMIENTOS 90000000
#define STATUS_OK 200
#define STATUS_NO_ENCONTRADO 404
#define STATUS_ERROR 500

typedef struct {
    int id;
    int idCuenta;
    int anio;
    int mes;
    int dia;
    char detalle[100];
    float importe;
    int eliminado;
} stMovimiento;

typedef struct{
    int status;
    int cantidad;
    stMovimiento * resultados;
} stResultadoMovimientos;


/**
 * @brief Persiste los movimientos presentes en el arreglo "movimientos"
 * @param vMovimientos Cantidad de movimientos presentes en el arreglo "movimientos"
 * @param movimientos Arreglo conteniendo los movimientos a persisitir
 */
int persistirMovimientosIniciales(int vMovimientos,stMovimiento movimientos[vMovimientos]);

/**
 * @brief Busca los movimientos existentes, si los hay, que esten asociados a la cuenta identificada por el parametro
 * "idCuenta"
 * @param idCuenta El id de la cuenta de la que se quiere obtener los movimientos
 * @return stResultado Una estructura stResultado que representa el resultado de haber realizado la busqueda requerida
 */
stResultadoMovimientos buscarMovimientosPorCuenta(int idCuenta);

/**
 * @brief Cambia el valor del atributo "eliminado" a todos los movimientos que esten asociados a la cuenta identificada
 * por el parametro "idCuenta"
 * @param idCuenta El id de la cuenta de la que se quiere eliminar los movimientos
 */
void eliminarMovimientosPorCuenta(int idCuenta);