## Queries para biblioteca

## Si estuvieramos desde el cliente de  MariaDB (mysql) ejecutar.
## show databases;
## use  biblioteca;
## show tables;

## En DBeaver, establcer conexión con BD y ejecutar script

## 1) Consultar todos los autores (su nombre y cuidad) de la biblioteca


## 2) obtener el cod del ejemplar más antiguo de la biblioteca

## 2.1) Ejemplar más reciente


## 3) Nombre de autor cuyo nombre contenga la cadena de caracteres 'th'


## 4) Autores de Francia


## 5) Países distintos de los que tenemos autores en la biblioteca

## 6) El número de países distintos 


## 7) Cuantos autores tenemos de cada pais (group by)

## 8) Cuantos ejemplares tenemos  de cada libro


## 9)  Cuantos ejemplares tenemos prestados


## 10)  Cuales son esos ejemplares



## 11) Numero de ejemplares prestados a cada alumno ordenados según el numero de libros
## que tienen en orden descendente


## INNER JOIN 
## 12) código de libro y su titulo de todos los libros que tenemos en la biblioteca 

  
## 12.1) el titulo de los libros de los que tengo ejemplares


## 13) numero de matricula, nombre del alumno y cod del ejemplar que tiene prestado cada alumno. 
## Obenter tambien los alumnos que no tienen ningun ejemplar prestado


## LEFT JOIN
## 14) Codigos de los libros de los que no tenemos ningún ejemplar 
## (son los libros que aparecen el la tabla "libro" y que no aparecen la tabla "ejemplar")

