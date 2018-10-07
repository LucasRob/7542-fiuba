/*
 * TP2_Operaciones.h 
 *
 *  Created on: 9/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __TP2_OPERACIONES_h__
#define __TP2_OPERACIONES_h__


#include "TDA_Shop_Track.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LSB_Errores.h"
#include "AB_BB_Errores.h"
#include "TDA_Index.h"
#include "TDA_Usuario.h"
#include "TDA_Pedido.h"
#include "TDA_Itinerario.h"
#include "TDA_Paquete.h"
#include "AB_BB.h"
#include "LSB.h"


void Agregar_Usuario(TDA_SHOP_TRACK* shop_track, 
char* usuario, char*  apellido, char*  nombres);

int Eliminar_Usuario(TDA_SHOP_TRACK* shop_track, char* usuario);

void Compra(TDA_SHOP_TRACK* shop_track, char* usuario, 
unsigned int nPedido, char* descripcion, unsigned int cantPaq);

void Buscar_En_Indice(TDA_SHOP_TRACK* shop_track, 
unsigned int nPedido, unsigned int nPaq, char* algo, 
char* ubicacion, char* fecha, char codigo);

void Estado_de_Ultimos_Pedidos(TDA_SHOP_TRACK* shop_track, 
char* usuario, int cantPedidos);

#endif

