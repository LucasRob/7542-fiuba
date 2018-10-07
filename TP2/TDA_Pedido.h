/*
 * TDA_Pedido.h 
 *
 *  Created on: 2/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __TDA_PEDIDO_h__
#define __TDA_PEDIDO_h__

#include "LSB.h"
#include <stdlib.h>
#include <string.h>
#include "TDA_Pedido_Errores.h"

typedef int (*comparator_pedido) (void*, void*);

typedef struct {
  unsigned int nPedido;
  char* descripcion;
  unsigned int cant_paq;
  T_LSB* paquetes;
  T_LSB* itinerarios;
  comparator_pedido func;
} TDA_PEDIDO;

// TDA_PEDIDO_Crear:
//
// PRE CONDICIÓN:
// TDA_PEDIDO no creado;
//
// POST CONDICIÓN:
// Crea un TDA_PEDIDO

void TDA_PEDIDO_Crear(TDA_PEDIDO* pedido, unsigned int cant_pedido
, char* desc, unsigned cant_paq, T_LSB* packs, T_LSB* itineraries);

// TDA_PEDIDO_Get_nPedido:
//
// PRE CONDICIÓN:
// TDA_PEDIDO  creado;
//
// POST CONDICIÓN:
// Devuelve el número de pedido.

unsigned int TDA_PEDIDO_Get_nPedido(TDA_PEDIDO pedido);

// TDA_PEDIDO_Get_Descripción:
//
// PRE CONDICIÓN:
// TDA_PEDIDO  creado;
//
// POST CONDICIÓN:
// Devuelve la descripción.

void TDA_PEDIDO_Get_Descripcion(TDA_PEDIDO pedido, char** desc);

// TDA_PEDIDO_Get_Cant_Paq:
//
// PRE CONDICIÓN:
// TDA_PEDIDO  creado;
//
// POST CONDICIÓN:
// Devuelve la cantidad de paquetes.

unsigned int TDA_PEDIDO_Get_Cant_Paq(TDA_PEDIDO pedido);

// TDA_PEDIDO_Get_Paquetes:
//
// PRE CONDICIÓN:
// TDA_PEDIDO  creado;
//
// POST CONDICIÓN:
// Devuelve la lista de paquetes.

void TDA_PEDIDO_Get_Paquetes(TDA_PEDIDO pedido, T_LSB** packs);

// TDA_PEDIDO_Get_Itinerarios:
//
// PRE CONDICIÓN:
// TDA_PEDIDO  creado;
//
// POST CONDICIÓN:
// Devuelve la lista de itinerarios.

void TDA_PEDIDO_Get_Itinerarios(TDA_PEDIDO pedido, T_LSB** itineraries);

// TDA_PEDIDO_Destruir:
//
// PRE CONDICIÓN:
// TDA_PEDIDO  creado;
//
// POST CONDICIÓN:
// Destruye TDA_PEDIDO

void TDA_PEDIDO_Destruir(TDA_PEDIDO *pedido);

// TDA_PEDIDO_Get_Comparador:
//
// PRE CONDICIÓN:
// TDA_PEDIDO creado;
//
// POST CONDICIÓN:
// Devuelve la función de comparación.

comparator_pedido TDA_PEDIDO_Get_Comparador(TDA_PEDIDO pedido);
#endif
