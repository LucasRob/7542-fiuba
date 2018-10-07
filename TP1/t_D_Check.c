 /*
 *T_D_CHECK.c
 *
 *  Created on: 16-mar-2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */
#include "t_D_Check.h"

// ACLARACIÓN SOBRE LITTLE Y BIG ENDIAN EN ESTE TP:
// Al leer los bits desde un archivo y guardandolos en
// enteros estos se guardan en little endian ej:
// si los bytes leidos son: 65726f4c y lo guarda como
// entero, va interpretarlo como tal entonces el 4c es
// el bit menos significativo, el que sigue es el 6f
// y así. Entonces al tener el entero como x = 0x4c6f7265
// estoy guradando los bits tal cual los leí.


int crear_D_Check(t_D_Check* myTdc, char *myDir) {
  strcpy(myTdc->dir, myDir);
  if (!(myTdc->pFile = fopen (myTdc->dir, "rb")))
	return ERR_BINARY_NOT_FOUND;
	else return SUCCESSFUL_EXECUTION;
}

int destruir_D_Check(t_D_Check* myTdc) {
  int error;
  error = fclose(myTdc->pFile);
  if (error)
      return ERR_FILE_CLOSE;
      else return SUCCESSFUL_EXECUTION;
}

// FUNCIONAMIENTO MD5:
// El MD5 comienza inicializando variables en 1)
//  y enpieza a leer el archivo 2). Pueden ocurrir 3
// casos: el primero que la cantidad de enteros
// de 4 bytes sea menor a 14 (3). Esto implica que
// no se encuentra entre los primeros 56 bytes entonces el
// padding consistirá en agregar un 1 en la posición indicada por
// result y tantos ceros hasta la posición 14 que es donde va el
// tamaño total del archivo según el algoritmo de MD5.
//   El otro caso (4) es si el tamaño del archivo está entre
// 56 y 64 (posiciones 14 y 15 llenas). Se debe agregar el 1
// donde corresponda y procesar ese array. Luego se hace otro
// array (5) con la cantidad de ceros hasta el byte 56 y luego el tamaño
// del archivo. Puede ocurrir que existen bits en la posición 15 del array
// y el uno se debe colocar en el array auxiliar. Este caso se contempla en
// 6).
//   El último (7) caso es si el vector de enteros está lleno. Entonces
// Se procesa directamente.
// Al final se hace un swap de los hi (8) porque deben estar así para hacer
//  el append (9). En varias instancias se calcula el tamaño del archivo.
// Esto se calcula obteniendo los bits del fread (10) y los bits extras
// que pueda haber en una posición que contenga menos de 4 bytes (11).


int md5(t_D_Check myTdc, char *myDigest) {
  unsigned long int r[R_K_SIZE], hi[HI_SIZE], tam_parcial, bits;
  unsigned long int k[R_K_SIZE] = { 0xd76aa478, 0xe8c7b756,
0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613,
0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562,
0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453,
0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6, 0xc33707d6, 0xf4d50d87,
0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44,
0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 0x289b7ec6, 0xeaa127fa,
0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8,
0xc4ac5665, 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 0x6fa87e4f,
0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235,
0x2ad7d2bb, 0xeb86d391 };
  size_t result, next;
  unsigned short int i;
  unsigned long int tam_14 = 0;
  unsigned long int tam_15 = 0;
  unsigned long int bits_extras = 0;

  fprintf(stderr, "%s - comienza procesamiento\n", myTdc.dir);
  inicializar(hi, r);    // VER 1)
  next = 0;
  bits = 0;
  do {
    blanquear_int(myTdc.pBuffer, BUFFER_SIZE);
    result = fread(myTdc.pBuffer, sizeof(unsigned long int),
		   BUFFER_SIZE, myTdc.pFile);  // VER 2)
    tam_parcial = result * 4 * 8;  // VER(10)
    actualizar_tamano(&tam_14, &tam_15, tam_parcial);
    bits = bits + tam_parcial;
    verificar_kb(&bits, myTdc.dir);
    if (result < 14) {  // VER 4)
      next = padding(myTdc.pBuffer, result, &bits_extras);
      actualizar_tamano(&tam_14, &tam_15, bits_extras);
      bits = bits + bits_extras;
      verificar_kb(&bits, myTdc.dir);
      agregar_tamano(myTdc.pBuffer, tam_14, tam_15);
      procesar(myTdc.pBuffer, hi, r, k);
    } else if ((result >= 14) && (result < BUFFER_SIZE)) {   // VER 5
      next = padding(myTdc.pBuffer, result, &bits_extras);  // VER 11
      actualizar_tamano(&tam_14, &tam_15, bits_extras);
      bits = bits + bits_extras;
      verificar_kb(&bits, myTdc.dir);
      procesar(myTdc.pBuffer, hi, r, k);
    } else procesar(myTdc.pBuffer, hi, r, k);   //  VER 8
  }while (!feof(myTdc.pFile));
  if ((result >= 14) && (result < BUFFER_SIZE)) {  //  VER 6
    blanquear_int(myTdc.pBuffer, BUFFER_SIZE);
    agregar_tamano(myTdc.pBuffer, tam_14, tam_15);
    if (next == ERR_PROXIMA_POS)   // VER 7
      myTdc.pBuffer[0] = 0x80000000;
    procesar(myTdc.pBuffer, hi, r, k);
  }
  for (i = 0;i < HI_SIZE;i++)
    swap_endian(&(hi[i]));   //  VER 9
  append(hi, myDigest);
  fprintf(stderr, "%s - finaliza procesamiento\n", myTdc.dir);
  return SUCCESSFUL_EXECUTION;
}



