#include "../../persistencias/clientes/persistenciaClientes.h"

/**
 * @brief Genera un arreglo de clientes y los persiste.
 * @param idClientes Arreglo a llenar con los numeros de cliente de cada cliente creado.
 * @return La cantidad de clientes correctamente creados.
 */
int opInicializarClientes(int idClientes[100]);

/**
 * @brief Valida que el string "nombre" sea un nombre o apellido valido.
 * @param nombre El string a validar como nombre.
 * @return 0 si es invalido, 1 si es valido.
 */
int opValidarString(const char string[]);

/**
 * @brief Valida que el string ingresado sea un dni o numero de telefono valido.
 * @param digitos cantidad de digitos del string.
 * @param string el string a validar.
 * @return 0 si es invalido, 1 si es valido.
 */
int opValidarNumero(int digitos, const char string[10]);

/**
 * @brief Valida que el string ingresado sea un email valido.
 * @param correo el string a validar como email.
 * @return 0 si es invalido, 1 si es valido.
 */
int opValidarCorreo(const char correo[]);

/**
 * @brief Valida que el string ingresado sea una direccion valida.
 * @param direccion el string a validar como direccion.
 * @return 0 si es invalido, 1 si es valido.
 */
int opValidarDireccion(char direccion[]);

/**
 * @brief Genera un stCliente con los datos ingresados y lo persiste en el archivo de clientes si posee dni email y tele
 * telefono unico
 * @param nombre Nombre del cliente a guardar.
 * @param apellido Apellido del cilente a guardar.
 * @param dni Dni del cliente a guardar. Debe ser unico.
 * @param email Email del cliente a guardar. Debe ser unico.
 * @param domicilio Domicilio del cliente a guardar.
 * @param telefono Telefono del cliente a guarda. Debe ser unico.
 * @return Retorna 200 si el cliente se creo correctamente, 1 2 o 3 si ya existen esos datos o 500 si hubo un error.
 */
int opGuardarNuevoCliente(char nombre[], char apellido[], char dni[], char email[], char domicilio[], char telefono[]);

/**
 * @brief Busca un cliente por su nro de cliente.
 * @param arrayNroCliente Numero de cliente a buscar en el archivo.
 * @return Estructura conteniendo los resultados de la busqueda.
 */
stResultadoClientes opBuscarCliente(int arrayNroCliente[]);

/**
 * @brief Lista los clientes existentes en el archivo.
 * @return Estructura conteniendo los resultados de la busqueda.
 */
stResultadoClientes opListarClientes();

/**
 * @brief Actualiza un cliente identificado por su numero de cliente.
 * @param cliente Estructura del cliente a actualizar.
 * @param nombre Nombre del cliente a actualizar.
 * @param apellido Apellido del cliente a actualizar.
 * @param dni DNI del cliente a actualizar.
 * @param email Email del cliente a actualizar.
 * @param domicilio Domicilio del cliente a actualizar.
 * @param telefono Telefono del cliente a actualizar.
 * @return El resultado de la operacion.
 */
int opActualizarCliente(stCliente cliente,
                        char nombre[],
                        char apellido[],
                        char dni[],
                        char email[],
                        char domicilio[],
                        char telefono[]);
/**
 * @brief Elimina el cliente identificado por su nro de cliente.
 * @param arrayNroCliente
 * @return El resultado de la operacion.
 */
int opBorrarCliente(int arrayNroCliente[]);