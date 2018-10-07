/*
 * Engine.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __ENGINE_h__
#define __ENGINE_h__

#include "jugador.h"
#include "File_Player_Manipulator.h"
#include "Engine_Constantes.h"


namespace myEngine { 
  
  // ATRIBUTOS Parseo:
  //
  //
  // X: Posición X obtenida por parseo. 
  //
  // Y: Posición Y obtenida por parseo.
  //
  // COD: Código obtenido por parseo.
  //

  // Métodos Parseo:
  //
  //
  // GetX: Devuelve la posición X. 
  //
  // GetY: Devuelve la posición Y.
  //
  // GetCod: Devuelve el código.
  //

  class Parseo {
  private:
    int x;
    int y;
    char codigo;
  public:
    Parseo(int i, int j, char code) {
      x = i;
      y = j;
      codigo = code;
    }
    int GetX()const {return x;}
    int GetY()const {return y;}
    char GetCodigo()const {return codigo;}
  }; 

  // ATRIBUTOS ENGINE:
  //
  // TIMEOUT: La cantidad de turnos hasta
  // finalizar el juego.
  //
  // CANTJUGADORES: La cantidad total de
  // jugadores.
  //
  // JUGADORES: Array de jugadores.
  //
  // MyFPM: Array de manipulador de archivos
  // de jugadores.
  //
  
  class Engine {
  private:
    int timeout;
    int cantJugadores;
    myJugador::Jugador *jugadores;
    myManipulator::FpM *myManip;
    int Accion(int, char, const Parseo&);
    int Verificar_Cantidad_Archivos_Cerrados(void);
    int Verificar_Jugadores_Vivos(void);
    const myEngine::Parseo Parsear_Linea(std::string&);
    const myEngine::Parseo Parsear_Mapa(std::string&, std::ifstream&);
    void LlenarMatriz(std::string&, std::ifstream&, int, int);
    int Turno(std::string&, int&, int&);
    void Imprimir(int filiacion);
    int BuscarPosicionSiguiente(std::string&, int);
  public:
    Engine(void); 
    ~Engine(void);
    myJugador::Jugador* GetJugadores(void);
    bool LlenarMapa(std::string&, int);
    void LlenarManipulador(const char**);
    int Jugar(void);
  };
    
  Engine::Engine(void) {
    this->timeout = 0; 
    this->cantJugadores = 0; 
    this->myManip = NULL; 
    this->jugadores = NULL;
  }
     
  // FUNCIONAMIENTO Destructor de Engine:
  // Destruye el mapa y luego libera
  // la memoria dinámica de jugadores y
  // myManip. 

  Engine::~Engine(void) {
    this->jugadores->BorrarMapa();
    delete [] this->jugadores;
    delete [] this->myManip;
  }

  // FUNCIONAMIENTO ObtenerValorNumerico:
  // Convierte un char a int. Sirve para cuando
  // se parsea el archivo de mapa.
  
  int ObtenerValorNumerico(std::string &linea) {
    int pos = linea.find(" ");
    std::string valor = linea.substr(pos, linea.length());
    std::stringstream convert(valor);
    int res = 0;
    convert >> res;
    return res;
  }

  // FUNCIONAMIENTO ObtenerValorNumerico:
  // Convierte un char a int. Sirve para cuando
  // se parsea el archivo de acciones del jugador.

  int ObtenerValorNumerico(std::string &linea, int pos) {
    std::string valor = linea.substr(pos, linea.length());
    std::stringstream convert(valor);
    int res = 0;
    convert >> res;
    return res;
  }

  // FUNCIONAMIENTO Parsear_Mapa:
  // Parsea el archivo de mapa.
   
  const myEngine::Parseo Engine::Parsear_Mapa
    (std::string &linea, std::ifstream& fMapa) {
    std::getline(fMapa, linea);
    int filas = ObtenerValorNumerico(linea);
    std::getline(fMapa, linea);
    int columnas = ObtenerValorNumerico(linea);
    std::getline(fMapa, linea);
    int cant_players = ObtenerValorNumerico(linea);
    std::getline(fMapa, linea);
    int tiempo = ObtenerValorNumerico(linea);
    this->timeout = tiempo;
    this->cantJugadores = cant_players;
    myEngine::Parseo miParseo(filas, columnas, 0);
    return (miParseo);
  }
  
  // FUNCIONAMIENTO LlenarMatriz:
  // Llena la matriz con los datos del
  // archivo de mapa.

  void Engine::LlenarMatriz(std::string &linea, 
			    std::ifstream& fMapa, int filas, int columnas) {
    std::getline(fMapa, linea);
    int j = 0;
    this->jugadores[0].CrearMapa(filas, columnas);
    while (fMapa.good() && (j < filas)) {
      int k = 2;
      for (int i = 0; i < columnas; ++i) {
	this->jugadores[0].CrearCelda(i, j, linea[k]);
	++k;
      }
      ++j;
      std::getline(fMapa, linea);
    }
  }
  
  // FUNCIONAMIENTO LlenarMatriz:
  // Llena el mapa. Si el archivo posee cantidad
  // de jugadores menor a 2 entonces no se llena
  // y termina el juego.

  bool Engine::LlenarMapa(std::string &dir, int cant_jug) {
    bool res = true;
    std::ifstream fMapa(dir.c_str());
    std::string linea; 
    if (fMapa.is_open()) {
      const myEngine::Parseo &miParseo = Parsear_Mapa(linea, fMapa);   
      if (this->cantJugadores >= MINIMO_JUGADORES) {
	this->jugadores = new myJugador::Jugador[this->cantJugadores];
	LlenarMatriz(linea, fMapa, miParseo.GetX(), miParseo.GetY());
      } else res = false;
    }
    fMapa.close();
    return res;
  }

  // FUNCIONAMIENTO LlenarMatriz:
  // Llena el manipulador de archivos de 
  // jugadores.
  
  void Engine::LlenarManipulador(const char* argv[]) {
    this->myManip = new myManipulator::FpM[this->cantJugadores];
    for (int i = 0; i < this->cantJugadores; ++i) {
      std::string argumento(argv[i + 2]);
      this->myManip[i].Llenar(argumento);
    }
  }
  
  // FUNCIONAMIENTO LlenarMatriz:
  // Realiza una acción de acuerdo al código
  // pasado por parámetro. Si este es incorrecto
  // es una acción invalida. 

  int Engine::Accion(int pos, char accion, const myEngine::Parseo &miParseo) {
    switch (accion) {
    case MOVER: {  
      this->jugadores[pos].DesbloquearHormigas();
      return (this->jugadores[pos].Movimiento
	      (miParseo.GetX(), miParseo.GetY(), miParseo.GetCodigo()));
      break;
    }
    case GENERAR_HORMIGA: {
      this->jugadores[pos].DesbloquearHormigueros();
      return (this->jugadores[pos].GeneracionDeHormigas
	      (miParseo.GetX(), miParseo.GetY(), miParseo.GetCodigo()));
      return ACCION_VALIDA;
      break;
    }
    case GENERAR_HORMIGUERO: { 
      this->jugadores[pos].DesbloquearHormigas();
      return (this->jugadores[pos].GeneracionDeHormigueros
	      (miParseo.GetX(), miParseo.GetY()));
      break;
    }
    default: {  
      return ACCION_INVALIDA;
      break;
    }
    }
  }

  // FUNCIONAMIENTO Verificar_Cantidad_Archivos_Cerrados:
  // Verifica la cantidad de archivos cerrados.

  int Engine::Verificar_Cantidad_Archivos_Cerrados(void) {
    int res = ACCION_VALIDA;
    
    for (int i = 0; i < cantJugadores; ++i) {
      if (this->myManip[i].EstaAbierto() == false)
	++res;
    }
    return res;
  }
   
  // FUNCIONAMIENTO Verificar_Cantidad_Jugadores_Vivos:
  // Verifica la cantidad de jugadores vivos.

  int Engine::Verificar_Jugadores_Vivos(void) {
    int res = 0;
    
    for (int i = 0; i < cantJugadores; ++i) {
      this->jugadores[i].VerificarVida();
      if (this->jugadores[i].EstasVivo() == true)
	++res;
    }
    return res;
  }
   
  // FUNCIONAMIENTO BuscarPosicionSiguiente:
  // Busca la posición siguiente del separador del
  // archivo de jugadores para obtener luego el dato.

  int Engine::BuscarPosicionSiguiente(std::string &linea, int posAnterior) {
    unsigned int i = posAnterior;
    while ((i < linea.length()) && (linea.at(i) != CARACTER_SEPARADOR))
      ++i;
    if (linea.at(i) == CARACTER_SEPARADOR)
      return (i + 1);
    else return -1;
  }
  
  // FUNCIONAMIENTO Parsear_Linea:
  // Parsea la linea del archivo de jugadores.

  const myEngine::Parseo Engine::Parsear_Linea(std::string &linea) {
    int x = ObtenerValorNumerico(linea, POSICION_X);
    int PosicionSiguiente = BuscarPosicionSiguiente(linea, POSICION_X);
    int y = ObtenerValorNumerico(linea, PosicionSiguiente);
    PosicionSiguiente = BuscarPosicionSiguiente(linea, PosicionSiguiente);
    int codigo = linea.at(PosicionSiguiente);
    myEngine::Parseo miParseo(x, y, codigo);
    return (miParseo);
  }

  // FUNCIONAMIENTO TURNO:
  // Habilita un turno para el jugador, siempre
  // que no sea fin de turno y el jugador este vivo.
  // Luego de la acción verifica los jugadores vivos.
  // En caso de fin de turno decrementa el timeout e
  // incrementa pos que indica que jugador está jugando
  // actualmente.
   
  int Engine::Turno(std::string &linea, int& pos, int& jugadores_vivos) {  
    int res = ACCION_VALIDA;
    if ((linea.at(0) != FINALIZAR_TURNO) && 
	(this->jugadores[pos].EstasVivo() == true)) {
      const myEngine::Parseo &miParseo = Parsear_Linea(linea);   
      res = Accion(pos, linea.at(0), miParseo);
      jugadores_vivos = Verificar_Jugadores_Vivos();
    } else {
      ++pos;
      --this->timeout;
    }
    return res;
  }

  // FUNCIONAMIENTO IMPRIMIR:
  // Imprime el estado final de la partida.

  void Engine::Imprimir(int vivos) {
    std::cout << STDOUT_1 << " " << 
      this->jugadores[0].GetFilas() << std::endl;
    std::cout << STDOUT_2 << " " << 
      this->jugadores[0].GetColumnas() << std::endl;
    std::cout << STDOUT_3 << " " << vivos << std::endl;
    if (this->timeout == 0)
      std::cout << STDOUT_4 << " " << TIMEOUT << std::endl;
    else std::cout << STDOUT_4 << " " << NO_TIMEOUT << std::endl;
    this->jugadores[0].ImprimirMapa();
  }
   
  // FUNCIONAMIENTO JUGAR:
  // Controla el juego. El programa
  // termina cuando quede un jugador o
  // se terminaron las acciones o timeout
  // es cero o una acción invalida. Luego de
  // terminar imprime el estado final de la
  // partida.

  int Engine::Jugar(void) {
    int archivos_cerrados = 0;
    int jugadores_vivos = this->cantJugadores;
    std::string linea;
    int i = 0;
    int res = ACCION_VALIDA;
    
    while ((archivos_cerrados < this->cantJugadores) && 
	   (jugadores_vivos >= MINIMO_JUGADORES) && 
	   (this->timeout != PARTIDA_TERMINADA) && 
	   (res != ACCION_INVALIDA)) {
      if (i >= this->cantJugadores)
	i = 0;
      this->myManip[i].DameLinea(linea);
      if (!this->myManip[i].EsEOF()) { 
	res = Turno(linea, i, jugadores_vivos);
      } else if (this->myManip[i].EstaAbierto() == true) {
	this->myManip[i].CerrarArchivo();
	archivos_cerrados = Verificar_Cantidad_Archivos_Cerrados();
	++i;
      }
    } 
    if (res == ACCION_VALIDA) 
      Imprimir(jugadores_vivos);
    return res;
  }
}

#endif
