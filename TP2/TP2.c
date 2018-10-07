#include "TP2_Operaciones.h"
#include "Get_String.h"


void Obtener_Datos_Agregar_Usuario(char* linea, 
char** usuario, char** apellido, char** nombres) {
  char* token = NULL;
  int begin = 0, end = 0;
  
  *usuario = (char*)malloc(sizeof(char) * (TAM_USU + 1));
  *apellido = (char*)malloc(sizeof(char) * (TAM_APELLIDO + 1));
  *nombres = (char*)malloc(sizeof(char) * (TAM_NOMBRES + 1));

  token = strchr(linea, ',');
  begin = (token - linea +1);

  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  strncpy(*usuario, linea + begin, end - begin -1);
  (*usuario)[end - begin - 1] = 0;
  
  begin = end;
  
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  strncpy(*apellido, linea + begin, end - begin -1);
  (*apellido)[end - begin - 1] = 0;

  begin = end;
  strcpy(*nombres, linea + begin);
}

void Obtener_Datos_Eliminar_Usuario(char* linea, char** usuario) {
  char* token = NULL;
  int begin = 0;

  *usuario = (char*)malloc(sizeof(char) * (TAM_USU + 1));

  token = strchr(linea, ',');
  begin = (token - linea +1);
  strcpy(*usuario, linea + begin);
}

void Obtener_Datos_Compra(char* linea, char** usuario, 
unsigned int* nPedido, char** detallePedido, unsigned int* cantPaq) {
  char* token = NULL;  
  int begin = 0, end = 0;
  
  *usuario = (char*)malloc(sizeof(char) * (TAM_USU + 1));

  token = strchr(linea, ',');
  begin = (token - linea +1);

  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  strncpy(*usuario, linea + begin, end - begin -1);
  (*usuario)[end - begin - 1] = 0;
  
  begin = end;
  
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *nPedido = atoi(linea + begin);

  begin = end;
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *detallePedido = (char*)malloc(sizeof(char) * (end - begin));
  strncpy(*detallePedido, linea + begin, end - begin -1);
  (*detallePedido)[end - begin - 1] = 0;
  
  begin = end;
  
  *cantPaq = atoi(linea + begin);
}

void Obtener_Datos_Despacho_De_Paquete(char* linea, 
unsigned int* nPedido, unsigned int* nPaq, char** contenidoPaq, 
char** ubicacion, char** fecha) {
  char* token = NULL;
  int begin = 0, end = 0;
  
  *ubicacion = (char*)malloc(sizeof(char) * (TAM_UBI + 1));
  *fecha = (char*)malloc(sizeof(char) * (TAM_FECHA + 1));

  token = strchr(linea, ',');
  begin = (token - linea +1);

  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *nPedido = atoi(linea + begin);
  
  begin = end;
  
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *nPaq = atoi(linea + begin);

  begin = end;
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *contenidoPaq = (char*)malloc(sizeof(char) * (end - begin));
  strncpy(*contenidoPaq, linea + begin, end - begin -1);
  (*contenidoPaq)[end - begin - 1] = 0;
  
  begin = end;
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  strncpy(*ubicacion, linea + begin, end - begin -1);
  (*ubicacion)[end - begin - 1] = 0;

  begin = end;
  strcpy(*fecha, linea + begin);
}

void Obtener_Datos_Posta_Del_Paquete(char* linea, 
unsigned int* nPedido, unsigned int* nPaq, char** ubicacion, 
char** descripcion, char** fecha) {
  char* token = NULL;
  int begin = 0, end = 0;
  
  *ubicacion = (char*)malloc(sizeof(char) * (TAM_UBI + 1));
  *fecha = (char*)malloc(sizeof(char) * (TAM_FECHA + 1));

  token = strchr(linea, ',');
  begin = (token - linea +1);

  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *nPedido = atoi(linea + begin);
  
  begin = end;
  
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *nPaq = atoi(linea + begin);

  begin = end;
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  strncpy(*ubicacion, linea + begin, end - begin -1);
  (*ubicacion)[end - begin - 1] = 0;

  begin = end;
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *descripcion = (char*)malloc(sizeof(char) * (end - begin));
  strncpy(*descripcion, linea + begin, end - begin -1);
  (*descripcion)[end - begin - 1] = 0;
  
  begin = end;
  strcpy(*fecha, linea + begin);
}

void Obtener_Datos_Recepcion_Del_Paquete(char* linea, 
unsigned int* nPedido, unsigned int* nPaq, char** ubicacion, 
char** fecha) {
  char* token = NULL;
  int begin = 0, end = 0;
  
  *ubicacion = (char*)malloc(sizeof(char) * (TAM_UBI + 1));
  *fecha = (char*)malloc(sizeof(char) * (TAM_FECHA + 1));

  token = strchr(linea, ',');
  begin = (token - linea +1);

  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *nPedido = atoi(linea + begin);
  
  begin = end;
  
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *nPaq = atoi(linea + begin);

  begin = end;
  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  strncpy(*ubicacion, linea + begin, end - begin -1);
  (*ubicacion)[end - begin - 1] = 0;

  begin = end;
  strcpy(*fecha, linea + begin);
}

void Obtener_Datos_Estado_Del_Pedido(char* linea, unsigned int* nPedido) {
  char* token = NULL;
  int begin = 0, end = 0;

  token = strchr(linea, ',');
  begin = (token - linea +1);

  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *nPedido = atoi(linea + begin);
}

void Obtener_Datos_Itinerario_Del_Pedido(char* linea, unsigned int* nPedido) {
  char* token = NULL;
  int begin = 0, end = 0;

  token = strchr(linea, ',');
  begin = (token - linea +1);

  token = strchr(linea + begin, ',');
  end = (token - linea +1);
  *nPedido = atoi(linea + begin);
}

// FUNCIONAMIENTO Crear_Estructura:
// Crea la estructura para realizar la aplicación

void Crear_Estructura(TDA_SHOP_TRACK* track) {
  TAB_BB* usuarios, *indices;

  usuarios = (TAB_BB*)malloc(sizeof(TAB_BB));
  AB_BB_Crear(usuarios, sizeof(TDA_USU*));
  indices = (TAB_BB*)malloc(sizeof(TAB_BB));
  AB_BB_Crear(indices, sizeof(TDA_INDEX*));
  TDA_SHOP_TRACK_Crear(track, usuarios, indices);
}

// FUNCIONAMIENTO Destruit_Estructura:
// Libera la memoría que no se haya liberado
// antes y destruye la estructura.

void Destruir_Estructura(TDA_SHOP_TRACK* track) {
  TAB_BB* usuarios, *indices;
  TDA_USU* usu = NULL;
  char* usuario = NULL, *usu_bus = NULL;
  int error = 0, N = 0;
  
  TDA_SHOP_TRACK_Get_Usuarios(*track, &usuarios);
  TDA_SHOP_TRACK_Get_Indices(*track, &indices);
  AB_BB_MoverCte(usuarios, AB_BB_RAIZ, &error);
  while (!(AB_BB_Vacio(*usuarios)) && (error != 1)) {
    AB_BB_ElemCte(*usuarios, &usu);
    TDA_USU_Get_Usuario(*usu, &usuario);
    N = strlen(usuario);
    usu_bus = (char*)malloc(sizeof(char) * (N + 1));
    strcpy(usu_bus, usuario);
    Eliminar_Usuario(track, usu_bus);
    free(usu_bus);
    AB_BB_MoverCte(usuarios, AB_BB_RAIZ, &error);
  }
  AB_BB_Vaciar(usuarios);
  AB_BB_Vaciar(indices);
  TDA_SHOP_TRACK_Destruir(track);
}

int main(int argc, char* argv[]) {
  TDA_SHOP_TRACK track;
  char* linea = NULL, *usuario = NULL, *apellido = NULL, 
*nombres = NULL, *detallePed = NULL, *contenidoPaq = NULL, 
*ubicacion = NULL, *fecha = NULL, *descripcion = NULL;
  int errorCode, res = 0;
  char code;
  unsigned int nPedido = 0, cantPaq = 0, nPaq = 0;
  
  if (argc > 1)
    return 1;
  else {
    Crear_Estructura(&track);
    while (!feof(stdin)) {
      errorCode = getString(&linea);
      if (errorCode == RES_OK) {
	code = linea[0];
	switch (code) {
	case 'A':
	  Obtener_Datos_Agregar_Usuario(linea, &usuario, &apellido, &nombres);
	  Agregar_Usuario(&track, usuario, apellido, nombres);
	  break;
	case 'E':
	  Obtener_Datos_Eliminar_Usuario(linea, &usuario);
	  res = Eliminar_Usuario(&track, usuario);
	  if (res == 0) {
	    fprintf(stdout, "Usuario '%s' eliminado\n", usuario);
	    free(usuario);
	  }
	  break;
	case 'C':
	  Obtener_Datos_Compra(linea, &usuario, &nPedido, &detallePed, &cantPaq);
	  Compra(&track, usuario, nPedido, detallePed, cantPaq);
	  break;
	case 'D':
	  Obtener_Datos_Despacho_De_Paquete(linea, &nPedido, 
&nPaq, &contenidoPaq, &ubicacion, &fecha);
	  Buscar_En_Indice(&track, nPedido, nPaq, contenidoPaq, 
ubicacion, fecha, code);
	  break;
	case 'P':
	  Obtener_Datos_Posta_Del_Paquete(linea, &nPedido, 
&nPaq, &ubicacion, &descripcion, &fecha);
	  Buscar_En_Indice(&track, nPedido, nPaq, descripcion, ubicacion, fecha, code);
	  break;
	case 'R':
	  Obtener_Datos_Recepcion_Del_Paquete(linea, &nPedido, 
&nPaq, &ubicacion, &fecha);
	  Buscar_En_Indice(&track, nPedido, nPaq, NULL, ubicacion, fecha, code);
	  break;
	case 'Y':
	  Obtener_Datos_Estado_Del_Pedido(linea, &nPedido);
	  Buscar_En_Indice(&track, nPedido, 0, NULL, NULL, NULL, code);
	  break;
	case 'Z':
	  Obtener_Datos_Itinerario_Del_Pedido(linea, &nPedido);
	  Buscar_En_Indice(&track, nPedido, 0, NULL, NULL, NULL, code);
	  break;
	default:
	  fprintf(stdout, "Error\n");
	  fprintf(stderr, "Error al parsear: %s\n", linea);
	  break;
	}
	free(linea);
      }
    }
    Destruir_Estructura(&track);
    return RES_OK;
  }
}
