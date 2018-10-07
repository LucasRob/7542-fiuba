#include "Engine.h"

// FUNCIONAMIENTO Destructor Main:
// Si la extensión del archivo de mapas
// es invalido devuelve 1, sino llena el
// mapa. El main devuelve 2 si la cantidad de 
// jugadores es menor a la mínima (dos). Devuelve
// 3 si hubo una acción invalida cuando se juega.

myMap::Map* myJugador::Jugador::miMapa = NULL;
int myJugador::Jugador::codJug = 1;

int main(int argc, const char* argv[]) {
  myEngine::Engine miEngine;
  std::string argumento(argv[1]);
  std::string dir;
  size_t found;
  int pos = 0;
   
  found = argumento.find(".map");
  if (found == std::string::npos)
    return 1;
  else {
    pos = argumento.find("=");
    dir = argumento.substr(pos + 1, argumento.length());
    if (miEngine.LlenarMapa(dir, argc - 2) == false)
      return 2;
    else {
      miEngine.LlenarManipulador(argv);
      return(miEngine.Jugar());
    }
  }
}
