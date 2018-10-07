/*
 * TDA_Usuario.h 
 *
 *  Created on: 4/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __TDA_USU_h__
#define __TDA_USU_h__

#include "LSB.h"
#include <stdlib.h>
#include <string.h>
#include "TDA_Usuario_Errores.h"

// CONSTANTES:
//
// TAM_USU: Tamaño de un usuario
// TAM_APELLIDO: Tamaño de un apellido
// TAM_NOMBRES: Tamaño de los nombres

#define TAM_USU 20
#define TAM_APELLIDO 30
#define TAM_NOMBRES 50

typedef int (*comparator_usuario) (void*, void*);

typedef struct {
  char *usuario;
  char *apellido;
  char *nombres;
  T_LSB* pedidos;
  comparator_usuario func;
} TDA_USU;


// TDA_USU_Crear:
//
// PRE CONDICIÓN:
// TDA_USU no creado;
//
// POST CONDICIÓN:
// Crea un TDA_USU

void TDA_USU_Crear(TDA_USU* usu, char* usuario, 
char* apellido, char* nombres, T_LSB* pedidos);

// TDA_USU_Get_Usuario:
//
// PRE CONDICIÓN:
// TDA_USU  creado;
//
// POST CONDICIÓN:
// Devuelve el usuario.

void TDA_USU_Get_Usuario(TDA_USU usu, char** usuario);

// TDA_USU_Get_Apellido:
//
// PRE CONDICIÓN:
// TDA_USU  creado;
//
// POST CONDICIÓN:
// Devuelve el apellido.

void TDA_USU_Get_Apellido(TDA_USU usu, char** apellido);

// TDA_USU_Get_Nombres:
//
// PRE CONDICIÓN:
// TDA_USU  creado;
//
// POST CONDICIÓN:
// Devuelve los nombres.

void TDA_USU_Get_Nombres(TDA_USU usu, char** nombres);

// TDA_USU_Get_Pedidos:
//
// PRE CONDICIÓN:
// TDA_USU  creado;
//
// POST CONDICIÓN:
// Devuelve la lista de pedidos.

void TDA_USU_Get_Pedidos(TDA_USU usu, T_LSB** pedidos);

// TDA_USU_Destruir:
//
// PRE CONDICIÓN:
// TDA_USU  creado;
//
// POST CONDICIÓN:
// Destruye TDA_USU

void TDA_USU_Destruir(TDA_USU *usu);

// TDA_USU_Get_Comparador:
//
// PRE CONDICIÓN:
// TDA_USU creado;
//
// POST CONDICIÓN:
// Devuelve la función de comparación.

comparator_usuario TDA_USU_Get_Comparador(TDA_USU usu);
#endif
