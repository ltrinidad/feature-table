# feature-table

## Interfaz v1.0:

### Crear Tabla
```c
t_table* tabla = table_create();
```

### Agregar títulos (opcional)
``` c
table_add_titles(tabla, 3, "Primera", "Segunda", "Tercera");
```
Siendo el segundo parámetro la cantidad de títulos (esta función tiene argumentos variables).

### Crear una fila
```c
t_row* fila1 = row_create();
```
### Agregar data a una fila
```c
row_add_data(fila1, data1, dataAsString); 
```
Añade luego del último elemento. Además, _data_ puede ser cualquier puntero a struct (es un _void*_), por eso definimos un _dataAsString_ como displayer

### Agregar data a una fila en un cierto índice
```c
row_add_data_at_index(fila1, 1, data, dataAsString);
```
En este caso, la posición cero quedaría vacía o con guion.

### Agregar filas a una tabla
```c
table_add_rows(tabla, 2, fila1, fila2);
```
Siendo el segundo parámetro la cantidad de filas (esta función tiene argumentos variables). 

### Agregar una lista como fila
_En este caso, la lista es una [lista de la so-commons-library](https://github.com/sisoputnfrba/so-commons-library/blob/master/src/commons/collections/list.h)_
```c
t_list* lista = list_create();

//... lleno la lista con algo, de cierta estructura

table_add_list_as_row(tabla, lista, listElementAsString);
```
Finalmente, si hay una fila de 5 elementos y es la mayor en tamaño, todas las demás filas van a tener los espacios vacíos o un guion en esos lugares sobrantes.

### Desplegar la tabla por pantalla
```c
table_show(tabla);
```
