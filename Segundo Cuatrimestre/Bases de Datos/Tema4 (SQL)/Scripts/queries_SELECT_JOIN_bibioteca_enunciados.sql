## Queries para biblioteca

## Si estuvieramos desde el cliente de  MariaDB (mysql) ejecutar.
show databases;
use  biblioteca2;
show tables;

## En DBeaver, establcer conexión con BD y ejecutar script

## 1) Consultar todos los autores (su nombre y cuidad) de la biblioteca

SELECT nombre_autor , ciudad FROM autor a; 

## 2) obtener el cod del ejemplar más antiguo de la biblioteca

SELECT cod_ejemplar, fecha_edicion  FROM ejemplar e ORDER BY fecha_edicion LIMIT 1; 

## 2.1) Ejemplar más reciente

SELECT cod_ejemplar, fecha_edicion  FROM ejemplar e ORDER BY fecha_edicion DESC LIMIT 1;

## 3) Nombre de autor cuyo nombre contenga la cadena de caracteres 'th'

SELECT nombre_autor FROM autor a WHERE nombre_autor LIKE '%th%'; 

## 4) Autores de Francia

SELECT nombre_autor FROM autor a WHERE pais = 'Francia'; 

## 5) Países distintos de los que tenemos autores en la biblioteca

SELECT DISTINCT pais FROM autor a;  

## 6) El número de países distintos 

SELECT COUNT(DISTINCT pais) AS numeroPaises FROM autor a;

## 7) Cuantos autores tenemos de cada pais (group by)

SELECT pais , COUNT(cod_autor) AS numAutores FROM autor a GROUP BY pais; 

## 8) Cuantos ejemplares tenemos  de cada libro

SELECT cod_libro_ej AS libro , COUNT(cod_ejemplar) AS numEjemplares FROM ejemplar e GROUP BY cod_libro_ej; 

## 9)  Cuantos ejemplares tenemos prestados

SELECT COUNT(cod_ejemplar_prestamo) AS numPrestados FROM prestamo p WHERE fecha_devolucion IS NULL; 

## 10)  Cuales son esos ejemplares

SELECT cod_ejemplar_prestamo FROM prestamo p WHERE fecha_devolucion IS NULL; 

## 11) Numero de ejemplares prestados a cada alumno ordenados según el numero de libros
## que tienen en orden descendente

SELECT num_matricula_prestamo AS alumno , COUNT(cod_ejemplar_prestamo) AS numPrestados FROM prestamo p GROUP BY num_matricula_prestamo ORDER BY numPrestados DESC;

## INNER JOIN 
## 12) código de libro y su titulo de todos los ejemplares que tenemos en la biblioteca 

SELECT l.cod_libro , e.cod_ejemplar , l.titulo FROM libro l JOIN ejemplar e ON l.cod_libro = e.cod_libro_ej;

## 12.1) el titulo de los libros de los que tengo ejemplares

SELECT e.cod_ejemplar AS ejemplar , l.titulo  FROM libro l JOIN ejemplar e ON l.cod_libro = e.cod_libro_ej 

## 13) numero de matricula, nombre del alumno y cod del ejemplar que tiene prestado cada alumno. 
## Obenter tambien los alumnos que no tienen ningun ejemplar prestado

SELECT a.num_matricula, a.nombre, p.cod_ejemplar_prestamo FROM alumno a JOIN prestamo p ON a.num_matricula = p.num_matricula_prestamo
WHERE p.fecha_devolucion IS NULL; 


SELECT a.num_matricula, a.nombre, p.cod_ejemplar_prestamo FROM alumno a JOIN prestamo p ON a.num_matricula = p.num_matricula_prestamo
WHERE p.fecha_devolucion IS NOT NULL;

## LEFT JOIN
## 14) Codigos de los libros de los que no tenemos ningún ejemplar 
## (son los libros que aparecen el la tabla "libro" y que no aparecen la tabla "ejemplar")

SELECT l.cod_libro, l.titulo FROM libro l LEFT JOIN ejemplar e ON l.cod_libro = e.cod_libro_ej WHERE e.cod_libro_ej IS NULL;


