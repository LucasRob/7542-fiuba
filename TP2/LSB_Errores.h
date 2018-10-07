/*
 *LSB_ERRORES
 *
 *  Created on: 1-4-2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __LSB_ERRORES_H__
#define __LSB_ERRORES_H__

// ERRORES:
//
// LSB_IGUAL: Devuelve este valor si la comparación
//  de los dos elementos dió igual
//
// LSB_INSERTADO: Si pudo insertar el elemento
// LSB_BORRADO: Si pudo borrar el elemento 
// LSB_MOVIDO: Si pudo mover el elemento
// LSB_ENCONTRADO: Si pudo encontrar el elemento
// ERR_LSB_NO_EXISTE: Si no existe el elemento a buscar
// ERR_LSB_NO_MEMORIA: Si no pudo reservar memoria para alocar
// LSB_MAYOR: Devuelve este valor si la comparación 
// de los dos elementos dió mayor
//
// LSB_MENOR: Devuelve este valor si la comparación 
// de los dos elementos dió menor

#define LSB_IGUAL 0
#define LSB_INSERTADO 0
#define LSB_BORRADO 0
#define LSB_MOVIDO 0
#define LSB_ENCONTRADO 0
#define ERR_LSB_NO_EXISTE 1
#define ERR_LSB_NO_MEMORIA 1
#define LSB_MAYOR 1
#define LSB_MENOR -1


#endif
