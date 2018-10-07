/*
 * TDA_Pedido.c 
 *
 *  Created on: 2/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#include "TDA_Pedido.h"


// FUNCIONAMIENTO TDA_PEDIDO_comparar_nPaquete:
// Compara dos elementos de tipo PEDIDO por sus
// número de paquete.

int TDA_PEDIDO_comparar_nPedido(void* num1, void* num2) {
  if ((*(TDA_PEDIDO**)(num1))->nPedido < (*(TDA_PEDIDO**)(num2))->nPedido) 
    return TDA_PEDIDO_MENOR;
  else if ((*(TDA_PEDIDO**)(num1))->nPedido > (*(TDA_PEDIDO**)(num2))->nPedido) 
    return TDA_PEDIDO_MAYOR;
  else return TDA_PEDIDO_IGUAL;
}

// FUNCIONAMIENTO TDA_PEDIDO_Get_nPedido:
// Devuelve el número de pedido.

unsigned int TDA_PEDIDO_Get_nPedido(TDA_PEDIDO pedido) {
  return (pedido.nPedido);
}

// FUNCIONAMIENTO TDA_PEDIDO_Get_Cant_Paq:
// Devuelve la cantidad de paquetes.

unsigned int TDA_PEDIDO_Get_Cant_Paq(TDA_PEDIDO pedido) {
  return (pedido.cant_paq);
}

// FUNCIONAMIENTO TDA_PEDIDO_Get_Paquetes:
// Devuelve la lista de paquetes.

void TDA_PEDIDO_Get_Paquetes(TDA_PEDIDO pedido, T_LSB** packs) {
  *packs = pedido.paquetes;
}

// FUNCIONAMIENTO TDA_PEDIDO_Get_Descripcion:
// Devuelve la descripción del paquete.

void TDA_PEDIDO_Get_Descripcion(TDA_PEDIDO pedido, char** desc) {
  *desc = pedido.descripcion;
}

// FUNCIONAMIENTO TDA_PEDIDO_Get_Itinerarios:
// Devuelve la lista de itinerarios.

void TDA_PEDIDO_Get_Itinerarios(TDA_PEDIDO pedido, T_LSB** itineraries) {
  *itineraries = pedido.itinerarios;
}

// FUNCIONAMIENTO TDA_PEDIDO_Get_Comparador:
// Devuelve la función de comparación de itinerario.

comparator_pedido TDA_PEDIDO_Get_Comparador(TDA_PEDIDO pedido) {
  return pedido.func;
}

// FUNCIONAMIENTO TDA_PEDIDO_Crear:
// Crea un tipo pedido.

void TDA_PEDIDO_Crear(TDA_PEDIDO* pedido, unsigned int cant_pedido, 
char* desc, unsigned cant_paq, T_LSB* packs, T_LSB* itineraries) {
  pedido->func = &TDA_PEDIDO_comparar_nPedido;
  pedido->nPedido = cant_pedido; 
  pedido->cant_paq = cant_paq; 
  pedido->paquetes = packs;
  pedido->itinerarios = itineraries;
  pedido->descripcion = desc;
}

// FUNCIONAMIENTO TDA_PEDIDO_Destruir:
// Destruye el TDA_PEDIDO liberando la memoria
// dinámica que posea.

void TDA_PEDIDO_Destruir(TDA_PEDIDO *pedido) {
  free(pedido->descripcion);
  free(pedido->paquetes);
  free(pedido->itinerarios);
  pedido->descripcion = NULL;
  pedido->paquetes = NULL;
  pedido->itinerarios = NULL;
}
