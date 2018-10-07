#include "commonSocket.h"
#include "commonSocket_Exception.h"

// FUNCIONAMIENTO RECIBIR:
// Método que permite recibir bytes desde un socket.
// La condición de funcionamiento normal es que
// se haya establecido una conexión entre dos sockets.
// Sino el método devuelve una excepción.

Connection::Socket::Socket(void) {}

Connection::Socket::Socket(const Socket& s) {}

void Connection::Socket::Recibir(std::string& mensaje) {
  int numbytes = 0;
  int len = 1;
  char *buf = new char[MAXDATASIZE];
  strcpy(buf, "");
  char* p = buf;
  while (((p - buf) < MAXDATASIZE) && (buf[len - 1] != '\n')) {
    numbytes = recv(this->sock, p, MAXDATASIZE - (p - buf), 0);
    if (numbytes <= 0) { 
      delete [] buf;
      throw recvEx;
    }
    len = strlen(p);
    p += numbytes;
  }
  mensaje = buf;
  delete [] buf;
}

// FUNCIONAMIENTO ENVIAR:
// Envía datos a otro socket. Previamente
// se debe haber establecido una conexión entre
// ambos sokets. Sino devuelve excepción.

void Connection::Socket::Enviar(std::string& mensaje) {
  char *buf = new char[MAXDATASIZE];  
  char *p = buf;
  strcpy(buf, mensaje.c_str());
  int len = strlen(buf) + 1;
  while ((p - buf) < len) {
    int bytecount = send(this->sock, p, len - (p - buf), 0);
    if (bytecount  <= 0) {
      delete [] buf;
      throw sendEx;
    }
    p += bytecount;
  }
  delete [] buf;
}

// FUNCIONAMIENTO CLOSE:
// Cierra el socket.

void Connection::Socket::Close(void) {
  shutdown(this->sock, SHUT_RDWR);
  close(this->sock);
}

// FUNCIONAMIENTO CONECTAR_MODO_CLIENTE:
// Conecta el socket en modo cliente. 
// Si ocurre algún error en el proceso devuelve
// excepción.

bool Connection::Socket::ConectarModoCliente(const std::string &dir, int port) {
  try {
    this->GetHostByName(dir.c_str());
    this->GenerarSocket();
    this->Connect(port);
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}

// FUNCIONAMIENTO CONECTAR_MODO_SERVIDOR:
// Conecta el socket en modo servidor. 
// Si ocurre algún error en el proceso devuelve
// excepción.

bool Connection::Socket::ConectarModoServidor(int port) {
  try {
    this->GenerarSocket();
    this->Bind(port);
  } catch(const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}

// FUNCIONAMIENTO GET_HOST_BY_NAME
// Obtiene información sobre la dirección de ip
// En caso de error devuelve excepción

void Connection::Socket::GetHostByName(const char* adress) {
  if ((this->he = gethostbyname(adress)) == NULL) 
    throw gethostEx;
}

// FUNCIONAMIENTO SOCKET
// Genera un socket y lo devuelve en sock.
// En caso de error devuelve excepción.

void Connection::Socket::GenerarSocket(void) {
  std::cout << "Creando socket...n" << std::endl;
  if ((this->sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    throw socketEx;
}

// FUNCIONAMIENTO CONNECT
// Conecta el socket al servidor. En 
// caso de error devuelve excepción.

void Connection::Socket::Connect(int port) {
  their_addr.sin_family = AF_INET; 
  their_addr.sin_port = htons(port);
  their_addr.sin_addr = *((struct in_addr *)he->h_addr);
  memset(&(their_addr.sin_zero), 8, sizeof(int)); 
  if (connect(this->sock, (struct sockaddr *)
	      &(this->their_addr), sizeof(struct sockaddr)) == -1) 
    throw connectEx;
}

// FUNCIONAMIENTO BIND
// Vincula una dirección con el socket. En caso de
// error devuelve excepción.

void Connection::Socket::Bind(int port) {
  memset((char *)&(this->serv_addr), 0, sizeof(this->serv_addr));
  this->serv_addr.sin_family = AF_INET; 
  this->serv_addr.sin_port = htons(port);
  this->serv_addr.sin_addr.s_addr = INADDR_ANY;
  std::cout << "Bindeando...n" << std::endl;
  if (bind(this->sock,
	   (struct sockaddr*)&(this->serv_addr),
	   (socklen_t)sizeof(struct sockaddr)) < 0 )
    throw bindEx;
}

// FUNCIONAMIENTO ESCUCHAR
// Permite al socket aceptar conexiones. La 
// cantidad es establecida por parámetro.

void Connection::Socket::Escuchar(void) {
  std::cout << "Escuchando...n" << std::endl;
  listen(this->sock, MAXCONNECTIONS); 
  this->clilen = (socklen_t)sizeof(this->cli_addr);
}

// FUNCIONAMIENTO SET_SOCKET
// Setea un socket a una variable. Se utiliza
// cuando se instancia un objeto de tipo Cliente.
// Al crearlo se le pasa una variable que representa
// a un socket, que es el resultado de hacer accept.
// Con este puede recibir y enviar datos de otro socket.

void Connection::Socket::setSocket(int newSock) {
  this->sock = newSock;
}

// FUNCIONAMIENTO SET_SOCKET
// Acepta una conexión y devuelve un socket
// vinculado a esa conexión. En caso contrario
// devuelve false.

bool Connection::Socket::Aceptar(Connection::Socket& socketIO) {
  int newsock = 0;
  std::cout << "Aceptando...n" << std::endl;
  newsock = accept(this->sock, (struct sockaddr *)
		   &(this->cli_addr), &(this->clilen));
  if (newsock < 0) {
    return false;
  } else {
    socketIO.setSocket(newsock);
    return true;
  }
}


