-- MariaDB dump 10.19  Distrib 10.6.11-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: biblioteca
-- ------------------------------------------------------
-- Server version	10.6.11-MariaDB-0ubuntu0.22.10.1

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
-- Table structure for table `alumno`
--

DROP TABLE IF EXISTS `alumno`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `alumno` (
  `num_matricula` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(100) DEFAULT NULL,
  `curso` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`num_matricula`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `alumno`
--

LOCK TABLES `alumno` WRITE;
/*!40000 ALTER TABLE `alumno` DISABLE KEYS */;
INSERT INTO `alumno` VALUES (1,'LUIS','PRIMERO'),(2,'LEO','SEGUNDO'),(3,'CLARA','PRIMERO'),(4,'TEO','TERCERO'),(5,'RAUL','TERCERO'),(6,'NURIA','CUARTO'),(7,'RAUL','CUARTO');
/*!40000 ALTER TABLE `alumno` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `autor`
--

DROP TABLE IF EXISTS `autor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `autor` (
  `cod_autor` int(11) NOT NULL AUTO_INCREMENT,
  `nombre_autor` varchar(100) DEFAULT NULL,
  `ciudad` varchar(100) DEFAULT NULL,
  `pais` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`cod_autor`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `autor`
--

LOCK TABLES `autor` WRITE;
/*!40000 ALTER TABLE `autor` DISABLE KEYS */;
INSERT INTO `autor` VALUES (1,'Del Valle','Sevilla','España'),(2,'Luca','Madrid','España'),(3,'Carbonero','Sevilla','España'),(4,'Belanger','Paris','Francia'),(5,'Smith','Londres','Inglaterra'),(6,'Baudin','Paris','Francia'),(7,'Cortes','Madrid','España');
/*!40000 ALTER TABLE `autor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ejemplar`
--

DROP TABLE IF EXISTS `ejemplar`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ejemplar` (
  `cod_ejemplar` varchar(100) NOT NULL,
  `cod_libro_ej` varchar(100) DEFAULT NULL,
  `fecha_compra` date DEFAULT NULL,
  `fecha_edicion` date DEFAULT NULL,
  `cod_estanteria_ej` int(11) DEFAULT NULL,
  PRIMARY KEY (`cod_ejemplar`),
  KEY `ejemplar_FK` (`cod_libro_ej`),
  KEY `ejemplar_fk2` (`cod_estanteria_ej`),
  CONSTRAINT `ejemplar_FK` FOREIGN KEY (`cod_libro_ej`) REFERENCES `libro` (`cod_libro`),
  CONSTRAINT `ejemplar_fk2` FOREIGN KEY (`cod_estanteria_ej`) REFERENCES `estanteria` (`cod_estanteria`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ejemplar`
--

LOCK TABLES `ejemplar` WRITE;
/*!40000 ALTER TABLE `ejemplar` DISABLE KEYS */;
INSERT INTO `ejemplar` VALUES ('A','L-001','2019-03-12','2015-01-04',NULL),('B','L-001','2019-01-08','2012-01-01',NULL),('C','L-001','2018-04-12','2015-07-15',NULL),('D','L-002','2018-03-10','2013-02-12',NULL),('E','L-002','2017-04-05','2015-01-20',NULL),('F','L-003','2016-04-12','2015-09-14',NULL),('G','L-004','2018-05-24','2015-10-23',NULL),('H','L-005','2019-05-18','2010-06-05',NULL),('I','L-005','2017-02-02','2015-06-15',NULL),('J','L-005','2017-03-02','2015-02-15',NULL),('K','L-005','2017-04-02','2015-09-15',NULL);
/*!40000 ALTER TABLE `ejemplar` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `estanteria`
--

DROP TABLE IF EXISTS `estanteria`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `estanteria` (
  `cod_estanteria` int(11) NOT NULL AUTO_INCREMENT,
  `planta` int(11) DEFAULT NULL,
  `sala` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`cod_estanteria`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `estanteria`
--

LOCK TABLES `estanteria` WRITE;
/*!40000 ALTER TABLE `estanteria` DISABLE KEYS */;
INSERT INTO `estanteria` VALUES (1,1,'Sala10'),(2,1,'Sala10'),(3,1,'Sala12'),(4,2,'Sala15'),(5,2,'Sala15'),(6,3,'Sala20'),(7,3,'Sala21'),(8,4,'Sala30'),(9,4,'Sala30'),(10,4,'Sala30'),(11,NULL,NULL);
/*!40000 ALTER TABLE `estanteria` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `libro`
--

DROP TABLE IF EXISTS `libro`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `libro` (
  `cod_libro` varchar(100) NOT NULL,
  `cod_autor_lib` int(11) DEFAULT NULL,
  `titulo` varchar(100) DEFAULT NULL,
  `editorial` varchar(100) DEFAULT NULL,
  `area_tematica` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`cod_libro`),
  KEY `libro_FK` (`cod_autor_lib`),
  CONSTRAINT `libro_FK` FOREIGN KEY (`cod_autor_lib`) REFERENCES `autor` (`cod_autor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `libro`
--

LOCK TABLES `libro` WRITE;
/*!40000 ALTER TABLE `libro` DISABLE KEYS */;
INSERT INTO `libro` VALUES ('L-001',1,'La casa embrujada','Anaya','Suspense'),('L-002',2,'Naturaleza muerta','SM','Ciencias'),('L-003',2,'Los bits de colores','Anaya','Ingenieria'),('L-004',4,'Le petit maison','Anaya','Ciencias'),('L-005',6,'El ordenador verde','SM','Ingenieria'),('L-006',3,'Los numeros ','Santiillana','Matematicas'),('L-007',5,'Las letras incomprendidas','Santiillana','Lengua');
/*!40000 ALTER TABLE `libro` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `prestamo`
--

DROP TABLE IF EXISTS `prestamo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `prestamo` (
  `fecha_prestamo` date NOT NULL,
  `fecha_devolucion` date DEFAULT NULL,
  `cod_ejemplar_prestamo` varchar(100) NOT NULL,
  `num_matricula_prestamo` int(11) NOT NULL,
  PRIMARY KEY (`num_matricula_prestamo`,`cod_ejemplar_prestamo`,`fecha_prestamo`),
  KEY `prestamo_FK` (`cod_ejemplar_prestamo`),
  CONSTRAINT `prestamo_FK` FOREIGN KEY (`cod_ejemplar_prestamo`) REFERENCES `ejemplar` (`cod_ejemplar`),
  CONSTRAINT `prestamo_FK_1` FOREIGN KEY (`num_matricula_prestamo`) REFERENCES `alumno` (`num_matricula`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `prestamo`
--

LOCK TABLES `prestamo` WRITE;
/*!40000 ALTER TABLE `prestamo` DISABLE KEYS */;
INSERT INTO `prestamo` VALUES ('2019-03-24','2020-01-12','A',1),('2019-03-24','2020-01-12','C',1),('2019-12-12','2020-03-05','B',2),('2020-02-23','2020-03-09','C',3),('2019-08-09','2020-03-10','D',4),('2020-01-05',NULL,'E',5),('2020-02-15',NULL,'F',5),('2020-03-15',NULL,'G',6),('2020-02-22',NULL,'H',7);
/*!40000 ALTER TABLE `prestamo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'biblioteca'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-02-21  0:40:04
