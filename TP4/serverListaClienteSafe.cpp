#include "serverListaClienteSafe.h"

void ClientListSafe::ListaClienteSafe::
SetElem(Client::Cliente *cliente) {
  Security::Lock l(mutex);
  this->lista.SetElem(cliente);
}

void ClientListSafe::ListaClienteSafe::verificarConexiones(void) {
  Security::Lock l(mutex);
  this->lista.verificarConexiones();
}

void ClientListSafe::ListaClienteSafe::cerrarConexiones(void) {
  Security::Lock l(mutex);
  this->lista.cerrarConexiones();
}

ClientListSafe::ListaClienteSafe::~ListaClienteSafe(void) {
}

