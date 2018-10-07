/*
 * Cine.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __CINE_h__
#define __CINE_h__

#include <fstream>
#include <sstream>
#include "serverReserva.h"
#include "serverFuncion.h"

// Cine: Contiene los datos de un
// cine que son reservas y funciones.

// ATRIBUTOS:
//
// RESERVAS: Los datos de las reservas del usuario.
//
// FUNCIONES: Los datos de las funciones del cine.

namespace Cinema {
  class Cine {
  private:
    Reservation::Reserva reservas;
    Movie::Funcion funciones;
    void llenar(const std::string &linea, int cod);
    unsigned int llenarFuncion(const std::string &linea, int cod);
    void llenarReservas(const std::string &linea, 
			unsigned int posAnterior, int cod);
    int convertirAInt(const std::string &valor);
    void obtenerSiguientePosicion(unsigned int &posAnterior, 
				  unsigned int &posActual, const std::string &linea);
  public:
    void Consultar(int codCliente, std::ostringstream& oss);
    void cargar(char *dir);
    void Listado(std::ostringstream &oss);
    void Reservar(int codCliente, int codFuncion, 
		  int cantReservas, std::ostringstream& oss);
    void Serializar(char* dir);
  };
}


#endif
