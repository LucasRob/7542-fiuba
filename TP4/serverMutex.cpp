#include "serverMutex.h"

// FUNCIONAMIENTO MUTEX:
// Crea el mutex.

Security::Mutex::Mutex() {
  pthread_mutex_init(&m, 0);
}

// FUNCIONAMIENTO ~MUTEX:
// Destruye el mutex.

Security::Mutex::~Mutex() {
  pthread_mutex_destroy(&m);
}

// FUNCIONAMIENTO LOCK:
// Bloquea una operación para varios
// hilos. 

void Security::Mutex::lock() {
  pthread_mutex_lock(&m);
}

// FUNCIONAMIENTO UNLOCK:
// Desbloquea el mutex.

void Security::Mutex::unlock() {
  pthread_mutex_unlock(&m);
}

// FUNCIONAMIENTO LOCK:
// Bloquea el mutex.

Security::Lock::Lock(Mutex &m):m(m) {
  m.lock();
}

// FUNCIONAMIENTO ~LOCK:
// Desbloquea el mutex.

Security::Lock::~Lock() {
  m.unlock();
}
