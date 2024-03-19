## Queries TIPO JOIN para gestion_pedidos

## Si estuvieramos desde el cliente de  MariaDB (mysql) ejecutar.
## show databases;
## use  GestionPedidos;
## show tables;

## En DBeaver, establcer conexión con BD y ejecutar script

## INNER JOIN
## 1) Consultar los clientes (id_cliente, su nombre) que tengan pedidos y añadir a la consulta el identificador 
## del pedido y la descripción 

SELECT c.id_cliente , c.nombre_cl , p.id_pedido , p.descripcion_pedido FROM cliente c JOIN pedido p ON p.id_cliente_ped = c.id_cliente; 

## LEFT JOIN 
## 2) Seleccionar todos los clientes incluyendo en la consulta el id_cliente, su nombre, el id del pedido  y  
## la descripción del (incluyendo en la lista los clientes que no tengan pedidos)
   
SELECT c.id_cliente , c.nombre_cl , p.id_pedido , p.descripcion_pedido FROM cliente c LEFT JOIN pedido p ON p.id_cliente_ped = c.id_cliente;

## LEFT JOIN
## 3) Para todos los proveedores de la tabla proveedores obtener el stock de cada uno de los articulos existentes en el alamcen

SELECT p.id_proveedor , a.id_articulo_almacen , a.stock_articulo_almacen FROM proveedor p LEFT JOIN almacen a ON a.id_proveedor_almacen = p.id_proveedor  

## RIGHT JOIN 
## 4) Obtener los nombres de los todos los proveedores indicando cuales de ellos están en la tabla almacen y cuales no

SELECT p.id_proveedor , a.id_proveedor_almacen , a.id_articulo_almacen FROM almacen a RIGHT JOIN proveedor p ON p.id_proveedor = a.id_proveedor_almacen;

## RIGHT JOIN
##5)Obtener el id articulo y la descripción del articulo de los articulos contenidos en los pedidos. Muestra también la identidad 
## del pedido. Podría haber articulos no incluidos en ningun pedido

SELECT DISTINCT a.id_articulo , a.descripcion_articulo , dp.id_pedido_detalles FROM detalles_pedido dp RIGHT JOIN articulo a ON dp.id_articulo_detalles  = a.id_articulo; 

## 6) seleccior cantidad de cada articulo del almacen - sumar el stock acumulado por articulo
## mostrar el id_articulo y su stock total

SELECT id_articulo_almacen , SUM(stock_articulo_almacen) FROM almacen a GROUP BY id_articulo_almacen;


