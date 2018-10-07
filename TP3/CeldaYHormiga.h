/*
 * CeldaYHormiga.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __CELDAYHORMIGA_h__
#define __CELDAYHORMIGA_h__

#include "CeldaYHormiga_Constantes.h"

#include <iostream>


namespace myCeldaYHormiga {
  
  class Celda;
  class Celda_Agua;
  class Celda_Tierra;
  class Celda_Comida;
  class Celda_Hormiguero;

  class Hormiga {
  public:
    virtual ~Hormiga(void) { };
    virtual int GetX(void) const = 0;
    virtual int GetY(void) const = 0;
    virtual void SetX(int x) = 0;
    virtual void SetY(int y) = 0;
    virtual int GetFiliacion(void) = 0;
    virtual void Bloquear(void) = 0;
    virtual bool EstasViva(void) = 0;
    virtual void Desbloquear(int filiacion) = 0;
    virtual void Morir(void) = 0;
    virtual Hormiga* Copiar(void) = 0;
    virtual int VerificarGenerarHormiguero(int filiacion) = 0;
    virtual void Imprimir(void) = 0;
    virtual int visitar(Celda_Agua *miCelda, Hormiga *OtraHormiga) = 0;
    virtual int visitar(Celda_Tierra *miCelda, Hormiga *OtraHormiga) = 0;
    virtual int visitar(Celda_Comida *miCelda, Hormiga *OtraHormiga) = 0; 
    virtual int visitar(Celda_Hormiguero *miCelda, Hormiga *OtraHormiga) = 0; 
  };

  // ATRIBUTOS HORMIGA VOLADORA:
  //
  // X: Posición X de la hormiga.
  //
  // Y: Posición Y de la hormiga.
  //
  // FILIACIÓN: Determina a que jugador pertenece
  // la hormiga.
  //
  // VIDA: Determina si la hormiga está viva o
  // muerta.
  //
  // BLOQUEO: Determina si la hormiga está
  // bloqueada para su uso.
 
  class Hormiga_Voladora: public Hormiga {
  private:
    int x;
    int y;
    int filiacion;
    bool vida;
    bool bloqueo;
  public:
    Hormiga_Voladora(int, int , int);
    virtual int GetX(void)const; 
    virtual int GetY(void)const;
    virtual void SetX(int x);
    virtual void SetY(int y);
    virtual int GetFiliacion(void);
    virtual void Bloquear(void);
    virtual bool EstasViva(void);
    virtual void Desbloquear(int filiacion);
    virtual void Morir(void);
    virtual Hormiga* Copiar();
    virtual int VerificarGenerarHormiguero(int filiacion);
    virtual void Imprimir(void);
    virtual int visitar(Celda_Agua*, Hormiga*);
    virtual int visitar(Celda_Tierra*, Hormiga*);
    virtual int visitar(Celda_Comida*, Hormiga*); 
    virtual int visitar(Celda_Hormiguero*, Hormiga*);
  };

  // FUNCIONAMIENTO Constructor de Hormiga:
  // Una hormiga se crea con su posición en el mapa,
  // su filiación a un usuario y nace siempre bloqueada
  // para su uso.

  Hormiga_Voladora::Hormiga_Voladora(int i, int j, int numJugador) {
    x = i; 
    y = j; 
    filiacion = numJugador; 
    vida = true;
    bloqueo = true;
  }

  // FUNCIONAMIENTO GetX:
  // Devuelve la posición x de la hormiga.
 
  int Hormiga_Voladora::GetX(void)const {
    return x;
  }

  // FUNCIONAMIENTO GetY:
  // Devuelve la posición x de la hormiga.

  int Hormiga_Voladora::GetY(void)const {
    return y;
  }

  // FUNCIONAMIENTO SetX:
  // Cambia la posición x de la hormiga.

  void Hormiga_Voladora::SetX(int x) {
    this->x = x;
  }

  // FUNCIONAMIENTO SetY:
  // Cambia la posición y de la hormiga.
 
  void Hormiga_Voladora::SetY(int y) {
    this->y = y;
  }

  // FUNCIONAMIENTO EstasViva:
  // Regresa si está viva la hormiga o no.

  bool Hormiga_Voladora::EstasViva(void) {
    return vida;
  }

  // FUNCIONAMIENTO Morir:
  // Mata la hormiga.

  void Hormiga_Voladora::Morir(void) {
    this->vida = false;
  }

  // FUNCIONAMIENTO Bloquear:
  // bloquea la hormiga para su uso.

  void Hormiga_Voladora::Bloquear(void) {
    this->bloqueo = false;
  }

  // FUNCIONAMIENTO Desbloquear:
  // Desbloquea la hormiga para su uso,
  // en caso se que el usuario que generó
  // la acción este afiliado a la hormiga.

  void Hormiga_Voladora::Desbloquear(int filiacion) {
    if (this->filiacion == filiacion) 
      if (this->bloqueo == true)
	this->bloqueo = false;
  }

  // FUNCIONAMIENTO GetFiliacion:
  // Devuelve la filiación de la hormiga.

  int Hormiga_Voladora::GetFiliacion(void) {
    return this->filiacion;
  }

  // FUNCIONAMIENTO Copia:
  // Crea una copia de la hormiga a un puntero.

  Hormiga* Hormiga_Voladora::Copiar(void) {
    Hormiga* OtraHormiga = new Hormiga_Voladora(this->x, 
						this->y, this->filiacion);
    return OtraHormiga;
  }

  // FUNCIONAMIENTO VerificarGenerarHormiguero:
  // Verifica si la hormiga puede generar un hormiguero.
  // En este caso es una acción invalida.

  int Hormiga_Voladora::VerificarGenerarHormiguero(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella puede visitar una
  // celda agua entonces se realiza la lógica de las
  // colisiones: si hay otra hormiga en la celda
  // la otra muere y la visitante vive si es de distinta
  // filiación con respecto a la otra hormiga. En caso
  // contrario muere esta también. Si está bloqueada
  // la hormiga es una acción invalida.

  int Hormiga_Voladora::visitar(Celda_Agua *miCelda, Hormiga *OtraHormiga) {
    if (this->bloqueo == false) {
      if (OtraHormiga != NULL) {
	OtraHormiga->Morir();
	if (this->filiacion == OtraHormiga->GetFiliacion())
	  this->vida = false;
      }
      return ACCION_VALIDA;
    } else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella puede visitar una
  // celda tierra entonces se realiza la lógica de las
  // colisiones: si hay otra hormiga en la celda
  // la otra muere y la visitante vive si es de distinta
  // filiación con respecto a la otra hormiga. En caso
  // contrario muere esta también. Si está bloqueada
  // la hormiga es una acción invalida.
 
  int Hormiga_Voladora::visitar(Celda_Tierra *miCelda, Hormiga *OtraHormiga) {
    if (this->bloqueo == false) {
      if (OtraHormiga != NULL) {
	OtraHormiga->Morir();
	if (this->filiacion == OtraHormiga->GetFiliacion())
	  this->vida = false;
      }
      return ACCION_VALIDA;
    } else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella no puede visitar
  // una celda comida entonces es una acción invalida.

  int Hormiga_Voladora::visitar(Celda_Comida *miCelda, Hormiga *OtraHormiga) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda hormiguero. En este caso ella puede visitar una
  // celda tierra entonces se realiza la lógica de las
  // colisiones: si hay otra hormiga en la celda
  // la otra muere y la visitante vive si es de distinta
  // filiación con respecto a la otra hormiga. En caso
  // contrario muere esta también. Si está bloqueada
  // la hormiga es una acción invalida.
 
  int Hormiga_Voladora::visitar(Celda_Hormiguero *miCelda, 
				Hormiga *OtraHormiga) {
    if (this->bloqueo == false) {
      if (OtraHormiga != NULL) {
	OtraHormiga->Morir();
	if (this->filiacion == OtraHormiga->GetFiliacion())
	  this->vida = false;
      }
      return ACCION_VALIDA;
    } else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Imprimir:
  // Imprime por STDOUT un código que 
  // identifica a la clase de la hormiga.
 
  void Hormiga_Voladora::Imprimir(void) {
    std::cout << VOLADORA  << this->filiacion;
  }

  // ATRIBUTOS HORMIGA OBRERA:
  //
  // X: Posición X de la hormiga.
  //
  // Y: Posición Y de la hormiga.
  //
  // FILIACIÓN: Determina a que jugador pertenece
  // la hormiga.
  //
  // VIDA: Determina si la hormiga está viva o
  // muerta.
  //
  // BLOQUEO: Determina si la hormiga está
  // bloqueada para su uso.

  class Hormiga_Obrera: public Hormiga {
  private:
    int x;
    int y;
    int filiacion;
    bool vida;
    bool bloqueo;
  public:
    Hormiga_Obrera(int, int, int);
    virtual void SetX(int x);
    virtual void SetY(int y);
    virtual void Desbloquear(int filiacion);
    virtual int VerificarGenerarHormiguero(int filiacion);
    virtual int GetX(void)const; 
    virtual int GetY(void)const;
    virtual int GetFiliacion(void);
    virtual void Bloquear(void);
    virtual bool EstasViva(void);
    virtual void Morir(void);
    virtual Hormiga* Copiar(void);
    virtual void Imprimir(void);
    virtual int visitar(Celda_Agua*, Hormiga*);
    virtual int visitar(Celda_Tierra*, Hormiga*);
    virtual int visitar(Celda_Comida*, Hormiga*); 
    virtual int visitar(Celda_Hormiguero*, Hormiga*);
  };

  // FUNCIONAMIENTO Constructor de Hormiga:
  // Una hormiga se crea con su posición en el mapa,
  // su filiación a un usuario y nace siempre bloqueada
  // para su uso.

  Hormiga_Obrera::Hormiga_Obrera(int i, int j, int numJugador) {
    x = i;
    y = j;
    filiacion = numJugador; 
    vida = true;
    bloqueo = true;
  }

  // FUNCIONAMIENTO GetX:
  // Devuelve la posición x de la hormiga.

  int Hormiga_Obrera::GetX(void)const {
    return x;
  }
  
  // FUNCIONAMIENTO GetY:
  // Devuelve la posición x de la hormiga.

  int Hormiga_Obrera::GetY(void)const {
    return y;
  }

  // FUNCIONAMIENTO SetX:
  // Cambia la posición x de la hormiga.

  void Hormiga_Obrera::SetX(int x) {
    this->x = x;
  }
 
  // FUNCIONAMIENTO SetY:
  // Cambia la posición y de la hormiga.

  void Hormiga_Obrera::SetY(int y) {
    this->y = y;
  }

  // FUNCIONAMIENTO EstasViva:
  // Regresa si está viva la hormiga o no.

  bool Hormiga_Obrera::EstasViva(void) {
    return vida;
  }

  // FUNCIONAMIENTO Morir:
  // Mata la hormiga.

  void Hormiga_Obrera::Morir(void) {
    this->vida = false;
  }

  // FUNCIONAMIENTO Bloquear:
  // bloquea la hormiga para su uso.

  void Hormiga_Obrera::Bloquear(void) {
    this->bloqueo = false;
  }

  // FUNCIONAMIENTO Desbloquear:
  // Desbloquea la hormiga para su uso,
  // en caso se que el usuario que generó
  // la acción este afiliado a la hormiga.

  void Hormiga_Obrera::Desbloquear(int filiacion) {
    if (this->filiacion == filiacion)
      if (this->bloqueo == true)
	this->bloqueo = false;
  }

  // FUNCIONAMIENTO GetFiliacion:
  // Devuelve la filiación de la hormiga.

  int Hormiga_Obrera::GetFiliacion(void) {
    return this->filiacion;
  }

  // FUNCIONAMIENTO Copia:
  // Crea una copia de la hormiga a un puntero.

  Hormiga* Hormiga_Obrera::Copiar(void) {
    Hormiga* OtraHormiga = new Hormiga_Obrera(this->x, 
					      this->y, this->filiacion);
    return OtraHormiga;
  }

  // FUNCIONAMIENTO VerificarGenerarHormiguero:
  // Verifica si la hormiga puede generar un hormiguero.
  // En el caso de una hormiga obrera es válido. Siempre
  // que no esté bloqueada y la filiación coincida con el
  // usuario que invovó la acción.

  int Hormiga_Obrera::VerificarGenerarHormiguero(int filiacion) {
    if (this->bloqueo == false)
      if (this->filiacion == filiacion) {
	this->bloqueo = true;
	return ACCION_VALIDA;
      }
      else return ACCION_INVALIDA;
    else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella no puede visitar
  // una celda agua entonces es una acción invalida.
 
  int Hormiga_Obrera::visitar(Celda_Agua *miCelda, Hormiga *OtraHormiga) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella puede visitar una
  // celda tierra entonces se realiza la lógica de las
  // colisiones: si hay otra hormiga en la celda
  // la otra muere y la visitante vive si es de distinta
  // filiación con respecto a la otra hormiga. En caso
  // contrario muere esta también. Si está bloqueada
  // la hormiga es una acción invalida.
 
  int Hormiga_Obrera::visitar(Celda_Tierra *miCelda, Hormiga *OtraHormiga) {
    if (this->bloqueo == false) {
      if (OtraHormiga != NULL) {
	OtraHormiga->Morir();
	if (this->filiacion == OtraHormiga->GetFiliacion())
	  this->vida = false;
      }
      return ACCION_VALIDA;
    } else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella no puede visitar
  // una celda comida entonces es una acción invalida.

  int Hormiga_Obrera::visitar(Celda_Comida *miCelda, Hormiga *OtraHormiga) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella puede visitar una
  // celda hormiguero entonces se realiza la lógica de las
  // colisiones: si hay otra hormiga en la celda
  // la otra muere y la visitante vive si es de distinta
  // filiación con respecto a la otra hormiga. En caso
  // contrario muere esta también. Si está bloqueada
  // la hormiga es una acción invalida.

  int Hormiga_Obrera::visitar(Celda_Hormiguero *miCelda, Hormiga *OtraHormiga) {
    if (this->bloqueo == false) {
      if (OtraHormiga != NULL) {
	OtraHormiga->Morir();
	if (this->filiacion == OtraHormiga->GetFiliacion())
	  this->vida = false;
      }
      return ACCION_VALIDA;
    } else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Imprimir:
  // Imprime por STDOUT un código que 
  // identifica a la clase de la hormiga.

  void Hormiga_Obrera::Imprimir(void) {
    std::cout << OBRERA << this->filiacion;
  }

  // ATRIBUTOS HORMIGA RECOLECTORA:
  //
  // X: Posición X de la hormiga.
  //
  // Y: Posición Y de la hormiga.
  //
  // FILIACIÓN: Determina a que jugador pertenece
  // la hormiga.
  //
  // VIDA: Determina si la hormiga está viva o
  // muerta.
  //
  // BLOQUEO: Determina si la hormiga está
  // bloqueada para su uso.

  class Hormiga_Recolectora: public Hormiga {
  private:
    int x;
    int y;
    int filiacion;
    bool vida;
    bool bloqueo;
  public:
    Hormiga_Recolectora(int, int, int);
    virtual void SetX(int x);
    virtual void SetY(int y);
    virtual void Desbloquear(int filiacion);
    virtual int VerificarGenerarHormiguero(int filiacion);
    virtual int GetX(void)const; 
    virtual int GetY(void)const;
    virtual bool EstasViva(void);
    virtual void Bloquear(void);
    virtual void Morir(void);
    virtual Hormiga* Copiar(void);
    virtual void Imprimir(void);
    virtual int visitar(Celda_Agua*, Hormiga*);
    virtual int visitar(Celda_Tierra*, Hormiga*);
    virtual int visitar(Celda_Comida*, Hormiga*); 
    virtual int visitar(Celda_Hormiguero*, Hormiga*);
    virtual int GetFiliacion(void);
  };

  // FUNCIONAMIENTO Constructor de Hormiga:
  // Una hormiga se crea con su posición en el mapa,
  // su filiación a un usuario y nace siempre bloqueada
  // para su uso.

  Hormiga_Recolectora::Hormiga_Recolectora(int i, int j, int numJugador) {
    x = i;
    y = j;
    filiacion = numJugador;
    vida = true;
    bloqueo = true;
  }

  // FUNCIONAMIENTO GetX:
  // Devuelve la posición x de la hormiga.

  int Hormiga_Recolectora::GetX(void)const {
    return x;
  }
  
  // FUNCIONAMIENTO GetY:
  // Devuelve la posición x de la hormiga.

  int Hormiga_Recolectora::GetY(void)const {
    return y;
  }

  // FUNCIONAMIENTO SetX:
  // Cambia la posición x de la hormiga.

  void Hormiga_Recolectora::SetX(int x) {
    this->x = x;
  }
 
  // FUNCIONAMIENTO SetY:
  // Cambia la posición y de la hormiga.

  void Hormiga_Recolectora::SetY(int y) {
    this->y = y;
  }

  // FUNCIONAMIENTO EstasViva:
  // Regresa si está viva la hormiga o no.

  bool Hormiga_Recolectora::EstasViva(void) {
    return vida;
  }
 
  // FUNCIONAMIENTO Morir:
  // Mata la hormiga.

  void Hormiga_Recolectora::Morir(void) {
    this->vida = false;
  }

  // FUNCIONAMIENTO Bloquear:
  // bloquea la hormiga para su uso.

  void Hormiga_Recolectora::Bloquear(void) {
    this->bloqueo = false;
  }

  // FUNCIONAMIENTO Desbloquear:
  // Desbloquea la hormiga para su uso,
  // en caso se que el usuario que generó
  // la acción este afiliado a la hormiga.

  void Hormiga_Recolectora::Desbloquear(int filiacion) {
    if (this->filiacion == filiacion)
      if (this->bloqueo == true)
	this->bloqueo = false;
  }
 
  // FUNCIONAMIENTO GetFiliacion:
  // Devuelve la filiación de la hormiga.

  int Hormiga_Recolectora::GetFiliacion(void) {
    return this->filiacion;
  }

  // FUNCIONAMIENTO Copia:
  // Crea una copia de la hormiga a un puntero.

  Hormiga* Hormiga_Recolectora::Copiar(void) {
    Hormiga* OtraHormiga = new Hormiga_Recolectora(this->x, 
						   this->y, this->filiacion);
    return OtraHormiga;
  }

  // FUNCIONAMIENTO VerificarGenerarHormiguero:
  // Verifica si la hormiga puede generar un hormiguero.
  // En este caso es una acción invalida.

  int Hormiga_Recolectora::VerificarGenerarHormiguero(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella no puede visitar
  // una celda agua entonces es una acción invalida.
 
  int Hormiga_Recolectora::visitar(Celda_Agua *miCelda, Hormiga *OtraHormiga) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella puede visitar una
  // celda tierra entonces se realiza la lógica de las
  // colisiones: si hay otra hormiga en la celda
  // de la misma filiación mueren las dos, sino
  // es una acción invalida porque una hormiga recolectora
  // no puede atacar. También es invalido si está bloqueada.
 
  int Hormiga_Recolectora::visitar(Celda_Tierra *miCelda, 
				   Hormiga *OtraHormiga) {
    if (this->bloqueo == false) {
      if (OtraHormiga != NULL) {
	if (OtraHormiga->GetFiliacion() == this->filiacion) {
	  OtraHormiga->Morir();
	  this->vida = false;
	  return ACCION_VALIDA;
	} else return ACCION_INVALIDA;
      }  else return ACCION_VALIDA;
    } else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella puede visitar una
  // celda comida entonces recolecta la comida avisando
  // al jugador que pudo recolecta.
 
  int Hormiga_Recolectora::visitar(Celda_Comida *miCelda, 
				   Hormiga *OtraHormiga) {
    return PUDO_RECOLECTAR;
  }

  // FUNCIONAMIENTO Visitar:
  // Visitar es parte del "doble despacho", una
  // manera usando polimorfismo de que la hormiga
  // posea cierto comportamiento dependiendo de que
  // celda visita. En este caso ella puede visitar una
  // celda tierra entonces se realiza la lógica de las
  // colisiones: si hay otra hormiga en la celda
  // de la misma filiación mueren las dos, sino
  // es una acción invalida porque una hormiga recolectora
  // no puede atacar. También es invalido si está bloqueada.

  int Hormiga_Recolectora::visitar(Celda_Hormiguero *miCelda, 
				   Hormiga *OtraHormiga) {
    if (this->bloqueo == false) {
      if (OtraHormiga != NULL) 
	return ACCION_INVALIDA;
      else return ACCION_VALIDA;
    } else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Imprimir:
  // Imprime por STDOUT un código que 
  // identifica a la clase de la hormiga.

  void Hormiga_Recolectora::Imprimir(void) {
    std::cout << RECOLECTORA << this->filiacion;
  }
 
  class Celda {
  public:
    virtual ~Celda(void) {}
    virtual int recibir(Hormiga* miHormiga) = 0;
    virtual void SetHormiga(Hormiga* hormiga) = 0;
    virtual Hormiga* GetHormiga(void) = 0;
    virtual int CrearHormigaObrera(int filiacion) = 0;
    virtual int CrearHormigaVoladora(int filiacion) = 0;
    virtual int CrearHormigaRecolectora(int filiacion) = 0;
    virtual bool EstasViva(void) = 0;
    virtual void DesbloquearHormiga(int filiacion) = 0;
    virtual void Desbloquear(int filiacion) = 0;
    virtual bool HormigaEstaViva(void) = 0;
    virtual void BorrarHormiga(void) = 0;
    virtual int GetFiliacionHormiga(void) = 0;
    virtual int GetFiliacion(void) = 0;
    virtual int VerificarGenerarHormiguero(int filiacion) = 0;
    virtual void Imprimir(void) = 0;
  };

  // ATRIBUTOS CELDA AGUA :
  //
  // X: Posición X de la celda.
  //
  // Y: Posición Y de la celda.
  // 
  // MyANT: Puntero a hormiga que se encuentra
  // posicionada en la celda.
  //
  // FILIACIÓN: Determina a que jugador pertenece
  // la celda. En este caso no está afiliada a
  // ninguna.
  //
  // VIDA: Determina si la celda está viva o
  // muerta. En este caso siempre está viva. 
  //
  // BLOQUEO: Determina si la celda está
  // bloqueada para su uso. En este caso
  // está siempre desbloqueada.

  class Celda_Agua: public Celda {
  private:
    int x;
    int y;
    Hormiga *myAnt;
    int vida;
    int filiacion;
  public:
    Celda_Agua(int, int);
    ~Celda_Agua(void);
    virtual int recibir(Hormiga* miHormiga);
    virtual void SetHormiga(Hormiga* hormiga);
    virtual Hormiga* GetHormiga(void);
    virtual int CrearHormigaObrera(int filiacion);
    virtual int CrearHormigaVoladora(int filiacion);
    virtual int CrearHormigaRecolectora(int filiacion);
    virtual void DesbloquearHormiga(int filiacion);
    virtual void Desbloquear(int filiacion);
    virtual bool EstasViva(void);
    virtual bool HormigaEstaViva(void);
    virtual void BorrarHormiga(void);
    virtual int GetFiliacionHormiga(void);
    virtual int GetFiliacion(void);
    virtual int VerificarGenerarHormiguero(int filiacion);
    virtual void Imprimir(void);
  };

  // FUNCIONAMIENTO Constructor de Celda_Agua:
  // Una celda se crea con su posición en el mapa,
  // En este caso la vida es eterna y no tiene 
  // parentesco con un usuario.

  Celda_Agua::Celda_Agua(int i, int j) {
    x = i;
    y = j; 
    myAnt = NULL;
    vida = true;
    filiacion = SIN_PARENTESCO;
  } 

  // FUNCIONAMIENTO destructor de Celda_Agua:
  // Libero la memória dinámica de la hormiga.

  Celda_Agua::~Celda_Agua(void) {
    if (this->myAnt != NULL)
      delete myAnt;
  }

  // FUNCIONAMIENTO Recibir:
  // Parte del doble despacho. Recibir permite
  // que la hormiga sepa la clase de la celda
  // a la que visita para poder determinar 
  // por polimorfismo a que método visitar llamar.
  // Aparte termina la lógica de las colisiones con 
  // los resultados de visitar: Si la hormiga visitante
  // vive, celda realiza una copia de esta a su celda
  // y la visitante muere. La nueva hormiga se bloquea
  // para su uso. Si había una hormiga en la celda
  // y hubo colisión ocurre que murió, entonces borra
  // la memoria dinámica de la hormiga y hace la copia
  // de la visitante.

  int Celda_Agua::recibir(Hormiga* miHormiga) {
    int res = miHormiga->visitar(this, this->myAnt);
    if (res == ACCION_VALIDA) {
      if (miHormiga->EstasViva() == true) {
	miHormiga->SetX(this->x);
	miHormiga->SetY(this->y);
	if (this->myAnt == NULL)
	  this->myAnt = miHormiga->Copiar();
	else {
	  delete this->myAnt;
	  this->myAnt = NULL;
	  this->myAnt = miHormiga->Copiar();
	}
	miHormiga->Morir();
	this->myAnt->Bloquear();
      }
    }
    return res;
  }

  // FUNCIONAMIENTO EstasViva:
  // Regresa si está viva la celda.
  // En este caso es inmortal.

  bool Celda_Agua::EstasViva(void) {
    return vida;
  }

  // FUNCIONAMIENTO GetFiliacionHormiga:
  // Devuelve la filiación de la hormiga
  // posicionada en la celda. Si no hay
  // una hormiga en la celda se se devuelve
  // sin parentesco.

  int Celda_Agua::GetFiliacionHormiga(void) {
    if (this->myAnt != NULL)
      return this->myAnt->GetFiliacion();
    else return SIN_PARENTESCO;
  }

  // FUNCIONAMIENTO GetFiliacion:
  // Devuelve la filiación de la celda
  // En este caso es sin parentesco.

  int Celda_Agua::GetFiliacion(void) {
    return this->filiacion;
  }

  // FUNCIONAMIENTO HormigaEstaViva:
  // Devuelve si la hormiga está viva. 

  bool Celda_Agua::HormigaEstaViva(void) {
    return(this->myAnt->EstasViva());
  }

  // FUNCIONAMIENTO SetHormiga:
  // Agrega una hormiga a la celda.

  void Celda_Agua::SetHormiga(Hormiga* hormiga) {
    this->myAnt = hormiga;
  }

  // FUNCIONAMIENTO GetHormiga:
  // Devuelve la hormiga a la celda.

  Hormiga* Celda_Agua::GetHormiga(void) {
    return(this->myAnt);
  }

  // FUNCIONAMIENTO CrearHormigaObrera:
  // Crea una hormiga obrera. En este caso
  // esta celda no puede crear una entonces es
  // una acción invalida.

  int Celda_Agua::CrearHormigaObrera(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO CrearHormigaVoladora:
  // Crea una hormiga voladora. En este caso
  // esta celda no puede crear una entonces es
  // una acción invalida.

  int Celda_Agua::CrearHormigaVoladora(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO CrearHormigaRecolectora:
  // Crea una hormiga recolectora. En este caso
  // esta celda no puede crear una entonces es
  // una acción invalida.

  int Celda_Agua::CrearHormigaRecolectora(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO DesbloquearHormiga:
  // Desbloquea la hormiga posicionada sobre
  // ella para su uso.

  void Celda_Agua::DesbloquearHormiga(int filiacion) {
    if (this->myAnt != NULL)
      this->myAnt->Desbloquear(filiacion);
  }

  // FUNCIONAMIENTO BorrarHormiga:
  // Borra la hormiga de la celda.
 
  void Celda_Agua::BorrarHormiga(void) {
    if (this->myAnt != NULL) {
      delete this->myAnt;
      this->myAnt = NULL;
    }
  }

  // FUNCIONAMIENTO Desbloquear:
  // Desbloquea la Celda. En este caso
  // la celda siempre está desbloqueada.

  void Celda_Agua::Desbloquear(int filiacion) {}

  // FUNCIONAMIENTO VerificarGenerarHormiguero:
  // Verifica si la hormiga puede generar un hormiguero.
  // En caso que no exista la hormiga es una acción
  // invalida.

  int Celda_Agua::VerificarGenerarHormiguero(int filiacion) {
    if (this->myAnt != NULL)
      return (this->myAnt->VerificarGenerarHormiguero(filiacion));
    else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO Imprimir:
  // Imprime por STDOUT una 
  // representación actual del
  // estado de la celda.

  void Celda_Agua::Imprimir(void) {
    if (this->myAnt != NULL) {
      std::cout << "(" << this->filiacion;
      this->myAnt->Imprimir();
      std::cout << ")";
    } else std::cout << AGUA;
  }

  // ATRIBUTOS CELDA TIERRA:
  //
  // X: Posición X de la celda.
  //
  // Y: Posición Y de la celda.
  //
  // MyANT: Puntero a hormiga que se encuentra
  // posicionada en la celda.
  //
  // FILIACIÓN: Determina a que jugador pertenece
  // la celda. En este caso no está afiliada a
  // ninguna.
  //
  // VIDA: Determina si la celda está viva o
  // muerta. En este caso siempre está viva. 
  //
  // BLOQUEO: Determina si la celda está
  // bloqueada para su uso. En este caso
  // está siempre desbloqueada.
 
  class Celda_Tierra: public Celda {
  private:
    int x;
    int y;
    Hormiga *myAnt;
    int vida;
    int filiacion;
  public:
    Celda_Tierra(int i, int j);
    ~Celda_Tierra(void);
    virtual int recibir(Hormiga* miHormiga);
    virtual void SetHormiga(Hormiga* hormiga);
    virtual Hormiga* GetHormiga(void);
    virtual int CrearHormigaObrera(int filiacion);
    virtual int CrearHormigaVoladora(int filiacion);
    virtual int CrearHormigaRecolectora(int filiacion);
    virtual void DesbloquearHormiga(int filiacion);
    virtual void Desbloquear(int filiacion);
    virtual bool EstasViva(void);
    virtual bool HormigaEstaViva(void);
    virtual void BorrarHormiga(void);
    virtual int GetFiliacionHormiga(void);
    virtual int GetFiliacion(void);
    virtual int VerificarGenerarHormiguero(int filiacion);
    virtual void Imprimir(void);
  };

  // FUNCIONAMIENTO Constructor de Celda_Tierra:
  // Una celda se crea con su posición en el mapa,
  // En este caso la vida es eterna y no tiene 
  // parentesco con un usuario.

  Celda_Tierra::Celda_Tierra(int i, int j) {
    x = i;
    y = j; 
    myAnt = NULL;
    vida = true;
    filiacion = SIN_PARENTESCO;
  }

  // FUNCIONAMIENTO destructor de Celda_Tierra:
  // Libero la memória dinámica de la hormiga.

  Celda_Tierra::~Celda_Tierra(void) {
    if (this->myAnt != NULL)
      delete myAnt;
  } 

  // FUNCIONAMIENTO Recibir:
  // Parte del doble despacho. Recibir permite
  // que la hormiga sepa la clase de la celda
  // a la que visita para poder determinar 
  // por polimorfismo a que método visitar llamar.
  // Aparte termina la lógica de las colisiones con 
  // los resultados de visitar: Si la hormiga visitante
  // vive, celda realiza una copia de esta a su celda
  // y la visitante muere. La nueva hormiga se bloquea
  // para su uso. Si había una hormiga en la celda
  // y hubo colisión ocurre que murió, entonces borra
  // la memoria dinámica de la hormiga y hace la copia
  // de la visitante.

  int Celda_Tierra::recibir(Hormiga* miHormiga) { 
    int res = miHormiga->visitar(this, this->myAnt);
    if (res == ACCION_VALIDA) {
      if (miHormiga->EstasViva() == true) {
	miHormiga->SetX(this->x);
	miHormiga->SetY(this->y);
	if (this->myAnt == NULL)
	  this->myAnt = miHormiga->Copiar();
	else {
	  delete this->myAnt;
	  this->myAnt = NULL;
	  this->myAnt = miHormiga->Copiar();
	}
	miHormiga->Morir();
	this->myAnt->Bloquear();
      }
    }
    return res;
  }

  // FUNCIONAMIENTO EstasViva:
  // Regresa si está viva la celda.
  // En este caso es inmortal.

  bool Celda_Tierra::EstasViva(void) {
    return vida;
  }

  // FUNCIONAMIENTO GetFiliacionHormiga:
  // Devuelve la filiación de la hormiga
  // posicionada en la celda. Si no hay
  // una hormiga en la celda se se devuelve
  // sin parentesco.

  int Celda_Tierra::GetFiliacionHormiga(void) {
    if (this->myAnt != NULL)
      return this->myAnt->GetFiliacion();
    else return SIN_PARENTESCO;
  }

  // FUNCIONAMIENTO GetFiliacion:
  // Devuelve la filiación de la celda
  // En este caso es sin parentesco.

  int Celda_Tierra::GetFiliacion(void) {
    return this->filiacion;
  }

  // FUNCIONAMIENTO HormigaEstaViva:
  // Devuelve si la hormiga está viva. 

  bool Celda_Tierra::HormigaEstaViva(void) {
    return(this->myAnt->EstasViva());
  }

  // FUNCIONAMIENTO SetHormiga:
  // Agrega una hormiga a la celda.

  void Celda_Tierra::SetHormiga(Hormiga* hormiga) {
    this->myAnt = hormiga;
  }

  // FUNCIONAMIENTO GetHormiga:
  // Devuelve la hormiga a la celda.

  Hormiga* Celda_Tierra::GetHormiga(void) {
    return(this->myAnt);
  }

  // FUNCIONAMIENTO CrearHormigaObrera:
  // Crea una hormiga obrera. En este caso
  // esta celda no puede crear una entonces es
  // una acción invalida.

  int Celda_Tierra::CrearHormigaObrera(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO CrearHormigaVoladora:
  // Crea una hormiga voladora. En este caso
  // esta celda no puede crear una entonces es
  // una acción invalida.

  int Celda_Tierra::CrearHormigaVoladora(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO CrearHormigaRecolectora:
  // Crea una hormiga recolectora. En este caso
  // esta celda no puede crear una entonces es
  // una acción invalida.

  int Celda_Tierra::CrearHormigaRecolectora(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO DesbloquearHormiga:
  // Desbloquea la hormiga posicionada sobre
  // ella para su uso.

  void Celda_Tierra::DesbloquearHormiga(int filiacion) {
    if (this->myAnt != NULL)
      this->myAnt->Desbloquear(filiacion);
  }

  // FUNCIONAMIENTO Desbloquear:
  // Desbloquea la Celda. En este caso
  // la celda siempre está desbloqueada.

  void Celda_Tierra::Desbloquear(int filiacion) {}

  // FUNCIONAMIENTO VerificarGenerarHormiguero:
  // Verifica si la hormiga puede generar un hormiguero.
  // En caso que no exista la hormiga es una acción
  // invalida.

  int Celda_Tierra::VerificarGenerarHormiguero(int filiacion) {
    if (this->myAnt != NULL)
      return (this->myAnt->VerificarGenerarHormiguero(filiacion));
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO BorrarHormiga:
  // Borra la hormiga de la celda.
 
  void Celda_Tierra::BorrarHormiga(void) {
    if (this->myAnt != NULL) {
      delete this->myAnt;
      this->myAnt = NULL;
    }
  }

  // FUNCIONAMIENTO Imprimir:
  // Imprime por STDOUT una 
  // representación actual del
  // estado de la celda.

  void Celda_Tierra::Imprimir(void) {
    if (this->myAnt != NULL) {
      this->myAnt->Imprimir();
    } else std::cout << TIERRA;
  }
	    
  // ATRIBUTOS CELDA COMIDA:
  //
  // X: Posición X de la celda.
  //
  // Y: Posición Y de la celda.
  //
  // MyANT: Puntero a hormiga que se encuentra
  // posicionada en la celda.
  //
  // FILIACIÓN: Determina a que jugador pertenece
  // la celda. En este caso no está afiliada a
  // ninguna.
  //
  // VIDA: Determina si la celda está viva o
  // muerta. En este caso siempre está viva. 
  //
  // BLOQUEO: Determina si la celda está
  // bloqueada para su uso. En este caso
  // está siempre desbloqueada.

  class Celda_Comida: public Celda {
  private:
    int x;
    int y;
    Hormiga *myAnt;
    int vida;
    int filiacion;
  public:
    Celda_Comida(int i, int j);
    ~Celda_Comida(void);
    virtual int recibir(Hormiga* miHormiga);
    virtual void SetHormiga(Hormiga* hormiga);
    virtual Hormiga* GetHormiga(void);
    virtual int CrearHormigaObrera(int filiacion);
    virtual int CrearHormigaVoladora(int filiacion);
    virtual int CrearHormigaRecolectora(int filiacion);
    virtual void DesbloquearHormiga(int filiacion);
    virtual void Desbloquear(int filiacion);
    virtual bool EstasViva(void);
    virtual bool HormigaEstaViva(void);
    virtual void BorrarHormiga(void);
    virtual int GetFiliacionHormiga(void);
    virtual int GetFiliacion(void);
    virtual int VerificarGenerarHormiguero(int filiacion);
    virtual void Imprimir(void);
  };

  // FUNCIONAMIENTO Constructor de Celda_Tierra:
  // Una celda se crea con su posición en el mapa,
  // En este caso la vida es eterna y no tiene 
  // parentesco con un usuario.

  Celda_Comida::Celda_Comida(int i, int j) {
    x = i;
    y = j; 
    myAnt = NULL;
    vida = true;
    filiacion = SIN_PARENTESCO;
  }

  // FUNCIONAMIENTO destructor de Celda_Comida:
  // Libero la memória dinámica de la hormiga.

  Celda_Comida::~Celda_Comida(void) {
    if (this->myAnt != NULL)
      delete myAnt;
  }  

  // FUNCIONAMIENTO Recibir:
  // Parte del doble despacho. Recibir permite
  // que la hormiga sepa la clase de la celda
  // a la que visita para poder determinar 
  // por polimorfismo a que método visitar llamar.
  // Aparte termina la lógicade visitar: 
  // Este caso particular si pudo recolectar le cambia
  // la posición a la de la celda. El resto de la lógica
  // la realiza mapa.

  int Celda_Comida::recibir(Hormiga* miHormiga) { 
    int res = miHormiga->visitar(this, this->myAnt);
    if (res == PUDO_RECOLECTAR) {
      miHormiga->SetX(this->x);
      miHormiga->SetY(this->y);
    }
    return res;
  }

  // FUNCIONAMIENTO HormigaEstaViva:
  // Devuelve si la hormiga está viva. 

  bool Celda_Comida::HormigaEstaViva(void) {
    return(this->myAnt->EstasViva());
  }

  // FUNCIONAMIENTO EstasViva:
  // Regresa si está viva la celda.
  // En este caso es inmortal.

  bool Celda_Comida::EstasViva(void) {
    return vida;
  }

  // FUNCIONAMIENTO GetFiliacionHormiga:
  // Devuelve la filiación de la hormiga
  // posicionada en la celda. Si no hay
  // una hormiga en la celda se se devuelve
  // sin parentesco.

  int Celda_Comida::GetFiliacionHormiga(void) {
    if (this->myAnt != NULL)
      return this->myAnt->GetFiliacion();
    return SIN_PARENTESCO;
  }

  // FUNCIONAMIENTO GetFiliacion:
  // Devuelve la filiación de la celda
  // En este caso es sin parentesco.

  int Celda_Comida::GetFiliacion(void) {
    return this->filiacion;
  }

  // FUNCIONAMIENTO SetHormiga:
  // Agrega una hormiga a la celda.

  void Celda_Comida::SetHormiga(Hormiga* hormiga) {
    this->myAnt = hormiga;
  }

  // FUNCIONAMIENTO GetHormiga:
  // Devuelve la hormiga a la celda.

  Hormiga* Celda_Comida::GetHormiga(void) {
    return(this->myAnt);
  }

  // FUNCIONAMIENTO CrearHormigaObrera:
  // Crea una hormiga obrera. En este caso
  // esta celda no puede crear una entonces es
  // una acción invalida.

  int Celda_Comida::CrearHormigaObrera(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO CrearHormigaVoladora:
  // Crea una hormiga voladora. En este caso
  // esta celda no puede crear una entonces es
  // una acción invalida.

  int Celda_Comida::CrearHormigaVoladora(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO CrearHormigaRecolectora:
  // Crea una hormiga recolectora. En este caso
  // esta celda no puede crear una entonces es
  // una acción invalida.

  int Celda_Comida::CrearHormigaRecolectora(int filiacion) {
    return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO DesbloquearHormiga:
  // Desbloquea la hormiga posicionada sobre
  // ella para su uso.

  void Celda_Comida::DesbloquearHormiga(int filiacion) {
    if (this->myAnt != NULL)
      this->myAnt->Desbloquear(filiacion);
  }

  // FUNCIONAMIENTO Desbloquear:
  // Desbloquea la Celda. En este caso
  // la celda siempre está desbloqueada.

  void Celda_Comida::Desbloquear(int filiacion) {}

  // FUNCIONAMIENTO VerificarGenerarHormiguero:
  // Verifica si la hormiga puede generar un hormiguero.
  // En caso que no exista la hormiga es una acción
  // invalida.

  int Celda_Comida::VerificarGenerarHormiguero(int filiacion) {
    if (this->myAnt != NULL) {
      return (this->myAnt->VerificarGenerarHormiguero(filiacion));
    } else return ACCION_INVALIDA;
  }
 
  // FUNCIONAMIENTO BorrarHormiga:
  // Borra la hormiga de la celda.

  void Celda_Comida::BorrarHormiga(void) {
    if (this->myAnt != NULL) {
      delete this->myAnt;
      this->myAnt = NULL;
    }
  }

  // FUNCIONAMIENTO Imprimir:
  // Imprime por STDOUT una 
  // representación actual del
  // estado de la celda.

  void Celda_Comida::Imprimir(void) {
    std::cout << COMIDA;
  }

  // ATRIBUTOS CELDA HORMIGUERO:
  //
  // X: Posición X de la celda.
  //
  // Y: Posición Y de la celda.
  //
  // MyANT: Puntero a hormiga que se encuentra
  // posicionada en la celda.
  //
  // FILIACIÓN: Determina a que jugador pertenece
  // la celda hormiguero.
  //
  // VIDA: Determina si la celda está viva o
  // muerta. 
  //
  // BLOQUEO: Determina si la celda está
  // bloqueada para su uso.

  class Celda_Hormiguero: public Celda {
  private:
    int x;
    int y;
    int filiacion;
    Hormiga *myAnt;
    bool vida;
    bool bloqueo;
  public:
    Celda_Hormiguero(int, int, int);
    ~Celda_Hormiguero(void);
    virtual int recibir(Hormiga* miHormiga);
    virtual void Desbloquear(int filiacion);
    virtual void SetHormiga(Hormiga* hormiga);
    virtual Hormiga* GetHormiga(void);
    virtual int CrearHormigaObrera(int filiacion);
    virtual int CrearHormigaVoladora(int filiacion);
    virtual int CrearHormigaRecolectora(int filiacion);
    virtual void DesbloquearHormiga(int filiacion);
    virtual bool EstasViva(void);
    virtual bool HormigaEstaViva(void);
    virtual void BorrarHormiga(void);
    virtual int GetFiliacionHormiga(void);
    virtual int GetFiliacion(void);
    virtual int VerificarGenerarHormiguero(int filiacion);
    virtual void Imprimir(void);
  };

  // FUNCIONAMIENTO Constructor de Celda_Hormiguero:
  // Una celda se crea con su posición en el mapa,
  // y con la filiacion de acuerdo al número de 
  // usuario.

  Celda_Hormiguero::Celda_Hormiguero(int i, int j, int numJugador) {
    x = i;
    y = j; 
    filiacion = numJugador;
    myAnt = NULL; 
    vida = true;
    bloqueo = false;
  }

  // FUNCIONAMIENTO Recibir:
  // Parte del doble despacho. Recibir permite
  // que la hormiga sepa la clase de la celda
  // a la que visita para poder determinar 
  // por polimorfismo a que método visitar llamar.
  // Aparte termina la lógica de las colisiones con 
  // los resultados de visitar: Si la hormiga visitante
  // vive, celda realiza una copia de esta a su celda
  // y la visitante muere. La nueva hormiga se bloquea
  // para su uso. Si había una hormiga en la celda
  // y hubo colisión ocurre que murió, entonces borra
  // la memoria dinámica de la hormiga y hace la copia
  // de la visitante. 
  // En el caso de hormiguero al ser un elemento con vida 
  // mortal recibir resuelve la lógica de la colisión con 
  // ente celda y la hormiga visitante:
  // Si la hormiga visitante y la celda son de 
  // la misma filiación la celda no muere, caso contrario
  // ocurre lo contrario. 
  // El último caso es la triple colisión: Si la colisión
  // resultó en que murieron las dos hormigas, entonces
  // son de la misma filiación, entonces la celda muere
  // porque por lógica del programa el hormiguero
  // es fraterno a ellas porque este no puede contener 
  // una hormiga de distinta filiación.
  // Entonces si muere las hormigas muere el hormiguero.

  int Celda_Hormiguero::recibir(Hormiga* miHormiga) { 
    int res = miHormiga->visitar(this, this->myAnt);
    if (miHormiga->EstasViva() == true) {
      miHormiga->SetX(this->x);
      miHormiga->SetY(this->y);
      if (this->myAnt == NULL)
	this->myAnt = miHormiga->Copiar();
      else {
	delete this->myAnt;
	this->myAnt = NULL;
	this->myAnt = miHormiga->Copiar();
      }
      miHormiga->Morir();
      this->myAnt->Bloquear();
      if (this->filiacion != this->myAnt->GetFiliacion()) 
	this->vida = false;
    } else this->vida = false;
   
    return res;
  }

  // FUNCIONAMIENTO destructor de Celda_Comida:
  // Libero la memória dinámica de la hormiga.

  Celda_Hormiguero::~Celda_Hormiguero(void) {
    if (this->myAnt != NULL)
      delete myAnt;
  }  
  
  // FUNCIONAMIENTO BorrarHormiga:
  // Borra la hormiga de la celda.

  void Celda_Hormiguero::BorrarHormiga(void) {
    if (this->myAnt != NULL) {
      delete this->myAnt;
      this->myAnt = NULL;
    }
  }

  // FUNCIONAMIENTO HormigaEstaViva:
  // Devuelve si la hormiga está viva. 

  bool Celda_Hormiguero::HormigaEstaViva(void) {
    return(this->myAnt->EstasViva());
  }
 
  // FUNCIONAMIENTO EstasViva:
  // Regresa si está viva el hormiguero.

  bool Celda_Hormiguero::EstasViva(void) {
    return vida;
  }

  // FUNCIONAMIENTO GetFiliacionHormiga:
  // Devuelve la filiación de la hormiga
  // posicionada en la celda. Si no hay
  // una hormiga en la celda se se devuelve
  // sin parentesco.

  int Celda_Hormiguero::GetFiliacionHormiga(void) {
    if (this->myAnt != NULL)
      return this->myAnt->GetFiliacion();
    return SIN_PARENTESCO;
  }

  // FUNCIONAMIENTO Desbloquear:
  // Desbloquea la Celda. Si la filiación
  // coincide se desbloquea.

  void Celda_Hormiguero::Desbloquear(int filiacion) {
    if (this->filiacion == filiacion)
      if (this->bloqueo == true)
	this->bloqueo = false;
  }
 
  // FUNCIONAMIENTO SetHormiga:
  // Agrega una hormiga a la celda.

  void Celda_Hormiguero::SetHormiga(Hormiga* hormiga) {
    this->myAnt = hormiga;
  }

  // FUNCIONAMIENTO GetHormiga:
  // Devuelve la hormiga a la celda.

  Hormiga* Celda_Hormiguero::GetHormiga(void) {
    return(this->myAnt);
  }

  // FUNCIONAMIENTO CrearHormigaObrera:
  // Crea una hormiga obrera en caso que 
  // el hormiguero no esté bloqueado, sea
  // del usuario que la llamó y no exista una 
  // hormiga allí. Si no se cumple alguna condición
  // es acción invalida.

  int Celda_Hormiguero::CrearHormigaObrera(int filiacion) {
    if (this->bloqueo == false) {
      if (this->filiacion == filiacion) {
	if (this->myAnt == NULL) {
	  myCeldaYHormiga::Hormiga *ant = 
	    new myCeldaYHormiga::Hormiga_Obrera(this->x, this->y, filiacion);
	  this->myAnt = ant;
	  this->bloqueo = true;
	} else return ACCION_INVALIDA;
      } else return ACCION_INVALIDA;
    } else return ACCION_INVALIDA;
    return ACCION_VALIDA;
  }

  // FUNCIONAMIENTO CrearHormigaVoladora:
  // Crea una hormiga voladora en caso que 
  // el hormiguero no esté bloqueado, sea
  // del usuario que la llamó y no exista una 
  // hormiga allí. Si no se cumple alguna condición
  // es acción invalida.

  int Celda_Hormiguero::CrearHormigaVoladora(int filiacion) {
    if (this->bloqueo == false) {
      if (this->filiacion == filiacion) {
	if (this->myAnt == NULL) {
	  myCeldaYHormiga::Hormiga *ant = 
	    new myCeldaYHormiga::Hormiga_Voladora(this->x, this->y, filiacion);
	  this->myAnt = ant;
	  this->bloqueo = true;
	} else return ACCION_INVALIDA;
      } else return ACCION_INVALIDA;
    } else return ACCION_INVALIDA;
    return ACCION_VALIDA;
  }

  // FUNCIONAMIENTO CrearHormigaRecolectora:
  // Crea una hormiga recolectora en caso que 
  // el hormiguero no esté bloqueado, sea
  // del usuario que la llamó y no exista una 
  // hormiga allí. Si no se cumple alguna condición
  // es acción invalida.

  int Celda_Hormiguero::CrearHormigaRecolectora(int filiacion) {
    if (this->bloqueo == false) {
      if (this->filiacion == filiacion) {
	if (this->myAnt == NULL) {
	  myCeldaYHormiga::Hormiga *ant = 
	    new myCeldaYHormiga::Hormiga_Recolectora(this->x, this->y, filiacion);
	  this->myAnt = ant;
	  this->bloqueo = true;
	} else return ACCION_INVALIDA;
      } else return ACCION_INVALIDA;
    } else return ACCION_INVALIDA;
    return ACCION_VALIDA;
  }

  // FUNCIONAMIENTO GetFiliacion:
  // Devuelve la filiación del hormiguero.
  
  int Celda_Hormiguero::GetFiliacion(void) {
    return this->filiacion;
  }

  // FUNCIONAMIENTO VerificarGenerarHormiguero:
  // Verifica si la hormiga puede generar un hormiguero.
  // En caso que no exista la hormiga es una acción
  // invalida.

  int Celda_Hormiguero::VerificarGenerarHormiguero(int filiacion) {
    if (this->myAnt != NULL) {
      return (this->myAnt->VerificarGenerarHormiguero(filiacion));
    } else return ACCION_INVALIDA;
  }

  // FUNCIONAMIENTO DesbloquearHormiga:
  // Desbloquea la hormiga posicionada sobre
  // ella para su uso.

  void Celda_Hormiguero::DesbloquearHormiga(int filiacion) {
    if (this->myAnt != NULL)
      this->myAnt->Desbloquear(filiacion);
  }

  // FUNCIONAMIENTO Imprimir:
  // Imprime por STDOUT una 
  // representación actual del
  // estado de la celda.

  void Celda_Hormiguero::Imprimir(void) {
    if (this->myAnt != NULL) {
      std::cout << "(" << this->filiacion;
      this->myAnt->Imprimir();
      std::cout << ")";
    } else std::cout << this->filiacion;
  }
}
#endif
