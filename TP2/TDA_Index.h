/*
 * TDA_Index.h 
 *
 *  Created on: 5/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __TDA_INDEX_h__
#define __TDA_INDEX_h__

#include <stdlib.h>
#include <string.h>
#include "TDA_Index_Errores.h"

// CONSTANTES:
//
// TAM_USU: Tamaño de un usuario

#define TAM_USU 20


typedef int (*comparator_index) (void*, void*);

typedef struct {
  char* usuario;
  unsigned int nPedido;
  comparator_index func;
} TDA_INDEX;

// TDA_INDEX_Crear:
//
// PRE CONDICIÓN:
// TDA_INDEX no creado;
//
// POST CONDICIÓN:
// Crea un TDA_INDEX

void TDA_INDEX_Crear(TDA_INDEX* index, char* usuario, unsigned int cant_pedido);

// TDA_INDEX_Get_Usuario:
//
// PRE CONDICIÓN:
// TDA_INDEX  creado;
//
// POST CONDICIÓN:
// Devuelve el usuario.

void TDA_INDEX_Get_Usuario(TDA_INDEX index, char** usuario);

// TDA_INDEX_Get_nPedido:
//
// PRE CONDICIÓN:
// TDA_INDEX  creado;
//
// POST CONDICIÓN:
// Devuelve el número de pedido.

unsigned int TDA_INDEX_Get_nPedido(TDA_INDEX index);

// TDA_INDEX_Get_Comparador:
//
// PRE CONDICIÓN:
// TDA_INDEX creado;
//
// POST CONDICIÓN:
// Devuelve la función de comparación.

comparator_index TDA_INDEX_Get_Comparador(TDA_INDEX index);

// TDA_INDEX_Destruir:
//
// PRE CONDICIÓN:
// TDA_INDEX  creado;
//
// POST CONDICIÓN:
// Destruye TDA_INDEX

void TDA_INDEX_Destruir(TDA_INDEX *index);
#endif
