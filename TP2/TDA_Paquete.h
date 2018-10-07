/*
 * TDA_Paquete.h 
 *
 *  Created on: 2/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __TDA_PAQUETE_h__
#define __TDA_PAQUETE_h__

#include <stdlib.h>
#include <string.h>
#include "TDA_Paquete_Errores.h"

// CONSTANTES:
//
// TAM_UBI: Tamaño de una ubicación

#define TAM_UBI 50


typedef int (*comparator) (void*, void*);

typedef enum {
  ENVIADO,
  ENTREGADO,
} T_ESTADO_PAQUETE;

typedef struct {
  unsigned int nPaquete;
  char* ubicacion;
  T_ESTADO_PAQUETE estado;
  char* contenido;
  comparator func;
} TDA_PAQ;

// TDA_PAQ_Crear:
//
// PRE CONDICIÓN:
// TDA_PAQ no creado;
//
// POST CONDICIÓN:
// Crea un TDA_PAQ

void TDA_PAQ_Crear(TDA_PAQ* paq, unsigned int cant_paq, 
char* ubi, T_ESTADO_PAQUETE status, char* cont);

// TDA_PAQ_Get_nPaquete:
//
// PRE CONDICIÓN:
// TDA_PAQ  creado;
//
// POST CONDICIÓN:
// Devuelve el número de paquete.

unsigned int TDA_PAQ_Get_nPaquete(TDA_PAQ paq);

// TDA_PAQ_Get_Ubicacion:
//
// PRE CONDICIÓN:
// TDA_PAQ  creado;
//
// POST CONDICIÓN:
// Devuelve la ubicación.

void TDA_PAQ_Get_Ubicacion(TDA_PAQ paq, char** ubi);

// TDA_PAQ_Get_Estado:
//
// PRE CONDICIÓN:
// TDA_PAQ  creado;
//
// POST CONDICIÓN:
// Devuelve el estado.

T_ESTADO_PAQUETE TDA_PAQ_Get_Estado(TDA_PAQ paq); 

// TDA_PAQ_Set_Estado:
//
// PRE CONDICIÓN:
// TDA_PAQ  creado;
//
// POST CONDICIÓN:
// Setea el estado del paquete.

void TDA_PAQ_Set_Estado(TDA_PAQ* paq, T_ESTADO_PAQUETE status);

// TDA_PAQ_Set_Ubicacion:
//
// PRE CONDICIÓN:
// TDA_PAQ  creado;
//
// POST CONDICIÓN:
// Setea el estado del paquete.

void TDA_PAQ_Set_Ubicacion(TDA_PAQ* paq, char* ubi);

// TDA_PAQ_Get_Contenido:
//
// PRE CONDICIÓN:
// TDA_PAQ  creado;
//
// POST CONDICIÓN:
// Devuelve el contenido.

void TDA_PAQ_Get_Contenido(TDA_PAQ paq, char** cont);

// TDA_PAQ_Destruir:
//
// PRE CONDICIÓN:
// TDA_PAQ  creado;
//
// POST CONDICIÓN:
// Destruye TDA_PAQ

void TDA_PAQ_Destruir(TDA_PAQ *paq);

// TDA_PAQ_Get_Comparador:
//
// PRE CONDICIÓN:
// TDA_PAQ creado;
//
// POST CONDICIÓN:
// Devuelve la función de comparación.

comparator TDA_PAQ_Get_Comparador(TDA_PAQ paq);
#endif


















