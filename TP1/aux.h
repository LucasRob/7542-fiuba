/*
 *AUX.h
 *
 *  Created on: 17-mar-2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef AUX_
#define AUX_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errores.h"
#include <math.h>

// FILE_SIZE: Tamaño de la dirección de los archivos binarios
// BUFFER_SIZE: Tamaño del buffer de los 512 bits
// R_K_SIZE: Tamaño de las variables r y s de la función md5
// APPEND_SIZE: Tamaño de las variables para hace append
// HI_SIZE: Tamaño de las variable hi
// HASH_SIZE: Tamaño de las variable hash

#define FILE_SIZE  255
#define BUFFER_SIZE 16
#define R_K_SIZE 64
#define APPEND_SIZE 32
#define HI_SIZE 4
#define HASH_SIZE 35

// INICIALIZAR:
//
// PRE CONDICIÓN:
// hi, o y l vacios
//
// POST CONDICIÓN:
// Devuelve hi y r con los valores para utilixar MD5

// DETALLES:
// Inicializa las variables auxiliares para realizar el algoritmo md5
// Estas son los hi, el vector r

void inicializar(unsigned long int *hi, unsigned long int *o);

// LEFTROTATE:
//
// PRE CONDICIÓN:
// x y c llenos con valores apropiados (x un entero largo sin signo y
// c un entero corto sin signo
//
// POST CONDICIÓN:
// x es rotado c lugares
//
// DETALLES:
// Rotar consiste en correr los bits c lugares a la izquierda empezando
// por el bit menos significativo. Como al hacer corrimientos se pierden
// bits estos (los c más significativos) se vuelven a guardan en la parte
// alta de la dirección

unsigned long int leftrotate(unsigned long int x, unsigned long int c);

// APPEND:
//
// PRE CONDICIÓN:
// hi lleno y result vacio
//
// POST CONDICIÓN:
// Copia los 32 bytes de los 4 hi a el vector digest
//
// DETALLES:
// Convierte los resultados hexadecimales a string
// y genera el digest (VER AUX.C)

void append(unsigned long int *hi, char *result);

// SWAP_ENDIAN:
//
// PRE CONDICIÓN:
// x lleno con un entero largo sin signo
//
// POST CONDICIÓN:
// Cambia el "endianess" del entero.
//
// DETALLES:
// Un palabra es little endian es aquella que
// tiene sus bits menos significativos en la
// dirección más baja y el big endian los más
// significativos. Los procesadores INTEL
// son little endian y por lo tanto la mayoria
// de las máquinas. Para el ejercicio se
// necesita cambiar el "endianess", porque se quiere
// mostrar ciertos hexadecimales como la máquina los
// interpreta que es little endian. Esto es porque los enteros
// se muestran (al hacer un DISPLAY en GDB) en el orden
// del menos significativo al más de izq a derecha y no de derecha
// a izq que es como están guardados. Ej: Si se quiere mostrar
// el número 0x65726f4c como la máquina lo guarda swap endian
// lo cambia a 0x4c6f7265

void swap_endian(unsigned long int* x);

// PROCESAR:
//
// PRE CONDICIÓN:
// Los parámetros llenos y no vacios
//
// POST CONDICIÓN:
// Procesa el algoritmo y actualiza los resultados
// parciales o finales en hi
//
// DETALLES:
// El algoritmo consiste en aplicar cuatro funciones
// bit a bit en los hi usando los hi iniciales y usando
// los valores leidos del archivo junto con los de los
// arrays k y r

void procesar(unsigned long int *pBuffer, unsigned long int *hi
, unsigned long int *r, unsigned long int *k);

// PADDING:
//
// PRE CONDICIÓN:
// Array lleno o vacio pero inicializado con ceros, tam y pos con valores
// coherentes
//
// POST CONDICIÓN:
// Agrega la cantidad de bits necesaria (un uno y n ceros)
//
// DETALLES:
//
// Agrega cierta cantidad de bits (un uno y x cantidad de ceros) para poder
// aplicar correctamente el algoritmo de MD5
// ARRAY es el array a procesar, POS es el valor que devolvió FREAD
// al leer el archivo que indica la cantidad total de elementos de 4 bytes
// leidos del archivo. En este caso será usado como el lugar donde se empezará
// a agregar los bits para el padding ya que si logró leer 4 elementos,
// la posición 4 del array es donde se colocará el uno.
// TAM es el tamaño total del archivo. Para mas explicación ver PADDING en
// AUX.C

int padding(unsigned long int *array, size_t pos,
unsigned long int *bits_extras);

// BLANQUEAR_STRING:
//
// PRE CONDICIÓN:
// Array existente y size coherente con losn límites del array.
//
// POST CONDICIÓN:
// Agrega ceros en array hasta la posición pos
//
// DETALLES:
//
// Blanquea (agrega cero) al char * que se
// pasa por parámetro en una cantidad pos

void blanquear_string(char *array, size_t pos);


// BLANQUEAR_INT:
//
// PRE CONDICIÓN:
// Array existente y size coherente con losn límites del array.
//
// POST CONDICIÓN:
// Agrega ceros en array hasta la posición pos
//
// DETALLES:
//
// Blanquea (agrega cero) al unsigned long int* que se
// pasa por parámetro en una cantidad pos

void blanquear_int(unsigned long int *array, size_t pos);

// PARSEAR:
//
// PRE CONDICIÓN:
// pFile existente; res y dir existentes
//
// POST CONDICIÓN:
// Devuelve en res el resultado de aplicar al archivo del
// tdc el algoritmo de md5 y en dir la dirección del archivo
// a aplicar
//
//
// DETALLES:
//
// Estos datos se encuentran en el archivo "checksums.txt que
// es el archivo que se pasa como parámetro en pFile

void parsear(char *res, char *dir, FILE* pFile);

// ACTUALIZAR_TAMANO
//
// PRE CONDICIÓN:
// tam_14, tam_15 y tam_parcial con valores coherentes.
//
// POST CONDICIÓN:
// Devuelve en tam_14 y tam_15 el tamaño del archivo.
// Se usan dos variables por si el archivo de entrada tiene una
// longitud mayor que 4 bytes.
//
// DETALLES:
// tam_parcial contiene la cantidad de bits leidos hasta
// el momento
void actualizar_tamano(unsigned long int *tam_14,
unsigned long int *tam_15, unsigned long int tam_parcial);

// AGREGAR_TAMANO
//
// PRE CONDICIÓN:
// array, tam_14, tam_15 y tam_parcial con valores coherentes.
//
// POST CONDICIÓN:
// Actualiza en array las posiciones 14 y 15 con el tamaño
// del archivo
//
// DETALLES:
// Se usan dos variables por si el archivo de entrada tiene una
// longitud mayor que 4 bytes.
void agregar_tamano(unsigned long int *array,
unsigned long int tam_14, unsigned long int tam_15);

// VERIFICAR_KB
//
// PRE CONDICIÓN:
// bits inicializada o ya con un valor acumulado, dir
// no vacia.
//
// POST CONDICIÓN:
// Verifica la cantidad de bits leidos y los informa por
// stderr. En caso de alcanzarce 1 kb. bits contendrá un cero.
//
// DETALLES:
// bits lleva acumulado la cantidad total de bits leidos.
void verificar_kb(unsigned long int *bits, char *dir);
#endif /* AUX_ */

