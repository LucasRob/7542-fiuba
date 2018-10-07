/*
 * Jugador.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __JUGADOR_h__
#define __JUGADOR_h__

#include "CeldaYHormiga.h"
#include "Map.h"
#include "Jugador_Constantes.h"

// ATRIBUTOS JUGADOR:
//
// MAPA: Representación lógica del mapa.
// Es estático porque puede ser modificado
// por cualquier jugador y es privado para
// que sea usado solamente por los jugadores.
//
// CODJUG: Una variable estática para 
// inicializar los números de jugador.
//
// CANTCOMIDA: Cantidad de comida.
//
// VIDA: Determina si un jugador vive o no.
//

namespace myJugador { 
  class Jugador {
  private:
    static myMap::Map *miMapa;
    static int codJug;
    int cantComida;
    int numJugador;
    bool vida;
    void CrearHormiguero(int, int, int);
    int CrearHormiga(int, int, char);
    int CrearHormigaObrera(int x, int y);
    int CrearHormigaVoladora(int x, int y);
    int CrearHormigaRecolectora(int x, int y);
  public:
    Jugador(void);
    ~Jugador(void);
    int Movimiento(int, int, char);
    int GeneracionDeHormigas(int, int, char);
    int GeneracionDeHormigueros(int , int);
    void CrearMapa(int, int);
    void BorrarMapa(void);
    void CrearCelda(int, int, char);
    void DesbloquearHormigas(void);
    void DesbloquearHormigueros(void);
    bool EstasVivo(void);
    void ImprimirMapa(void);
    int GetFilas(void);
    int GetColumnas(void);
    void VerificarVida(void);
  };

  // FUNCIONAMIENTO Constructor de Jugador:
  // Construye el jugador asignando su 
  // código con la variable estática.
  // Un jugador comienza con una unidad de
  // comida.

  Jugador::Jugador(void) {
    cantComida = 1;
    numJugador = codJug;
    ++codJug;
    vida = true;
  }

  // FUNCIONAMIENTO Destructor de Jugador:
  // No destruye aquí el mapa, sino que lo
  // hace el engine una sola vez.

  Jugador::~Jugador(void) {
  }

  // FUNCIONAMIENTO EstasViva:
  // Regresa si está vivo.

  bool Jugador::EstasVivo(void) {
    return vida;
  }

  // FUNCIONAMIENTO GetFilas:
  // Ordena al mapa devolver la
  // cantidad de filas.

  int Jugador::GetFilas(void) {
    return (this->miMapa->GetFilas());
  }

  // FUNCIONAMIENTO GetColumnas:
  // Ordena al mapa devolver la
  // cantidad de filas.
  
  int Jugador::GetColumnas(void) {
    return (this->miMapa->GetColumnas());
  }

  // FUNCIONAMIENTO CrearCelda:
  // Ordena crear una celda dependiendo
  // del tipo.
  
  void Jugador::CrearCelda(int x, int y, char code) {
    switch (code) {
    case TIERRA: {  
      this->miMapa->CrearCeldaTierra(x, y);
      break;
    }
    case AGUA: {  
      this->miMapa->CrearCeldaAgua(x, y);
      break;
    }
    case COMIDA: {  
      this->miMapa->CrearCeldaComida(x, y);
      break;
    }
    default: {  
      int numJugador = code - '0';
      this->miMapa->CrearCeldaHormiguero(x, y, numJugador);
      break;
    }
    }
  }

  // FUNCIONAMIENTO CrearMapa:
  // Crea el mapa.
  
  void Jugador::CrearMapa(int N, int M) {
    this->miMapa = new myMap::Map(N, M);
  }

  // FUNCIONAMIENTO BorraMapa:
  // Borra el mapa.
  
  void Jugador::BorrarMapa(void) {
    delete this->miMapa;
  }

  // FUNCIONAMIENTO CrearHormigaObrera:
  // Ordena al mapa a crear una hormiga
  // obrera. Si pudo crearla resta una unidad
  // de comida.
  
  int Jugador::CrearHormigaObrera(int x, int y) {
    int res = this->miMapa->CrearHormigaObrera(x, y, this->numJugador);
    if (res == ACCION_VALIDA) 
      --this->cantComida;
    return res;
  }

  // FUNCIONAMIENTO CrearHormigaVoladora:
  // Ordena al mapa a crear una hormiga
  // voladora. Si pudo crearla resta una unidad
  // de comida.
  
  int Jugador::CrearHormigaVoladora(int x, int y) {
    int res = this->miMapa->CrearHormigaVoladora(x, y, this->numJugador);
    if (res == ACCION_VALIDA) 
      --this->cantComida;
    return res;
  }

  // FUNCIONAMIENTO CrearHormigaRecolectora:
  // Ordena al mapa a crear una hormiga
  // recolectora. Si pudo crearla resta una unidad
  // de comida.
    
  int Jugador::CrearHormigaRecolectora(int x, int y) {
    int res = this->miMapa->CrearHormigaRecolectora(x, y, this->numJugador);
    if (res == ACCION_VALIDA) 
      --this->cantComida;
    return res;
  }

  // FUNCIONAMIENTO CrearHormigaRecolectora:
  // Crear una hormiga dependiendo del tipo.

  int Jugador::CrearHormiga(int x, int y, char code) {
    switch (code) {
    case HORMIGA_OBRERA: { 
      return (CrearHormigaObrera(x, y));
      break;
    }
    case HORMIGA_VOLADORA: {
      return (CrearHormigaVoladora(x, y));
      break;
    }
    case HORMIGA_RECOLECTORA: {
      return (CrearHormigaRecolectora(x, y));
      break;
    }
    default: {  
      return ACCION_INVALIDA;
      break;
    }
    }
  }

  // FUNCIONAMIENTO GeneracionDeHormigas:
  // Crear una hormiga en posición x, y. Si no 
  // tiene suficiente cantidad de comida es una
  // acción invalida.

  int Jugador::GeneracionDeHormigas(int x, int y, char cod_hormiga) {
    int res = ACCION_VALIDA;

    if (this->cantComida >= COMIDA_PARA_GENERAR_HORMIGA) {
      res = CrearHormiga(x, y, cod_hormiga);
    } else res = ACCION_INVALIDA;
    return res;
  }

  // FUNCIONAMIENTO DesbloquearHormigas:
  // Ordena al mapa a desbloquear las hormigas
  // del jugador.

  void Jugador::DesbloquearHormigas(void) {
    this->miMapa->DesbloquearHormigas(this->numJugador);
  }

  // FUNCIONAMIENTO DesbloquearHormigueros:
  // Ordena al mapa a desbloquear los hormigueros

  void Jugador::DesbloquearHormigueros(void) {
    this->miMapa->DesbloquearCeldas(this->numJugador);
  }

  // FUNCIONAMIENTO VerificarVida:
  // Verifica si un usuario está vivo, con la 
  // cantidad de hormigueros vivos.
        
  void Jugador::VerificarVida(void) {
    this->vida = this->miMapa->VerificarHormigueros(this->numJugador);
    if (this->vida == false)
      this->miMapa->BorrarHormigas(this->numJugador);
  }
    
  // FUNCIONAMIENTO Movimiento:
  // Realiza el movimiento de una hormiga
  // Si se pudo recolectar comida, incrementa en uno
  // su cantidad de comida.

  int Jugador::Movimiento(int x, int y, char direccion) {
    int res = ACCION_VALIDA;
    res = this->miMapa->MoverHormiga(x, y, direccion, this->numJugador);
    if (res == PUDO_RECOLECTAR) { 
      ++this->cantComida;
      res = ACCION_VALIDA;
    }
    return res;
  }

  // FUNCIONAMIENTO Generación de Hormigueros:
  // Genera un hormiguero si tiene suficiente cantidad
  // de comida sino es una acción invalida.

  
  int Jugador::GeneracionDeHormigueros(int x, int y) {
    if (this->cantComida >= COMIDA_PARA_GENERAR_HORMIGUEROS) {
      int res = this->miMapa->GenerarHormiguero(x, y, this->numJugador);
      if (res == PUDO_CREAR_HORMIGUERO) {
        this->cantComida = this->cantComida - PUDO_CREAR_HORMIGUERO;
	return ACCION_VALIDA;
      } else return ACCION_INVALIDA;
    } else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO ImprimirMapa:
  // Imprime mapa.

  void Jugador::ImprimirMapa(void) {
    this->miMapa->ImprimirMapa();
  }
}
  
#endif
