/*
 * Cliente.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __CLIENTE_h__
#define __CLIENTE_h__

#include "serverCine_Safe.h"
#include "serverThread.h"
#include "commonSocket.h"
#include <sstream>

// Cliente: Clase que representa a un
// cliente. Su función es realizar consultas
// al servidor.

// ATRIBUTOS:
//
// ESTA_ANDADANDO: Determina si el hilo de cliente
// sigue corriendo.
//
// CINE: Contiene los datos del cine.
//
// SOCKET: El socket del cliente.

namespace Client {
  class Cliente: public Thread {
  private:
    CinemaSafe::CineSafe &cine;
    Connection::Socket &socket;
    bool estaAndando;
    void Reservar(std::string& mensaje);
    void Listado(std::string& mensaje);
    void Consultar(std::string& mensaje);
    void Salir(std::string& mensaje);
    void Error(std::string& mensaje);
  public:
    explicit Cliente(CinemaSafe::CineSafe &cine, Connection::Socket &socket);
    ~Cliente(void);
    virtual void run();
    virtual void stop();
    bool VerificarProceso(void);
  };
}


#endif
