#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include "opClientes.h"
#include "../../utils/gotoxy.h"

#define NOMBRES {"CHRISTIAN","NATALIA","LUCIANO","CRISTIAN","ANA","CORDELIA","ELENA","PEDRO","PABLO","TAMARA",         \
                "JUAN CRUZ","MARIA ELENA","DOMINGO","CORDELIA","SERGIO","ROMINA","JUAN IGNACIO","ANA MARIA","CARLOS",  \
                "FLORENCIA","JUAN CARLOS","NELIDA","ANTONIO","RAMIRO","BLANCA","BEATRIZ","JONATHAN","JENIFER","DANIEL",\
                "SANDRA","NESTOR","SUSANA","DIEGO","JESICA","AMIR","VALENTIN","VALENTINA","EMILIANO","MARIA MARTA",    \
                "JOSE MARIA","MARIA JOSE","VICENTE","ESTHER","GREGORIO","YUE","AMALIA","EVA","ADAN","LILIANA","ELIOT", \
                "YAMILA","BLAS","MAXIMA","MAXIMILIANO","ANDREA","KEVIN","ABRIL","JUAN CRUZ","MARGARITA","CAROLINA",    \
                "CAMILO","KAREN","NICOLAS","NICOLE","CRISTINA","MARCELO","MELISSA","GONZALO","AYELEN","EZEQUIEL",      \
                "CAMILA","NAHUEL","AYELEN","MATEO","AGUSTIN","PATRICIA","CASANDRA","RAMON","ZULMA","JOAN","EMILIA",    \
                "LEONEL","CINTIA","JUAN MANUEL","MANUEL","SOLEDAD","NATIVIDAD","OSCAR","FEDERICO","OCTAVIO",           \
                "GUADALUPE","ROCIO","CATALINA","GUSTAVO","ANDRES","ROBERTO","TATIANA","CESAR","ELIZA","MARIA EUGENIA", \
                "MAURICIO","LISANDRO","LUDMILA","KARINA","VIVIANA","DIANA","DAIANA","ROBIN","TOMAS","CHRISTOPHER",     \
                "LAUREANO","GABRIEL","LUCAS","TADEO","BENJAMIN","ADRIAN","LISANDRO","JOSHUA","MARCOS","HERNESTO",      \
                "XIMENA","XIOMARA","CINTIA","SILVIA","NESTOR","IAN","RODRIGO","MARIANA","JOEL","JOELINNE","JOSEFINA",  \
                "WALTER","VICTOR","VICTORIA","MARIO","LILIBETH","JAVIER","MARIEL","MABEL","KATRINA"}

#define APELLIDOS   {"ARIAS","CAMPISI","PELUSO","DI ANGELO","RICCI","FERNANDEZ","RAMIREZ","GONZALES","BIANCHI","LANG", \
                    "BELEDO","BERTOLINNI","RAMOS","KUBALA","ULLUA","ULLOA","OCHOA","DI MARTINO","ORTIZ","MELLERA",     \
                    "GIMENEZ","GOMEZ","VIVO","CENTURION","TURNER","VAN GOGH","LANGE","ESPOSITO","FUCENECO","ARGENTO",  \
                    "CHANG","HUDSON","COHEN","BEN SIMON","TOLCHINSKY","FONZI","PONCE","RIVAS","KINOMOTO","TAGLIANI",   \
                    "CARMONA","RIBAUDO","PEREZ","MORENO","ZABALSA","POTTER","SALOMON","BAEZ","PAEZ","PAZ","VILLA",     \
                    "WINDSOR","DELMONTE","BERGOGLIO","MILLER","SCHMIDT","MONTE AGUDO","DEL SOLAR","RIMOLDI","CABRALES",\
                    "CANEGATTO","GRANGER","BARRIOS","BARROSO","MORALEDA","JOHNSON","SMITH","SANCHEZ","SIMPSON",        \
                    "LATORRE","SOSA","SAN MARTIN","OLMOS","OLMEDO","MONTES","CORTEZ","CASA MAYOR","GIANIBELLI",        \
                    "GIANINI","WEICH","FABIANI","MORAN","SUAREZ","LANZANI","BELL","MARADONA","PRASAD","BEGAM","BEGUM", \
                    "WANG","CONTRERAS","MORGENDORFFER","LANNISTER","LOPEZ","JUNCO","PERGOLINNI","FLANDERS","GARCIA",   \
                    "PINTO","CARLETTI","HARINGTON","SCOTT","CARTER","CASTRO","QUINTO","PINOS","BUENO","DI SANTO",      \
                    "CARLOTTO","BONAFIDI","SANTORO","SANTOS","TRINIDAD","VEGA","BELTRAN","LEFEVRE","MERCIER","ROYAL",  \
                    "QUITO","JACKSON","JONAS","REY","REYNOSO","GUION","MC DONALDS","MARTINEZ","DE ORTIZ","BLANCO",     \
                    "BLANC","ROLDAN","VISCHETTI","DA SILVA","RUSO","ANDERSON","ALONSO","ALFONZO","VARGAS","CRUZ",      \
                    "MENDOZA","CHAVEZ"}
#define CALLES      {"Sarmiento", "San Martin", "Belgrano", "Rivadavia", "Alvear", "Mitre", "Alsina", "Pueyrredon",    \
                    "Callao","Lavalle", "Urquiza", "Guemes", "San Lorenzo", "San Juan", "Moreno", "Balcarce",          \
                    "San Luis", "Entre Rios", "Corrientes","Santa Fe", "9 de Julio", "Independencia", "Espana",        \
                    "Buenos Aires", "Montevideo", "Santa Cruz", "Chacabuco", "Chile", "Peru","Ayacucho", "Parana",     \
                    "Viamonte", "Junin", "Alem", "Tucuman", "Azcuenaga", "Castelli", "San Nicolas", "Mendoza",         \
                    "Santiago del Estero", "Colon", "Salta", "San Jose", "Cuyo", "General Paz", "Pasco", "Alberti",    \
                    "Santiago", "Caseros","Paso", "San Juan Bautista", "Piedras", "Esmeralda", "Tacuari",              \
                    "Belgrano Sur", "Victoria", "Humberto", "Rodriguez Pena","Echeverria", "Bernardo de Irigoyen",     \
                    "Las Heras", "25 de Mayo", "Riobamba", "Maipu", "Yrigoyen", "Potosi", "General Urquiza","Defensa", \
                    "Carlos Calvo", "Soler", "Elcano", "Paraguay", "Misiones", "Larrea", "Pichincha", "Dorrego",       \
                    "Azcuenaga","Venezuela", "Aristobulo del Valle", "Bolivar", "Salguero", "Melian", "Laprida",       \
                    "San Antonio", "Concepcion Arenal","Pasaje de la Piedad", "Marcelo T. de Alvear", "Gallo",         \
                    "Carlos Gardel", "Mexico", "Brasil", "Zapiola", "Sarandi","Montserrat", "Sanchez de Bustamante",   \
                    "Vidal", "Gascon", "Cochabamba", "Ugarteche", "Honduras", "Estados Unidos","Mejico", "Yatay",      \
                    "Mercedes", "Las Casas", "Andrade", "Zavaleta", "Riachuelo", "Villa Urquiza", "Ayolas", "Arenales",\
                    "Trelles", "Doblas", "San Ignacio de Loyola", "Cervantes", "Solis", "Jorge Newbery", "San Benito", \
                    "Carlos Pellegrini","Calderon de la Barca", "Bouchard", "Varela", "Doblas",                        \
                    "San Ignacio de Loyola", "Cervantes", "Solis", "Jorge Newbery","San Benito", "Carlos Pellegrini",  \
                    "Calderon de la Barca"}

void generarDni(char dni[10]) {
    int dniRandom = 0;
    for (int i = 0; i < 9; i++) {
        dniRandom += (rand() % 10) * (int) pow(10, i);
    }
    sprintf(dni, "%d", dniRandom);
}

void generarEmail(stCliente *cliente) {
    char domains[2][8] = {"gmail", "hotmail"};
    sprintf(cliente->email, "%c.%s@%s.com", tolower(cliente->nombre[0]), strlwr(cliente->apellido),
            domains[rand() % 2]);
}

void generarDomicilio(stCliente *cliente) {
    char calles[130][21] = CALLES;
    sprintf(cliente->domicilio, "%s , %05d.", calles[rand() % 130], rand() % 10000);
}

void generarTelefono(stCliente *cliente) {
    sprintf(cliente->telefono, "%d-%d%d", (rand() % 3890) + 10, (rand() % 5) + 1, rand() % 999999);
}

int opInicializarClientes(int idClientes[50]) {
    stCliente clientes[50];
    char nombres[140][13] = NOMBRES;
    char apellidos[140][13] = APELLIDOS;

    for (int i = 0; i < 50; i++) {
        stCliente cliente;
        cliente.id = i;
        cliente.nroCliente = ID_INICIAL_CLIENTES + i;
        idClientes[i] = cliente.nroCliente;
        strcpy(cliente.nombre, nombres[rand() % 140]);
        strcpy(cliente.apellido, apellidos[rand() % 140]);
        generarDni(cliente.dni);
        generarEmail(&cliente);
        generarDomicilio(&cliente);
        generarTelefono(&cliente);
        cliente.eliminado = 0;
        clientes[i] = cliente;
        gotoxy(25, 13);
        printf("%d | %d ", cliente.id, cliente.nroCliente);
        usleep(1000000 / 50);
    }
    return persistirClientesIniciales(50, clientes);
}

int opValidarString(const char nombre[]) {
    int validez = 1;
    int longitud = strlen(nombre);
    if (30 <= longitud) {
        validez = 0;
    } else {
        int i = 0;
        while ((i < validez) && validez == 1) {
            if (!isalpha(nombre[i]) && nombre[i] != ' ') validez = 0;
            i++;
        }
    }
    return validez;
}

int opValidarDni(int digitos, const char dni[10]) {
    int validez = 1;
    int longitud = strlen(dni);
    if (longitud < 7 || (longitud > digitos - 1)) {
        validez = 0;
    } else {
        int i = 0;
        while (i < longitud && validez == 1) {
            if (!isdigit(dni[i])) validez = 0;
            i++;
        }
    }
    return validez;
}

int opValidarCorreo(const char correo[]) {
    int validez = 0;
    int longitud = strlen(correo);
    int posicionArroba = 0;
    while (correo[posicionArroba] != '@' && posicionArroba < longitud - 10) {
        posicionArroba++;
    }
    if (posicionArroba != 0 && (strstr(correo + posicionArroba, "@gmail.com") != NULL ||
                                strstr(correo + posicionArroba, "@hotmail.com") != NULL)) {
        validez = 1;
    }
    return validez;
}

int opValidarDireccion(char direccion[]) {
    int validez = 1;
    for (int i = 0; i < strlen(direccion); i++) {
        if (!isalpha(direccion[i]) && !isdigit(direccion[i]) && !isblank(direccion[i])) validez = 0;
    }
    return validez;
}

int opGuardarNuevoCliente(char nombre[], char apellido[], char dni[], char email[], char domicilio[], char telefono[]) {
    stCliente cliente;
    cliente.id = obtenerNuevoIdCliente();
    if (cliente.id != -1) {
        cliente.nroCliente = ID_INICIAL_CLIENTES + cliente.id;
        strcpy(cliente.nombre, nombre);
        strcpy(cliente.apellido, apellido);
        strcpy(cliente.dni, dni);
        strcpy(cliente.email, email);
        strcpy(cliente.domicilio, domicilio);
        strcpy(cliente.telefono, telefono);
        cliente.eliminado = 0;
        return persistirClienteNuevo(cliente);
    } else {
        return 500;
    }
}

double convertirNroCuentaArrayAInt(const int arrayNroCliente[8]) {
    double intNroCliente = 0;
    for (int i = 0; i <= 7; i++) {
        intNroCliente = intNroCliente + (double) arrayNroCliente[i] * pow(10, 7 - i);
    }
    return intNroCliente;
}

stResultadoClientes opBuscarCliente(int arrayNroCliente[]) {
    int nroCliente = (int) convertirNroCuentaArrayAInt(arrayNroCliente);
    return buscarClientePorNroCliente(nroCliente);
}

stResultadoClientes opListarClientes() {
    return listarClientes();
}

int opActualizarCliente(stCliente cliente,
                        char nombre[], char apellido[], char dni[], char email[], char domicilio[], char telefono[]) {
    strcpy(cliente.nombre, nombre);
    strcpy(cliente.apellido, apellido);
    strcpy(cliente.dni, dni);
    strcpy(cliente.email, email);
    strcpy(cliente.domicilio, domicilio);
    strcpy(cliente.telefono, telefono);
    cliente.eliminado = 0;
    return persistirActualizacion(cliente);
}

int opBorrarCliente(int arrayNroCliente[]){
    int nroCliente =(int) convertirNroCuentaArrayAInt(arrayNroCliente);
    return persistirClienteEliminado(nroCliente);
}