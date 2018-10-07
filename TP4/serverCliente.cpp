#include "serverCliente.h"

// FUNCIONAMIENTO CLIENTE:
// Crea el cliente.

Client::Cliente::Cliente(CinemaSafe::CineSafe &cine, 
			 Connection::Socket &socket):cine(cine), socket(socket) {
  this->estaAndando = true;
}

Client::Cliente::~Cliente(void) {
}

// FUNCIONAMIENTO VERIFICAR_PROCESO:
// Regresa si un hilo está corriendo o no.

bool Client::Cliente::VerificarProceso(void) {
  return (this->estaAndando);
}

// FUNCIONAMIENTO CONVERTIR_A_INT:
// Convierte a int un string.

int convertirAInt(std::string &valor) {
  std::stringstream convert(valor);
  int res = 0;
  convert >> res;
  return res;
}

// FUNCIONAMIENTO OBTENER_SIGUIENTE_POSICION:
// Obtiene la siguiente posición con el
// próximo dato del buffer.
// 

void obtenerSiguientePosicion(unsigned int &posAnterior, 
			      unsigned int &posActual, std::string &linea) {
  posAnterior = posActual;
  posActual = (linea.find("|", posAnterior + 1));
}

// FUNCIONAMIENTO PARSEAR_BUF
// Parsea el buffer cuando se realiza reservar. 

void ParsearBuf(int &codCliente, int &codFuncion, 
		int &cantReservas, std::string linea) {
  unsigned int posAnterior = 0;
  unsigned int posActual = linea.find("|");
  obtenerSiguientePosicion(posAnterior, posActual, linea);
  std::string valor = linea.substr(posAnterior + 1, 
				   posActual - posAnterior - 1);
  codCliente = convertirAInt(valor);
  obtenerSiguientePosicion(posAnterior, posActual, linea);
  valor = linea.substr(posAnterior + 1, posActual - posAnterior - 1);
  codFuncion = convertirAInt(valor);
  obtenerSiguientePosicion(posAnterior, posActual, linea);
  valor = linea.substr(posAnterior + 1, posActual - posAnterior - 1);
  cantReservas = convertirAInt(valor);
}

// FUNCIONAMIENTO PARSEAR_BUF
// Parsea el buffer cuando se realiza consulta. 

void ParsearBuf(int &codCliente, std::string linea) {
  unsigned int posActual = linea.find("|");
  std::string valor = linea.substr(posActual + 1, linea.length() - 2);
  codCliente = convertirAInt(valor);
}

// FUNCIONAMIENTO RESERVAR:
// Ejecuta y devuelve el resultado de la
// operación reservar.

void Client::Cliente::Reservar(std::string& mensaje) {
  std::ostringstream buffer;
  int codCliente = 0;
  int codFuncion = 0;
  int cantReservas = 0;
  
  ParsearBuf(codCliente, codFuncion, cantReservas, mensaje);
  this->cine.Reservar(codCliente, codFuncion, cantReservas, buffer);
  mensaje.clear();
  mensaje = buffer.str();
  try {
    this->socket.Enviar(mensaje);
  } catch(const std::exception &e) {
    std::cerr << e.what() << std::endl;
    this->estaAndando = false;
  }
}

// FUNCIONAMIENTO LISTADO:
// Ejecuta y devuelve el resultado de la
// operación listado.

void Client::Cliente::Listado(std::string& mensaje) {
  std::ostringstream buffer;
  this->cine.Listado(buffer);
  mensaje.clear();
  mensaje = buffer.str();
  try {
    this->socket.Enviar(mensaje);
  } catch(const std::exception &e) {
    std::cerr << e.what() << std::endl;
    this->estaAndando = false;
  }
}

// FUNCIONAMIENTO CONSULTAR:
// Ejecuta y devuelve el resultado de la
// operación consultar.

void Client::Cliente::Consultar(std::string& mensaje) {
  std::ostringstream buffer;
  int codCliente = 0;
  ParsearBuf(codCliente, mensaje);
  this->cine.Consultar(codCliente, buffer);
  mensaje.clear();
  mensaje = buffer.str();
  try {
    this->socket.Enviar(mensaje);
  } catch(const std::exception &e) {
    std::cerr << e.what() << std::endl;
    this->estaAndando = false;
  }
}

// FUNCIONAMIENTO SALIR:
// Ejecuta y devuelve el resultado de la
// operación salir.

void Client::Cliente::Salir(std::string& mensaje) {
  mensaje.clear();
  mensaje = "S\n";
  this->estaAndando = false;
  try {
    this->socket.Enviar(mensaje);
  } catch(const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

// FUNCIONAMIENTO SALIR:
// Ejecuta y devuelve el resultado de una
// operación errónea.

void Client::Cliente::Error(std::string& mensaje) {
  mensaje.clear();
  mensaje = "error\n";
  try {
    this->socket.Enviar(mensaje);
  } catch(const std::exception &e) {
    std::cerr << e.what() << std::endl;
    this->estaAndando = false;
  }
}

// FUNCIONAMIENTO RUN:
// El método que ejecuta el hilo de cliente.
// Recibe la petición del cliente y la ejecuta
// devolviendo un resultado. Termina cuando el usuario
// realiza salir o cuando hubo una desconexión del socket.

void Client::Cliente::run() {
  std::string mensaje;
  bool exception = false;
  while (this->estaAndando == true) {
    try {
      this->socket.Recibir(mensaje);
    } catch(std::exception &e) {
      std::cerr << e.what() << std::endl;
      this->estaAndando = false;
      exception = true;
    }
    if (exception == false) {
      switch (mensaje[0]) {
      case('L'): {
	Listado(mensaje);
	break;
      }
      case('R'): {
	Reservar(mensaje);
	break;
      }
      case('C'): {
	Consultar(mensaje);
	break;
      }
      case('S'): {
	Salir(mensaje);
	break;
      }
      default: {
	Error(mensaje);
	break;
      }
      }
    }
  }
}

// FUNCIONAMIENTO STOP:
// Detiene la ejecución del cliente.

void Client::Cliente::stop() {
  this->socket.Close();
}
