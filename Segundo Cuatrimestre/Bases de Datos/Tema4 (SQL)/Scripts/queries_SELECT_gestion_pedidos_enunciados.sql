## Queries para gestion_pedidos

## Si estuvieramos desde el cliente de  MariaDB (mysql) ejecutar.
## show databases;
## use  GestionPedidos;
## show tables;

## En DBeaver, establcer conexión con BD y ejecutar script


## 1) Seleccionar los sliente (nombre y saldo) con el mayor saldo 
 
SELECT nombre_cl , MAX(saldo_cl) FROM cliente c;

## 2) Seleccionar el id del pedido y la fecha del pedido más antiguo
 
SELECT id_pedido , MIN(fecha_pedido) FROM pedido p;  

## 3) Seleccionar el id del pedido y la fecha del pedido más reciente
 
SELECT id_pedido , MAX(fecha_pedido) FROM pedido p; 

## 4) Seleccionar el nombre de los Clientes cuyo nombre contega una 'a'
 
SELECT nombre_cl FROM cliente c WHERE nombre_cl LIKE '%a%';

## 5) Seleccionar el nm¡ombe y la ciudad de los Clientes de Madrid
 
SELECT nombre_cl , ciudad_cl FROM cliente c WHERE ciudad_cl = 'Madrid';

## 6) Seleccionar el país, el saldo y el nombre de los Clientes de España que tengan saldo superior a 200 euros

SELECT pais_cl , saldo_cl , nombre_cl FROM cliente c WHERE pais_cl  = 'España' AND saldo_cl > 200; 

## 7) Clientes (nombre, pais y descuento) que sean de España o cuyo descuento sea inferior a 10% ordenados por descuento
 
SELECT nombre_cl , pais_cl , descuento_cl FROM cliente c WHERE pais_cl = 'España' OR descuento_cl < 10 ORDER BY descuento_cl;



## 8)  Clientes (nombre y saldo) con saldo entre 300 y 500
 
SELECT nombre_cl , saldo_cl FROM cliente c WHERE saldo_cl IN (300, 500);

## 9)  Seleccionar el id  y el nombre de los Clientes cuyo identificador sea 3 o 5 ordenados de forma ASC. 

SELECT id_cliente , nombre_cl FROM cliente c WHERE id_cliente = 3 OR id_cliente = 5 ORDER BY id_cliente ASC; 

## 10) Seleccionar el id, el nombre y la ciudad de los CLientes que no sean de Madrid
 
SELECT id_cliente , nombre_cl , ciudad_cl FROM cliente c WHERE ciudad_cl != 'Madrid';

## 11) Seleccionar el id, el nombre y la dirección de los Clientes que no tienen direccion
 
SELECT id_cliente , nombre_cl , direccion_cl FROM cliente c WHERE direccion_cl IS NULL;

## 12) Seleccionar el identificador y el stock de los articulos cuyo stock es mayor de 100
 
SELECT id_articulo_almacen , stock_articulo_almacen FROM almacen a WHERE stock_articulo_almacen > 100; 

##13) Seleccionar el nombre de las ciudades distintas en las que residen nuestros clientes

SELECT DISTINCT ciudad_cl FROM cliente c;

##14) Numero de ciudades distintas en las que viven los clientes
 
SELECT COUNT(DISTINCT ciudad_cl) FROM cliente c; 

## 15) Numero de clientes residentes en cada ciudad
 
SELECT ciudad_cl , COUNT(*) AS numeroClientes FROM cliente c GROUP BY ciudad_cl; 

## 16) Numero de Articulos agrupados por proveedor que tenemos en el alamacen (listarlos en orden descendente)

SELECT id_proveedor_almacen , COUNT(id_articulo_almacen) AS numeroArticulos FROM  almacen a GROUP BY id_proveedor_almacen ORDER BY numeroArticulos DESC;

## 17) Coste total de todos los articulos que suministra un proveedor (utilizar el stock y precio unitario)

SELECT id_proveedor_almacen , SUM(stock_articulo_almacen * precio_unitario) AS costeTotal FROM almacen a GROUP BY id_proveedor_almacen;  

## 18) Precio medio de todos los articulos del alamacen
 
SELECT AVG(precio_unitario) AS precioMedio FROM almacen a; 

## 19) Precio medio de todos los articulos de un proveedor
 
SELECT id_proveedor_almacen , AVG(precio_unitario) AS precioMedio FROM almacen a GROUP BY id_proveedor_almacen;

