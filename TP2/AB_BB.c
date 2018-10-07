#include "AB_BB.h"


// FUNCIONAMIENTO ENCONTRAR_MI:
// Encuentra el valor más chico de una rama 
// que es el elemento más a la izquierda de
// una rama.

TNodoAB_BB* Encontrar_Min(TNodoAB_BB* temp) { 
  if (temp == NULL || temp->izq == NULL)
    return temp;
  return Encontrar_Min(temp->izq);
}

// FUNCIONAMIENTO BuscarPadre:
// Busca el padre de un nodo
// a partir de conocer el hijo. 
// Se busca a partir de la raíz

TNodoAB_BB* BuscarPadre(TNodoAB_BB *padre, TNodoAB_BB *hijo) {
  TNodoAB_BB *pAux = NULL;
  if ((padre->izq == hijo) || (padre->der == hijo))
    return padre;
  else {
    if (padre->izq != NULL)
      pAux = BuscarPadre(padre->izq, hijo);
    if ((padre->der != NULL) && (pAux == NULL))
      pAux = BuscarPadre(padre->der, hijo);
    return pAux;
  }
}

// FUNCIONAMIENTO rama_hijo:
// Determina a que rama pertenece un
// hijo.

unsigned short int rama_hijo(TNodoAB_BB *padre, TNodoAB_BB *hijo) {
  if (padre -> izq == hijo) 
    return AB_BB_IZQ;
  else return AB_BB_DER;
}
 
// FUNCIONAMIENTO AB_BB_BorrarCte:
// Borra elemento corriente del árbol
// Hay diferentes casos si el nodo es hoja,
// si es un elemento con hijos o si le falta
// algún hijo.

void AB_BB_BorrarCte(TAB_BB *ab) {
  TNodoAB_BB *pAux = NULL, *padre = NULL;
  unsigned short int rama = 0;
  if (ab->cte->izq && ab->cte->der) {
    pAux = Encontrar_Min(ab->cte->der);  // Encuentra el mínimo de 
    // rama derecha
    padre = BuscarPadre(ab->raiz, pAux);  // Busca el padre del mínimo
    AB_BB_ModifCte(ab, pAux->elem);  // Modifica el valor por el encontrado
    if (padre != NULL)  // si existe
      rama = rama_hijo(padre, pAux);  // busco la rama del hijo
    if (rama == AB_BB_IZQ) {  // si el hijo esta a la izq.
      free(pAux->elem);  // Elimina el mínimo
      free(pAux);
      padre->izq = NULL;  // Elimina la referencia
    } else {  // si el hijo esta a la der.
      free(pAux->elem);  // Elimina el mínimo
      free(pAux);
      padre->der = NULL;  // Elimina la referencia
    }
  } else {
    padre = BuscarPadre(ab->raiz, ab->cte);  // busco padre
    if (padre != NULL)  // si existe
      rama = rama_hijo(padre, ab->cte);  // busco la rama del hijo
    if ((ab->cte->izq == NULL) && (ab->cte->der == NULL)) {  // si es hoja
      if (padre == NULL) {  // si no tiene padre es la raíz
	pAux = ab->raiz;
	ab->raiz = NULL;
	ab->cte = NULL;
	free(pAux->elem);
	free(pAux);
      } else {
	if (rama == AB_BB_IZQ) {
	  pAux = ab->cte;
	  ab->cte = padre;  // El corriente es el padre
	  free(pAux->elem);
	  free(pAux);
	  ab->cte->izq = NULL;
	} else {
	  pAux = ab->cte;
	  ab->cte = padre;
	  free(pAux->elem);
	  free(pAux);  // El corriente es el padre
	  ab->cte->der = NULL;
	}
      }
    } else if (ab->cte->izq == NULL) {  // Si no tiene hijo izq
      pAux = ab->cte;
      ab->cte = ab->cte->der;  // El cte es el de la derecha a el
      if (pAux == ab->raiz)   // si es la raíz
	ab->raiz = ab->cte;
      else  if (rama == AB_BB_IZQ)  // si no es la raíz se fija el abuelo del 
	padre->izq = ab->cte;  // cte y lo hace apuntar al nieto
      else padre->der = ab->cte;
      free(pAux->elem);
      free(pAux);
    } else {
      pAux = ab->cte,
	ab->cte = ab->cte->izq;  // El cte es el de la derecha a el
      if (pAux == ab->raiz)  // si es la raíz
	ab->raiz = ab->cte;
      else  if (rama == AB_BB_IZQ)  // si no es la raíz se fija el abuelo del 
	padre->izq = ab->cte;  // cte y lo hace apuntar al nieto
      else padre->der = ab->cte;
      free(pAux->elem);
      free(pAux);
    } 
  }
}

// FUNCIONAMIENTO AB_BB_Crear:
// Crea el árbol.

void AB_BB_Crear(TAB_BB *ab, int tdato) {
  ab->tamdato = tdato;
  ab->raiz = NULL;
  ab->cte = NULL;
}

// FUNCIONAMIENTO AB_BB_ElemCte:
// Devuelve el elemento corriente.

void AB_BB_ElemCte(TAB_BB ab, void *elem) {
  memcpy(elem, ab.cte->elem, ab.tamdato);
}

// FUNCIONAMIENTO AB_BB_ElemCte:
// Modifica el elemento corriente.

void AB_BB_ModifCte(TAB_BB *ab, void *elem) {
  memcpy(ab->cte->elem, elem, ab->tamdato);
}

// FUNCIONAMIENTO AB_BB_MoverCte:
// Mueve el corriente según el movimiento.

void AB_BB_MoverCte(TAB_BB *ab, TMovimiento_AB_BB mov, int *error) {
  *error = 0;
  switch (mov) {
  case AB_BB_IZQ : if (ab->cte->izq != NULL)
      ab->cte = ab->cte->izq;
    else
      *error = 1;
    break;
  case AB_BB_DER : if (ab->cte->der != NULL)
      ab->cte = ab->cte->der;
    else
      *error = 1;
    break;
  case AB_BB_PAD : if (ab->cte != ab->raiz)
      ab->cte = BuscarPadre(ab->raiz, ab->cte);
    else
      *error = 1;
    break;
  case AB_BB_RAIZ : if (ab->raiz != NULL)
      ab->cte = ab->raiz;
    else
      *error = 1;
    break;
  default : *error = 1;
  }
}

// FUNCIONAMIENTO VaciarSub:
// Vacía un sub árbol de un árbol
// es parte de AB_BB_Vaciar.

void VaciarSub(TNodoAB_BB *pnodo) {
  if (pnodo != NULL) {
    if ((pnodo->izq == NULL) && (pnodo->der == NULL)) {
      free(pnodo->elem);
      free(pnodo);
    }
    else {
      VaciarSub(pnodo->izq);
      VaciarSub(pnodo->der);
      free(pnodo->elem);
      free(pnodo);
    }
  }
}

// FUNCIONAMIENTO AB_BB_Vaciar:
// Vacía el árbol recorriendo sus
// sus subárboles.

void AB_BB_Vaciar(TAB_BB *ab) {
  VaciarSub(ab->raiz);
  ab->raiz = NULL;
  ab->cte = NULL;
}

// FUNCIONAMIENTO AB_BB_Insertar:
// Inserta un elemento según el movimiento

void AB_BB_Insertar(TAB_BB *ab, int mov, void *elem, int *error) {
  TNodoAB_BB *pAux;
  *error = 0;
  pAux = (TNodoAB_BB*) malloc(sizeof(TNodoAB_BB));
  pAux->izq = NULL;
  pAux->der = NULL;
  if (pAux) {
    pAux->elem = malloc(ab->tamdato);
    if (pAux->elem) {
      memcpy(pAux->elem, elem, ab->tamdato);
      switch (mov) {
      case AB_BB_IZQ : if (ab->cte->izq == NULL)
	  ab->cte->izq = pAux;
	else
	  *error = 1;
	break;
      case AB_BB_DER : if (ab->cte->der == NULL)
	  ab->cte->der = pAux;
	else
	  *error = 1;
	break;
      case AB_BB_RAIZ : if (ab->raiz == NULL)
	  ab->raiz = pAux;
	else
	  *error = 1;
	break;
      default : *error = 1;
      }
      if (*error) {
	free(pAux->elem);
	free(pAux);
      }
      else
	ab->cte = pAux;
    }
    else {  // if (pAux->elem)
      *error = 1;
      free(pAux);
    }
  }
  else  // if (paux)
    *error = 1;
}

// FUNCIONAMIENTO AB_BB_Insertar_Ordenado:
// Inserta un elemento según ordenadamente.
// La convención es los hijos menores a la
// izquierda del padre, sino a la derecha.
// Esto se realiza con la función de comparación
// pasada por parámetro. El algoritmo funciona si
// se puede mover al lugar que debe insertar el elemento
// si pudo lo inserta, sino mueve y compara con aquel.
// si un elemento da igual genera error. 

int AB_BB_Insertar_Ordenado(TAB_BB *ab, void* elem, 
int(*comparar)(void*, void*)) {
  int error;
  int res;
  void* elem2 = 0; 

  if (AB_BB_Vacio(*ab)) {  // Si está vacio.
    AB_BB_Insertar(ab, AB_BB_RAIZ, elem, &error);  // Inserta en la raíz.
    return AB_BB_INSERTADO;
  } else {  // Si está lleno
    elem2 = malloc(sizeof(ab->tamdato));
    AB_BB_ElemCte(*ab, elem2);  // Obtengo el corriente.
    res = comparar(elem, elem2);  // Compara con el elmento ingresado
    free(elem2);
    if (res == AB_BB_MENOR) {  // Si es menor trata de ir a un nodo izq.
      AB_BB_MoverCte(ab, AB_BB_IZQ, &error);
      if (error == 1) {  // Si no pudo mover, lo inserta allí.
	AB_BB_Insertar(ab, AB_BB_IZQ, elem, &error);
	return AB_BB_INSERTADO;
      } else return(AB_BB_Insertar_Ordenado(ab, elem, comparar));
    } else if (res == AB_BB_MAYOR) {  // Si es mayor trata de ir a la derecha.
      AB_BB_MoverCte(ab, AB_BB_DER, &error);
      if (error == 1) {  // Si no hay elementos a la derecha, lo inserta allí.
	AB_BB_Insertar(ab, AB_BB_DER, elem, &error);
	return AB_BB_INSERTADO;
      } else return(AB_BB_Insertar_Ordenado(ab, elem, comparar));
    } else return ERR_AB_BB_INSERTAR_IGUAL;  // Si es igual lo informa.
  }
}

// FUNCIONAMIENTO AB_BB_Busqueda:
// Busca un elemento. Sigue las mismas
// reglas que AB_BB_Insertar_Ordenado.

int AB_BB_Busqueda(TAB_BB *ab, void* elem, int(*comparar)(void*, void*)) {
  int error;
  int res;
  void* elem2 = malloc(sizeof(ab->tamdato));

  AB_BB_ElemCte(*ab, elem2);  // Obtiene el corriente.
  res = comparar(elem, elem2);  // Lo compara con el ingresado.
  free(elem2);
  if (res == AB_BB_MENOR) {  // Si es menor va hacia la rama izquierda
    AB_BB_MoverCte(ab, AB_BB_IZQ, &error);
    if (error == 1) 
      return ERR_AB_BB_BUSQUEDA_NO_ENCONTRADO;  // Si no hay más 
    // elementos devuelve error.
    else return(AB_BB_Busqueda(ab, elem, comparar));
  } else if (res == AB_BB_MAYOR) {  // Si es mayor va hacia la rama derecha.
    AB_BB_MoverCte(ab, AB_BB_DER, &error);
    if (error == 1) 
      return ERR_AB_BB_BUSQUEDA_NO_ENCONTRADO;  // Si no hay más elementos
    // devuelve error.
    else return(AB_BB_Busqueda(ab, elem, comparar));
  } else return AB_BB_ENCONTRADO;
}

// FUNCIONAMIENTO AB_BB_Vacio:
// Verifica si un árbol está vacío

int AB_BB_Vacio(TAB_BB ab) {
  if (ab.raiz == NULL)
    return  ERR_AB_BB_VACIO;
  else return AB_BB_NO_VACIO;
}


