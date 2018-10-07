#include "serverServer.h"

// FUNCIONAMIENTO TP4_SERVER:
// Crea un socket y lo vincula al puerto
// pasado por parámetro.
// Luego corre el hilos del servidor hasta
// que se ingrese q. Luego cierra y graba los 
// cambios realizados.

int main(int argc, char *argv[]) {
  CinemaSafe::CineSafe cine;
  Server::Servidor server(cine);
  if (argc == 3) {
    if (server.ConectarServidor(argv[1])) {
      cine.cargar(argv[2]);
      server.start();
      char salir = 0;
      while (salir != 'q') {
	std::cin >> salir;
      }
      server.stop();
      server.join();
      cine.Serializar(argv[2]);
    } 
  } else std::cerr << "Error parámetros\n"; 
  return 0;
}
