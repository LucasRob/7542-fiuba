/*
 *AB_BB.h ARBOL BINARIO BUSQUEDA Y BORRADO
 *
 *  Created on: 31-03-2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __AB_BB_H__
#define __AB_BB_H__

#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "AB_BB_Errores.h"

typedef enum {
  AB_BB_IZQ, 
  AB_BB_DER, 
  AB_BB_PAD, 
  AB_BB_RAIZ,
} TMovimiento_AB_BB;


typedef struct TNodoAB_BB {
  void* elem;
  struct TNodoAB_BB *izq, *der;
} TNodoAB_BB;

typedef struct TAB_BB {
  TNodoAB_BB *raiz, *cte;
  int tamdato;
} TAB_BB;

// AB_BB_Crear:
//
// PRE CONDICIÓN:
// ab vacío.
//
// POST CONDICIÓN:
// ab creado.

void AB_BB_Crear(TAB_BB *ab, int tdato);

// AB_BB_ElemCte:
//
// PRE CONDICIÓN:
// ab creado y no vacío.
//
// POST CONDICIÓN:
// Devuelve en elem el valor del
// nodo corriente.

void AB_BB_ElemCte(TAB_BB ab, void *elem);

// AB_BB_ModifCte:
//
// PRE CONDICIÓN:
// ab creado y no vacío.
//
// POST CONDICIÓN:
// modifica el valor del 
// elemento del nodo corriente.

void AB_BB_ModifCte(TAB_BB *ab, void *elem);

// AB_BB_MoverCte:
//
// PRE CONDICIÓN:
// ab creado y no vacío.
//
// POST CONDICIÓN:
// si pudo mover devuelve 0 sino 1.

void AB_BB_MoverCte(TAB_BB *ab, TMovimiento_AB_BB mov, int *error);

// AB_BB_Vaciar:
//
// PRE CONDICIÓN:
// ab creado. 
//
// POST CONDICIÓN:
// árbol vaciado.

void AB_BB_Vaciar(TAB_BB *ab);

// AB_BB_Vacio:
//
// PRE CONDICIÓN:
// ab creado. 
//
// POST CONDICIÓN:
// Devuelve ERR_AB_BB_VACIO o 
// AB_BB_NO_VACIO.

int AB_BB_Vacio(TAB_BB ab);

// AB_BB_BorrarCte:
//
// PRE CONDICIÓN:
// ab creado. 
//
// POST CONDICIÓN:
// El elemento corriente se borra
// y cambia por otro (Ver la función en
// AB_BB.c
// 


void AB_BB_BorrarCte(TAB_BB *ab);

// AB_BB_Insertar_Ordenado:
//
// PRE CONDICIÓN:
// ab creado 
//
// POST CONDICIÓN:
// Devuelve AB_BB_INSERTADO si pudo 
// insertarlo o ERR_AB_BB_INSERTAR_IGUAL
// Si el elemento a insertar es igual a 
// alguno del árbol.

int AB_BB_Insertar_Ordenado(TAB_BB *ab, void* elem, 
int(*comparar)(void*, void*));

// AB_BB_Busqueda:
//
// PRE CONDICIÓN:
// ab creado 
//
// POST CONDICIÓN:
// Devuelve AB_BB_ENCONTRADO si encontró
// el elemento o ERR_AB_BB_BUSQUEDA_NO_ENCONTRADO
// Si el elemento a insertar es igual a 
// alguno del árbol

int AB_BB_Busqueda(TAB_BB *ab, void* elem, int(*comparar)(void*, void*));

#endif

