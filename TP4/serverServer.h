/*
 * Server.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __SERVER_h__
#define __SERVER_h__

// Servidor: Clase que representa a un
// servidor. En el se conectan los clientes
// y hacen las consultas pertinentes.

// ATRIBUTOS:
//
// ESTA_ANDADANDO: Determina si el hilo de servidor
// sigue corriendo.
//
// CINE: Contiene los datos del cine.
//
// SOCKET: El socket del servidor.

#include "serverListaClienteSafe.h"

namespace Server {
  class Servidor: public Thread {
  private:
    bool estaAndando;
    CinemaSafe::CineSafe &cine;
    Connection::Socket socket;
  public:
    explicit Servidor(CinemaSafe::CineSafe &cine);
    bool ConectarServidor(char* puerto);
    virtual void run();
    virtual void stop();
  };
}


#endif
