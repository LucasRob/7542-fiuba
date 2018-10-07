/*
 * File_Player_Manipulator.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __FILE_PLAYER_MANIPULATOR_h__
#define __FILE_PLAYER_MANIPULATOR_h__

#include <iostream>
#include <fstream>
#include <sstream>

// ATRIBUTOS FPM:
//
// ARCH: Archivo de un jugador.
//
// ABIERTO: Booleano para saber si está abierto 
// el archivo.
// 

namespace myManipulator { 

  class FpM {
  private:
    std::ifstream *arch;
    bool abierto;
  public:
    FpM(void) {abierto = true; arch = NULL;}
    ~FpM(void);
    void DameLinea(std::string &linea);
    void Llenar(std::string&);
    bool EsEOF(void);
    bool EstaAbierto(void);
    void CerrarArchivo(void);
  };

  // FUNCIONAMIENTO DameLinea:
  // Devuelve una línea del archivo.
 
  void FpM::DameLinea(std::string &linea) {
    std::getline(*arch, linea);   
  }

  // FUNCIONAMIENTO Llenar:
  // Llena un archivo de jugadores.
 
  void FpM::Llenar(std::string &argumento) {
    int pos = argumento.find("=");
    std::string dir = argumento.substr(pos + 1, argumento.length());
    this->arch = new std::ifstream(dir.c_str());
  }

  // FUNCIONAMIENTO ESOF:
  // Si está el archivo en fin de línea.

  bool FpM::EsEOF(void) {
    return (this->arch->eof());
  }

  // FUNCIONAMIENTO ESOF:
  // Si está el archivo está abierto.

  bool FpM::EstaAbierto(void) {
    return (this->abierto);
  }

  // FUNCIONAMIENTO Destructor FPM:
  // Destruye la referencia al archivo.

  FpM::~FpM(void) {
    delete this->arch;
  }

  // FUNCIONAMIENTO CerrarArchivo:
  // Cierra el archivo.

  void FpM::CerrarArchivo(void) {
    this->abierto = false;
    this->arch->close();
  }
}

#endif
