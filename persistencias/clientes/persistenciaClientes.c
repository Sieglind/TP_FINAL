#include <stdio.h>
#include <sys/stat.h>
#include <malloc.h>
#include "persistenciaClientes.h"


int persistirClientesIniciales(int vClientes, stCliente clientes[vClientes]) {
    int result = 0;
    FILE *archivo = fopen(ARCHIVO_CLIENTES, "wb");
    if (archivo) {
        result = fwrite(clientes, sizeof(stCliente), vClientes, archivo);
        fclose(archivo);
    }
    return result;
}

//int obtenerNuevoIdCliente() {
//    struct stat status;
//    if (stat(ARCHIVO_CLIENTES, &status) == 0) {
//        return status.st_size / sizeof(stCliente);
//    } else {
//        return -1;
//    }
//}
//
//stResultadoClientes implementarBusquedaChar(FILE *archivo, stCliente consulta) {
//    stCliente cliente;
//    stResultadoClientes resultado = {.status = -1};
//    while (fread(&cliente, sizeof(stCliente), 1, archivo) == 1 && resultado.status == -1) {
//        if (strcmp(consulta.dni, cliente.dni) == 0) {
//            resultado.status = 0;
//        } else if (strcmp(consulta.email, cliente.email) == 0) {
//            resultado.status = 1;
//        } else if (strcmp(consulta.telefono, cliente.telefono) == 0) {
//            resultado.status = 2;
//        }
//    }
//    return resultado;
//}
//
//int persistirClienteNuevo(stCliente cliente) {
//    FILE *archivo = fopen(ARCHIVO_CLIENTES, "r+b");
//    if (archivo) {
//        fseek(archivo, 0, SEEK_SET);
//        stResultadoClientes resultado = implementarBusquedaChar(archivo, cliente);
//        fseek(archivo, 0, SEEK_END);
//        if (resultado.status != -1) {
//            fclose(archivo);
//            return resultado.status;
//        }
//        fwrite(&cliente, sizeof(stCliente), 1, archivo);
//        fclose(archivo);
//        return 200;
//    } else return 500;
//}
//
//stCliente implementarBusquedaInt(FILE *archivo, int nroCliente) {
//    stCliente cliente;
//    int encontrado = 0;
//    while (encontrado == 0 && fread(&cliente, sizeof(stCliente), 1, archivo) == 1) {
//        if (cliente.nroCliente == nroCliente && cliente.eliminado == 0) encontrado = 1;
//    }
//    if (encontrado == 0) cliente.id = -1;
//    return cliente;
//}
//
//stResultadoClientes buscarClientePorNroCliente(int nroCliente) {
//    stResultadoClientes resultado;
//    FILE *archivo = fopen(ARCHIVO_CLIENTES, "rb");
//    if (archivo) {
//        stCliente cliente = implementarBusquedaInt(archivo, nroCliente);
//        if (cliente.id != -1) {
//            resultado.status = STATUS_OK;
//            resultado.cantidad = 1;
//            resultado.resultados = &cliente;
//            fclose(archivo);
//            return resultado;
//        } else {
//            fclose(archivo);
//            resultado.status = STATUS_NO_ENCONTRADO;
//            return resultado;
//        }
//    } else {
//        resultado.status = STATUS_ERROR;
//        return resultado;
//    }
//}

//stResultadoClientes listarClientes() {
//    stResultadoClientes resultado;
//    int cantidad = obtenerNuevoIdCliente();
//    if (cantidad != 0) {
//        FILE *archivo = fopen(ARCHIVO_CLIENTES, "rb");
//        if (archivo) {
//            stCliente *clientes = (stCliente *) malloc(sizeof(stCliente) * cantidad);
//            stCliente cliente;
//            int noEliminados = 0;
//            for (int i = 0; i < cantidad; i++) {
//                fread(&cliente, sizeof(stCliente), 1, archivo);
//                if (cliente.eliminado == 0) clientes[noEliminados++] = cliente;
//            }
//            fclose(archivo);
//            resultado.status = STATUS_OK;
//            resultado.cantidad = noEliminados;
//            resultado.resultados = clientes;
//            return resultado;
//        } else {
//            resultado.status = STATUS_ERROR;
//            return resultado;
//        }
//    } else {
//        resultado.status = STATUS_NO_ENCONTRADO;
//        return resultado;
//    }
//}
//
//int persistirActualizacion(stCliente cliente) {
//    FILE *archivo = fopen(ARCHIVO_CLIENTES, "r+b");
//    if (archivo) {
//        fseek(archivo, cliente.id * sizeof(stCliente), SEEK_SET);
//        fwrite(&cliente, sizeof(stCliente), 1, archivo);
//        fclose(archivo);
//        return 200;
//    } else {
//        return 500;
//    }
//}
//
//int persistirClienteEliminado(int nroCliente) {
//    FILE *archivo = fopen(ARCHIVO_CLIENTES, "r+b");
//    if (archivo) {
//        stCliente cliente = implementarBusquedaInt(archivo, nroCliente);
//        if (cliente.id != -1) {
//            cliente.eliminado = 1;
//            fseek(archivo, cliente.id * sizeof(stCliente), SEEK_SET);
//            if (fwrite(&cliente, sizeof(stCliente), 1, archivo) == 1){
//                fclose(archivo);
//                return 200;
//            }
//        } else {
//            fclose(archivo);
//            return 404;
//        }
//    } else {
//        return 500;
//    }
//}