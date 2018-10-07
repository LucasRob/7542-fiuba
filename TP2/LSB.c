/*
 * LSB.c Lista Simple con Busqueda
 *
 *  Created on: 1/1/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#include "LSB.h"


// LSB_Crear
// Pre: lsb no fue creada.
// Post: lsb creada y vacía 

void LSB_Crear(T_LSB *lsb, int tdato) {
  lsb->cte = NULL;
  lsb->prim = NULL;
  lsb->tamdato = tdato;
}

// LSB_Vaciar
// Pre: lsb creada.
// Post: lsb vacía.

void LSB_Vaciar(T_LSB *lsb) {
  TNodo_LSB *pNodo, *siguiente;
  for (pNodo = lsb->prim;(pNodo);pNodo = siguiente) {
    siguiente = pNodo->sig;
    free(pNodo->elem);
    free(pNodo);
  }
  lsb->prim = lsb->cte = NULL;
}

// LSB_Vacia
// Pre: lsb creada.
// Post: Si lsb tiene elementos devuelve FALSE sino TRUE.

int LSB_Vacia(T_LSB lsb) {
  return (lsb.prim == NULL);
}

// LSB_Elemcte
// Pre: lsb creada y no vacía.
// Post: Se devuelve en elem elemento corriente de la lista.

void LSB_ElemCte(T_LSB lsb, void *elem) {
  memcpy(elem, lsb.cte->elem, lsb.tamdato);
}

// LSB_Modifcte
// Pre: lsb creada y no vacía.
// Post: El contenido del elemento actual quedo actualizado con elem. 

void LSB_ModifCte(T_LSB *lsb, void* elem) {
  memcpy(lsb->cte->elem, elem, lsb->tamdato);
}

// LSB_Movercte
// Pre: lsb creada y no vacía.
// Post: Si lsb esta vacía, devuelve ERR_LSB_NO_EXISTE. Sino:
// Si mov = LSB_PRIMERO, el nuevo elemento corriente es el primero. 
// Devuelve LSB_MOVIDO.
// Si mov = LSB_SIGUIENTE, el nuevo elemento corriente es 
// el siguiente al anterior. Si estaba en el ultimo elemento, 
// devuelve ERR_LSB_NO_EXISTE, sino LSB_MOVIDO.
// Si mov = LSB_ANTERIOR, devuelve ERR_LSB_NO_EXISTE. 

int LSB_MoverCte(T_LSB *lsb, TMovimiento_LSB mov) {
  if (lsb->prim == NULL)
    return ERR_LSB_NO_EXISTE;
  switch (mov) {
  case LSB_PRIMERO:
    lsb->cte = lsb->prim;
    break;
  case LSB_SIGUIENTE:
    if (lsb->cte->sig == NULL)
      return ERR_LSB_NO_EXISTE;
    else
      lsb->cte = lsb->cte->sig;
    break;
  case LSB_ANTERIOR:
    return ERR_LSB_NO_EXISTE;
  }
  return LSB_MOVIDO;
}

// LSB_Borrarcte
// Pre: lsb creada y no vacía.
// Post: Se elimino el elemento corriente, El nuevo elemento es el siguiente o
// el anterior si el corriente era el ultimo elemento.

int LSB_BorrarCte(T_LSB *lsb) {
  TNodo_LSB *PNodo = lsb->cte;
  if (lsb->cte == NULL)
    return ERR_LSB_NO_EXISTE;
  else if (lsb->cte == lsb->prim) {
    lsb->prim = lsb->cte->sig;
    lsb->cte = lsb->prim;
  } else {
    TNodo_LSB *PAux = lsb->prim;
    while (PAux->sig != lsb->cte)
      PAux = PAux->sig;
    PAux->sig = lsb->cte->sig;
    if (PAux->sig)  // Si no es el último
      lsb->cte = PAux->sig;
    else
      lsb->cte = PAux;  // Si es el último queda 
    // en el anterior al borrado
  }
  free(PNodo->elem);
  free(PNodo);
  return LSB_BORRADO;
}

// LSB_Insertar
// Pre: lsb creada.
// Post: elem se agrego a la lista y es el actual elemento corriente.
// Si mov=LSB_PRIMERO: Se insertó como primero de la lista.
// Si mov=LSB_SIGUIENTE: Se insertó después del elemento corriente.
// Si mov=LSB_ANTERIOR: Se insertó antes del elemento corriente.
// Si pudo insertar el elemento devuelve LSB_INSERTADO, sino ERR_LSB_NO_MEMORIA.

int LSB_Insertar(T_LSB *lsb, TMovimiento_LSB mov, void* elem) {
  TNodo_LSB *pNodo = (TNodo_LSB*) malloc(sizeof(TNodo_LSB));
  if (!pNodo) 
    return ERR_LSB_NO_MEMORIA;  // No hay memoria disponible
  else if ((lsb->prim == NULL) || (mov == LSB_PRIMERO) 
|| ((mov == LSB_ANTERIOR) && (lsb->prim == lsb->cte))) { 
    // Si esta vacía o hay que insertar en el primero o
    // hay que insertar en el anterior y el actual es el primero */
    pNodo->sig = lsb->prim;
    lsb->prim = lsb->cte = pNodo;
  } else {
    if (mov == LSB_SIGUIENTE) {
      pNodo->sig = lsb->cte->sig;
      lsb->cte->sig = pNodo;
    } else {  // LSB_ANTERIOR 
      TNodo_LSB *pAux = lsb->prim;
      while (pAux->sig != lsb->cte)
	pAux = pAux->sig;
      pAux->sig = pNodo;
      pNodo->sig = lsb->cte;
    }
  }
  pNodo->elem = malloc(lsb->tamdato);
  memcpy(pNodo->elem, elem, lsb->tamdato);
  lsb->cte = pNodo;
  return LSB_INSERTADO; 
}

// LSB_Busqueda
// Pre: lsb creada y función de comparación definida.
// Post: El elemento corriente es el elemento buscado, sino error
// Si M=LSB_PRIMERO: se busca desde primero de la lista.
// Si M=LSB_SIGUIENTE: se busca desde el elemento corriente.
// Si M=LSB_ANTERIOR: se busca desde el elemento anterior al corriente.
// Si pudo insertarlo el elemento devuelve LSB_ENCONTRADO, 
// sino ERR_LSB_NO_EXISTE.

int LSB_Busqueda(T_LSB *lsb, void* elem, TMovimiento_LSB mov, 
int(*comparar)(void*, void*)) {
  int res = 1, error = 0;
  void* elem2 = malloc(sizeof(lsb->tamdato));

  error = LSB_MoverCte(lsb, mov);
  while ((error == LSB_MOVIDO) && (res != LSB_IGUAL)) {  // Si
    // se pudo mover o el elemento no lo encontró
    LSB_ElemCte(*lsb, elem2);
    res = comparar(elem, elem2);
    if (res != LSB_IGUAL) 
      error = LSB_MoverCte(lsb, LSB_SIGUIENTE);
  }
  free(elem2);
  if (res ==  LSB_IGUAL)
    return LSB_ENCONTRADO;
  else return ERR_LSB_NO_EXISTE;
}
