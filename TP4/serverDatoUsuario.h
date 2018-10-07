/*
 * DatoUsuario.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __DATO_USUARIO_h__
#define __DATO_USUARIO_h__

#include <iostream>
#include <map>
#include <list>
#include <sstream>
#include <fstream>

// DatoUsuario: Contiene los datos de una
// reserva del usuario.

// ATRIBUTOS:
//
// COD_FUNCIÓN: El código de la función.
//
// CANT_RESERVAS: Cantidad de reservas
// del usuario en una función determinada.

namespace UserData {
  class DatoUsuario {
  private:
    int codFuncion;
    int cantReservas;
  public:
    DatoUsuario(int, int);
    bool operator == (const DatoUsuario &OtroDato);
    bool operator != (const DatoUsuario &OtroDato);    
    bool operator < (const DatoUsuario &OtroDato);    
    int GetCodFuncion(void) const;
    int GetCantReservas(void) const;
    void ActualizarReservas(const DatoUsuario &OtroDato);
  };

// ListaDatoUsuario: Contiene una lista
// con los datos del usuario en materia
// de reservas.

// ATRIBUTOS:
//
// LISTA: La lista de dato usuario.
//

// i_Usuario: Iterador de lista de usuario.

typedef std::list<DatoUsuario>::iterator i_Usuario;

  class ListaDatosUsuario {
  private:
    std::list<DatoUsuario> lista;
    void ActualizarLista(DatoUsuario &dato);
  public:
    void SetElem(int cod, int cant);
    void VincularIteradores(i_Usuario &inicio, i_Usuario &fin);
    void Serializar(int codCliente, int codFuncion, std::ofstream &arch);
  };
}

#endif
