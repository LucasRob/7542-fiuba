/*
 * Reserva.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __RESERVA_h__
#define __RESERVA_h__

#include <map>
#include "serverDatoUsuario.h"

// Reserva: Contiene todos los datos de las
// reservas del usuario.

// ATRIBUTOS:
//
// MAPA: Mapa que contiene las reservas
// del usuario.
//
// I_MAPA_USUARIO: El iterador para mapa de reservas.

namespace Reservation {
  typedef std::map <int, UserData::ListaDatosUsuario>::iterator i_mapaUsuario;
  class Reserva {
  private:
    std::map <int, UserData::ListaDatosUsuario> mapa;
  public:
    void SetElem(int codCliente, int codFuncion, int cantReservas); 
    bool MostrarCodigo(int cantReservas, int& codFuncion);
    bool ExisteCod(int codCliente);
    void VincularIteradores(int codCliente,  UserData::i_Usuario &inicio, 
			    UserData::i_Usuario &fin);
    void SerializarElemento(int codFuncion, std::ofstream &arch);
  };
}

#endif
