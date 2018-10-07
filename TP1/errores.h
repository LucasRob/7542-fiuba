/*
 *ERROES.H
 *
 *  Created on: 17-mar-2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef ERRORES__
#define ERRORES_

// SUCCESSFUL_EXECUTION: Devuelve este valor si la ejecución fué exitosa
// ERR_CHECKSUMS_NOT_FOUND: Error cuando no se encuentra el archivo de checksums
// ERR_ARGUMENTS: Error c uando no coincide la cantidad de argumentos del main
// ERR_BINARY_NOT_FOUND: Error cuando no se encuentra archivo binario
// ERR_FILE_CLOSE: Error cuando se cierra el archivo
// ERR_PROXIMA_POS: Error cuando al hacer el padding se deber agregar el uno de
// marca en otro padding auxiliar.

#define SUCCESSFUL_EXECUTION 0
#define ERR_CHECKSUMS_NOT_FOUND 1
#define ERR_ARGUMENTS 2
#define ERR_BINARY_NOT_FOUND 3
#define ERR_FILE_CLOSE 4
#define ERR_PROXIMA_POS 5
#endif /* ERRORES_ */
