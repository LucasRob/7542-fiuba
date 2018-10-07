#ifndef __LISTACLIENTE_h__
#define __LISTACLIENTE_h__

#include "serverCliente.h"
#include <list>

// ListaCliente: Contiene las lista
// de clientes que realizan operaciones
// con el servidor.

// ATRIBUTOS:
//
// LISTA: La lista de los clientes.
//
// I_CLIENTES: El iterador de la lista de clientes.

typedef std::list<Client::Cliente*>::iterator i_clientes;
namespace ClientList {
  class ListaCliente {
  private:
    std::list<Client::Cliente*> lista;
  public:
    void SetElem(Client::Cliente *cliente);
    void verificarConexiones(void);
    void cerrarConexiones(void);
    ~ListaCliente(void);
  };
}


#endif
