TablasHash
==========

implementación y uso de tablas de dispersión en lenguaje C++

IMPLEMENTACIÓN: 

Implementar procedimientos de inserción y búsqueda en una tabla hash o tabla de dispersión con direccionamiento 
abierto y dispersión pseudo-aleatoria, y realizar análisis de rendimiento de las principales estrategias de 
exploración: exploración lineal, cuadrática, dispersión doble y re-dispersión.

Se utilizarán dos clases de objetos: una clase celda y otra clase tabla. 

La clase tabla tendrá como funciones miembros la búsqueda y la inserción.


El programa principal trabajará con registros con un número de DNI (sin letra) de ocho cifras como clave y debe
hacer lo siguiente:


1. Crear un banco de prueba con números de DNIs aleatorios entre 25.000.001 y 75.000.000
creados con la función rnd y almacenados en un vector BANCO.


2. Un sistema de menús permitirá realizar, por este orden, las elecciones siguientes:

a. Elegir el número de celdas.

b. Elegir el tamaño de los bloques.

c. Elegir el método de exploración:

Opciones: exploración lineal, cuadrática, dispersión doble y re-dispersión

d. Elegir el factor de carga.

e. Elegir el número de pruebas (búsquedas e inserciones) a realizar.


3. Una vez cargada la tabla se realizarán las pruebas de la siguiente forma:

a. Cargar la tabla desde el banco de prueba según las selecciones realizadas.

b. Inicializar los contadores del número de comparaciones de claves.

c. Realizar el número de búsquedas elegido.
Para ello obtener al azar claves ya introducidas y buscarlas.

d. Simular el número de inserciones elegido sin alterar el factor de carga
Para ello generar al azar nuevas claves y encontrar la posición de inserción.

e. Mostrar las opciones elegidas y las estadísticas del número de comparaciones de clave
