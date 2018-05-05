/*
 * feature-table.h
 *
 *  Created on: 5 may. 2018
 *      Author: utnso
 */

#ifndef FEATURE_TABLE_H_
#define FEATURE_TABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <commons/collections/list.h>
#include <commons/string.h>
#include <string.h>

// TEST
typedef struct{
	char* nombre;
	char* apellido;
} t_alumno;


// TIPOS Y ESTRUCTURAS
typedef t_list t_row;

typedef struct {
    void* data;
    char* (*to_string)(void*);
} t_row_element; // el manejo de linkear un elemento con el siguiente/anterior ya lo hace t_list


// FUNCIONES
t_row* 				row_create					();
void 				row_add_data				(t_row* row, void* data, char* (*to_string)(void*));

// FUNCIONES PRIVADAS
char* 				_row_element_as_string_at_index		(t_row* row, int index);

// TEST
t_alumno* 			new_alumno 					(char* nombre, char* apellido);
char* 				alumno_to_string			(void* elem);

#endif /* FEATURE_TABLE_H_ */
