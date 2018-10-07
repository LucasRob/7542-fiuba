/*
 * Map.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __MAP_h__
#define __MAP_h__

#include "CeldaYHormiga.h"
#include <iostream>
#include "Matcher.h"

// ATRIBUTOS MAPA:
//
// Matriz: matriz donde se guardan las celdas.
//
// N: Cantidad de filas.
//
// M: Cantidad de columnas.
//

namespace myMap { 
  class Map {
  private:
    myCeldaYHormiga::Celda ***matriz;
    int N;
    int M;
    void ReemplazarCelda(int x, int y);
    void ReemplazarPorHormiguero(int x, int y, int filiacion);
    void Actualizar(int x, int y);
    void CasoRecolectora(int x, int y, myCeldaYHormiga::Hormiga*);
    int MoverNorte(int x, int y, int filiacion);
    int MoverSur(int x, int y, int filiacion);
    int MoverEste(int x, int y, int filiacion);
    int MoverOeste(int x, int y, int filiacion);
  public:
    Map(int, int);
    ~Map(void);
    myCeldaYHormiga::Celda* GetCelda(int, int);
    void CrearCeldaTierra(int x, int y); 
    void CrearCeldaAgua(int x, int y); 
    void CrearCeldaHormiguero(int x, int y, int filiacion); 
    void CrearCeldaComida(int x, int y); 
    int CrearHormigaRecolectora(int x, int y, int filiacion); 
    int CrearHormigaVoladora(int x, int y, int filiacion); 
    int CrearHormigaObrera(int x, int y, int filiacion); 
    void DesbloquearHormigas(int filiacion);
    void DesbloquearCeldas(int filiacion);
    int MoverHormiga(int x, int y, char dir, int filiacion);
    void BorrarHormigas(int filiacion);
    bool VerificarHormigueros(int filiacion);
    int GenerarHormiguero(int x, int y, int filiacion);
    void ImprimirMapa(void);
    int GetFilas(void);
    int GetColumnas(void);
  };

  // FUNCIONAMIENTO Constructor de Mapa:
  // Construye el mapa asignando con el 
  // tamaño indicado.

  Map::Map(int N, int M) {
    this->N = N;
    this->M = M;
    this->matriz = new myCeldaYHormiga::Celda**[N];
    for (int i = 0; i < N; ++i) {
      matriz[i] = new myCeldaYHormiga::Celda*[M];
      for (int j = 0; j < M; ++j)
	matriz[i][j] = NULL;
    }
  }

  // FUNCIONAMIENTO Destructor de Mapa:
  // Destruye el mapa liberando la 
  // memoria dinámica de sus atributos.

  Map::~Map(void) {
    int i, j;
    for (i = 0; i < N; ++i) {
      for (j = 0; j < M; ++j) {
	delete this->matriz[i][j];
      }
      delete [] this->matriz[i];
    }
    delete [] this->matriz;
  }

  // FUNCIONAMIENTO GetFilas:
  // Devuelve la cantidad de filas.

  int Map::GetFilas(void) {
    return this->N;
  }
 
  // FUNCIONAMIENTO GetColumnas:
  // Devuelve la cantidad de columnas.

  int Map::GetColumnas(void) {
    return this->M;
  }

  // FUNCIONAMIENTO CrearCeldaTierra:
  // Crea una celda tierra.
 
  void Map::CrearCeldaTierra(int x, int y) {
    this->matriz[x][y] = new myCeldaYHormiga::Celda_Tierra(x, y);
  }

  // FUNCIONAMIENTO CrearCeldaComida:
  // Crea una celda comida.

  void Map::CrearCeldaComida(int x, int y) {
    this->matriz[x][y] = new myCeldaYHormiga::Celda_Comida(x, y);
  }

  // FUNCIONAMIENTO CrearCeldaAgua:
  // Crea una celda agua.

  void Map::CrearCeldaAgua(int x, int y) {
    this->matriz[x][y] = new myCeldaYHormiga::Celda_Agua(x, y);
  }

  // FUNCIONAMIENTO CrearCeldaHormiguero:
  // Crea una celda hormiguero.

  void Map::CrearCeldaHormiguero(int x, int y, int filiacion) {
    this->matriz[x][y] = new myCeldaYHormiga::Celda_Hormiguero(x, y, filiacion);
  }

  // FUNCIONAMIENTO CrearHormigaObrera:
  // Ordena a la celda x, y a crear una hormiga
  // obrera.

  int Map::CrearHormigaObrera(int x, int y, int filiacion) {
    return(this->matriz[x][y]->CrearHormigaObrera(filiacion));
  } 

  // FUNCIONAMIENTO CrearHormigaVoladora:
  // Ordena a la celda x, y a crear una hormiga
  // voladora.
 
  int Map::CrearHormigaVoladora(int x, int y, int filiacion) {
    return(this->matriz[x][y]->CrearHormigaVoladora(filiacion));
  }

  // FUNCIONAMIENTO CrearHormigaRecolectora:
  // Ordena a la celda x, y a crear una hormiga
  // recolectora.

  int Map::CrearHormigaRecolectora(int x, int y, int filiacion) {
    return(this->matriz[x][y]->CrearHormigaRecolectora(filiacion));
  } 

  // FUNCIONAMIENTO DesbloquearHormigas:
  // Desbloquea las hormigas de un usuario con
  // filiación dada.

  void Map::DesbloquearHormigas(int filiacion) {
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j) {
	this->matriz[i][j]->DesbloquearHormiga(filiacion);
      }
  }

  // FUNCIONAMIENTO DesbloquearCeldas:
  // Desbloquea los hormigueros de un usuario con
  // filiación dada.

  void Map::DesbloquearCeldas(int filiacion) {
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j) {
	this->matriz[i][j]->Desbloquear(filiacion);
      }
  }

  // FUNCIONAMIENTO ReemplazarCelda:
  // Reemplaza una celda en i, j por una
  // tierra.

  void Map::ReemplazarCelda(int i, int j) {
    delete this->matriz[i][j];
    this->matriz[i][j] = NULL;
    CrearCeldaTierra(i, j);
  }

  // FUNCIONAMIENTO Actualizar:
  // Actualiza los resultados de mover:
  // Si la hormiga en la celda está muerta la 
  // mata. Si está muerta la celda (caso hormiguero)
  // lo mata y lo reemplaza por tierra. En caso 
  // que la celda muerta tuviera una hormiga viva,
  // la saca de esta la reemplaza por tierra y la
  // vuelve a poner.

  void Map::Actualizar(int x, int y) {
    if (this->matriz[x][y]->HormigaEstaViva() == false) {
      this->matriz[x][y]->BorrarHormiga();
      if (this->matriz[x][y]->EstasViva() == false) 
	ReemplazarCelda(x, y);
    } else if (this->matriz[x][y]->EstasViva() == false) {
      myCeldaYHormiga::Hormiga *ant = this->matriz[x][y]->GetHormiga();
      this->matriz[x][y]->SetHormiga(NULL);
      ReemplazarCelda(x, y);
      this->matriz[x][y]->SetHormiga(ant);
    }
  }

  // FUNCIONAMIENTO CasoRecolectora:
  // Borra la celda comida reemplazando por
  // tierra y pone la hormiga.

  void Map::CasoRecolectora(int x, int y, myCeldaYHormiga::Hormiga* ant) {
    ReemplazarCelda(x, y);
    this->matriz[x][y]->SetHormiga(ant);
  }

  // FUNCIONAMIENTO MoverNorte:
  // Mueve una hormiga al norte. Lo hace
  // si la hormiga es de la misma filiación
  // que le ordenó moverse. Sino es acción invalida.
  // Luego de ordenar que la hormiga visite la celda
  // los resultados se actualizan. Devuelve 
  // Pudo_Recolectar en caso de que una hormiga 
  // recolectora visite una celda comida.
  // Como el mapa tiene los costados unidos, 
  // realiza la lógica también.

  int Map::MoverNorte(int x, int y, int filiacion) {
    int inc = 0;
    int res = 0;
    if ((y - 1) >= 0)
      inc = - 1;
    else inc = this->N - 1;
    myCeldaYHormiga::Hormiga *ant = this->matriz[x][y]->GetHormiga();
    myMatcher::Matcher<myCeldaYHormiga::Hormiga> miMatcher(filiacion);
    if (miMatcher(ant) == true) {
      res = this->matriz[x][y + inc]->recibir(ant);
      if (res == ACCION_VALIDA) {
	Actualizar(x, y);
	Actualizar(x, y + inc);
      } else if (res == PUDO_RECOLECTAR) { 
	CasoRecolectora(x, y + inc, ant);
	this->matriz[x][y]->SetHormiga(NULL);
      }
    } else return ACCION_INVALIDA;
    return res;
  }

  // FUNCIONAMIENTO MoverSur:
  // Mueve una hormiga al sur. Lo hace
  // si la hormiga es de la misma filiación
  // que le ordenó moverse. Sino es acción invalida.
  // Luego de ordenar que la hormiga visite la celda
  // los resultados se actualizan. Devuelve 
  // Pudo_Recolectar en caso de que una hormiga 
  // recolectora visite una celda comida.
  // Como el mapa tiene los costados unidos, 
  // realiza la lógica también.

  int Map::MoverSur(int x, int y, int filiacion) {
    int inc = 0;
    int res = 0;
    if ((y + 1) < this->N) 
      inc = + 1;
    else inc = - (this->N - 1);
    myCeldaYHormiga::Hormiga *ant = this->matriz[x][y]->GetHormiga();
    myMatcher::Matcher<myCeldaYHormiga::Hormiga> miMatcher(filiacion);
    if (miMatcher(ant) == true) {
      res = this->matriz[x][y + inc]->recibir(ant);
      if (res == ACCION_VALIDA) {
	Actualizar(x, y);
	Actualizar(x, y + inc);
      } else if (res == PUDO_RECOLECTAR) {
	CasoRecolectora(x, y + inc, ant);
	this->matriz[x][y]->SetHormiga(NULL);
      }
    } else return ACCION_INVALIDA;
    return res;
  }

  // FUNCIONAMIENTO MoverEste:
  // Mueve una hormiga al este. Lo hace
  // si la hormiga es de la misma filiación
  // que le ordenó moverse. Sino es acción invalida.
  // Luego de ordenar que la hormiga visite la celda
  // los resultados se actualizan. Devuelve 
  // Pudo_Recolectar en caso de que una hormiga 
  // recolectora visite una celda comida.
  // Como el mapa tiene los costados unidos, 
  // realiza la lógica también.

  int Map::MoverEste(int x, int y, int filiacion) {
    int inc = 0;
    int res = 0;
    if ((x + 1) < this->M) 
      inc = + 1;
    else inc = - (this->N - 1);
    myCeldaYHormiga::Hormiga *ant = this->matriz[x][y]->GetHormiga();
    myMatcher::Matcher<myCeldaYHormiga::Hormiga> miMatcher(filiacion);
    if (miMatcher(ant) == true) {
      res = this->matriz[x + inc][y]->recibir(ant);
      if (res == ACCION_VALIDA) {
	Actualizar(x, y);
	Actualizar(x + inc, y);
      } else if (res == PUDO_RECOLECTAR) { 
	CasoRecolectora(x + inc, y, ant);
	this->matriz[x][y]->SetHormiga(NULL); 
      }
    } else return ACCION_INVALIDA;
    return res;
  }

  // FUNCIONAMIENTO MoverOeste:
  // Mueve una hormiga al oeste. Lo hace
  // si la hormiga es de la misma filiación
  // que le ordenó moverse. Sino es acción invalida.
  // Luego de ordenar que la hormiga visite la celda
  // los resultados se actualizan. Devuelve 
  // Pudo_Recolectar en caso de que una hormiga 
  // recolectora visite una celda comida.
  // Como el mapa tiene los costados unidos, 
  // realiza la lógica también.

  int Map::MoverOeste(int x, int y, int filiacion) {
    int inc = 0;
    int res = 0;
    if ((x - 1) > 0) 
      inc = - 1;
    else inc = + (this->N - 1);
    myCeldaYHormiga::Hormiga *ant = this->matriz[x][y]->GetHormiga();
    myMatcher::Matcher<myCeldaYHormiga::Hormiga> miMatcher(filiacion);
    if (miMatcher(ant) == true) {
      res = this->matriz[x + inc][y]->recibir(ant);
      if (res == ACCION_VALIDA) {
	Actualizar(x, y);
	Actualizar(x + inc, y);
      } else if (res == PUDO_RECOLECTAR) {
	CasoRecolectora(x + inc, y, ant);
	this->matriz[x][y]->SetHormiga(NULL); 
      }
    } else return ACCION_INVALIDA;
    return res;
  }

  // FUNCIONAMIENTO VerificarHormigueros:
  // Verifica la cantidad de hormigueros de
  // un jugador.
   
  bool Map::VerificarHormigueros(int filiacion) {
    int cant = 0;
    for (int j = 0; j < N; ++j)
      for (int i = 0; i < M; ++i) {
	int fil = this->matriz[i][j]->GetFiliacion();
	if ((fil != SIN_PARENTESCO) && (fil == filiacion))
	  ++cant;
      }
    if (cant == 0)
      return false;
    else return true;
  }

  // FUNCIONAMIENTO BorrarHormigas:
  // Borra las hormigas de un jugador
  // y las reemplaza por tierras.

  void Map::BorrarHormigas(int filiacion) {
    for (int j = 0; j < N; ++j)
      for (int i = 0; i < M; ++i) {
	int fil = this->matriz[i][j]->GetFiliacionHormiga();
	if ((fil != SIN_PARENTESCO) && (fil == filiacion)) {
	  this->matriz[i][j]->BorrarHormiga();
	  ReemplazarCelda(i, j);
	}
      }
  }

  // FUNCIONAMIENTO MoverHormigas:
  // Mueve las hormigas de acuerdo a
  // su dirección.

  int Map::MoverHormiga(int x, int y, char dir, int filiacion) {
    int res = ACCION_VALIDA;

    switch (dir) {
    case NORTE: {
      return (MoverNorte(x, y, filiacion));
      break;
    }
    case SUR: { 
      return (MoverSur(x, y, filiacion));
      break;
    }
    case ESTE: { 
      return (MoverEste(x, y, filiacion));
      break;
    }
    case OESTE: { 
      return (MoverOeste(x, y, filiacion));
      break;
    }
    default: {  
      return ACCION_INVALIDA;
      break;
    }
    }
    return res;
  }

  // FUNCIONAMIENTO ReemplazarHormigueros:
  // Reemplaza una celda por un hormiguero.

  void Map::ReemplazarPorHormiguero(int i, int j, int filiacion) {
    delete this->matriz[i][j];
    this->matriz[i][j] = NULL;
    CrearCeldaHormiguero(i, j, filiacion);
  }

  // FUNCIONAMIENTO GenerarHormigueros:
  // Genera un hormiguero con una hormiga
  // posicionada en x, y. Si es obrera lo crea
  // sino es acción invalida.

  int Map::GenerarHormiguero(int x, int y, int filiacion) {
    if ((x <= N) && (y <= M)) {
      int res = this->matriz[x][y]->VerificarGenerarHormiguero(filiacion);
      if (res == ACCION_VALIDA) {
	myCeldaYHormiga::Hormiga *ant = this->matriz[x][y]->GetHormiga();
	ReemplazarPorHormiguero(x, y, filiacion);
	this->matriz[x][y]->SetHormiga(ant);
	return PUDO_CREAR_HORMIGUERO;
      } else return ACCION_INVALIDA;
    } return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO ImprimirMapa:
  // Imprime una representación del
  // estado del mapa.

  void Map::ImprimirMapa(void) {
    for (int j = 0; j < N; ++j) {
      std::cout << SIMBOLO_MAPA << " ";
      for (int i = 0; i < M; ++i)  
	this->matriz[i][j]->Imprimir();
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}

#endif
