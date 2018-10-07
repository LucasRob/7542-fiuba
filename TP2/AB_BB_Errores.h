/*
 *AB_BB_ERRORES
 *
 *  Created on: 1-4-2012
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __AB_BB_ERRORES_H__
#define __AB_BB_ERRORES_H__

// ERRORES:
//
// AB_BB_NO_VACIO: Cuando un árbol no esta vacio 
// AB_BB_IGUAL: Devuelve este valor si la comparación 
// de los dos elementos dió igual.
//
// AB_BB_ENCONTRADO: Devuelve este valor si la se encontró el elemento.
// AB_BB_INSERTADO: Si pudo insertar el elemento.
// AB_BB_BORRADO: Si pudo borrar el elemento. 
// AB_BB_MAYOR: Devuelve este valor si la comparación. 
// de los dos elementos dio mayor.
// AB_BB_MOVIDO: Si pudo mover el elemento.
// AB_BB_ENCONTRADO: Si pudo encontrar el elemento.
// ERR_AB_BB_INSERTAR_IGUAL: Cuando el elemento a insertar es igual a otro.  
// ERR_AB_BB_NO_ENCONTRADO: Cuando no encontró el elemento.   
// ERR_AB_BB_VACIO: Cuando el árbol está vacío.  
// ERR_AB_BB_BUSQUEDA_NO_ENCONTRADO: Cuando no encontró el elemento.
// AB_BB_MENOR: Devuelve este valor si la comparación 
// de los dos elementos dio menor.

#define AB_BB_NO_VACIO 0
#define AB_BB_IGUAL 0
#define AB_BB_ENCONTRADO 0
#define AB_BB_INSERTADO 0
#define AB_BB_BORRADO 0
#define AB_BB_MAYOR 1  
#define ERR_AB_BB_INSERTAR_IGUAL 1  
#define ERR_AB_BB_NO_ENCONTRADO 1  
#define ERR_AB_BB_VACIO 1  
#define ERR_AB_BB_BUSQUEDA_NO_ENCONTRADO 1  
#define AB_BB_MENOR -1  

#endif
