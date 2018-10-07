/*
 * TDA_Paquete.c 
 *
 *  Created on: 2/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#include "TDA_Paquete.h"


// FUNCIONAMIENTO TDA_PAQ_comparar_nPaquete:
// Compara dos elementos de tipo ITI por sus
// número de paquete.

int TDA_PAQ_comparar_nPaquete(void* num1, void* num2) {
  if ((*(TDA_PAQ**)(num1))->nPaquete < (*(TDA_PAQ**)(num2))->nPaquete) 
    return TDA_PAQ_MENOR;
  else if ((*(TDA_PAQ**)(num1))->nPaquete > (*(TDA_PAQ**)(num2))->nPaquete) 
    return TDA_PAQ_MAYOR;
  else return TDA_PAQ_IGUAL;
}

// FUNCIONAMIENTO TDA_PAQ_Get_nPaquete:
// Devuelve el número de paquete.

unsigned int TDA_PAQ_Get_nPaquete(TDA_PAQ paq) {
  return (paq.nPaquete);
}

// FUNCIONAMIENTO TDA_PAQ_Get_Ubicacion:
// Devuelve la ubicación del paquete.

void TDA_PAQ_Get_Ubicacion(TDA_PAQ paq, char** ubi) {
  *ubi = paq.ubicacion;
}

// FUNCIONAMIENTO TDA_PAQ_Get_Estado:
// Devuelve el estado del paquete.

T_ESTADO_PAQUETE TDA_PAQ_Get_Estado(TDA_PAQ paq) {
  return(paq.estado);
}

// FUNCIONAMIENTO TDA_PAQ_Set_Estado:
// Setea el estado del paquete.

void TDA_PAQ_Set_Estado(TDA_PAQ* paq, T_ESTADO_PAQUETE status) {
  paq->estado = status;
}

// FUNCIONAMIENTO TDA_PAQ_Set_Ubicacion:
// Setea la ubicación del paquete.

void TDA_PAQ_Set_Ubicacion(TDA_PAQ* paq, char* ubi) {
  paq->ubicacion = ubi;
}

// FUNCIONAMIENTO TDA_PAQ_Get_Contenido:
// Devuelve el contenido del paquete.

void TDA_PAQ_Get_Contenido(TDA_PAQ paq, char** cont) {
    *cont = paq.contenido;
}

// FUNCIONAMIENTO TDA_PAQ_Destruir:
// Destruye el TDA_PAQ liberando la memoria
// dinámica que posea.

void TDA_PAQ_Destruir(TDA_PAQ *paq) {
  free(paq->contenido);
  free(paq->ubicacion);
  paq->contenido = NULL;
  paq->ubicacion = NULL;
}

// FUNCIONAMIENTO TDA_PAQ_Get_Comparador:
// Devuelve la función de comparación de paquete.


comparator TDA_PAQ_Get_Comparador(TDA_PAQ paq) {
  return paq.func;
}

// FUNCIONAMIENTO TDA_PAQ_Crear:
// Crea un tipo paquete.

void TDA_PAQ_Crear(TDA_PAQ* paq, unsigned int cant_paq, 
char* ubi, T_ESTADO_PAQUETE status, char* cont) {
  paq->func = &TDA_PAQ_comparar_nPaquete;
  paq->nPaquete = cant_paq; 
  paq->ubicacion = ubi;
  paq->estado = status;
  paq->contenido = cont;
}
