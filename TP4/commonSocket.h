/*
 * CommonSocket.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __COMMONSOCKET_h__
#define __COMMONSOCKET_h__

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

// MAXDATASIZE: Cantidad Máxima de datos a transferir.
// MAXCONNECTIONS: Cantidad Máxima de conexiones.

#define MAXDATASIZE 200 
#define MAXCONNECTIONS 5

// Socket: Clase que representa a un socket.
// Contiene todas las variables para poder
// usarlo tanto en modo servidor como en
//  modo cliente.

namespace Connection {
  class Socket {
  private:
    int sock;
    unsigned int clilen;
    struct hostent *he;
    struct sockaddr_in their_addr;
    struct sockaddr_in cli_addr, serv_addr;
    void GetHostByName(const char* adress);
    void GenerarSocket(void);
    void Connect(int port);
    void Crear(void);
    void Bind(int port);
    Socket& operator =(const Socket &s);
    Socket(const Socket& s);
  public:
    Socket(void);
    void Recibir(std::string& mensaje);
    void Enviar(std::string& mensaje);
    void Close(void);
    void Escuchar(void);
    bool Aceptar(Connection::Socket& socketIO);
    bool ConectarModoServidor(int port);
    bool ConectarModoCliente(const std::string &dir, int port);
    void setSocket(int newSock);
  };
}
  

#endif
