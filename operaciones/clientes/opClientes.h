#include "../../persistencias/clientes/persistenciaClientes.h"

int opInicializarClientes(int idClientes[100]);

int opValidarString(const char nombre[]);

int opValidarDni(int digitos, const char dni[10]);

int opValidarCorreo(const char correo[]);

int opValidarDireccion(char direccion[]);

int opGuardarNuevoCliente(char nombre[], char apellido[], char dni[], char email[], char domicilio[], char telefono[]);

stResultadoClientes opBuscarCliente(int arrayNroCliente[]);

stResultadoClientes opListarClientes();

int opActualizarCliente(stCliente cliente,char nombre[], char apellido[], char dni[], char email[], char domicilio[], char telefono[]);

int opBorrarCliente(int arrayNroCliente[]);