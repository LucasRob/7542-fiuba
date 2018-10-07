#include "serverDatoUsuario.h"

// FUNCIONAMIENTO GET_COD_FUNCION: 
// Devuelve el código de la función.

int UserData::DatoUsuario::GetCodFuncion(void) const {
  return this->codFuncion;
}

// FUNCIONAMIENTO GET_CANT_RESERVAS: 
// Devuelve la cantidad de reservas.

int UserData::DatoUsuario::GetCantReservas(void) const {
  return this->cantReservas;
}

// FUNCIONAMIENTO OPERATOR ==
// Compara dos dato usuario.

bool UserData::DatoUsuario::operator == (const DatoUsuario &OtroDato) {
  if (this->codFuncion == OtroDato.GetCodFuncion())
    return true;
  else return false;
}

// FUNCIONAMIENTO OPERATOR <
// Compara dos dato usuario.

bool UserData::DatoUsuario::operator < (const DatoUsuario &OtroDato) {
  if (this->codFuncion < OtroDato.GetCodFuncion())
    return true;
  else return false;
}

// FUNCIONAMIENTO OPERATOR !=
// Compara dos dato usuario.

bool UserData::DatoUsuario::operator != (const DatoUsuario &OtroDato) {
  return (!(*this == OtroDato));
}

// FUNCIONAMIENTO DATO_USUARIO:
// Crea un dato usuario.

UserData::DatoUsuario::DatoUsuario(int codFuncion, int cantReservas) {
  this->codFuncion = codFuncion;
  this->cantReservas = cantReservas;
} 

// FUNCIONAMIENTO ACTUALIZAR_RESERVAS:
// Actualiza la cantidad de reservas de un usuario.

void UserData::DatoUsuario::ActualizarReservas
(const DatoUsuario &OtroDato) {
  this->cantReservas = this->cantReservas + OtroDato.GetCantReservas(); 
}

// FUNCIONAMIENTO ACTUALIZAR_LISTA:
// Actualiza lista de datos del usuario. Agrega o
// actualiza los datos de las reservas de un usuario.

void UserData::ListaDatosUsuario::ActualizarLista(DatoUsuario &Dato) {
  std::list<DatoUsuario>::iterator i;
  i = this->lista.begin();
  while ((i != (this->lista.end())) && (Dato != *i)) {
    ++i;
  }
  if (i == this->lista.end()) {
     this->lista.push_front(Dato);
     this->lista.sort();
  } else i->ActualizarReservas(Dato);
}

// FUNCIONAMIENTO SET_ELEM:
// Agrega un elemento a la lista.

void UserData::ListaDatosUsuario::SetElem(int cod, int cant) {
  DatoUsuario Dato(cod, cant);
  if (this->lista.empty())
    this->lista.push_front(Dato);
  else ActualizarLista(Dato);
} 

// FUNCIONAMIENTO SERIALIZAR:
// Graba los datos de la lista de usuario.

void UserData::ListaDatosUsuario::Serializar
(int codCliente, int codFuncion, std::ofstream &arch) {
  std::list<DatoUsuario>::iterator i;
  this->lista.sort();
  i = this->lista.begin();
  while ((i != (this->lista.end())) && (i->GetCodFuncion() != codFuncion)) {
    ++i;
  }  
  if (i != this->lista.end()) {
    arch << "|" << codCliente << "|" << i->GetCantReservas();  
  }
}

// FUNCIONAMIENTO VINCULAR_ITERADORES
// Copia el valor de inicio y fin de la 
// lista de datos usuarios.

void UserData::ListaDatosUsuario::
VincularIteradores(i_Usuario &inicio, i_Usuario &fin) {
  inicio = this->lista.begin();
  fin = this->lista.end();
}



