#ifndef __LISTACLIENTESAFE_h__
#define __LISTACLIENTESAFE_h__

#include "serverListaCliente.h"
#include "serverMutex.h"

// ListaClienteSafe: Versión thread
// safe de lista cliente. Las primitivas
// son las mismas que ListaCliente.

// ATRIBUTOS:
//
// MUTEX: Objeto que permite bloquear
// el uso de más de un hilo de un recurso, 
// si hay uno ya usándolo.
//

namespace ClientListSafe {
  class ListaClienteSafe {
  private:
    ClientList::ListaCliente lista;
    Security::Mutex mutex;
  public:
    void SetElem(Client::Cliente *cliente);
    void verificarConexiones(void);
    ~ListaClienteSafe(void);
    void cerrarConexiones(void);
  };
}


#endif

