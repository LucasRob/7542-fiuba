#include "serverReserva.h"

// FUNCIONAMIENTO SET_ELEM:
// Agrega un elemento. En caso de estar
// vacío el mapa crea la lista de reservas
// y las agrega.

void Reservation::Reserva::SetElem(int codCliente, 
				 int codFuncion, int cantReservas) {
  if (this->mapa.empty()) {
    UserData::ListaDatosUsuario lista;
    lista.SetElem(codFuncion, cantReservas);
    this->mapa.insert(std::pair<int, UserData::ListaDatosUsuario>
			(codCliente, lista));
  } else this->mapa[codCliente].SetElem(codFuncion, cantReservas);
}

// FUNCIONAMIENTO SERIALIZAR_ELEMENTO:
// Serializa los datos de reserva con código
// cod.

void Reservation::Reserva::SerializarElemento(int codFuncion, 
					    std::ofstream &arch) {
  Reservation::i_mapaUsuario i;
  i = this->mapa.begin();
  for (i = this->mapa.begin(); i != this->mapa.end(); ++i) {
    i->second.Serializar(i->first, codFuncion, arch);
  }
} 

// FUNCIONAMIENTO EXISTE_COD
// Verifica si existe el código de cliente.
// en caso afirmativo devuelve true, sino false.

bool Reservation::Reserva::ExisteCod(int codCliente) {
  Reservation::i_mapaUsuario i;
  i = this->mapa.find(codCliente);
  if (i == this->mapa.end())
    return false;
  else return true;
}

// FUNCIONAMIENTO VINCULAR_ITERADORES
// Vincula los valores de inicio y fin de datoUsuario.

void Reservation::Reserva::VincularIteradores(int codCliente, 
					      UserData::i_Usuario &inicio, UserData::i_Usuario &fin) {
  this->mapa[codCliente].VincularIteradores(inicio, fin);
}


