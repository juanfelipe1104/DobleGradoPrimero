## Queries para biblioteca

## Si estuvieramos desde el cliente de  MariaDB (mysql) ejecutar.
show databases;
use  biblioteca2;
show tables;

## En DBeaver, establcer conexión con BD y ejecutar script

## 1) Cuales son las distintas salas en las que hay estantenias  dentro de la biblioteca

SELECT DISTINCT e.sala FROM estanteria e WHERE e.sala IS NOT NULL; 

## 2) En que planta se encuentra cada sala

SELECT e.planta, e.sala FROM estanteria e WHERE e.planta OR e.sala IS NOT NULL GROUP BY e.sala; 

## 3) Cuantas estanterías hay 

SELECT COUNT(e.cod_estanteria) AS numEstanterias FROM estanteria e; 

#3.1) Cuantas estanterías hay en cada planta. Indicar la planta

SELECT e.planta, COUNT(e.cod_estanteria) AS numEstanterias FROM estanteria e WHERE e.planta IS NOT NULL GROUP BY e.planta;

## 4) Cuales son esas estanterías y en que planta y sala está ubicada cada una

SELECT * FROM estanteria e; 

## 5) Obtener las estanterías que aún no están ubicadas en la bibilioteca
 
SELECT e.cod_estanteria FROM estanteria e WHERE e.sala OR e.planta IS NULL; 

## 6) Cuantos ejemplares hay en cada estantería

SELECT e.cod_estanteria , COUNT(e2.cod_ejemplar) FROM estanteria e JOIN ejemplar e2 ON e.cod_estanteria = e2.cod_estanteria_ej
GROUP BY e.cod_estanteria; 

## 7) Obtener el num_matricula de los alumno y obtener cuantos ejemplares tiene o ha tenido prestados cada uno, ordernados de mayor a menor

SELECT a.num_matricula, COUNT(p.cod_ejemplar_prestamo) AS numPrestados FROM prestamo p JOIN alumno a ON p.num_matricula_prestamo = a.num_matricula
GROUP BY a.num_matricula ORDER BY numPrestados DESC;

## 7.1) Obtener además el nombre del alumno

SELECT a.num_matricula, a.nombre, COUNT(p.cod_ejemplar_prestamo) AS numPrestados FROM prestamo p JOIN alumno a ON p.num_matricula_prestamo = a.num_matricula
GROUP BY a.num_matricula ORDER BY numPrestados DESC;

## 8)  Listar los cod del ejemplares que están actualmente prestados. Indicar el nombre y curso del alumno que lo tiene prestado 

SELECT p.cod_ejemplar_prestamo, a.num_matricula, a.nombre, a.curso FROM prestamo p JOIN alumno a ON p.num_matricula_prestamo = a.num_matricula
WHERE p.fecha_devolucion IS NULL;

## 9) Nombre, curso y numero de ejemplares que tiene prestado cada alumno

SELECT a.num_matricula, a.nombre, a.curso, COUNT(p.cod_ejemplar_prestamo) FROM prestamo p JOIN alumno a ON p.num_matricula_prestamo = a.num_matricula
WHERE p.fecha_devolucion IS NULL GROUP BY a.num_matricula;

## 10) Lista de ejemplares que nunca han sido prestados

SELECT e.cod_ejemplar FROM ejemplar e LEFT JOIN prestamo p ON e.cod_ejemplar = p.cod_ejemplar_prestamo
WHERE p.fecha_prestamo IS NULL;


