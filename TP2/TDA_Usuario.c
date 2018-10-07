/*
 * TDA_Usuario.c 
 *
 *  Created on: 4/4/2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#include "TDA_Usuario.h"


// FUNCIONAMIENTO TDA_USU_comparar_usuario:
// Compara dos elementos de tipo USU por sus
// número de paquete.

int TDA_USU_comparar_usuario(void* usu1, void* usu2) {
  if ((strcmp(((*(TDA_USU**)(usu1))->usuario), 
((*(TDA_USU**)(usu2))->usuario))) < 0)
    return TDA_USU_MENOR;
  else if ((strcmp(((*(TDA_USU**)(usu1))->usuario), 
((*(TDA_USU**)(usu2))->usuario))) > 0)
    return  TDA_USU_MAYOR;
  else return TDA_USU_IGUAL;
}

// FUNCIONAMIENTO TDA_USU_Get_Usuario:
// Devuelve el usuario.

void TDA_USU_Get_Usuario(TDA_USU usu, char** usuario) {
  *usuario = usu.usuario;
}

// FUNCIONAMIENTO TDA_USU_Get_Apellido:
// Devuelve el apellido.

void TDA_USU_Get_Apellido(TDA_USU usu, char** apellido) {
  *apellido = usu.apellido;
}

// FUNCIONAMIENTO TDA_USU_Get_Nombres:
// Devuelve los nombres.

void TDA_USU_Get_Nombres(TDA_USU usu, char** nombres) {
  *nombres = usu.nombres;
}

// FUNCIONAMIENTO TDA_USU_Destruir:
// Destruye el TDA_USU liberando la memoria
// dinámica que posea.

void TDA_USU_Destruir(TDA_USU *usu) {
  free(usu->usuario);
  free(usu->apellido);
  free(usu->nombres);
  free(usu->pedidos);
  usu->usuario = NULL;
  usu->apellido = NULL;
  usu->nombres = NULL;
  usu->pedidos = NULL;
}

// FUNCIONAMIENTO TDA_USU_Get_Pedidos:
// Devuelve la lista de pedidos.

void TDA_USU_Get_Pedidos(TDA_USU usu, T_LSB** pedidos) {
  *pedidos = usu.pedidos;
}

// FUNCIONAMIENTO TDA_USU_Get_Comparador:
// Devuelve la función de comparación de usuario.

comparator_usuario TDA_USU_Get_Comparador(TDA_USU usu) {
  return usu.func;
}

// FUNCIONAMIENTO TDA_USU_Crear:
// Crea un tipo usuario.

void TDA_USU_Crear(TDA_USU* usu, char* usuario, 
char* apellido, char* nombres, T_LSB* pedidos) {
  usu->func = &TDA_USU_comparar_usuario;
  usu->usuario = usuario;
  usu->apellido = apellido;
  usu->nombres = nombres;
  usu->pedidos = pedidos;
}
