#include "serverDatoFuncion.h"

// FUNCIONAMIENTO DATOFUNCION: Crea un dato función.

MovieData::DatoFuncion::DatoFuncion(const std::string nombrePelicula, 
					const std::string fecha, int reservasDisponibles) {
  this->nombrePelicula = nombrePelicula;
  this->fecha = fecha;
  this->reservasDisponibles = reservasDisponibles;
}

// FUNCIONAMIENTO OPERATOR <<: Imprime los 
// datos que contiene datoFunción.

std::ostringstream& MovieData::operator<<(std::ostringstream& oss, 
					  MovieData::DatoFuncion &funcion) {
  oss << funcion.nombrePelicula
      << "\t" 
      << funcion.fecha 
      << "\t" 
      << "(" 
      << funcion.reservasDisponibles 
      << ")" 
      << "0x03";
  return oss;
}

// FUNCIONAMIENTO SERIALIZAR: Graba en un archivo 
// los datos que contiene datoFunción.

void MovieData::DatoFuncion::Serializar(std::ofstream& arch) {
  arch << this->nombrePelicula 
       << "|" 
       << this->fecha 
       << "|" 
       << this->reservasDisponibles 
       << "|";
}

// FUNCIONAMIENTO GET_RESERVAS_DISPONIBLES: 
// Devuelve las reservas disponibles.

int MovieData::DatoFuncion::GetReservasDisponibles(void) {
  return this->reservasDisponibles;
}

// FUNCIONAMIENTO RESERVAS:
// Si hay la suficiente cantidad, se descuenta 
// la cantidad de reservas que el usuario pidió.

bool MovieData::DatoFuncion::Reservar(int cantReservas) {
  if (cantReservas <= this->reservasDisponibles) { 
    this->reservasDisponibles = this->reservasDisponibles - cantReservas; 
    return true;
  } else return false;
}

// FUNCIONAMIENTO MOSTRAR_VALORES
// Muestra determinados valores de datoFunción.
// sirve en conjunto con otros métodos para mostrar. 

void MovieData::DatoFuncion::MostrarValores(std::ostringstream& oss) {
  oss << this->nombrePelicula << "\t" << this->fecha << "\t"; 
}

