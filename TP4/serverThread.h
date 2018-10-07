/*
 * Thread.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>
#include <iostream>

// Thread: Clase que crea un hilo para 
// cliente. 

// ATRIBUTOS:
//
// P: El thread de pthread.
//

class Thread {
public:
  Thread();
  virtual void start() {
    pthread_create(&this->t, 0, callback, this);
  }
  virtual void stop() = 0;
  virtual void join();
  virtual void run() = 0;
  virtual ~Thread();
private:
  pthread_t t;
  static void* callback(void* o) {
    ((Thread*)o)->run();
    return 0;
  }
  Thread(const Thread &c) {}
  Thread& operator =(const Thread &c);
};

#endif
