#include "menuClientes.h"

#include <stdio.h>
#include <conio.h>

#include "../../interfaces/interfaces.h"
#include "../navegacion/navegacion.h"
#include "../../utils/gotoxy.h"

#include "../../operaciones/clientes/opClientes.h"

#define BREADCRUMB_BUSCAR       "CLIENTES : Buscar     :Ingrese un numero de cliente para buscar     : "
#define BREADCRUMB_ACTUALIZAR   "CLIENTES : Actualizar :Ingrese un numero de cliente para actualizar : "
#define BREADCRUMB_ELIMINAR     "CLIENTES : Eliminar   :Ingrese un numero de cliente para borrar     : "
#define MENSAJE_NO_ENCONTRADO   "No se encontro un cliente ascoiado a dicho numero de cliente."
#define MENSAJE_ERROR           "Error desconocido."
#define PAGINA_ANTERIOR         "<-- Pagina Anterior"
#define PAGINA_SIGUIENTE        "Pagina Siguiente -->"

int navegarMenuClientes();

nodoArbol *menuCrearCliente(nodoArbol *arbol);

int menuIngresarCliente(char nombre[],
                        char apellido[],
                        char dni[],
                        char email[],
                        char domicilio[],
                        char telefono[],
                        int x,
                        int y,
                        int pasoSiguiente);

int menuBuscarCliente(nodoArbol *arbol);

int menuIngresarNroCliente(int arrayNroCliente[], int status, char breadcrumb[]);

int obtenerNroCliente(int arrayNroCliente[]);

int mostrarCuentas(nodoArbol *arbol);

void mostrarMovimientos(nodoLista * lista);

int mostrarResultadoCliente(nodoArbol * nodo, int x,int esActualizacion);

int menuListarClientes(nodoArbol *arbol);

int menuResultadosClientes(stResultadoClientes resultado);

void mostrarPaginaClientes(stResultadoClientes resultado, int paginaActual, int paginas);

int menuActualizarCliente(nodoArbol *arbol);

int menuBorrarCliente(nodoArbol *arbol);

int menuClientes() {
    nodoArbol *arbol = nuevoArbol();
    arbol = cargarClientesEnArbol(arbol);
    cargarCuentasEnArbol(arbol);
    arbol = cargarMovimientosArbol(arbol);

    int opcion = 0;
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                cargarMenuClientes();
                opcion = navegarMenuClientes();
                break;
            case 28:
                opcion = 0;
                arbol = menuCrearCliente(arbol);
                break;
            case 43:
                opcion = menuBuscarCliente(arbol);
                break;
            case 58:
                opcion = menuListarClientes(arbol);
                break;
            case 73:
                opcion = menuActualizarCliente(arbol);
                break;
            case 88:
                opcion = menuBorrarCliente(arbol);
                break;
        }
    }
    return 0;
}

int navegarMenuClientes() {
    cargarMenuClientes();
    int posiciones[] = {28, 43, 58, 73, 88};
    return navegarMenu(posiciones, 5, ESCAPE);
}

nodoArbol *menuCrearCliente(nodoArbol *arbol) {
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char telefono[12];
    int paso = 1;
    int x = 33;
    int y = 12;
    while (paso != ESCAPE) {
        switch (paso) {
            case 1:
                paso = menuIngresarCliente(nombre, apellido, dni, email, domicilio, telefono, x, y, 2);
                break;
            case 2:
                arbol = opGuardarNuevoCliente(arbol, nombre, apellido, dni, email, domicilio, telefono);
                gotoxy(x, whereY() + 1);
                paso = 200;
                break;
            case 200:
                printf("CLIENTE CREADO...");
                paso = ESCAPE;
                getch();
                break;
        }
    }
    return arbol;
}

int menuIngresarCliente(char nombre[],
                        char apellido[],
                        char dni[],
                        char email[],
                        char domicilio[],
                        char telefono[],
                        int x,
                        int y,
                        int pasoSiguiente) {
    int paso = 1;
    while (paso != ESCAPE && paso != 13) {
        switch (paso) {
            case 1:
                gotoxy(x, y);
                printf("NOMBRE: ");
                if (solicitarString(30, nombre, x + 8, y++) == ESCAPE) {
                    paso = ESCAPE;
                } else {
                    paso = 2;
                }
                break;
            case 2:
                paso = opValidarString(nombre) ? 3 : 1;
                break;
            case 3:
                gotoxy(x, y);
                printf("APELLIDO: ");
                if (solicitarString(30, apellido, x + 10, y++) == ESCAPE) {
                    paso = ESCAPE;
                } else {
                    paso = 4;
                }
                break;
            case 4:
                paso = opValidarString(apellido) ? 5 : 3;
                break;
            case 5:
                gotoxy(x, y);
                printf("DNI: ");
                if (solicitarString(10, dni, x + 5, y++) == ESCAPE) {
                    paso = ESCAPE;
                } else {
                    paso = 6;
                }
                break;
            case 6:
                paso = opValidarNumero(10, dni) ? 7 : 5;
                break;
            case 7:
                gotoxy(x, y);
                printf("EMAIL: ");
                if (solicitarString(30, email, x + 7, y++) == ESCAPE) {
                    paso = ESCAPE;
                } else {
                    paso = 8;
                }
                break;
            case 8:
                paso = opValidarCorreo(email) ? 9 : 7;
                break;
            case 9:
                gotoxy(x, y);
                printf("DOMICILIO: ");
                if (solicitarString(45, domicilio, x + 11, y++) == ESCAPE) {
                    paso = ESCAPE;
                } else {
                    paso = 10;
                }
                break;
            case 10:
                paso = opValidarDireccion(domicilio) ? 11 : 9;
                break;
            case 11:
                gotoxy(x, y);
                printf("TELEFONO: ");
                if (solicitarString(12, telefono, x + 10, y++) == ESCAPE) {
                    paso = ESCAPE;
                } else {
                    paso = 12;
                }
                break;
            case 12:
                paso = opValidarNumero(12, telefono) ? 13 : 11;
                break;
        }
    }
    return paso == ESCAPE ? ESCAPE : pasoSiguiente;
}

int menuBuscarCliente(nodoArbol *arbol) {
    int arrayNroCliente[8];
    nodoArbol *resultado;
    int opcion = 0;
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                opcion = menuIngresarNroCliente(arrayNroCliente, 200, BREADCRUMB_BUSCAR);
                break;
            case 1:
                resultado = opBuscarCliente(arbol, arrayNroCliente);
                if (arbol) {
                    opcion = 200;
                } else {
                    opcion = 404;
                }
                break;
            case 200:
                opcion = mostrarResultadoCliente(resultado, 33,0);
                break;
            case 404:
                opcion = menuIngresarNroCliente(arrayNroCliente, 404, BREADCRUMB_BUSCAR);
                break;
        }
    }
    return 0;
}

int menuIngresarNroCliente(int arrayNroCliente[], int status, char breadcrumb[]) {
    if (status == 200) {
        gotoxy(14, 2);
        printf("%-81s", breadcrumb);
        gotoxy(whereX() - 11, whereY());
    } else {
        gotoxy(whereX() - 8, 2);
        printf("%8s", " ");
        gotoxy(14, 3);
        printf("%-64s", status == 404 ? MENSAJE_NO_ENCONTRADO : MENSAJE_ERROR);
        gotoxy(84, 2);
    }
    return obtenerNroCliente(arrayNroCliente);
}

int obtenerNroCliente(int arrayNroCliente[]) {
    int digitos = 0;
    int digito;
    while (digitos < 8) {
        fflush(stdin);
        digito = getch();
        if ((48 <= digito) && (digito <= 57)) {
            printf("%c", digito);
            arrayNroCliente[digitos] = digito - 48;
            digitos++;
        } else if (digito == ESCAPE) {
            return ESCAPE;
        }
    }
    return 1;
}

int mostrarCuentas(nodoArbol *arbol) {
    cargarMenuClientes();
    int renglon = 5;
    char tipoDeCuenta[3][27] = {"Caja de ahorro en pesos.", "Caja de ahorro en dolares.", "Cuenta corriente en pesos."};
    for (int i = 0; i < arbol->vCuentas; i++) {
        gotoxy(2, renglon++);
        printf("Nro. de CLiente: %d | Nro. de Cuenta: %d | Tipo: %-26s | Mantenimiento: $%.2f",
               arbol->cuentas[i].dato.idCliente,
               arbol->cuentas[i].dato.nroCuenta,
               tipoDeCuenta[arbol->cuentas[i].dato.tipoDeCuenta-1],
               arbol->cuentas[i].dato.costoMensual);
    }
    gotoxy(2,20);
    printf("Ingrese un numero entre 1 y %d para ver los movimientos de la cuenta",arbol->vCuentas);
    fflush(stdin);
    int opcion = getch()-48;
    if(0 < opcion && opcion <= arbol->vCuentas){
        mostrarMovimientos(arbol->cuentas[opcion-1].listaMovimiento);
    }
    return 0;
}

void mostrarMovimientos(nodoLista * lista){
    cargarMenuClientes();
    int renglon = 5;
    gotoxy(2,renglon);
    while (lista && renglon <20 ){
        gotoxy(2, renglon++);
        printf("Fecha: %02d/%02d/%d                                ",
               lista->movimiento.dia,
               lista->movimiento.mes,
               lista->movimiento.anio);
        gotoxy(2, renglon++);
        printf("Detalle %-100s",
               lista->movimiento.detalle);
        gotoxy(2, renglon++);
        printf("Importe: %d", (int) lista->movimiento.importe);
        lista = lista->siguiente;
    }
    if(lista && lista->siguiente){
        gotoxy(2,22);
        printf("Mostrar mas: m");
        int opcion = getch();
        if (opcion == 109){
            mostrarMovimientos(lista);
        }
    }
}

int mostrarResultadoCliente(nodoArbol * nodo, int x,int esActualizacion) {
    gotoxy(x, 12);
    printf("NRO. DE CLIENTE: %-10d", nodo->cliente.nroCliente);
    gotoxy(x, whereY() + 1);
    printf("NOMBRE: %-29s", nodo->cliente.nombre);
    gotoxy(x, whereY() + 1);
    printf("APELLIDO: %-29s", nodo->cliente.apellido);
    gotoxy(x, whereY() + 1);
    printf("DNI: %-29s", nodo->cliente.dni);
    gotoxy(x, whereY() + 1);
    printf("EMAIL: %-30s", nodo->cliente.email);
    gotoxy(x, whereY() + 1);
    printf("DOMICILIO: %-45s", nodo->cliente.domicilio);
    gotoxy(x, whereY() + 1);
    printf("TELEFONO: %-12s", nodo->cliente.telefono);
    if(!esActualizacion){
        gotoxy(x, whereY() + 2);
        printf("Mostrar Cuentas: C");
        fflush(stdin);
        int opcion = getch();
        if (opcion == 99) mostrarCuentas(nodo);
    }
    return 0;
}

int menuListarClientes(nodoArbol *arbol) {
    stResultadoClientes resultado = opListarClientes(arbol);
    switch (resultado.status) {
        case 200:
            menuResultadosClientes(resultado);
            free(resultado.resultados);
            break;
        case 404:
            gotoxy(23, 3);
            printf("%-80s", "No se encontraron registros");
            getch();
            break;
        case 500:
            gotoxy(23, 3);
            printf("%-80s", "Error desconocido");
            getch();
            break;
    }
    return 0;
}

int menuResultadosClientes(stResultadoClientes resultado) {
    int paginas = (resultado.cantidad / 24) + (resultado.cantidad % 24 != 0 ? 1 : 0);
    int paginaActual = 0;
    int paginaDestino = 1;
    int opcion = 0;
    while (opcion != ESCAPE) {
        if (paginaDestino != paginaActual) {
            paginaActual = paginaDestino;
            mostrarPaginaClientes(resultado, paginaActual, paginas);
        }
        paginaDestino = navegarLista(paginaActual, paginas, &opcion);
    }
    return 0;
}

void mostrarPaginaClientes(stResultadoClientes resultado, int paginaActual, int paginas) {
    gotoxy(23, 3);
    printf("%-31s", 1 < paginaActual ? PAGINA_ANTERIOR : " ");
    printf("%02d", paginaActual);
    printf("%31s", paginaActual < paginas ? PAGINA_SIGUIENTE : " ");
    int inicio = (24 * (paginaActual - 1));
    int final = paginaActual < paginas ? inicio + 24 : resultado.cantidad;
    int renglon = 5;
    for (int indice = inicio; indice < final; indice++) {
        gotoxy(2, renglon++);
        printf("Nro. de CLiente: %d | Nombre y Apellido: %-25s %-25s | DNI: %s",
               resultado.resultados[indice].nroCliente,
               resultado.resultados[indice].nombre,
               resultado.resultados[indice].apellido,
               resultado.resultados[indice].dni);
    }
    int lineasUsadas = final - inicio;
    for (int i = 24; lineasUsadas < i; i--) {
        gotoxy(2, renglon++);
        printf("%-116c", ' ');
    }
}

int menuActualizarCliente(nodoArbol *arbol) {
    int arrayNroCliente[8];
    nodoArbol *resultado;
    stCliente cliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char telefono[12];
    int opcion = 0;
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                opcion = menuIngresarNroCliente(arrayNroCliente, 200, BREADCRUMB_ACTUALIZAR);
                break;
            case 1:
                resultado = opBuscarCliente(arbol, arrayNroCliente);
                if (resultado) {
                    cliente = resultado->cliente;
                    opcion = 200;
                } else {
                    opcion = 404;
                }
                break;
            case 200:
                mostrarResultadoCliente(resultado, 2,1);
                opcion = menuIngresarCliente(nombre, apellido, dni, email, domicilio, telefono, 60, 13, 3);
                break;
            case 404:
                opcion = menuIngresarNroCliente(arrayNroCliente, 404, BREADCRUMB_ACTUALIZAR);
                break;
            case 3:
                opcion = opActualizarCliente(resultado, cliente, nombre, apellido, dni, email, domicilio, telefono);
                break;
            case 4:
                gotoxy(25, 3);
                printf("%-80s", "Cliente correctamente actualizado.");
                opcion = 0;
                getch();
                break;
        }
    }
    return 0;
}

int menuBorrarCliente(nodoArbol *arbol) {
    int arrayNroCliente[8];
    int opcion = 0;
    while (opcion != ESCAPE) {
        switch (opcion) {
            case 0:
                opcion = menuIngresarNroCliente(arrayNroCliente, 200, BREADCRUMB_ELIMINAR);
                break;
            case 1:
                arbol = opBorrarCliente(arbol, arrayNroCliente);
                opcion = 200;
                break;
            case 200:
                gotoxy(25, 3);
                printf("%-80s", "Cliente correctamente eliminado.");
                opcion = 0;
                getch();
                break;
        }
    }
    return 0;
}