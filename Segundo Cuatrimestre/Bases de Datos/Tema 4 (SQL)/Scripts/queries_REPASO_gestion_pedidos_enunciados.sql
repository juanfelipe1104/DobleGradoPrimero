## Queries para GestionPedidos (Curso 2020-2021)


show databases;
use  gestion_pedidos2;
show tables;

 
## 1) Obtener el numero de articulos del alamcen, el stock máximo, el minimo y la media del precio unitario

SELECT COUNT(DISTINCT id_articulo_almacen), MAX(stock_articulo_almacen) , MIN(precio_unitario) , AVG(precio_unitario) FROM almacen a;

## 2) obtener lo solicitado en  el punto 1 pero para cada articulo

SELECT id_articulo_almacen , COUNT(id_articulo_almacen), MAX(stock_articulo_almacen) , MIN(precio_unitario) , AVG(precio_unitario) FROM almacen a GROUP BY id_articulo_almacen; 

## 3) Cruzarlo con la información del articulo para tener el nombre de dicho articulo

SELECT a2.id_articulo , a2.descripcion_articulo , COUNT(id_articulo_almacen), MAX(stock_articulo_almacen) , MIN(precio_unitario), AVG(precio_unitario)
FROM almacen a
RIGHT JOIN articulo a2
ON a.id_articulo_almacen = a2.id_articulo GROUP BY a.id_articulo_almacen; 

## 4) Por cada cliente (idntificador y nombre) el total de pedidos que ha realizado

SELECT id_cliente , nombre_cl, COUNT(p.id_pedido)
FROM cliente c
JOIN pedido p
ON c.id_cliente = p.id_cliente_ped GROUP BY id_cliente;  

## 5) Indicar, el número de clientes, el saldo medio y el descuento más alto de los clientes de Madrid

SELECT ciudad_cl , COUNT(id_cliente) AS numClientes , AVG(saldo_cl) AS saldoMedio , MAX(descuento_cl) AS maxDescuento
FROM cliente c
WHERE ciudad_cl = 'Madrid' GROUP BY ciudad_cl;

## 6) Insertar dos nuevos clientes en la BD de los que solo se conocen los siguientes datos: 
## Cliente 1 --> Nombre: Luis Pedreira, Ciudad: Murcia, Pais: España
## Cliente 2 --> Nombre: Laura Boix, Ciudad: Barcelos, País: España

INSERT
INTO cliente (nombre_cl, ciudad_cl, pais_cl)
VALUES ('Luis Pedreira', 'Murcia', 'España'), ('Laura Boix', 'Barcelos', 'España');

## 7) Actualizar el saldo, el credito y el descuento de los clientes Luis Pedreira y Luara Boix. Los valores en ambos clientes serán:
## saldo=100, credito=500, descuento=10

UPDATE cliente 
SET saldo_cl = 100, credito_cl = 500, descuento_cl = 10
WHERE nombre_cl = 'Luis Pedreira' OR nombre_cl = 'Laura Boix';

## 8) Insertar un en el almacen un nuevo producto cuyo codigo es 11 y el código de su proveedor es 3 

INSERT
INTO articulo (id_articulo)
VALUES('AA11');

INSERT
INTO almacen (id_articulo_almacen, id_proveedor_almacen)
VALUES('AA11', 'PROV3');

## 9) Actualiza la tabla alamcen para añdir al articulo y proveedor insertados en la sentencia anterior los valores de stock_articulo_almacen
## y de precio_unitario. Los valores deben ser 100 y 37 respectivamente. 

UPDATE almacen
SET stock_articulo_almacen = 100, precio_unitario = 37
WHERE id_articulo_almacen = 'AA11' AND id_proveedor_almacen = 'PROV3';

## 10) Eliminar del almacen aquellos articulos cuyo stock sea inferior a 30 unidades

DELETE
FROM almacen
WHERE stock_articulo_almacen < 30;

##11) Crear una vista con la informacion del identificador y el nombre del cliente así como con los identificadores 
## de los pedidos que ha realizado y su descripción

CREATE VIEW infoCliente AS
SELECT c.id_cliente , c.nombre_cl , p.id_pedido , p.descripcion_pedido
FROM cliente c JOIN pedido p ON c.id_cliente = p.id_cliente_ped;

## 12)  Obtner todos los campos de la vista creada en la query anterior

SELECT * FROM infoCliente ic;



