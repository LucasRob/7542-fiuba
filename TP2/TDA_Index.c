/*
 * TDA_Index.c 
 *
 *  Created on: 5/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#include "TDA_Index.h"



// FUNCIONAMIENTO TDA_INDEX_comparar_nPaquete:
// Compara dos elementos de tipo INDEX por sus
// número de paquete.

int TDA_INDEX_comparar_nPedido(void* index1, void* index2) {
  if ((*(TDA_INDEX**)(index1))->nPedido 
< (*(TDA_INDEX**)(index2))->nPedido) 
    return TDA_INDEX_MENOR;
  else if ((*(TDA_INDEX**)(index1))->nPedido > 
(*(TDA_INDEX**)(index2))->nPedido) 
    return  TDA_INDEX_MAYOR;
  else return TDA_INDEX_IGUAL;
}

// FUNCIONAMIENTO TDA_INDEX_Get_Usuario:
// Devuelve el usuario.

void TDA_INDEX_Get_Usuario(TDA_INDEX index, char** usuario) {
  *usuario = index.usuario;
}

// FUNCIONAMIENTO TDA_INDEX_Get_nPedido:
// Devuelve el número de pedido.

unsigned int TDA_INDEX_Get_nPedido(TDA_INDEX index) {
  return (index.nPedido);
}

// FUNCIONAMIENTO TDA_INDEX_Get_Comparador:
// Devuelve la función de comparación de index.

comparator_index TDA_INDEX_Get_Comparador(TDA_INDEX index) {
  return index.func;
}

// FUNCIONAMIENTO TDA_INDEX_Crear:
// Crea un tipo index.

void TDA_INDEX_Crear(TDA_INDEX* index, char* usuario, 
unsigned int cant_pedido)  {
  index->func = &TDA_INDEX_comparar_nPedido;
  index->usuario = usuario;
  index->nPedido = cant_pedido; 
}

// FUNCIONAMIENTO TDA_INDEX_Destruir:
// Destruye el TDA_INDEX liberando la memoria
// dinámica que posea.

void TDA_INDEX_Destruir(TDA_INDEX *index) {
  free(index->usuario);
  index->usuario = NULL;
}

