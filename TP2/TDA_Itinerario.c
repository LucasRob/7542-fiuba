/*
 * TDA_Itinerario.c 
 *
 *  Created on: 2/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#include "TDA_Itinerario.h"



// FUNCIONAMIENTO TDA_ITI_comparar_nPaquete:
// Compara dos elementos de tipo ITI por sus
// número de paquete.

int TDA_ITI_comparar_nPaquete(void* num1, void* num2) {
  if ((*(TDA_ITI**)(num1))->nPaquete < (*(TDA_ITI**)(num2))->nPaquete) 
    return TDA_ITI_MENOR;
  else if ((*(TDA_ITI**)(num1))->nPaquete > (*(TDA_ITI**)(num2))->nPaquete) 
    return  TDA_ITI_MAYOR;
  else return TDA_ITI_IGUAL;
}

// FUNCIONAMIENTO TDA_ITI_Get_nPaquete:
// Devuelve el número de paquete.

unsigned int TDA_ITI_Get_nPaquete(TDA_ITI iti) {
  return (iti.nPaquete);
}

// FUNCIONAMIENTO TDA_ITI_Get_Ubicacion:
// Devuelve la ubicación del paquete.

void TDA_ITI_Get_Ubicacion(TDA_ITI iti, char** ubi) {
  *ubi = iti.ubicacion;
}

// FUNCIONAMIENTO TDA_ITI_Get_Fecha:
// Devuelve la fecha del paquete.

void TDA_ITI_Get_Fecha(TDA_ITI iti, char** fecha) {
  *fecha = iti.fecha;
}

// FUNCIONAMIENTO TDA_ITI_Get_Descripcion:
// Devuelve la descripción del paquete.

void TDA_ITI_Get_Descripcion(TDA_ITI iti, char** description) {
  *description = iti.descripcion;
}

// FUNCIONAMIENTO TDA_ITI_Destruir:
// Destruye el TDA_ITI liberando la memoria
// dinámica que posea.

void TDA_ITI_Destruir(TDA_ITI *iti) {
  free(iti->descripcion);
  free(iti->fecha);
  free(iti->ubicacion);
  iti->descripcion = NULL;
  iti->fecha = NULL;
  iti->ubicacion = NULL;
}

// FUNCIONAMIENTO TDA_ITI_Get_Comparador:
// Devuelve la función de comparación de itinerario.

comparator_itinerario TDA_ITI_Get_Comparador(TDA_ITI iti) {
  return iti.func;
}

// FUNCIONAMIENTO TDA_ITI_Crear:
// Crea un tipo itinerario.

void TDA_ITI_Crear(TDA_ITI* iti, unsigned int cant_paq, 
char* ubi, char* fecha, char* desc) {
  iti->func = &TDA_ITI_comparar_nPaquete;
  iti->nPaquete = cant_paq; 
  iti->ubicacion = ubi;
  iti->fecha = fecha;
  iti->descripcion = desc;
}
