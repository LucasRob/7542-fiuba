#include "t_D_Check.h"

// FUNCIONAMIENTO MAIN:
// Primero verifica si hay un solo argumento
// aparte del nombre (1), sino devuelve ERR_ARGUMENTS (2),
// Si no encuentra el archivo de checksums (3)
// devuelve ERR_CHECKSUMS_NOT_FOUND (4). En caso contrario
// Empieza a parsear el archivo (5). Si no encuentra
// algún archivo de los listados igual se considera un
// caso favorable (6). Si encuentra un archivo le aplica el md5(7)
// y compara con el hash de checksums (8). El programa
// devolverá por stdout y stderr lo que corresponda de los
// resultados favorables.


int main(int argc, char* argv[]) {
  t_D_Check tdc;
  char direccion[FILE_SIZE];
  char digest[APPEND_SIZE+1];
  char hash[HASH_SIZE];
  FILE* pChecksums;
  int res = SUCCESSFUL_EXECUTION;


  if (argc > 1) {  // VER 1)
    if ((pChecksums =  fopen(argv[1], "r")) != NULL) {  // VER 3)
	while (!(feof(pChecksums))) {
	  blanquear_string(hash, HASH_SIZE);
	  blanquear_string(direccion, FILE_SIZE);
	  parsear(hash, direccion, pChecksums);  // VER 5)
	  res = crear_D_Check(&tdc, direccion);
	  if (res == ERR_BINARY_NOT_FOUND) {
	    fprintf(stdout, "%s NO ENCONTRADO\n", direccion);    // VER 6)
	    res = SUCCESSFUL_EXECUTION;
	  } else {
	    res = md5(tdc, digest);  //  VER 7)
	    if (strcmp(digest, hash) == 0)  // VER 8
	      fprintf(stdout, "%s OK\n", direccion);
	    else fprintf(stdout, "%s NO OK\n", direccion);
	    res = destruir_D_Check(&tdc);
	    if (res != 0)
	      res = SUCCESSFUL_EXECUTION;
	  }
	}
	fclose(pChecksums);
    } else res = ERR_CHECKSUMS_NOT_FOUND;   // VER 4)
  } else res =  ERR_ARGUMENTS;   // VER 2)

  return res;
}
