#include "serverListaCliente.h"    

// FUNCIONAMIENTO SET_ELEM:
// Agrega un elemento a la lista.

void ClientList::ListaCliente::SetElem
(Client::Cliente *cliente) {
  this->lista.push_front(cliente);
}

// FUNCIONAMIENTO VERIFICAR_CONEXIONES:
// Verifica si hay clientes conectarlos.
// en caso negativo, cierra su conexión
// con el servidor y lo borra de la lista
// (por eso se usa erase y no clear que borra
// toda la lista).

void ClientList::ListaCliente::verificarConexiones(void) {
  i_clientes i;;
  
  if (!this->lista.empty()) {
    for (i = this->lista.begin(); i != this->lista.end(); ++i) {
      bool estaAndando = (*i)->VerificarProceso();
      if (estaAndando == false) {
	(*i)->stop();
	(*i)->join();
	delete(*i);
	this->lista.erase(i--); 
      }
    }
  }
}

// FUNCIONAMIENTO VERIFICAR_CONEXIONES:
// Cierra todas las conexiones abiertas.

void ClientList::ListaCliente::cerrarConexiones(void) {
  i_clientes i;;
  
  if (!this->lista.empty()) {
    for (i = this->lista.begin(); i != this->lista.end(); ++i) {
	(*i)->stop();
	(*i)->join();
	delete(*i);
	this->lista.erase(i--); 
    }
  }
}


ClientList::ListaCliente::~ListaCliente(void) {
}
