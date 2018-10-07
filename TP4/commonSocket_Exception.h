#include <iostream>
#include <exception>

// FUNCIONAMIENTO RECV_EXCEPTION
// Genera esa excepción cuando se produce un error
// en recibir.

class RecvException: public std::exception {
  virtual const char* what() const throw() {
    return "Error Recibir";
  }
}recvEx;

// FUNCIONAMIENTO SEND_EXCEPTION
// Genera esa excepción cuando se produce un error
// en enviar.

class SendException: public std::exception {
  virtual const char* what() const throw() {
    return "Error Enviar";
  }
}sendEx;

// FUNCIONAMIENTO GET_HOST_EXCEPTION
// Genera esa excepción cuando se produce un error
// en GetHostByName.
 
class GetHostException: public std::exception {
  virtual const char* what() const throw() {
    return "Error Get Host By Name";
  }
}gethostEx;

// FUNCIONAMIENTO SOCKET_EXCEPTION
// Genera esa excepción cuando se produce un error
// en Generar Socket.

class SocketException: public std::exception {
  virtual const char* what() const throw() {
    return "Error Socket";
  }
}socketEx;

// FUNCIONAMIENTO CONNECT_EXCEPTION
// Genera esa excepción cuando se produce un error
// en connect.

class ConnectException: public std::exception {
  virtual const char* what() const throw() {
    return "Error Connect";
  }
}connectEx;

// FUNCIONAMIENTO BIND
// Genera esa excepción cuando se produce un error
// en bind.

class BindException: public std::exception {
  virtual const char* what() const throw() {
    return "Error Bind";
  }
}bindEx;

// FUNCIONAMIENTO ACCEPT
// Genera esa excepción cuando se produce un error
// en accept.

class AcceptException: public std::exception {
  virtual const char* what() const throw() {
    return "Error Accept";
  }
}acceptEx;
