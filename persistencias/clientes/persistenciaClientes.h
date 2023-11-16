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

int persistirClientesIniciales(int vClientes, stCliente clientes[vClientes]);

//int obtenerNuevoIdCliente();
//
//int persistirClienteNuevo(stCliente cliente);
//
//stResultadoClientes buscarClientePorNroCliente(int nroCliente);
//
//stResultadoClientes listarClientes();
//
//int persistirActualizacion(stCliente cliente);
//
//int persistirClienteEliminado(int nroCliente);