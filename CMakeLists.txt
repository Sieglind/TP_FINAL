cmake_minimum_required(VERSION 3.25)
project(TP_FINAL C)

set(CMAKE_C_STANDARD 11)

add_executable(TP_FINAL main.c
        interfaces/interfaces.c
        interfaces/interfaces.h
        utils/gotoxy.c
        utils/gotoxy.h
        menues/navegacion/navegacion.c
        menues/navegacion/navegacion.h
        operaciones/movimientos/opMovimientos.c
        operaciones/movimientos/opMovimientos.h
        menues/menu.c
        menues/menu.h
        menues/clientes/menuClientes.c
        menues/clientes/menuClientes.h
        menues/cuentas/menuCuentas.c
        menues/cuentas/menuCuentas.h
        menues/movimientos/menuMovimientos.c
        menues/movimientos/menuMovimientos.h
        menues/otros/menuOtros.c menues/otros/menuOtros.c
        menues/otros/menuOtros.c menues/otros/menuOtros.h
        operaciones/otros/otros.c
        operaciones/otros/otros.h
        persistencias/movimientos/persistenciaMovimientos.c
        persistencias/movimientos/persistenciaMovimientos.h
        operaciones/clientes/opClientes.c
        operaciones/clientes/opClientes.h
        persistencias/clientes/persistenciaClientes.c
        persistencias/clientes/persistenciaClientes.h
        persistencias/cuentas/persistenciaCuentas.c
        persistencias/cuentas/persistenciaCuentas.h
        operaciones/cuentas/opCuentas.c
        operaciones/cuentas/opCuentas.h
        listaMovimientos/listaMovimientos.c
        listaMovimientos/listaMovimientos.h
        arbolClientes/arbolCliente.c
        arbolClientes/arbolCliente.h
        celdaCuenta/celdaCuenta.c
        celdaCuenta/celdaCuenta.h
        utils/utils.c
        utils/utils.h
)
