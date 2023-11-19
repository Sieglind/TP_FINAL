#define ARCHIVO_CLIENTES "clientes.dat"
#define ID_INICIAL_CLIENTES 30000000

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