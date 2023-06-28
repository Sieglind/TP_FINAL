#define ARCHIVO_CLIENTES "clientes.dat"
#define ID_INICIAL_CLIENTES 30000000
#define STATUS_OK 200
#define STATUS_NO_ENCONTRADO 404
#define STATUS_ERROR 500

typedef struct {
    int id;
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char telefono[12];
    int eliminado;
} stCliente;

typedef struct {
    int status;
    int cantidad;
    stCliente *resultados;
} stResultadoClientes;

/**
 * @brief Persiste el arreglo de clientes iniciales.
 * @param vClientes Cantidad de clientes a persistir.
 * @param clientes Arreglo de clientes a persistir.
 * @return Retorna la cantidad de clientes correctamente persistidos.
 */
int persistirClientesIniciales(int vClientes, stCliente clientes[vClientes]);

/**
 * @brief Calcula la cantidad de clientes existentes en el archivo.
 * @return Entero equivalente a la cantidad de clientes existentes y que se corresponde con el id de un nuevo cliente.
 */
int obtenerNuevoIdCliente();

/**
 * @brief Persiste un cliente en el archivo de clientes.
 * @param cliente La estructura del cliente a persistir
 * @return EL resultado de la operacion.
 */
int persistirClienteNuevo(stCliente cliente);

/**
 * @brief Busca un cliente identificado por su numero de cliente.
 * @param nroCliente El numero de cliente que identifica al cliente.
 * @return Estructura conteniendo los resultados de la busqueda.
 */
stResultadoClientes buscarClientePorNroCliente(int nroCliente);

/**
 * @brief Devuelvo todos los clientes no eliminados existentes en el archivo.
 * @return Estructura conteniendi los resultados de la busqueda.
 */
stResultadoClientes listarClientes();

/**
 * @brief Persiste el cliente, sobreescribiendo los datos existentes.
 * @param cliente Estructura conteniento el cliente a sobreescribir.
 * @return Resultado de la operacion.
 */
int persistirActualizacion(stCliente cliente);

/**
 * @brief Cambia el estado del atributo eliminado del cliente identificado por el numero de cliente, de 0 a 1.
 * @param nroCliente Numero de cliente del cliente a eliminar.
 * @return Resultado de la operacion.
 */
int persistirClienteEliminado(int nroCliente);