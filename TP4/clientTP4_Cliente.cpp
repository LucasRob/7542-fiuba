#include "commonSocket.h"
#include <iostream>
#include <sstream>

// FUNCIONAMIENTO TP4_CLIENTE:
// Crea un socket y lo vincula al puerto
// y a la dirección pasada por parámetro.
// Luego realiza las operaciones dictaminadas
// por entrada estándar, hasta que el usuario
// elija S u ocurra un cierre de conexión
// y cierra el socket.

// FUNCIONAMIENTO CONVERTIR_A_INT:
// Convierte a int un string.

int convertirAInt(const std::string &valor) {
  std::stringstream convert(valor);
  int res = 890;
  convert >> res;
  return res;
}

// FUNCIONAMIENTO CONECTAR_CLIENTE:
// Conecta un cliente.

bool ConectarCliente(Connection::Socket &socketCliente, 
		     std::string &argumento) {
  unsigned int posParser = argumento.find(":");
  const std::string dir = argumento.substr(0, posParser);
  const std::string port = argumento.substr(posParser + 1, argumento.length());
  int miPort = convertirAInt(port);
  return (socketCliente.ConectarModoCliente(dir, miPort));
}

// FUNCIONAMIENTO FORMATEAR:
// Formatea el mensaje a ser enviado
// por el socket.

void Formatear(std::string &mensaje) {
  unsigned int posActual = mensaje.find(" ");
  while (posActual <= mensaje.length()) {
    mensaje.replace(posActual, 1, "|");
    posActual = mensaje.find(" ");
  }
  mensaje.append("\n"); 
}

// FUNCIONAMIENTO DESFORMATEAR:
// Desformatea el mensaje para
// ser enviado por salida estándar.

void Desformatear(std::string &mensaje) {
  unsigned int posActual = mensaje.find("|");
  while (posActual <= mensaje.length()) {
    mensaje.replace(posActual, 1, " ");
    posActual = mensaje.find("|");
  }
  posActual = mensaje.find("x");
  while (posActual <= mensaje.length()) {
    mensaje.replace(posActual, 3, "\n");
    mensaje.erase(posActual - 1, 1);
    posActual = mensaje.find("x");
  }
}

// FUNCIONAMIENTO IMPRIMIR:
// Imprime el mensaje.

void Imprimir(std::string &mensaje) {
  std::cout << mensaje;
}

int main(int argc, char *argv[]) {
  Connection::Socket socketCliente;
  std::string mensaje;
  bool exception = false;
  if (argc != 2) { 
    std::cerr << "uso: cliente hostnamen P.ej.: cliente localhost";
  } else {
    std::string argumento = argv[1]; 
    if (ConectarCliente(socketCliente, argumento) == true) {
      while ((mensaje.find("S\n") == std::string::npos) 
	     && (exception == false)) {
	getline(std::cin, mensaje);
	Formatear(mensaje);
	try {
	  socketCliente.Enviar(mensaje);
	} catch(std::exception &e) {
	  std::cerr << e.what() << std::endl;
	  exception = true;
	}
	try {
	  socketCliente.Recibir(mensaje);
	} catch(std::exception &e) {
	  std::cerr << e.what() << std::endl;
	  exception = true;
	}
	if (exception == false) {
	  Desformatear(mensaje);
	  Imprimir(mensaje);
	}
      }
      socketCliente.Close();
    }
  }
  return 0;  
}
