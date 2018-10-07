#include "serverFuncion.h"

// FUNCIONAMIENTO SET_ELEM: Agrega un elemento al mapa de 
// funciones.
    
void Movie::Funcion::SetElem(const std::string nombrePelicula, 
				 const std::string fecha, int reservasDisponibles, int cod) {
  MovieData::DatoFuncion dato(nombrePelicula, fecha, reservasDisponibles);
  this->funcion.insert(std::pair<int, MovieData::DatoFuncion>
		       (cod, dato));
}

// FUNCIONAMIENTO OPERATOR<<: Imprime los elemento
// del de función.

std::ostringstream& Movie::operator<<(std::ostringstream& oss, 
				      Movie::Funcion &funciones) {
  i_funcion i;
  for (i = funciones.funcion.begin(); i != funciones.funcion.end(); ++i) {
    oss << std::setfill('0') << std::setw(4)<< i->first << "\t";  
    oss << i->second;
  }
  oss << std::endl;
  return oss;
}

// FUNCIONAMIENTO VINCULAR_ITERADORES
// Vincula los valores de inicio y fin de datoUsuario.

void Movie::Funcion::VincularIteradores(i_funcion &inicio, i_funcion &N) {
  inicio = this->funcion.begin();
  N = this->funcion.end();
}

// FUNCIONAMIENTO GET_RESERVAS_DISPONIBLES: Devuelve las
// reservas disponibles.

int Movie::Funcion::GetReservasDisponibles(int codFuncion) {
  MovieData::DatoFuncion dato = this->funcion[codFuncion];
  return (dato.GetReservasDisponibles());
}

// FUNCIONAMIENTO RESERVAR: Reserva una cantidad
// de vacantes para una función.

bool Movie::Funcion::Reservar(int codFuncion, int cantReservas) {
  i_funcion i;
  i = this->funcion.find(codFuncion);
  if (i == this->funcion.end())
    return false;
  else return (i->second.Reservar(cantReservas));
}

// FUNCIONAMIENTO MOSTRAR_VALORES:
// Muestra los valores de la función.

void Movie::Funcion::MostrarValores(int codFuncion, 
					std::ostringstream& oss) {
  oss << std::setfill('0') << std::setw(4)<< codFuncion << "\t";  
  this->funcion[codFuncion].MostrarValores(oss);
}
