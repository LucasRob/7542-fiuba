/*
 *AUX.c
 *
 *  Created on: 16-mar-2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */
#include "aux.h"

// FUNCIONAMIENTO INICIALIZAR:
// Los valores para inicializar las variables hi y r son las
// dadas por el algoritmo de md5.

void inicializar(unsigned long int *hi, unsigned long int *o) {
  unsigned short int i = 0;

  hi[0] = 0x67452301;
  hi[1] = 0xefcdab89;
  hi[2] = 0x98badcfe;
  hi[3] = 0x10325476;

  while (i < 15) {
    o[i] = 7;
    o[i+1] = 12;
    o[i+2] = 17;
    o[i+3] = 22;
    i = i+4;
  }

  while (i < 31) {
    o[i] = 5;
    o[i+1] = 9;
    o[i+2] = 14;
    o[i+3] = 20;
    i = i+4;
  }

  while (i < 47) {
    o[i] = 4;
    o[i+1] = 11;
    o[i+2] = 16;
    o[i+3] = 23;
    i = i+4;
  }

  while (i < 63) {
    o[i] = 6;
    o[i+1] = 10;
    o[i+2] = 15;
    o[i+3] = 21;
    i = i+4;
  }
}
// FUNCIONAMIENTO SWAP_ENDIAN:
// Obtiene el primer byte del entero y luego lo corre n cantidad de
// veces para que quede en la posición nueva. Ej: El primer byte queda
// en la última posición el segundo en la tercera y asi hasta el último que
// queda en el primero.

void swap_endian(unsigned long int* x) {
     (*x) = ((((*x) & 0xff000000) >> 24) | (((*x) & 0x00ff0000) >>  8)
| (((*x) & 0x0000ff00) <<  8) | (((*x) & 0x000000ff) << 24));
}

// FUNCIONAMIENTO LEFT_ROTATE:
// Corre c bits de derecha a izquierda, y 32-c de derecha a izq
// luego hacer el Byte or de ese resultado
// Ej: x = 0x65726f4c
// x << 4 = 0x52726f4c0
// x >> 28 = 0x6
// or de los dos x = 52726f4c6

unsigned long int leftrotate(unsigned long int x, unsigned long int c) {
  return ((x << c) | (x >> (32-c)));
}

// FUNCIONAMIENTO APPEND:
// Realiza un and entre los valores de hi y una mascara
// obteniendo todos los bytes por separado en res. Luego
// es transformado a string y colocado uno por uno en result
// Ej: hi[0] = 0x65726f4c y mask = 0xf0000000
// primer pasada: res = 0x60000000, array = "60000000",
// result[0] = "6", al final mask = 0xf000000
// segunda pasada: res = 0x5000000, array = "5000000",
// result[1] = "5"
// se sigue así hasta procesar todos los hi.
// Sobre el uso de los hi como little o big endian ver aclaración
// en t_D_Check.c

void append(unsigned long int *hi, char *result) {
  char array[9];
  unsigned long int mask = 0xf0000000;
  unsigned long int res;
  unsigned short int i;

  blanquear_string(result, 33);
  for (i = 0; i < 8;i++) {
    res = (hi[0] & mask);
    sprintf(array, "%lx", res);
    result[i] = array[0];
    mask = mask >> 4;
  }
  mask = 0xf0000000;
  for (i = 8;i < 16; i++) {
    res = (hi[1] & mask);
    sprintf(array, "%lx", res);
    result[i] = array[0];
    mask = mask >> 4;
  }
  mask = 0xf0000000;
  for (i = 16;i < 24;i++) {
    res = (hi[2] & mask);
    sprintf(array, "%lx", res);
    result[i] = array[0];
    mask = mask >> 4;
  }
  mask = 0xf0000000;
  for (i = 24;i < 32;i++) {
    res = (hi[3] & mask);
    sprintf(array, "%lx", res);
    result[i] = array[0];
    mask = mask >> 4;
  }
}

// FUNCIONAMIENTO PROCESAR:
// Procesar aplica el algoritmo compuesto de 4 funciones y se suma su resultado
// a los hi
void procesar(unsigned long int *pBuffer, unsigned long int *hi
, unsigned long int *r, unsigned long int *k) {
  unsigned short int i, g;
  unsigned long int a, b, c, d, f, temp, aux, aux2;

  a = hi[0];
  b = hi[1];
  c = hi[2];
  d = hi[3];
  g = 0;
  f = 0;
  for (i = 0;i < R_K_SIZE;i++) {
    if ((i >= 0) && (i <= 15)) {
      f = ((b & c) | ((~b) & d));
      g = i;
    }
    else if ((i >= 16) && (i <= 31)) {
      f = ((d & b) | ((~d) & c));
      g = ((5 * i) + 1) % 16;
    }
    else if ((i >= 32) && (i <= 47)) {
      f = (b ^ c) ^ d;
      g = ((3*i) + 5) % 16;
    }
    else if ((i >= 48) && (i <= 63)) {
      f = (c ^ (b | (~d)));
      g = (7*i) % 16;
    }
    temp = d;
    d = c;
    c = b;
    aux2 = (a + f + k[i] + pBuffer[g]);
    aux = leftrotate(aux2, r[i]);
    b = b + aux;
    a = temp;
  }
  hi[0] = hi[0] + a;
  hi[1] = hi[1] + b;
  hi[2] = hi[2] + c;
  hi[3] = hi[3] + d;
}

// FUNCIONAMIENTO PADDING:
// Se realiza padding cuando la cantidad de bytes leidos
// de un archivo es menor a 64. Como se interpreta lo leido como
// 16 enteros de 4 bytes, si el fread devuelve un valor menor a 16
// se hace el padding.
//   El primer paso es colocar un uno despues del último bit leido. Esto
// se hace con pos que es el resultado de fread. ej: si pos es 9 quiere decir
// que pudo llenar 9 posiciones del array con números de 4 bytes. Esto es de
// 0 a 8. Por lo tanto en la posición 9 debe colocar el uno despues
// del último bit.
// 1) Este bit se busca en el ciclo WHILE haciendo un bitwise and
// con la máscara
//
// 2) Si no encontro un uno después de terminar el while
// agrega directamente un 0x80.
// Si encontró depende de como es la disposición de los bytes:
//
// 3) Ej: 0x05726f4c si la cantidad hasta el primer es 4
// se agrega el uno en la próxima posición. En caso de que justo
// sea la última posición se agrega el uno al comienzo del
// otro bloque (VER MD5 EN T_D_CHECK);
//
// 4) Ej: 0x00726f4c si la cantidad hasta el primer bit
// mod 2 es par se agrega como: // 0x80726f4c

// 5) Ej: 0x00026f4c si la cantidad de hasta el primer
// bit mod 2 es impar se agrega como: 0x80026f4c

// Esto se hace porque los números están en little endian pero
// se muestran en big endian (ver aclaración t_D_Check.c)
// entonces como el resultado debe ser interpretado luego
// como little, los numeros quedan:
// 3) 0x00000008 4) 0x4c6f7280 y 5) 0x4c6f0280
// que muestra que al final de los bits leidos se agrega un uno como marca

// Devuelve en bits_extras la cantidad de bits que se encuentra en
// en la posicion pos de array. 6)

int padding(unsigned long int *array, size_t pos,
	    unsigned long int *bits_extras) {
  unsigned short int i = 0, resto;
  unsigned long int mask = 0x80000000;
  unsigned long int cero = 0;

  while ((i < 32) && (cero == 0x0)) {
      cero = (array[pos] & mask);  // VER 1) En FUNCIONAMIENTO PADDING
      if (cero == 0x0) {
	mask = mask >> 1;
	i++;
      }
    }

  if (cero == 0x0) {  // VER 2) En FUNCIONAMIENTO PADDING
    array[pos] = 0x80;
    array[pos] = array[pos] | cero;
    // i = 32;
  } else {
    if (i == 4) {  // VER 3) En FUNCIONAMIENTO PADDING
      if (pos == 15)
	return ERR_PROXIMA_POS;  // VER 3) En FUNCIONAMIENTO PADDING
      else {
	cero = 0x80;
	array[pos + 1] = array[pos + 1] | cero;
	i = 32;
      }
    } else {
      resto = i / 4;
      if (fmod(resto, 2) == 0)  // VER 4) En FUNCIONAMIENTO PADDING
	cero = cero << 8;
      else {
	cero = cero << 12;
	i = i - 4;  // VER 5) En FUNCIONAMIENTO PADDING
	}
      array[pos] = array[pos] | cero;  // VER 5) En FUNCIONAMIENTO PADDING
    }
  }
  *bits_extras = 32 - i;
  return SUCCESSFUL_EXECUTION;
}

void blanquear_int(unsigned long int *array, size_t pos) {
  unsigned int i;
  for (i = 0 ;i < pos;i++)
    array[i] = (array[i] & 0x00000000);
}

// FUNCIONAMIENTO PARSEAR:
// El parseo obtiene los primeros 35 caracteres
// del archivo checksums que corresponden al hash
// y un " *", que luego se descartan. El resto
// se leen de a uno hasta encontrar "/n" o caracter de fin de archivo.
// El resultado da la ruta del archivo a leer.

void parsear(char *res, char *dir, FILE* pFile) {
  char c = 0;
  unsigned int i;

  if ((fgets(res, 35, pFile) != NULL)) {
    res[32] = '\0';
    i = 0;
    while (!(feof(pFile)) && (c != '\n') && (c != EOF)) {
      c = fgetc(pFile);
      if ((c != '\n') && (c != EOF)) {
	dir[i] = c;
	i++;
      }
    }
  }
}

void blanquear_string(char *array, size_t pos) {
  unsigned int i;
  for (i = 0 ;i < pos;i++)
    array[i] = 0;
}

// FUNCIONAMIENTO ACTUALIZAR_TAMANO:
// Actualiza el tamaño del archivo incrementando los tam_
// de a uno por si el archivo es mas grande que 4 bytes.
// En caso afirmativo que se llega a ese estado en tam_14
// vuelve a cero y se agrega un uno de carry en tam_15
//

void actualizar_tamano(unsigned long int *tam_14,
		       unsigned long int *tam_15, unsigned long int tam_parcial) {
  while (tam_parcial != 0) {
    while ((*tam_14 < 0xFFFFFFFF) && (tam_parcial != 0)) {
      (*tam_14)++;
      tam_parcial--;
    }
    if ((*tam_14 == 0xFFFFFFFF) && (tam_parcial != 0)) {
      (*tam_14)++;
      (*tam_15)++;
    }
  }
}

// FUNCIONAMIENTO AGREGAR_TAMANO:
// Actualiza el tamaño del archivo incrementando los tam_
// de a uno por si el archivo es mas grande que 4 bytes.
// En caso afirmativo que se llega a ese estado en tam_14
// vuelve a cero y se agrega un uno de carry en tam_15
//

void agregar_tamano(unsigned long int *array,
		    unsigned long int tam_14, unsigned long int tam_15) {
  (array)[14] = tam_14;
  (array)[15] = tam_15;
}

// FUNCIONAMIENTO VERIFICAR_KB:
// Verifica si bits contine 1 kb. En caso afirmativo
// devuelve el mensaje en stderr y inicializa la
// variable

void verificar_kb(unsigned long int *bits, char *dir) {
  if ((fmod(*bits, 8192) == 0) && (*bits != 0)) {
    fprintf(stderr, "%s - kilobyte procesado\n", dir);
    *bits = 0;
    }
}
