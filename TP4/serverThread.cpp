#include "serverThread.h"

// FUNCIONAMIENTO JOIN:
// Cierra el hilo.

void Thread::join() {
  void *p;
  pthread_join(this->t, &p);
}

Thread::Thread() {
}

Thread::~Thread() {
}


