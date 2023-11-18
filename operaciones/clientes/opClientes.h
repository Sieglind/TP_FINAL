#include "../../arbolClientes/arbolCliente.h"

int opInicializarClientes(int idClientes[50]);

int opValidarString(const char string[]);

int opValidarNumero(int digitos, const char string[10]);

int opValidarCorreo(const char correo[]);

int opValidarDireccion(char direccion[]);

nodoArbol *opGuardarNuevoCliente(nodoArbol *arbol,
                                 char nombre[],
                                 char apellido[],
                                 char dni[],
                                 char email[],
                                 char domicilio[],
                                 char telefono[]);

nodoArbol *opBuscarCliente(nodoArbol *arbol, int arrayNroCliente[]);

stResultadoClientes opListarClientes(nodoArbol *arbol);

int opActualizarCliente(
        nodoArbol *arbol,
        stCliente cliente,
        char nombre[],
        char apellido[],
        char dni[],
        char email[],
        char domicilio[],
        char telefono[]);

nodoArbol *opBorrarCliente(nodoArbol *arbol, int arrayNroCliente[]);