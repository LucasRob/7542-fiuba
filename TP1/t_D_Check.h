/*
 *T_D_CHECK.h
 *
 *  Created on: 16-mar-2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef T_D_CHECK_
#define T_D_CHECK

#include "aux.h"

// t_D_CHECK: Contine los elementos para realizar el MD5
// DIR: dirección del archivo a verificar
// pBUFFER: Buffer que contiene los 512 bits a procesar (16 enteros de 4 bytes)
// pFILE: El File descriptor del archivo a verificar

typedef struct {
  char dir[FILE_SIZE];
  unsigned long int pBuffer[BUFFER_SIZE];
  FILE* pFile;
} t_D_Check;

// CREAR_D_CHECK:
//
// PRE CONDICIÓN:
// myTDC vacio
//
// POST CONDICIÓN:
// Devuelve el myTdc creado, sinó ERR_BINARY_NOT_FOUND

// DETALLES:
// Crea el Verificador de Downloads
// regresa ERR_BINARY_NOT_FOUND si no encuentra el error
// sinó regresa SUCCESSFUL_EXECUTION

int crear_D_Check(t_D_Check* myTdc, char *myDir);

// DESTRUIR_D_CHECK:
//
// PRE CONDICIÓN:
// myTDC lleno
//
// POST CONDICIÓN:
// destruye el myTdc creado, sinó ERR_FILE_CLOSE
//
// DETALLES:
// Destruye el Verificador de Downloads
// regresa ERR_FILE_CLOSE si no pudo cerrar el archivo
// sinó regresa SUCCESFULL_EXECUTION

int destruir_D_Check(t_D_Check* myTdc);

// MD5:
//
// PRE CONDICIÓN:
// myTDC lleno y myDigest vacio
//
// POST CONDICIÓN:
// Regresa en myDigest el valor del algoritmo md5
// sobre mytdc, Devuelve SUCCESSFUL_EXECUTION
//
// DETALLES:
// Función que realiza el algoritmo md5 devolviendo una secuencia de char
// específica para un archivo dado.

int md5(t_D_Check myTdc, char *myDigest);


#endif /* T_D_CHECK_ */
