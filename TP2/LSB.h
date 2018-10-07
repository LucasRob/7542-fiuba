/*
 * LSB.h Lista Simple con Busqueda
 *
 *  Created on: 1/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */


#ifndef __LSB_h__
#define __LSB_h__

#include <stdlib.h>
#include <string.h>
#include "LSB_Errores.h"

typedef enum {
  LSB_PRIMERO,
  LSB_SIGUIENTE,
  LSB_ANTERIOR
} TMovimiento_LSB;

typedef struct TNodo_LSB {
  void* elem;
  struct TNodo_LSB *sig;
} TNodo_LSB;

typedef struct {
  TNodo_LSB *prim, *cte;
  int tamdato;
} T_LSB;

// LSB_Crear
// Pre: LSBb no fue creada.
// Post: LSBb creada y vacía 

void LSB_Crear(T_LSB *lsb, int tdato);

// LSB_Vaciar
// Pre: lsb creada.
// Post: lsb vacía.

void LSB_Vaciar(T_LSB *lsb);

// LSB_Vacia
// Pre: LSBb creada.
// Post: Si lsb tiene elementos devuelve FALSE sino TRUE.

int LSB_Vacia(T_LSB lsb);

// LSB_ElemCte
// Pre: LSBb creada y no vacía.
// Post: Se devuelve en elem el elemento corriente de la lista.

void LSB_ElemCte(T_LSB lsb, void* elem);

// LSB_ModifCorriente
// Pre: lsb creada y no vacía.
// Post: El contenido del elemento actual quedo actualizado con elem. 

void LSB_ModifCte(T_LSB *lsb, void* elem);

// LSB_MoverCte
// Pre: lsb creada y no vacía.
// Post: Si lsb esta vacía, devuelve FALSE. Sino:
// Si M = LSB_PRIMERO, el nuevo elemento corriente es el primero. Devuelve TRUE
// Si M = LSB_SIGUIENTE, el nuevo elemento corriente es el siguiente al
// anterior. Si estaba en el ultimo elemento, devuelve FALSE, sino TRUE.
// Si M = LSB_ANTERIOR, devuelve FALSE.

int LSB_MoverCte(T_LSB *lsb, TMovimiento_LSB mov);

// LSB_BorrarCorriente
// Pre: lsb creada y no vacía.
// Post: Se eliminó el elemento corriente, El nuevo elemento es el siguiente o
// el anterior si el corriente era el último elemento.
int LSB_BorrarCte(T_LSB *lsb);

// LSB_Insertar
// Pre: lsb creada.
// Post: elem se agregó a la lista y es el actual elemento corriente.
// Si M=LSB_PRIMERO: se insertó como primero de la lista.
// Si M=LSB_SIGUIENTE: se insertó después del elemento corriente.
// Si M=LSB_ANTERIOR: se insertó antes del elemento corriente.
// Si pudo insertar el elemento devuelve TRUE, sino FALSE.
int LSB_Insertar(T_LSB *lsb, TMovimiento_LSB mov, void* elem);

// LSB_Busqueda
// Pre: lsb creada y función de comparación definida.
// Post: El elemento corriente es el elemento buscado, sino error
// Si M=LSB_PRIMERO: se busca desde primero de la lista.
// Si M=LSB_SIGUIENTE: se busca desde el elemento corriente.
// Si M=LSB_ANTERIOR: se busca desde el elemento anterior al corriente.
// Si pudo insertarlo el elemento devuelve LSB_ENCONTRADO
// , sino ERR_LSB_NO_EXISTE.
int LSB_Busqueda(T_LSB *lsb, void* elem, 
TMovimiento_LSB mov, int(*comparar)(void*, void*));

#endif
