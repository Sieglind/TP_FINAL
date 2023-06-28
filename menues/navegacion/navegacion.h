#include <stdbool.h>

#define BACKSPACE 8
#define ENTER 13
#define ESCAPE 27
#define ESPACIO 32
#define IZQUIERDA 75
#define DERECHA 77
#define FINAL_STRING '\0'

/**
 * @brief Permite la navegacion de menues genericos.
 * @param posiciones Las coordenadas en el eje x de la consola de cada una de las opciones.
 * @param validos La cantidad de opciones disponibles para navegar,
 * @param valorDeEscape Que valor debe devolver el menu al presionar ESCAPE.
 * @return El valor de escape determinado por el atributo "valorDeEscape".
 */
int navegarMenu(int posiciones[], int validos, int valorDeEscape);

/**
 * @brief Permite la navegacion de paginas de resultados
 * @param paginaActual Pagina en la que se encuentra actualmente la vista.
 * @param paginas Cantidad de paginas disponibles para mostrar.
 * @param opcion Valor por referencia, permite la deteccion de salida de navegacion.
 * @return Devuelve el numero de pagina hacia donde se debe dirigir la vista,
 */
int navegarLista(int paginaActual, int paginas, int *opcion);

/**
 * @brief Perimte solicitar un string al usuario y guardarlo en "string"
 * @param dimension Dimension deseada para el string ingresado.
 * @param string Arreglo donde se guardara el string intresado.
 * @param x Posicion en el eje x donde se debe mostrar el string a medida que se escribe.
 * @param y Posicion en el eje y donde se debe mostrar el string a medida que se escribe.
 * @return Devuelve el ESCAPE o ENTER segun lo indique el usuario.
 */
int solicitarString(int dimension, char string[dimension], int x, int y);