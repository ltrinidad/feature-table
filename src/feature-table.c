/*
 ============================================================================
 Name        : feature-table.c
 Author      : ltrinidad
 Version     : v1.0
 ============================================================================
 */
#include "feature-table.h"


int main(void) {
	t_row* new_row = row_create();

	printf("Cree la fila :D \n");
	fflush(stdout);

	t_alumno* pepito = new_alumno("pepito", "perez");

	row_add_data(new_row, pepito, alumno_to_string);

	char* pepito_as_string = _row_element_as_string_at_index(new_row, 0);

	printf("Pepito to string: %s\n", pepito_as_string);
	fflush(stdout);

	free(pepito_as_string);

	// TODO falta liberar toda la memoria que pide la fila :D
	return 0;
}

// FUNCIONES

t_row* row_create(){
	return list_create();
}

void row_add_data(t_row* row, void* data, char* (*to_string)(void*)){
	t_row_element* new_row_element = malloc(sizeof(t_row_element));

	new_row_element->data = data;
	new_row_element->to_string = to_string;

	list_add(row, new_row_element);
}

// FUNCIONES PRIVADAS

char* _row_element_as_string_at_index(t_row* row, int index){
	t_row_element* element = list_get(row, index);

	return element->to_string(element->data);
}

// TEST

char* alumno_to_string(void* elem){
	t_alumno* alum = (t_alumno*) elem;

	char* as_string = string_new();

	string_append_with_format(&as_string ,"%s %s", alum->nombre, alum->apellido);

	return as_string;
}

t_alumno* new_alumno(char* nombre, char* apellido){
	t_alumno* alum = malloc(sizeof(t_alumno));

	alum->nombre = strdup(nombre);
	alum->apellido = strdup(apellido);

	return alum;
}
