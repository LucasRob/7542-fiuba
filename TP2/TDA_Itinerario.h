/*
 * TDA_Itinerario.h 
 *
 *  Created on: 2/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __TDA_ITINERARIO_h__
#define __TDA_ITINERARIO_h__

#include <stdlib.h>
#include <string.h>
#include "TDA_Itinerario_Errores.h"

// CONSTANTES:
//
// TAM_UBI: Tamaño de una ubicación
// TAM_FECHA: Tamaño de la fecha

#define TAM_UBI 50  
#define TAM_FECHA 8

typedef int (*comparator_itinerario) (void*, void*);

typedef struct {
  unsigned int nPaquete;
  char *ubicacion;
  char *fecha;
  char* descripcion;
  comparator_itinerario func;
} TDA_ITI;

// TDA_ITI_Crear:
//
// PRE CONDICIÓN:
// TDA_ITI no creado;
//
// POST CONDICIÓN:
// Crea un TDA_ITI

void TDA_ITI_Crear(TDA_ITI* iti, unsigned int cant_paq, 
char* ubi, char* fecha, char* desc);

// TDA_ITI_Get_nPaquete:
//
// PRE CONDICIÓN:
// TDA_ITI  creado;
//
// POST CONDICIÓN:
// Devuelve el número de paquete.

unsigned int TDA_ITI_Get_nPaquete(TDA_ITI iti);

// TDA_ITI_Get_Ubicacion:
//
// PRE CONDICIÓN:
// TDA_ITI  creado;
//
// POST CONDICIÓN:
// Devuelve la ubicación.

void TDA_ITI_Get_Ubicacion(TDA_ITI iti, char** ubi);

// TDA_ITI_Get_Fecha:
//
// PRE CONDICIÓN:
// TDA_ITI  creado;
//
// POST CONDICIÓN:
// Devuelve la Fecha.

void TDA_ITI_Get_Fecha(TDA_ITI iti, char** fecha);

// TDA_ITI_Get_Descripción:
//
// PRE CONDICIÓN:
// TDA_ITI  creado;
//
// POST CONDICIÓN:
// Devuelve la descripción.

void TDA_ITI_Get_Descripcion(TDA_ITI iti, char** description);

// TDA_ITI_Destruir:
//
// PRE CONDICIÓN:
// TDA_ITI  creado;
//
// POST CONDICIÓN:
// Destruye TDA_ITI

void TDA_ITI_Destruir(TDA_ITI *iti);

// TDA_ITI_Get_Comparador:
//
// PRE CONDICIÓN:
// TDA_ITI  creado;
//
// POST CONDICIÓN:
// Devuelve la función de comparación.

comparator_itinerario TDA_ITI_Get_Comparador(TDA_ITI iti);
#endif
