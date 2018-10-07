/*
 * TDA_Shop_Track.h 
 *
 *  Created on: 5/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __TDA_SHOP_TRACK_h__
#define __TDA_SHOP_TRACK_h__

#include "AB_BB.h"
#include <stdlib.h>

typedef int (*comparator_shop_track) (void*, void*);

typedef struct {
  TAB_BB* usuarios;
  TAB_BB* indices;
} TDA_SHOP_TRACK;

// TDA_SHOP_TRACK_Crear:
//
// PRE CONDICIÓN:
// TDA_SHOP_TRACK no creado;
//
// POST CONDICIÓN:
// Crea un TDA_SHOP_TRACK

void TDA_SHOP_TRACK_Crear(TDA_SHOP_TRACK* shop_track, 
TAB_BB* users, TAB_BB* indexes);

// TDA_SHOP_TRACK_Get_Usuarios:
//
// PRE CONDICIÓN:
// TDA_SHOP_TRACK  creado;
//
// POST CONDICIÓN:
// Devuelve la lista de usuarios.

void TDA_SHOP_TRACK_Get_Usuarios(TDA_SHOP_TRACK shop_track, TAB_BB** users);

// TDA_SHOP_TRACK_Get_Indices:
//
// PRE CONDICIÓN:
// TDA_SHOP_TRACK  creado;
//
// POST CONDICIÓN:
// Devuelve la lista de índices.

void TDA_SHOP_TRACK_Get_Indices(TDA_SHOP_TRACK shop_track, TAB_BB** indexes);

// TDA_SHOP_TRACK_Destruir:
//
// PRE CONDICIÓN:
// TDA_SHOP_TRACK  creado;
//
// POST CONDICIÓN:
// Destruye TDA_SHOP_TRACK

void TDA_SHOP_TRACK_Destruir(TDA_SHOP_TRACK *shop_track);


#endif
