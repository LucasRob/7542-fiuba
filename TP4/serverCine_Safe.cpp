#include "serverCine_Safe.h"


void CinemaSafe::CineSafe::Consultar(int codCliente, std::ostringstream& oss) {
  Security::Lock l(mutex);
  this->cine.Consultar(codCliente, oss);
}

void CinemaSafe::CineSafe::cargar(char *dir) {
  this->cine.cargar(dir);
}

void CinemaSafe::CineSafe::Listado(std::ostringstream &oss) {
  Security::Lock l(mutex);
  this->cine.Listado(oss);
}

void CinemaSafe::CineSafe::Reservar(int codCliente, 
				    int codFuncion, int cantReservas, std::ostringstream& oss) {
  Security::Lock l(mutex);
  this->cine.Reservar(codCliente, codFuncion, cantReservas, oss);
}

void CinemaSafe::CineSafe::Serializar(char* dir) {
  Security::Lock l(mutex);
  this->cine.Serializar(dir);
}
