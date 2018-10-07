/*
 * DatoFuncion.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __DATO_FUNCION_h__
#define __DATO_FUNCION_h__

#include <string>
#include <iostream>
#include <sstream>
#include "serverCine_Mensajes.h"
#include <fstream>

// DatoFunción: Contiene los datos de una
// función de cine.

// ATRIBUTOS:
//
// NOMBRE_PELICULA: Nombre de la película.
//
// FECHA: fecha de la función.
//
// RESERVAS_DISPONIBLES: Cantidad de 
// localidades disponibles.

namespace MovieData {
  class DatoFuncion {
  private:
    std::string nombrePelicula;
    std::string fecha;
    int reservasDisponibles;
  public:
    DatoFuncion(const std::string nombrePelicula, 
		const std::string fecha, int reservasDisponibles);
    DatoFuncion(void) {};
    int GetReservasDisponibles(void);
    bool Reservar(int cantReservas);
    void MostrarValores(std::ostringstream& oss);
    void Serializar(std::ofstream& arch);
    friend std::ostringstream& operator<<(std::ostringstream& oss, 
					  DatoFuncion &funcion);
  };
  std::ostringstream& operator<<(std::ostringstream& oss, DatoFuncion &funcion);
}

#endif
