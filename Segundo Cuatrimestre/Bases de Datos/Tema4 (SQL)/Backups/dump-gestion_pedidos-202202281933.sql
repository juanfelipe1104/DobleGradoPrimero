-- MariaDB dump 10.17  Distrib 10.4.11-MariaDB, for Win64 (AMD64)
--
-- Host: localhost    Database: gestion_pedidos
-- ------------------------------------------------------
-- Server version	10.4.11-MariaDB

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
-- Table structure for table `almacen`
--

DROP TABLE IF EXISTS `almacen`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `almacen` (
  `id_proveedor_almacen` varchar(100) NOT NULL,
  `id_articulo_almacen` varchar(100) NOT NULL,
  `stock_articulo_almacen` int(11) DEFAULT NULL,
  `precio_unitario` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_proveedor_almacen`,`id_articulo_almacen`),
  KEY `almacen_FK_1` (`id_articulo_almacen`),
  CONSTRAINT `almacen_FK` FOREIGN KEY (`id_proveedor_almacen`) REFERENCES `proveedor` (`id_proveedor`),
  CONSTRAINT `almacen_FK_1` FOREIGN KEY (`id_articulo_almacen`) REFERENCES `articulo` (`id_articulo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `almacen`
--

LOCK TABLES `almacen` WRITE;
/*!40000 ALTER TABLE `almacen` DISABLE KEYS */;
INSERT INTO `almacen` VALUES ('PROV1','AA01',50,10),('PROV1','AA02',100,15),('PROV2','AA01',200,12),('PROV2','AA03',150,25),('PROV2','AA04',25,12),('PROV3','AA01',50,8),('PROV3','AA03',75,28),('PROV4','AA05',300,5),('PROV4','AA06',200,2);
/*!40000 ALTER TABLE `almacen` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `articulo`
--

DROP TABLE IF EXISTS `articulo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `articulo` (
  `id_articulo` varchar(100) NOT NULL,
  `descripcion_articulo` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_articulo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `articulo`
--

LOCK TABLES `articulo` WRITE;
/*!40000 ALTER TABLE `articulo` DISABLE KEYS */;
INSERT INTO `articulo` VALUES ('AA01','Gel de baño'),('AA02','Colonia'),('AA03','Cereales'),('AA04','Mantequilla'),('AA05','Coca-cola'),('AA06','Patatas fritas'),('AA07','Desodorante'),('AA08','Champu');
/*!40000 ALTER TABLE `articulo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cliente`
--

DROP TABLE IF EXISTS `cliente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cliente` (
  `id_cliente` int(11) NOT NULL AUTO_INCREMENT,
  `direccion_cl` varchar(100) DEFAULT NULL,
  `saldo_cl` int(11) DEFAULT NULL,
  `credito_cl` int(11) DEFAULT NULL,
  `descuento_cl` int(11) DEFAULT NULL,
  `nombre_cl` varchar(100) DEFAULT NULL,
  `ciudad_cl` varchar(100) DEFAULT NULL,
  `pais_cl` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_cliente`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cliente`
--

LOCK TABLES `cliente` WRITE;
/*!40000 ALTER TABLE `cliente` DISABLE KEYS */;
INSERT INTO `cliente` VALUES (1,'Antonio Machado,1',300,800,10,'Tony','Madrid','España'),(2,'Picasso,7',500,1000,7,'Pepe','Valencia','España'),(5,'Real,3',400,500,5,'Jero','Soria','España'),(6,'Eliseos, 1',300,750,5,'Philip','Paris','Francia'),(7,'Picadilly Circus, 1',300,400,6,'Jhon','Londres','Inglaterra'),(8,'Saint Jean, 3',200,100,3,'JJ','Paris','Francia'),(9,'Paloma, 6',100,300,10,'Luis','Madrid','España'),(10,'Toledo, 1',200,500,25,'Lola','Madrid','España'),(11,'Gaudi, 1',50,100,3,'Carlos','Soria','España');
/*!40000 ALTER TABLE `cliente` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `detalles_pedido`
--

DROP TABLE IF EXISTS `detalles_pedido`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `detalles_pedido` (
  `id_pedido_detalles` varchar(100) NOT NULL,
  `id_articulo_detalles` varchar(100) NOT NULL,
  `cantidad_articulo_pedido` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_pedido_detalles`,`id_articulo_detalles`),
  KEY `detalles_pedido_FK_1` (`id_articulo_detalles`),
  CONSTRAINT `detalles_pedido_FK` FOREIGN KEY (`id_pedido_detalles`) REFERENCES `pedido` (`id_pedido`),
  CONSTRAINT `detalles_pedido_FK_1` FOREIGN KEY (`id_articulo_detalles`) REFERENCES `articulo` (`id_articulo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `detalles_pedido`
--

LOCK TABLES `detalles_pedido` WRITE;
/*!40000 ALTER TABLE `detalles_pedido` DISABLE KEYS */;
INSERT INTO `detalles_pedido` VALUES ('PED1','AA01',4),('PED1','AA02',2),('PED2','AA03',6),('PED2','AA04',10),('PED3','AA04',20),('PED4','AA05',5),('PED4','AA07',5);
/*!40000 ALTER TABLE `detalles_pedido` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pedido`
--

DROP TABLE IF EXISTS `pedido`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pedido` (
  `id_pedido` varchar(100) NOT NULL,
  `id_cliente_ped` int(11) DEFAULT NULL,
  `fecha_pedido` date DEFAULT NULL,
  `descripcion_pedido` varchar(100) DEFAULT NULL,
  `direccion_envio` varchar(100) DEFAULT NULL,
  `estado_pedido` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_pedido`),
  KEY `Pedido_FK` (`id_cliente_ped`),
  CONSTRAINT `Pedido_FK` FOREIGN KEY (`id_cliente_ped`) REFERENCES `cliente` (`id_cliente`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pedido`
--

LOCK TABLES `pedido` WRITE;
/*!40000 ALTER TABLE `pedido` DISABLE KEYS */;
INSERT INTO `pedido` VALUES ('PED1',1,'2020-02-15','Drogeria','Antonio Machado,1','solicitado'),('PED2',2,'2020-02-02','Alimentacion','Real,3 ','en curso'),('PED3',5,'2020-01-10','Compra completa','Gran Via, 10','entregado'),('PED4',1,'2020-01-10','Solo bebida','Antonio Machado,1 ','entregado');
/*!40000 ALTER TABLE `pedido` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proveedor`
--

DROP TABLE IF EXISTS `proveedor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `proveedor` (
  `id_proveedor` varchar(100) NOT NULL,
  `nombre_proveedor` varchar(100) DEFAULT NULL,
  `tlf_proveedor` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_proveedor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `proveedor`
--

LOCK TABLES `proveedor` WRITE;
/*!40000 ALTER TABLE `proveedor` DISABLE KEYS */;
INSERT INTO `proveedor` VALUES ('PROV1','ALFA','915555555'),('PROV2','BETA','939999999'),('PROV3','GAMMA','957777777'),('PROV4','OMEGA','953333333'),('PROV5','DLETA','976666666'),('PROV6','EPSILON','976666666');
/*!40000 ALTER TABLE `proveedor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary table structure for view `vista_pedidos`
--

DROP TABLE IF EXISTS `vista_pedidos`;
/*!50001 DROP VIEW IF EXISTS `vista_pedidos`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE TABLE `vista_pedidos` (
  `id_pedido` tinyint NOT NULL,
  `id_cliente_ped` tinyint NOT NULL,
  `fecha_pedido` tinyint NOT NULL,
  `descripcion_pedido` tinyint NOT NULL,
  `direccion_envio` tinyint NOT NULL,
  `estado_pedido` tinyint NOT NULL
) ENGINE=MyISAM */;
SET character_set_client = @saved_cs_client;

--
-- Dumping routines for database 'gestion_pedidos'
--

--
-- Final view structure for view `vista_pedidos`
--

/*!50001 DROP TABLE IF EXISTS `vista_pedidos`*/;
/*!50001 DROP VIEW IF EXISTS `vista_pedidos`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = cp850 */;
/*!50001 SET character_set_results     = cp850 */;
/*!50001 SET collation_connection      = cp850_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `vista_pedidos` AS select `pedido`.`id_pedido` AS `id_pedido`,`pedido`.`id_cliente_ped` AS `id_cliente_ped`,`pedido`.`fecha_pedido` AS `fecha_pedido`,`pedido`.`descripcion_pedido` AS `descripcion_pedido`,`pedido`.`direccion_envio` AS `direccion_envio`,`pedido`.`estado_pedido` AS `estado_pedido` from `pedido` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-02-28 19:33:57
