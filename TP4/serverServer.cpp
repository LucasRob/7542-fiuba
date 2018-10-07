#include "serverServer.h"

// FUNCIONAMIENTO SERVIDOR:
// Crea el servidor.

Server::Servidor::Servidor(CinemaSafe::CineSafe &cine):cine(cine) {
  this->estaAndando = true;
}

// FUNCIONAMIENTO CONECTAR_SERVIDOR:
// Conecta el servidor y devuelve si pudo o no.

bool Server::Servidor::ConectarServidor(char* puerto) {
  int port = atoi(puerto);
  return (this->socket.ConectarModoServidor(port));
}

// FUNCIONAMIENTO RUN:
// El método que ejecuta el hilo de servidor.
// Consiste en escuchar y aceptar conexiones de 
// clientes y ejecutar sus hilos. A medida que 
// se van ejecutando se verifica en la lista de 
// si siguen sus hilos en ejecución o no y dependiendo.
// del caso se cierran o no. En caso de terminar
// se cierran los hilos abiertos.

void Server::Servidor::run() {
  ClientListSafe::ListaClienteSafe lista;
  this->socket.Escuchar();
  while (this->estaAndando == true) {
    lista.verificarConexiones();
    Connection::Socket socketIO;
    if (this->socket.Aceptar(socketIO) == true) {
      Client::Cliente *cliente = new Client::Cliente(this->cine, socketIO);
      lista.SetElem(cliente);
      cliente->start();
    } 
  } 
  lista.cerrarConexiones();
}

// FUNCIONAMIENTO STOP:
// Detiene la ejecución del servidor.

void Server::Servidor::stop() {
  this->estaAndando = false;
  this->socket.Close();
}
