/*
 * TDA_Shop_Track.c 
 *
 *  Created on: 5/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#include "TDA_Shop_Track.h"


// FUNCIONAMIENTO TDA_SHOP_TRACK_Crear:
// Crea un tipo shop_track.

void TDA_SHOP_TRACK_Crear(TDA_SHOP_TRACK* shop_track, 
TAB_BB* users, TAB_BB* indexes) {
  shop_track->usuarios = users;
  shop_track->indices = indexes;
}

// FUNCIONAMIENTO TDA_SHOP_TRACK_Get_Usuarios:
// Devuelve la lista de usuarios.

void TDA_SHOP_TRACK_Get_Usuarios(TDA_SHOP_TRACK shop_track, TAB_BB** users) {
  *users = shop_track.usuarios;
}

// FUNCIONAMIENTO TDA_SHOP_TRACK_Get_Indices:
// Devuelve la lista de índices.

void TDA_SHOP_TRACK_Get_Indices(TDA_SHOP_TRACK shop_track, TAB_BB** indexes) {
  *indexes = shop_track.indices;
}

// FUNCIONAMIENTO TDA_SHOP_TRACK_Destruir:
// Destruye el TDA_SHOP_TRACK liberando la memoria
// dinámica que posea.

void TDA_SHOP_TRACK_Destruir(TDA_SHOP_TRACK *shop_track) {
  free(shop_track->usuarios);
  free(shop_track->indices);
  shop_track->usuarios = NULL;
  shop_track->indices = NULL;
}
