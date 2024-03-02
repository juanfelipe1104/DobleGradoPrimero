-- MariaDB dump 10.19  Distrib 10.6.16-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: gestion_pedidos
-- ------------------------------------------------------
-- Server version	10.6.16-MariaDB-0ubuntu0.22.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Articulo`
--

DROP TABLE IF EXISTS `Articulo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Articulo` (
  `CodigoArticulo` varchar(100) NOT NULL,
  `NombreArticulo` varchar(100) NOT NULL,
  `DescripcionArticulo` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`CodigoArticulo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Articulo`
--

LOCK TABLES `Articulo` WRITE;
/*!40000 ALTER TABLE `Articulo` DISABLE KEYS */;
INSERT INTO `Articulo` VALUES ('COD1','Articulo1','Cosa1'),('COD2','Articulo2','Cosa2'),('COD3','Articulo3','Cosa3');
/*!40000 ALTER TABLE `Articulo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Cliente`
--

DROP TABLE IF EXISTS `Cliente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Cliente` (
  `IdCliente` int(11) NOT NULL AUTO_INCREMENT,
  `Nombre` varchar(100) NOT NULL,
  `Direccion` varchar(100) DEFAULT NULL,
  `Ciudad` varchar(100) NOT NULL,
  `Pais` varchar(100) NOT NULL,
  `Saldo` float NOT NULL,
  `Credito` float DEFAULT NULL,
  `Descuento` float DEFAULT NULL,
  PRIMARY KEY (`IdCliente`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Cliente`
--

LOCK TABLES `Cliente` WRITE;
/*!40000 ALTER TABLE `Cliente` DISABLE KEYS */;
INSERT INTO `Cliente` VALUES (1,'Juan','Calle 3','Madrid','España',1234,12345,50),(2,'Daniel','Calle 5','Madrid','España',1234570,21345,60);
/*!40000 ALTER TABLE `Cliente` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `DetallesPedido`
--

DROP TABLE IF EXISTS `DetallesPedido`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `DetallesPedido` (
  `IdPedidoCarrito` varchar(100) NOT NULL,
  `CodigoArticuloCarrito` varchar(100) NOT NULL,
  `CantidadArticulos` int(11) NOT NULL,
  PRIMARY KEY (`IdPedidoCarrito`,`CodigoArticuloCarrito`),
  KEY `DetallesPedido_Articulo_FK` (`CodigoArticuloCarrito`),
  CONSTRAINT `DetallesPedido_Articulo_FK` FOREIGN KEY (`CodigoArticuloCarrito`) REFERENCES `Articulo` (`CodigoArticulo`),
  CONSTRAINT `DetallesPedido_Pedido_FK` FOREIGN KEY (`IdPedidoCarrito`) REFERENCES `Pedido` (`IdPedido`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `DetallesPedido`
--

LOCK TABLES `DetallesPedido` WRITE;
/*!40000 ALTER TABLE `DetallesPedido` DISABLE KEYS */;
INSERT INTO `DetallesPedido` VALUES ('PED1','COD1',20),('PED2','COD2',30);
/*!40000 ALTER TABLE `DetallesPedido` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `DetallesSuministro`
--

DROP TABLE IF EXISTS `DetallesSuministro`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `DetallesSuministro` (
  `IdProveedorSuministro` varchar(100) NOT NULL,
  `CodigoArticuloSuministro` varchar(100) NOT NULL,
  `Stock` int(11) NOT NULL,
  `PrecioUnitario` float NOT NULL,
  PRIMARY KEY (`IdProveedorSuministro`,`CodigoArticuloSuministro`),
  KEY `DetallesSuministro_Articulo_FK` (`CodigoArticuloSuministro`),
  CONSTRAINT `DetallesSuministro_Articulo_FK` FOREIGN KEY (`CodigoArticuloSuministro`) REFERENCES `Articulo` (`CodigoArticulo`),
  CONSTRAINT `DetallesSuministro_Proveedor_FK` FOREIGN KEY (`IdProveedorSuministro`) REFERENCES `Proveedor` (`IdProveedor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `DetallesSuministro`
--

LOCK TABLES `DetallesSuministro` WRITE;
/*!40000 ALTER TABLE `DetallesSuministro` DISABLE KEYS */;
INSERT INTO `DetallesSuministro` VALUES ('PROV1','COD1',40,12334500),('PROV1','COD2',40,12334500),('PROV1','COD3',40,12334500);
/*!40000 ALTER TABLE `DetallesSuministro` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Pedido`
--

DROP TABLE IF EXISTS `Pedido`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Pedido` (
  `IdPedido` varchar(100) NOT NULL,
  `DireccionPedido` varchar(100) NOT NULL,
  `FechaPedido` date NOT NULL,
  `EstadoPedido` varchar(100) NOT NULL,
  `IdClienteP` int(11) DEFAULT NULL,
  PRIMARY KEY (`IdPedido`),
  KEY `Pedido_Cliente_FK` (`IdClienteP`),
  CONSTRAINT `Pedido_Cliente_FK` FOREIGN KEY (`IdClienteP`) REFERENCES `Cliente` (`IdCliente`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Pedido`
--

LOCK TABLES `Pedido` WRITE;
/*!40000 ALTER TABLE `Pedido` DISABLE KEYS */;
INSERT INTO `Pedido` VALUES ('PED1','Calle 6','2024-02-26','Entregado',1),('PED2','Calle 6','2024-02-26','Entregado',2);
/*!40000 ALTER TABLE `Pedido` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Proveedor`
--

DROP TABLE IF EXISTS `Proveedor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Proveedor` (
  `IdProveedor` varchar(100) NOT NULL,
  `NombreProveedor` varchar(100) NOT NULL,
  `Telefono` int(11) NOT NULL,
  PRIMARY KEY (`IdProveedor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Proveedor`
--

LOCK TABLES `Proveedor` WRITE;
/*!40000 ALTER TABLE `Proveedor` DISABLE KEYS */;
INSERT INTO `Proveedor` VALUES ('PROV1','Camionero1',123456),('PROV2','Camionero2',123456),('PROV3','Camionero3',123456);
/*!40000 ALTER TABLE `Proveedor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'gestion_pedidos'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-02-26 19:08:26
