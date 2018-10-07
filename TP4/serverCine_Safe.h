/*
 * CineSafe.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __CINESAFE_h__
#define __CINESAFE_h__

#include "serverCine.h"
#include "serverMutex.h"

// CineSafe: Versión thread
// safe de cine. Las primitivas
// son las mismas que ListaCliente.

// ATRIBUTOS:
//
// MUTEX: Objeto que permite bloquear
// el uso de más de un hilo de un recurso, 
// si hay uno ya usándolo.
//

namespace CinemaSafe {
  class CineSafe {
  private:
    Cinema::Cine cine;
    Security::Mutex mutex;
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
