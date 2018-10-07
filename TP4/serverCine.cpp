#include "serverCine.h"

// FUNCIONAMIENTO OBTENER_SIGUIENTE_POSICIÓN:
// Obtiene la próxima posición del separador del 
// archivo de cartelera.

void Cinema::Cine::obtenerSiguientePosicion(unsigned int 
					    &posAnterior, unsigned int &posActual, const std::string &linea) {
  posAnterior = posActual;
  posActual = (linea.find("|", posAnterior + 1));
}

// FUNCIONAMIENTO LLENAR_RESERVAS:
// Obtiene la próxima posición del separador del 
// archivo de cartelera.

void Cinema::Cine::llenarReservas(const std::string &linea, 
				  unsigned int posAnterior, int cod) {
  unsigned int posActual = posAnterior;
  obtenerSiguientePosicion(posAnterior, posActual, linea);
  while (posActual > posAnterior) {
    std::string valor = linea.substr(posAnterior + 1, 
				     posActual - posAnterior - 1);
    int codCliente = convertirAInt(valor);
    obtenerSiguientePosicion(posAnterior, posActual, linea);
    valor = linea.substr(posAnterior + 1, posActual - posAnterior - 1);
    int cantReservas = convertirAInt(valor);
    this->reservas.SetElem(codCliente, 
			   cod, cantReservas);
    obtenerSiguientePosicion(posAnterior, posActual, linea);
  }
}

// FUNCIONAMIENTO CONVENTIR_A_INT:
// Convierte un string a int.

int Cinema::Cine::convertirAInt(const std::string &valor) {
  std::stringstream convert(valor);
  int res = 0;
  convert >> res;
  return res;
}

// FUNCIONAMIENTO LLENAR_FUNCIÓN:
// LLena los datos de las funciones.

unsigned int Cinema::Cine::llenarFuncion(const std::string &linea, int cod) {
  unsigned int posActual = linea.find("|");
  unsigned int posAnterior = 0;
  const std::string nombre = linea.substr(posAnterior, posActual);
  obtenerSiguientePosicion(posAnterior, posActual, linea);
  const std::string horario = linea.substr(posAnterior + 1, 
				     posActual - posAnterior - 1);
  obtenerSiguientePosicion(posAnterior, posActual, linea);
  const std::string valor = linea.substr(posAnterior + 1, 
				   posActual - posAnterior - 1);
  int reservasDisponibles = convertirAInt(valor);
  this->funciones.SetElem(nombre, horario, reservasDisponibles, cod);  
  return posActual;
}

// FUNCIONAMIENTO LLENAR:
// LLena las estructuras.

void Cinema::Cine::llenar(const std::string &linea, int cod) {
  unsigned int posActual = llenarFuncion(linea, cod);
  obtenerSiguientePosicion(posActual, posActual, linea);
  llenarReservas(linea, posActual, cod);
} 

// FUNCIONAMIENTO LLENAR:
// Serializa el resultado de la operación.

void Cinema::Cine::Serializar(char* dir) {
  std::ofstream arch(dir);
  Movie::i_funcion inicio;
  Movie::i_funcion N;
  Movie::i_funcion i;
  this->funciones.VincularIteradores(inicio, N);
  for (i = inicio; i != N; ++i) {
    i->second.Serializar(arch);
    this->reservas.SerializarElemento(i->first, arch);
    arch << std::endl;
  }
  arch.close();
}

// FUNCIONAMIENTO LISTADO:
// Genera el listado de funciones.

void Cinema::Cine::Listado(std::ostringstream &oss) {
  oss << this->funciones;
}

// FUNCIONAMIENTO RESERVAR:
// Realiza una reserva e imprime el resultado.

void Cinema::Cine::Reservar(int codCliente, int codFuncion, 
			    int cantReservas, std::ostringstream& oss) {
  if (!(this->funciones.Reservar(codFuncion, cantReservas)))
    oss << "error" << std::endl;
  else {
    this->reservas.SetElem(codCliente, codFuncion, cantReservas);
    oss << "ok" << std::endl;
  }
}

// FUNCIONAMIENTO RESERVAR:
// Realiza una consulta y la imprime.

void Cinema::Cine::Consultar(int codCliente, std::ostringstream& oss) {
  if (!(this->reservas.ExisteCod(codCliente)))
    oss << "error" << std::endl;
  else {
    UserData::i_Usuario inicio;
    UserData::i_Usuario N;
    UserData::i_Usuario i;
    this->reservas.VincularIteradores(codCliente, inicio, N);
    for (i = inicio; i != N; ++i) {
      oss << codCliente << "\t";
      int codFuncion = i->GetCodFuncion();
      this->funciones.MostrarValores(codFuncion, oss);
      oss << "(" 
	  << i->GetCantReservas() 
	  << ")" 
	  << "0x03";
    }
    oss << "\n";
  }
}

// FUNCIONAMIENTO CARGAR:
// Carga los datos a la estructura.

void Cinema::Cine::cargar(char *dir) {
  std::string miString;
  std::ifstream arch(dir);
  getline(arch, miString);
  int cod = 1;
  while (!arch.eof()) {
    llenar(miString, cod);
    getline(arch, miString);
    ++cod;
  }
  arch.close();
}

