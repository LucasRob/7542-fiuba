/*
 * Funcion.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __FUNCION_h__
#define __FUNCION_h__

#include <map>
#include "serverDatoFuncion.h"
#include <iomanip>

// Función: Contiene todos los datos de las
// funciones del cine.

// ATRIBUTOS:
//
// FUNCION: Mapa que contiene las funciones
// del cine.
//
// I_FUNCION: El iterador de función.

namespace Movie {
typedef std::map<int, MovieData::DatoFuncion>::iterator i_funcion;
  class Funcion {
  private:
    std::map <int, MovieData::DatoFuncion> funcion;
  public:
    void SetElem(const std::string nombrePelicula, 
		 const std::string fecha, int reservasDisponibles, int cod); 
    i_funcion GetPrincipio(void) const;
    i_funcion GetFinal(void) const;
    int GetReservasDisponibles(int codFuncion);
    bool Reservar(int codFuncion, int cantReservas);
    void MostrarValores(int codFuncion, std::ostringstream& oss);
    void VincularIteradores(i_funcion &inicio, i_funcion &N);
    friend std::ostringstream& operator<<(std::ostringstream& oss, 
					  Funcion &funciones);
  };
  std::ostringstream& operator<<(std::ostringstream& oss, Funcion &funciones);
}

#endif
