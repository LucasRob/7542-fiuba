/*
 * Mutex.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __MUTEX_H__
#define __MUTEX_H__

#include <pthread.h>
#include <iostream>

// Mutex: Clase que encapsula
// la clase de pthread mutex.
// Permite que varios hilos que 
// quieran acceder a un elemento al mismo
// tiempo esperen hasta que uno termine
// 

// ATRIBUTOS:
//
// M: El mutex de pthread.
//

namespace Security {

  class Mutex {
  private:
    pthread_mutex_t m;
    Mutex(const Mutex &c) {};
    Mutex& operator =(const Mutex &m);
  public:
    Mutex(void);
    ~Mutex();
    void lock();
    void unlock();
    friend class Lock;
  };

// Lock: Una mejora a la clase
// mutex.

// ATRIBUTOS:
//
// M: El mutex a utilizar.
//

  class Lock {
  private:
    Mutex &m;
  Lock(const Lock &c):m(c.m) {};
    Lock& operator =(const Lock &l);
  public:
    explicit Lock(Mutex &m);
    ~Lock();
  };
}

#endif

