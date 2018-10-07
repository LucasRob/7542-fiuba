#include "TP2_Operaciones.h"



// FUNCIONAMIENTO Crear_Usuario:
// Crea un usuario a partir de los datos
// pasados por parámetro

void Crear_Usuario(TDA_USU** usu, char* usuario, 
char* apellido, char* nombres, T_LSB** pedidos) {
  *pedidos = (T_LSB*)malloc(sizeof(T_LSB));
  LSB_Crear(*pedidos, sizeof(TDA_PEDIDO*));
  *usu = (TDA_USU*)malloc(sizeof(TDA_USU));
  TDA_USU_Crear(*usu, usuario, apellido, nombres, *pedidos);
}


// FUNCIONAMIENTO Borrar_Usuario:
// Borra un usuario con su memoria
// dinámica

void Borrar_Usuario(TDA_USU** usu) {
  TDA_USU_Destruir(*usu);
  free(*usu);
  *usu = NULL;
}

// FUNCIONAMIENTO Crear_Usuario_Búsqueda:
// Crea un usuario para realizar búsquedas
// La diferencia con Crear_Usuario es que
// no llena todo el tipo sino lo necesario
// para poder realizar una 

void Crear_Usuario_Busqueda(TDA_USU** usu_bus, char* user, 
char* apellido, char* nombres, T_LSB* pedidos) {
  *usu_bus = (TDA_USU*)malloc(sizeof(TDA_USU));  // Creo un TDA_USU para buscar
  TDA_USU_Crear(*usu_bus, user, apellido, nombres, pedidos);
}

// FUNCIONAMIENTO Borrar_Usuario_Bus:
// Borra un usuario búsqueda pero
// solo la memoria reservada para él
// no la dinámica que contiene.

void Borrar_Usuario_Bus(TDA_USU** usu_bus) {
  free(*usu_bus);
  *usu_bus = NULL;
}

// FUNCIONAMIENTO Crear_Pedido:
// Crea un pedido a partir de los datos
// pasados por parámetro

void Crear_Pedido(TDA_PEDIDO** pedido, unsigned int nPedido, 
char* descripcion, unsigned int nPaq, T_LSB** itis, T_LSB** paqs) {
  *pedido = (TDA_PEDIDO*)malloc(sizeof(TDA_PEDIDO));
  *itis = (T_LSB*)malloc(sizeof(T_LSB)); 
  LSB_Crear(*itis, sizeof(TDA_ITI*));
  *paqs = (T_LSB*)malloc(sizeof(T_LSB)); 
  LSB_Crear(*paqs, sizeof(TDA_PAQ*));
  TDA_PEDIDO_Crear(*pedido, nPedido, descripcion, nPaq, *paqs, *itis); 
}

// FUNCIONAMIENTO Borrar_Pedido:
// Borra un pedido con su memoria
// dinámica

void Borrar_Pedido(TDA_PEDIDO** pedido) {
  TDA_PEDIDO_Destruir(*pedido);
  free(*pedido);
  *pedido = NULL;
}

// FUNCIONAMIENTO Crear_Pedido_Busqueda:
// Crea un pedido para realizar busquedas
// La diferencia con Crear_Pedido es que
// no llena todo el tipo sinó lo necesario
// para poder realizar una búsqueda

void Crear_Pedido_Busqueda(TDA_PEDIDO** pedido_bus, 
unsigned int nPedido, char* descripcion, unsigned int nPaq, 
T_LSB* itis, T_LSB* paqs) {
  *pedido_bus = (TDA_PEDIDO*)malloc(sizeof(TDA_PEDIDO)); 
  TDA_PEDIDO_Crear(*pedido_bus, nPedido, descripcion, nPaq, paqs, itis); 
}

// FUNCIONAMIENTO Borrar_Pedido_Bus:
// Borra un pedido búsqueda pero
// solo la memoria reservada para él
// no la dinámica que contiene.

void Borrar_Pedido_Bus(TDA_PEDIDO** pedido_bus) {
  free(*pedido_bus);
  *pedido_bus = NULL;
}

// FUNCIONAMIENTO Crear_Index:
// Crea un índice a partir de los datos
// pasados por parámetro

void Crear_Index(TDA_INDEX** index, char* usuario, unsigned int nPedido) {
  *index = (TDA_INDEX*)malloc(sizeof(TDA_INDEX));
  TDA_INDEX_Crear(*index, usuario, nPedido);
}

// FUNCIONAMIENTO Borrar_Index_Bus:
// Borra un índice búsqueda pero
// solo la memoria reservada para él
// no la dinámica que contiene.

void Borrar_Index_Bus(TDA_INDEX** index) {
    free(*index);
    *index = NULL;
}

// FUNCIONAMIENTO Borrar_Indice:
// Borra un índice con su memoria
// dinámica

void Borrar_Index(TDA_INDEX** index) {
  TDA_INDEX_Destruir(*index);  
  free(*index);
  *index = NULL;
}

// FUNCIONAMIENTO Crear_Paquete:
// Crea un paquete a partir de los datos
// pasados por parámetro

void Crear_Paquete(TDA_PAQ** paq, unsigned int nPaq, 
char* contenido, char* ubicacion) {
  *paq = (TDA_PAQ*)malloc(sizeof(TDA_PAQ));
  TDA_PAQ_Crear(*paq, nPaq, ubicacion, ENVIADO, contenido);
}

// FUNCIONAMIENTO Borrar_Paquete:
// Borra un Paquete con su memoria
// dinámica

void Borrar_Paquete(TDA_PAQ** paquete) {
  TDA_PAQ_Destruir(*paquete);
  free(*paquete);
  *paquete = NULL;
}

// FUNCIONAMIENTO Borrar_Paquete_Bus:
// Borra un paquete búsqueda pero
// solo la memoria reservada para él
// no la dinámica que contiene.

void Borrar_Paquete_Bus(TDA_PAQ** paquete) {
  free(*paquete);
  *paquete = NULL;
}

// FUNCIONAMIENTO Crear_Itinerario:
// Crea un itinerario a partir de los datos
// pasados por parámetro

void Crear_Itinerario(TDA_ITI** iti, unsigned int nPaq, 
char* ubicacion, char* fecha, char* descripcion) {
  *iti = (TDA_ITI*)malloc(sizeof(TDA_ITI));
  TDA_ITI_Crear(*iti, nPaq, ubicacion, fecha, descripcion);
}

// FUNCIONAMIENTO Borrar_Itinerario:
// Borra un itinerario con su memoria
// dinámica

void Borrar_Itinerario(TDA_ITI** iti) {
  TDA_ITI_Destruir(*iti);
  free(*iti);
  *iti = NULL;
}

// FUNCIONAMIENTO Borrar_Itinerario_Bus:
// Borra un itinerario búsqueda pero
// solo la memoria reservada para él
// no la dinámica que contiene.

void Borrar_Itinerario_Bus(TDA_ITI** iti_bus) {
  free(*iti_bus);
  *iti_bus = NULL;
}

// FUNCIONAMIENTO Agregar_Usuario:
// Agrega un usuario a la estructura.
// verifica que no se haya ingresado antes. 
// En caso afirmativo lo ingresa sino muestra
// un mensaje de error por stderr.

void Agregar_Usuario(TDA_SHOP_TRACK* shop_track, 
char* usuario, char*  apellido, char*  nombres) {
  TDA_USU* usu = NULL;
  T_LSB* pedidos = NULL;
  TAB_BB* usuarios = NULL;
  int res = 1,  error = 1;
  Crear_Usuario(&usu, usuario, apellido, 
nombres, &pedidos);  // Crea la estructura para insertarlo
  TDA_SHOP_TRACK_Get_Usuarios(*shop_track, &usuarios);  // Obtengo usuarios
  if (!(AB_BB_Vacio(*usuarios))) {  // Si usuarios no está vacío
    AB_BB_MoverCte(usuarios, AB_BB_RAIZ, &error);
    res = AB_BB_Busqueda(usuarios, &usu, TDA_USU_Get_Comparador(*usu));
    if (res == AB_BB_ENCONTRADO) {  // Si lo encuentra imprime por stderr
      fprintf(stdout, "Error\n");
      fprintf(stderr, "El usuario '%s' ya existe\n", usuario);
      Borrar_Usuario(&usu);
    } else {  // Lo inserta
      AB_BB_MoverCte(usuarios, AB_BB_RAIZ, &res);
      AB_BB_Insertar_Ordenado(usuarios, &usu, TDA_USU_Get_Comparador(*usu));
      fprintf(stdout, "Usuario '%s' agregado\n", usuario);
    }
  } else {  // Si está vacío lo inserta primero
    fprintf(stdout, "Usuario '%s' agregado\n", usuario);
    AB_BB_Insertar_Ordenado(usuarios, &usu, TDA_USU_Get_Comparador(*usu));
  }
}  

// FUNCIONAMIENTO Eliminar_Usuario_Itinerarios:
// Elimina los itinerarios de un pedido de
// un usuario recorriendo la lista y liberando
// memoria 

void Eliminar_Usuario_Itinerarios(T_LSB** itinerarios) {
  TDA_ITI* iti;
  int mov = 0;

  mov = LSB_MoverCte(*itinerarios, LSB_PRIMERO);
  while (mov == LSB_MOVIDO) {
    LSB_ElemCte(**itinerarios, &iti);
    Borrar_Itinerario(&iti);  // Libera la memoria dinámica del iti
    mov = LSB_MoverCte(*itinerarios, LSB_SIGUIENTE);
  }
}

// FUNCIONAMIENTO Eliminar_Usuario_Paquetes:
// Elimina los paquete de un pedido de
// un usuario recorriendo la lista y liberando
// memoria 

void Eliminar_Usuario_Paquetes(T_LSB** paquetes) {
  TDA_PAQ* paq;
  int mov = 0;
  mov = LSB_MoverCte(*paquetes, LSB_PRIMERO);
  while (mov == LSB_MOVIDO) {
    LSB_ElemCte(**paquetes, &paq);
    Borrar_Paquete(&paq);  // Libera la memoria dinámica del paq
    mov = LSB_MoverCte(*paquetes, LSB_SIGUIENTE);
  }
}

// FUNCIONAMIENTO Eliminar_Usuario_Pedidos:
// Elimina los pedidos de un usuario recorriendo 
// la lista liberando los itinerarios y los
// paquetes de ser necesario. También libera
// los índices asociados con los número de 
// pedido

void Eliminar_Usuario_Pedidos(TDA_SHOP_TRACK** shop_track, T_LSB** pedidos) {
  TAB_BB* indices;
  TDA_INDEX* index, *index_bus;
  TDA_PEDIDO* pedido = NULL;
  T_LSB* itis = NULL;
  T_LSB* paqs = NULL;
  int res = 1, mov = 0;

  TDA_SHOP_TRACK_Get_Indices(**shop_track, &indices);  // Obtiene índices
  mov = LSB_MoverCte(*pedidos, LSB_PRIMERO); 
  while (mov == LSB_MOVIDO) {  // Mientras haya pedidos 
    LSB_ElemCte(**pedidos, &pedido);  // Obtiene pedido 
    AB_BB_MoverCte(indices, AB_BB_RAIZ, &res); 
    Crear_Index(&index_bus, " ", 
TDA_PEDIDO_Get_nPedido(*pedido));  // Crea un índice para buscar
    res = AB_BB_Busqueda(indices, &index_bus, 
TDA_INDEX_Get_Comparador(*index_bus)); 
    if (res == AB_BB_ENCONTRADO) {  // Si lo encuentra lo borra 
      AB_BB_ElemCte(*indices, &index);
      AB_BB_BorrarCte(indices);
      Borrar_Index(&index);
    }
    Borrar_Index_Bus(&index_bus);
    TDA_PEDIDO_Get_Itinerarios(*pedido, &itis);  // Obtiene itinerarios
    res = LSB_Vacia(*itis); 
    if (res == 0) {
      Eliminar_Usuario_Itinerarios(&itis);  // Los elimina de haber
    }
    LSB_Vaciar(itis);
    TDA_PEDIDO_Get_Paquetes(*pedido, &paqs);  // Obtiene paquetes
    res = LSB_Vacia(*paqs); 
    if (res == 0) {
      Eliminar_Usuario_Paquetes(&paqs);  // Los elimina de haber 
    }
    LSB_Vaciar(paqs);
    Borrar_Pedido(&pedido);  // Borra el pedido actual de la lista
    mov = LSB_MoverCte(*pedidos, LSB_SIGUIENTE);
  }
}

// FUNCIONAMIENTO Eliminar_Usuario_Pedidos:
// Elimina el usuario de la estructura 


void Eliminar_Usuario_Actual(T_LSB** pedidos, 
TAB_BB** usuarios, TDA_USU** usu) {
  LSB_Vaciar(*pedidos);  // Destruyo pedidos
  AB_BB_BorrarCte(*usuarios);  // Borro el usuario del árbol
  Borrar_Usuario(usu);  // Borro el usuario propiamente dicho
}

// FUNCIONAMIENTO Eliminar_Usuario:
// Elimina el usuario de la estructura
// Verificando si existe (de no ser así 
// se manda un mensaje por stderr) 

int Eliminar_Usuario(TDA_SHOP_TRACK* shop_track, char* usuario) {
  TAB_BB* usuarios;
  T_LSB* pedidos = NULL;
  TDA_USU* usu_bus = NULL, *usu = NULL;
  int res = 1;
  Crear_Usuario_Busqueda(&usu_bus, usuario, " ", " ", NULL);
  TDA_SHOP_TRACK_Get_Usuarios(*shop_track, &usuarios);  // Obtengo usuarios
  if (!(AB_BB_Vacio(*usuarios))) {  // Si usuarios no está vacio
    AB_BB_MoverCte(usuarios, AB_BB_RAIZ, &res);
    res = AB_BB_Busqueda(usuarios, &usu_bus, TDA_USU_Get_Comparador(*usu_bus));
    if (res == ERR_AB_BB_BUSQUEDA_NO_ENCONTRADO) {  
      // Si no encontró el usuario
      fprintf(stdout, "Error\n");
      fprintf(stderr, "El usuario '%s' no fue encontrado\n", usuario);
      free(usuario);
      usuario = NULL;
      res = 1;
    } else {
      Borrar_Usuario_Bus(&usu_bus);
      AB_BB_ElemCte(*usuarios, &usu);  // Obtengo el usuario a eliminar
      TDA_USU_Get_Pedidos(*usu, &pedidos);  // Obtengo sus pedidos
      res = LSB_Vacia(*pedidos);  // me fijo si está vacia
      if (res == 1) {  // Si está vacia la lista de pedidos libero el usuario
	// del árbol usuarios
	Eliminar_Usuario_Actual(&pedidos, &usuarios, &usu);
      } else {  // Libero los pedidos, paquetes e itinerarios
	Eliminar_Usuario_Pedidos(&shop_track, &pedidos);
	Eliminar_Usuario_Actual(&pedidos, &usuarios, &usu);
      }
    }
    res = 0;
  } else Borrar_Usuario_Bus(&usu_bus);
  return 0;
}

// FUNCIONAMIENTO Compra_Obtener_Pedido:
// Crea un pedido y obtiene la lista de pedidos

void Compra_Obtener_Pedido(TAB_BB** usuarios, 
unsigned int nPedido, char* descripcion, 
unsigned int cantPaq, T_LSB** pedidos, 
TDA_PEDIDO** pedido, TDA_USU* usu, 
T_LSB* itis, T_LSB* paqs) {
  Crear_Pedido(pedido, nPedido, descripcion, cantPaq, &itis, &paqs);
  AB_BB_ElemCte(**usuarios, &usu);  // Obtiene el usuario de usuarios 
  TDA_USU_Get_Pedidos(*usu, pedidos);  // Obtiene los pedidos
}

// FUNCIONAMIENTO Compra_Obtener_En_Indices:
// Busca un pedido en los índice. Si no lo
// encuentra devuelve por stderr. En caso contrario
// agrega un pedido a la lista de pedidos

void Compra_Buscar_En_Indices(TAB_BB** usuarios, 
char* usuario, unsigned int nPedido, char* descripcion, 
unsigned int cantPaq, TAB_BB** indices) {
  T_LSB* itis = NULL;
  T_LSB* paqs = NULL;
  T_LSB* pedidos = NULL;
  TDA_INDEX* indice = NULL;
  TDA_PEDIDO* pedido = NULL;
  TDA_USU* usu = NULL;
  int res = 1;

  Crear_Index(&indice, usuario, nPedido);  // Creo el indice 
  if (!(AB_BB_Vacio(**indices))) {
    AB_BB_MoverCte(*indices, AB_BB_RAIZ, &res);
    res = AB_BB_Busqueda(*indices, &indice, TDA_INDEX_Get_Comparador(*indice)); 
    if (res == AB_BB_ENCONTRADO) {  // Si el índice existe el pedido existe
      fprintf(stdout, "Error\n");
      fprintf(stderr, "El pedido '%u' ya fue ingresado al sistema\n", nPedido);
      free(indice);
      indice = NULL;
      free(usuario);
      usuario = NULL;
      free(descripcion);
      descripcion = NULL;
    } else {  // Si no existe el indice no existe el pedido y se ingresa
      AB_BB_MoverCte(*indices, AB_BB_RAIZ, &res);
      AB_BB_Insertar_Ordenado(*indices, &indice, 
TDA_INDEX_Get_Comparador(*indice));
      Compra_Obtener_Pedido(usuarios, nPedido, 
descripcion, cantPaq, &pedidos, &pedido, 
usu, itis, paqs);
      res = LSB_Busqueda(pedidos, &pedido, LSB_PRIMERO, 
TDA_PEDIDO_Get_Comparador(*pedido));
      res = LSB_Insertar(pedidos, LSB_SIGUIENTE, &pedido);
      fprintf(stdout, "Compra '%u' registrada\n", nPedido);
    } 

  } else {  // Si no existe indices, la lista de pedidos está vacia
    AB_BB_Insertar_Ordenado(*indices, &indice, 
TDA_INDEX_Get_Comparador(*indice)); 
    Compra_Obtener_Pedido(usuarios, nPedido, 
descripcion, cantPaq, &pedidos, &pedido, 
usu, itis, paqs);
    res = LSB_Insertar(pedidos, LSB_PRIMERO, &pedido);  
// Lo inserta al principio
    fprintf(stdout, "Compra '%d' registrada\n", nPedido);
  } 
}

// FUNCIONAMIENTO Compra:
// Realiza la compra de un pedido. Lo busca en 
// en la lista de usuarios. Si no lo encuentra
// devuelve por stderr, sinó sigue buscando
// en los índices.

void Compra(TDA_SHOP_TRACK* shop_track, 
char* usuario, unsigned int nPedido, char* descripcion, 
unsigned int cantPaq) {
  TDA_USU* usu_bus = NULL;
  TAB_BB* indices = NULL;
  TAB_BB* usuarios = NULL;
  int res = 1;
  TDA_SHOP_TRACK_Get_Usuarios(*shop_track, &usuarios);  // Obtengo usuarios
  if (!(AB_BB_Vacio(*usuarios))) {  // Si no está vacio   
    Crear_Usuario_Busqueda(&usu_bus, 
usuario, " ", " ", NULL);  // Busco usuario 
    AB_BB_MoverCte(usuarios, AB_BB_RAIZ, &res);
    res = AB_BB_Busqueda(usuarios, &usu_bus, TDA_USU_Get_Comparador(*usu_bus));
    if (res == AB_BB_ENCONTRADO) {  // Si lo encontró
      Borrar_Usuario_Bus(&usu_bus); 
      TDA_SHOP_TRACK_Get_Indices(*shop_track, &indices);
      Compra_Buscar_En_Indices(&usuarios, usuario, 
nPedido, descripcion, cantPaq, &indices);
    } else Borrar_Usuario_Bus(&usu_bus); 
  } else { 
    free(usuario);
    usuario = NULL;
    free(descripcion);
    descripcion = NULL;
  } 
}

// FUNCIONAMIENTO Verificar_Cantidad_Paquetes:
// Verifica si se puede agregar un paquete, fijándose
// cuantos posee con la cantidad máxima del pedido

int Verificar_Cantidad_Paquetes(unsigned int cant_paq, T_LSB* paqs) {
  int mov, cant = 0;
  mov = LSB_MoverCte(paqs, LSB_PRIMERO);
  while (mov == LSB_MOVIDO) {
    cant++;
    mov = LSB_MoverCte(paqs, LSB_SIGUIENTE);
  }
  return ((cant == cant_paq));
}

// FUNCIONAMIENTO Viaje_del_Paquete:
// Viaje del paquete realiza la recepción del paquete
// y la posta del paquete. La diferencia entre los dos es que
// la recepción cambia el estado del paquete a RECIBIDO. En este
// busca si el paquete existe, si es así ingresa un nuevo
// itinerario.

void Viaje_del_Paquete(T_LSB** pedidos, unsigned int nPedido, 
unsigned int nPaq, char* descripcion, char* ubicacion, 
char* fecha, char codigo) {
  T_LSB* paqs = NULL;
  T_LSB* itis = NULL;
  TDA_PAQ* paq = NULL, *paq_bus = NULL; 
  TDA_ITI* iti = NULL; 
  TDA_PEDIDO* pedido, *pedido_bus = NULL;
  char* ubi_paq = NULL;
  int res = 1, estado = 0, mov = 0;
  Crear_Pedido_Busqueda(&pedido_bus, nPedido, 
NULL, nPaq, NULL, NULL);
  res = LSB_Busqueda(*pedidos, &pedido_bus, 
LSB_PRIMERO, TDA_PEDIDO_Get_Comparador(*pedido_bus));
  LSB_ElemCte(**pedidos, &pedido);  // Obtiene el pedido
  Borrar_Pedido_Bus(&pedido_bus);
  TDA_PEDIDO_Get_Paquetes(*pedido, &paqs); 
  Crear_Paquete(&paq_bus, nPaq, NULL, NULL);
  res = LSB_Busqueda(paqs, &paq_bus, LSB_PRIMERO, 
TDA_PAQ_Get_Comparador(*paq_bus));
  if (res == ERR_LSB_NO_EXISTE) {  // Si el paquete no existe
    Borrar_Paquete_Bus(&paq_bus);
    fprintf(stdout, "Error\n");
    fprintf(stderr, "El paquete '%u' no fue encontrado\n", nPaq);
    free(ubicacion);
    ubicacion = NULL;
    free(descripcion);
    descripcion = NULL;
    free(fecha);
    fecha = NULL;
  }  else {  
    Borrar_Paquete_Bus(&paq_bus);
    LSB_ElemCte(*paqs, &paq);
    estado = TDA_PAQ_Get_Estado(*paq);
    if (estado == ENVIADO) { 
// Si el paquete no fue recibido su ubicación cambia
      TDA_PAQ_Get_Ubicacion(*paq, &ubi_paq);
      strcpy(ubi_paq, ubicacion);
      if (codigo == 'R') {  // Si es una recepción cambia el estado
	TDA_PAQ_Set_Estado(paq, ENTREGADO);
	fprintf(stdout, "Paquete '%u' del Pedido '%u' recibido\n", nPaq, nPedido);
      } else {
	fprintf(stdout, "Posta del Paquete '%u' ", nPaq);
	fprintf(stdout, "del Pedido '%u' registrada\n", nPedido);
      }
      TDA_PEDIDO_Get_Itinerarios(*pedido, &itis); 
      Crear_Itinerario(&iti, nPaq, ubicacion, fecha, descripcion);
      if (!(LSB_Vacia(*itis))) {
	mov = LSB_MoverCte(itis, LSB_PRIMERO);
	while (mov == LSB_MOVIDO) {
	  mov = LSB_MoverCte(itis, LSB_SIGUIENTE);
	}
	res = LSB_Insertar(itis, LSB_SIGUIENTE, &iti);  // Inserta el itinerario
      } else res = LSB_Insertar(itis, LSB_PRIMERO, &iti);
    } else {
      free(ubicacion);
      free(descripcion);
      free(fecha);
      ubicacion = NULL;
      descripcion = NULL;
      fecha = NULL;
    }
  }
}

// FUNCIONAMIENTO Despacho_del_Paquete:
// Agrega un nuevo paquete a un pedido. Si este existe
// no lo agrega sino verifica si la cantidad de paquetes
// del pedido ya se completó. Sino lo agrega.

void Despacho_de_Paquete(T_LSB** pedidos, unsigned int nPedido, 
unsigned int nPaq, char* contenido, char* ubicacion, char* fecha) {
  T_LSB* paqs = NULL;
  T_LSB* itis = NULL;
  TDA_PAQ* paquete = NULL, *paq_bus = NULL; 
  TDA_ITI* iti = NULL; 
  TDA_PEDIDO* pedido, *pedido_bus = NULL;
  char* descripcion = NULL;
  char* ubi_paq = NULL;
  int res = 1, mov = 0;

  Crear_Pedido_Busqueda(&pedido_bus, nPedido, NULL, nPaq, NULL, NULL);
  res = LSB_Busqueda(*pedidos, &pedido_bus, 
LSB_PRIMERO, TDA_PEDIDO_Get_Comparador(*pedido_bus));
  LSB_ElemCte(**pedidos, &pedido);
  Borrar_Pedido_Bus(&pedido_bus);
  TDA_PEDIDO_Get_Paquetes(*pedido, &paqs); 
  res = Verificar_Cantidad_Paquetes(TDA_PEDIDO_Get_Cant_Paq(*pedido), paqs);
  if (res == 1) {  // Si la cantidad de paquetes ya está completa
    fprintf(stdout, "Error\n");
    fprintf(stderr, "El pedido '%u' ya posee todos los paquetes\n", nPedido);
    free(ubicacion);
    free(contenido);
    free(fecha);
    ubicacion = NULL;
    descripcion = NULL;
    fecha = NULL;
  }  else {  
    Crear_Paquete(&paq_bus, nPaq, NULL, NULL);
    res = LSB_Busqueda(paqs, &paq_bus, 
LSB_PRIMERO, TDA_PAQ_Get_Comparador(*paq_bus));
    if (res == LSB_ENCONTRADO) {  // Si el paquete ya fué ingresado
      Borrar_Paquete_Bus(&paq_bus);
      free(ubicacion);
      free(descripcion);
      free(fecha);
      ubicacion = NULL;
      descripcion = NULL;
      fecha = NULL;
    }  else {  
      Borrar_Paquete_Bus(&paq_bus);
      TDA_PEDIDO_Get_Itinerarios(*pedido, &itis); 
      descripcion = (char*)malloc(sizeof(char) * 8);
      strcpy(descripcion, "Enviado");  // Setea la descripción
      // a enviado   
      ubi_paq = (char*)malloc(sizeof(char) * (TAM_UBI + 1));
      memcpy(ubi_paq, ubicacion, (TAM_UBI+1));  // Crea la ubicación
      Crear_Paquete(&paquete, nPaq, contenido, ubi_paq);
      Crear_Itinerario(&iti, nPaq, ubicacion, fecha, descripcion);
      if (!(LSB_Vacia(*paqs))) {
	res = LSB_Busqueda(paqs, &paquete, 
LSB_PRIMERO, TDA_PAQ_Get_Comparador(*paquete));
	res = LSB_Insertar(paqs, LSB_SIGUIENTE, &paquete);  // Si no existe
	// la lista de paquetes.
      } else res = LSB_Insertar(paqs, LSB_PRIMERO, &paquete);
      if (!(LSB_Vacia(*itis))) {
	mov = LSB_MoverCte(itis, LSB_PRIMERO);
	while (mov == LSB_MOVIDO) {  // Busca la última posición de la lista
	  mov = LSB_MoverCte(itis, LSB_SIGUIENTE);
	}
	res = LSB_Insertar(itis, LSB_SIGUIENTE, &iti);  // Lo inserta
      } else res = LSB_Insertar(itis, LSB_PRIMERO, &iti);
      fprintf(stdout, "Paquete '%u' del Pedido '%u' despachado\n", 
nPaq, nPedido);
    }
  }
}

// FUNCIONAMIENTO Calcular_Estado_del_Pedido:
// Calcula el estado del pedido en base a los
// estados de los paquetes.

void Calcular_Estado_del_Pedido(T_LSB* paquetes, char** estado, int cant_paq) {
  TDA_PAQ* paq;
  int mov = 0;
  T_ESTADO_PAQUETE status = 6;
  int cant_entregados = 0, cant_enviados = 0, suma = 0;
  mov = LSB_MoverCte(paquetes, LSB_PRIMERO);
  while (mov == LSB_MOVIDO) {
    LSB_ElemCte(*paquetes, &paq);
    status = TDA_PAQ_Get_Estado(*paq);
    if (status == ENTREGADO)
      cant_entregados++;  // Cuenta la cantidad de entregados
    else cant_enviados++;  // Cuenta la cantidad de enviados 
    mov = LSB_MoverCte(paquetes, LSB_SIGUIENTE);
  }
  suma = cant_enviados + cant_entregados;
  if (suma == cant_paq) {
    if (cant_enviados == cant_paq) {
    *estado = (char*)malloc(sizeof(char)*8);
    strcpy(*estado, "Enviado");
    } else if (cant_entregados == cant_paq) {
      *estado = (char*)malloc(sizeof(char)*10);
      strcpy(*estado, "Entregado");
    } else if (cant_enviados < cant_paq) {
      *estado = (char*)malloc(sizeof(char)*8);
      strcpy(*estado, "Enviado");
    }
  } else if ((cant_enviados == 0) && (cant_entregados == 0)) {
    *estado = (char*)malloc(sizeof(char)*10);
    strcpy(*estado, "Pendiente"); 
  } else  {
    *estado = (char*)malloc(sizeof(char)*12);
    strcpy(*estado, "Despachando");
  }
}

// FUNCIONAMIENTO Itinerario_del_Pedido:
// Muestra el itinerario de un pedido

void Itinerario_del_Pedido(TDA_USU* usuario, 
T_LSB* pedidos, unsigned int nPedido) {
  T_LSB* paqs = NULL;
  T_LSB* itis = NULL;
  TDA_PAQ* paq = NULL; 
  TDA_ITI* iti = NULL, *iti_bus = NULL; 
  TDA_PEDIDO* pedido, *pedido_bus = NULL;
  int res = 1, mov_paq = 2, nPaq = 0;
  char* estado = NULL;
  char* usu = NULL;
  char* nombres = NULL;
  char* apellido = NULL;
  char* ubicacion = NULL;
  char* contenido = NULL;
  char* descripcion = NULL;
  char* fecha = NULL;

  Crear_Pedido_Busqueda(&pedido_bus, nPedido, NULL, 0, NULL, NULL);
  res = LSB_Busqueda(pedidos, &pedido_bus, 
LSB_PRIMERO, TDA_PEDIDO_Get_Comparador(*pedido_bus));
  LSB_ElemCte(*pedidos, &pedido);
  Borrar_Pedido_Bus(&pedido_bus);
  TDA_PEDIDO_Get_Paquetes(*pedido, &paqs);
  TDA_PEDIDO_Get_Itinerarios(*pedido, &itis);
  Calcular_Estado_del_Pedido(paqs, &estado, TDA_PEDIDO_Get_Cant_Paq(*pedido));
  TDA_USU_Get_Usuario(*usuario, &usu);
  TDA_USU_Get_Nombres(*usuario, &nombres);
  TDA_USU_Get_Apellido(*usuario, &apellido);
  fprintf(stdout, "==========\n");
  fprintf(stdout, "Pedido: %u\n", nPedido);
  fprintf(stdout, "Usuario: %s\n", usu);
  fprintf(stdout, "Nombre: %s, %s\n", apellido, nombres);
  fprintf(stdout, "Estado: %s\n", estado);
  fprintf(stdout, "Itinerario:\n");
  mov_paq = LSB_MoverCte(paqs, LSB_PRIMERO);
  while (mov_paq == LSB_MOVIDO) {
    LSB_ElemCte(*paqs, &paq);
    TDA_PAQ_Get_Contenido(*paq, &contenido);
    nPaq = TDA_PAQ_Get_nPaquete(*paq);
    fprintf(stdout, "\t%u: %s", nPaq , contenido);
    Crear_Itinerario(&iti_bus, nPaq, NULL, NULL, NULL);
    res = LSB_Busqueda(itis, &iti_bus, 
LSB_PRIMERO, TDA_ITI_Get_Comparador(*iti_bus));
    while (res == LSB_ENCONTRADO) {
      LSB_ElemCte(*itis, &iti);
      TDA_ITI_Get_Descripcion(*iti, &descripcion);
      TDA_ITI_Get_Ubicacion(*iti, &ubicacion);
      TDA_ITI_Get_Fecha(*iti, &fecha);
      fprintf(stdout, " - %s(%s),%s", ubicacion, fecha, descripcion);
      res = LSB_Busqueda(itis, &iti_bus, LSB_SIGUIENTE, 
TDA_ITI_Get_Comparador(*iti_bus));
    }
    Borrar_Itinerario_Bus(&iti_bus);
    fprintf(stdout, "\n");
    mov_paq = LSB_MoverCte(paqs, LSB_SIGUIENTE);
  }   
  fprintf(stdout, "==========\n");
  free(estado);
}

// FUNCIONAMIENTO Estado_del_Pedido:
// Muestra el estado de un pedido

void Estado_del_Pedido(TDA_USU* usuario, T_LSB* pedidos, unsigned int nPedido) {
  T_LSB* paqs = NULL;
  TDA_PAQ* paq = NULL; 
  TDA_PEDIDO* pedido, *pedido_bus = NULL;
  int res = 1, mov = 2;
  char* estado = NULL;
  char* usu = NULL;
  char* nombres = NULL;
  char* apellido = NULL;
  char* ubicacion = NULL;
  char* contenido = NULL;

  Crear_Pedido_Busqueda(&pedido_bus, nPedido, NULL, 0, NULL, NULL);
  res = LSB_Busqueda(pedidos, &pedido_bus, LSB_PRIMERO, 
TDA_PEDIDO_Get_Comparador(*pedido_bus));
  LSB_ElemCte(*pedidos, &pedido);
  Borrar_Pedido_Bus(&pedido_bus);
  TDA_PEDIDO_Get_Paquetes(*pedido, &paqs);
  Calcular_Estado_del_Pedido(paqs, &estado, 
TDA_PEDIDO_Get_Cant_Paq(*pedido));
  TDA_USU_Get_Usuario(*usuario, &usu);
  TDA_USU_Get_Nombres(*usuario, &nombres);
  TDA_USU_Get_Apellido(*usuario, &apellido);
  fprintf(stdout, "==========\n");
  fprintf(stdout, "Pedido: %u\n", nPedido);
  fprintf(stdout, "Usuario: %s\n", usu);
  fprintf(stdout, "Nombre: %s, %s\n", apellido, nombres);
  fprintf(stdout, "Estado: %s\n", estado);
  fprintf(stdout, "Paquetes:\n");
  mov = LSB_MoverCte(paqs, LSB_PRIMERO);
  while (mov == LSB_MOVIDO) {
    LSB_ElemCte(*paqs, &paq);
    TDA_PAQ_Get_Contenido(*paq, &contenido);
    TDA_PAQ_Get_Ubicacion(*paq, &ubicacion);
    fprintf(stdout, "\t%u: %s - %s\n", 
TDA_PAQ_Get_nPaquete(*paq), contenido, ubicacion);
    mov = LSB_MoverCte(paqs, LSB_SIGUIENTE);
  }
  fprintf(stdout, "==========\n");
  free(estado);
}

// FUNCIONAMIENTO Buscar_En_Usuario:
// Busca en la lista de un usuario un pedido y deriva
// el flujo a despacho, posta, recepcion, itinerario y estado
// de un pedido

void Buscar_En_Usuario(TAB_BB** usuarios, char* usuario, 
unsigned int nPedido, unsigned int nPaq, char* algo, 
char* ubicacion, char* fecha, char codigo) {
  T_LSB* pedidos = NULL;
  TDA_USU* usu = NULL;
  TDA_USU* usu_bus = NULL;
  int res = 1;
  Crear_Usuario_Busqueda(&usu_bus, usuario, " ", " ", NULL);
  if (!(AB_BB_Vacio(**usuarios))) {  
    AB_BB_MoverCte(*usuarios, AB_BB_RAIZ, &res);
    res = AB_BB_Busqueda(*usuarios, &usu_bus, TDA_USU_Get_Comparador(*usu_bus));
    if (res == AB_BB_ENCONTRADO) {
      Borrar_Usuario_Bus(&usu_bus);
      AB_BB_ElemCte(**usuarios, &usu);  
      TDA_USU_Get_Pedidos(*usu, &pedidos);
      switch (codigo) {  // Dependiendo del código cambia el flujo a
      case 'D': Despacho_de_Paquete(&pedidos, nPedido, 
nPaq, algo, ubicacion, fecha);	break;
      case 'P': Viaje_del_Paquete(&pedidos, nPedido, nPaq, 
algo, ubicacion, fecha, codigo);
	break; 
      case 'R':
	algo = (char*)malloc(sizeof(char) * 9);
	strcpy(algo, "Recibido");
	Viaje_del_Paquete(&pedidos, nPedido, nPaq, algo, 
ubicacion, fecha, codigo);
	break;
      case 'Y': Estado_del_Pedido(usu, pedidos, nPedido);	
	break;
      case 'Z': Itinerario_del_Pedido(usu, pedidos, nPedido);	
	break;
      default: printf("%s", "NADA");
	break;
      }
    } else {
      if (ubicacion != NULL) {
	 free(ubicacion);
	 ubicacion = NULL;
      }
      if (fecha != NULL) {
	 free(fecha);
	 fecha = NULL;
      }
      if (algo != NULL) {
	 free(algo);
	 algo = NULL;
      }
    }
  } 
}

// FUNCIONAMIENTO Buscar_En_índice:
// Busca en los índices un pedido 

void Buscar_En_Indice(TDA_SHOP_TRACK* shop_track, 
unsigned int nPedido, unsigned int nPaq, char* algo, 
char* ubicacion, char* fecha, char codigo) {
  TAB_BB* usuarios = NULL;
  TAB_BB* indices = NULL;
  TDA_INDEX* indice = NULL, *indice_bus = NULL;
  char* usuario = NULL;
  int res = 1;
  TDA_SHOP_TRACK_Get_Indices(*shop_track, &indices);
  if (!(AB_BB_Vacio(*indices))) {   
    Crear_Index(&indice_bus, " ", nPedido);  // Creo el indice
    AB_BB_MoverCte(indices, AB_BB_RAIZ, &res);
    res = AB_BB_Busqueda(indices, &indice_bus, 
TDA_INDEX_Get_Comparador(*indice_bus)); 
    if (res == ERR_AB_BB_NO_ENCONTRADO) {  
// Si el índice no existe el pedido no existe
      fprintf(stdout, "Error\n");
      fprintf(stderr, "El pedido '%u' no fue encontrado\n", 
nPedido);
      Borrar_Index_Bus(&indice_bus);
      if (ubicacion != NULL) {
	free(ubicacion);
	ubicacion = NULL;
      }
      if (fecha != NULL) {
	free(fecha);
	fecha = NULL;
      }
      if (algo != NULL) {
	free(algo);
	algo = NULL;
      }
    } else {  // Si lo encontró verifica en la lista de usuarios
      Borrar_Index_Bus(&indice_bus);
      AB_BB_ElemCte(*indices, &indice);
      TDA_INDEX_Get_Usuario(*indice, &usuario);
      TDA_SHOP_TRACK_Get_Usuarios(*shop_track, &usuarios);  
      Buscar_En_Usuario(&usuarios, usuario, nPedido, 
nPaq, algo, ubicacion, fecha, codigo);
    }
  } else {  // En caso que no haya indices libero la memoria
    if (ubicacion != NULL) {
      free(ubicacion);
      ubicacion = NULL;
    }
    if (fecha != NULL) {
      free(fecha);
      fecha = NULL;
    }
    if (algo != NULL) {
      free(algo);
      algo = NULL;
    }
  }
}

