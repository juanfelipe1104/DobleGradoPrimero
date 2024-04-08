-- MySQL dump 10.19  Distrib 10.3.34-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: utad
-- ------------------------------------------------------
-- Server version	10.3.34-MariaDB-0ubuntu0.20.04.1

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
-- Table structure for table `alumnos`
--

DROP TABLE IF EXISTS `alumnos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `alumnos` (
  `num_matricula` int(11) NOT NULL,
  `dni_alumno` varchar(100) DEFAULT NULL,
  `nombre_alumno` varchar(100) DEFAULT NULL,
  `mail_alumno` varchar(100) DEFAULT NULL,
  `fecha_ingreso_alumno` date DEFAULT NULL,
  PRIMARY KEY (`num_matricula`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `alumnos`
--

LOCK TABLES `alumnos` WRITE;
/*!40000 ALTER TABLE `alumnos` DISABLE KEYS */;
INSERT INTO `alumnos` VALUES (101,'65333888W','Belen Gonzalez','belen@utad.com','2019-09-16'),(102,'33224455H','Clara Lopez','clara@utad.com','2018-09-16'),(103,'23321244R','Dario Martin','dario@utad.com','2017-09-16'),(104,'55555555R','Miguel Varela','miguel@utad.com','2020-09-16'),(105,'23321244R','Pablo Ferandez','pablo@utad.com','2020-09-16'),(106,'37888888R','Jaime Garcia','jaime@utad.com','2017-09-16'),(107,'23321244R','Ana Calvo','ana@utad.com','2017-09-16'),(108,'11222333R','Laura Ordoñez','laura@utad.com','2017-09-16');
/*!40000 ALTER TABLE `alumnos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asignaturas`
--

DROP TABLE IF EXISTS `asignaturas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `asignaturas` (
  `id_asig` int(11) NOT NULL AUTO_INCREMENT,
  `nombre_asig` varchar(100) DEFAULT NULL,
  `creditos_asig` int(11) DEFAULT NULL,
  `temporalidad_asig` varchar(100) DEFAULT NULL,
  `tipo_asig` varchar(100) DEFAULT NULL,
  `id_curso_asig` int(11) DEFAULT NULL,
  `id_prof_asig` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_asig`),
  KEY `asignaturas_fk` (`id_curso_asig`),
  KEY `asignaturas_fk_1` (`id_prof_asig`),
  CONSTRAINT `asignaturas_fk` FOREIGN KEY (`id_curso_asig`) REFERENCES `curso` (`id_curso`),
  CONSTRAINT `asignaturas_fk_1` FOREIGN KEY (`id_prof_asig`) REFERENCES `profesores` (`id_profesor`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asignaturas`
--

LOCK TABLES `asignaturas` WRITE;
/*!40000 ALTER TABLE `asignaturas` DISABLE KEYS */;
INSERT INTO `asignaturas` VALUES (1,'Algebra',6,'Q1','obligatoria',1,1),(2,'Lab BBDD',6,'Q2','obligatoria',1,2),(3,'Programacion I',6,'Q1','obligatoria',1,2),(5,'Algoritmos',6,'Q1','obligatoria',2,4),(6,'Concurrencia',6,'Q2','optativa',2,5),(7,'DIbujo 3D',6,'A','libre',5,5),(8,'Personajes',6,'A','libre',5,5),(10,'Programacion II',6,'Q1','obligatoria',2,3),(11,'Analitica de Datos',6,'A','obligatoria',10,7);
/*!40000 ALTER TABLE `asignaturas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `curso`
--

DROP TABLE IF EXISTS `curso`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `curso` (
  `id_curso` int(11) NOT NULL AUTO_INCREMENT,
  `creditos_curso` varchar(100) DEFAULT NULL,
  `nivel_curso` int(11) DEFAULT NULL,
  `url_curso` varchar(100) DEFAULT NULL,
  `id_grado_curso` int(11) DEFAULT NULL,
  `codigo_curso` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_curso`),
  KEY `curso_fk` (`id_grado_curso`),
  CONSTRAINT `curso_fk` FOREIGN KEY (`id_grado_curso`) REFERENCES `grado` (`id_grado`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `curso`
--

LOCK TABLES `curso` WRITE;
/*!40000 ALTER TABLE `curso` DISABLE KEYS */;
INSERT INTO `curso` VALUES (1,'60',1,'http://inso_primero.utad.com',1,'INSO_1'),(2,'60',2,'http://inso_segundo.utad.com',1,'INSO_2'),(3,'60',3,'http://inso_tercero.utad.com',1,'INSO_3'),(4,'60',4,'http://inso_cuarto.utad.com',1,'INSO_4'),(5,'40',1,'http://andi_primero.utad.com',4,'ANDI_1'),(7,'40',2,'http://andi_segundo.utad.com',4,'ANDI_2'),(8,'35',1,'http://divi_primero.utad.com',5,'DIVI_1'),(9,'35',2,'http://divi_segundo.utad.com',5,'DIVI_2'),(10,'60',1,'http://bigd_primero.utad.com',6,'BIGD_1');
/*!40000 ALTER TABLE `curso` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `grado`
--

DROP TABLE IF EXISTS `grado`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `grado` (
  `id_grado` int(11) NOT NULL AUTO_INCREMENT,
  `codigo_grado` varchar(100) NOT NULL,
  `tipo_grado` varchar(100) DEFAULT NULL,
  `nombre_grado` varchar(100) DEFAULT NULL,
  `creditos_grado` varchar(100) DEFAULT NULL,
  `url_grado` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_grado`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `grado`
--

LOCK TABLES `grado` WRITE;
/*!40000 ALTER TABLE `grado` DISABLE KEYS */;
INSERT INTO `grado` VALUES (1,'INSO','D','Ingenierría del Software','240','http://inso.utad.com'),(2,'MAIS','D','Matematica Computacional e Ingeniería del Software','240','http://mais.utad.com'),(3,'DIDI','D','Diseño Digital','240','http://didi.utad.com'),(4,'ANDI','F','Animación Digital','120','http://andi.utad.com'),(5,'DIVI','M','Diseño de Videojuegos','120','http://divi.utad.com'),(6,'BIGD','M','Big Data','120','http://bigd.utad.com');
/*!40000 ALTER TABLE `grado` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `grupo`
--

DROP TABLE IF EXISTS `grupo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `grupo` (
  `id_grupo` int(11) NOT NULL AUTO_INCREMENT,
  `turno_grupo` varchar(100) DEFAULT NULL,
  `letra_grupo` varchar(100) DEFAULT NULL,
  `aula_grupo` varchar(100) DEFAULT NULL,
  `id_curso_grupo` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_grupo`),
  KEY `grupo_fk` (`id_curso_grupo`),
  CONSTRAINT `grupo_fk` FOREIGN KEY (`id_curso_grupo`) REFERENCES `curso` (`id_curso`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `grupo`
--

LOCK TABLES `grupo` WRITE;
/*!40000 ALTER TABLE `grupo` DISABLE KEYS */;
INSERT INTO `grupo` VALUES (1,'Mañana','A','MD900',1),(2,'Mañana','B','MD205',1),(3,'Tarde','C','MD900',1),(4,'Tarde','D','MD201',1),(5,'Mañana','A','MD900',2),(6,'Tarde','B','MD205',2),(7,'Mañana','B','MD205',3),(8,'Tarde','B','MD209',4),(10,'Tarde','A','MD209',10),(11,'Tarde','B','MD209',10);
/*!40000 ALTER TABLE `grupo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `matriculas`
--

DROP TABLE IF EXISTS `matriculas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `matriculas` (
  `id_matricula` int(11) NOT NULL AUTO_INCREMENT,
  `id_estudiante_mat` int(11) DEFAULT NULL,
  `id_asigntaura_mat` int(11) DEFAULT NULL,
  `fecha_matriculacion` date DEFAULT NULL,
  `nota` int(11) DEFAULT NULL,
  `turno_matricula` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_matricula`),
  UNIQUE KEY `matriculas_UN` (`id_estudiante_mat`,`id_asigntaura_mat`,`fecha_matriculacion`),
  KEY `matriculas_fk` (`id_estudiante_mat`),
  KEY `matriculas_fk_1` (`id_asigntaura_mat`),
  CONSTRAINT `matriculas_fk` FOREIGN KEY (`id_estudiante_mat`) REFERENCES `alumnos` (`num_matricula`),
  CONSTRAINT `matriculas_fk_1` FOREIGN KEY (`id_asigntaura_mat`) REFERENCES `asignaturas` (`id_asig`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `matriculas`
--

LOCK TABLES `matriculas` WRITE;
/*!40000 ALTER TABLE `matriculas` DISABLE KEYS */;
INSERT INTO `matriculas` VALUES (1,101,1,'2020-09-03',7,'Mañana'),(2,101,2,'2020-09-03',6,'Mañana'),(3,101,3,'2020-09-03',5,'Tarde'),(4,102,1,'2019-09-03',8,'Mañana'),(5,102,2,'2019-09-03',8,'Mañana'),(6,103,7,'2018-09-03',4,'Tarde'),(7,103,8,'2018-09-03',3,'Tarde'),(8,104,5,'2020-09-03',7,'Tarde'),(9,104,6,'2020-09-03',8,'Tarde'),(10,101,1,'2019-09-03',3,'Mañana');
/*!40000 ALTER TABLE `matriculas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `profesores`
--

DROP TABLE IF EXISTS `profesores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `profesores` (
  `id_profesor` int(11) NOT NULL AUTO_INCREMENT,
  `dni_profesor` varchar(100) DEFAULT NULL,
  `nombre_profesor` varchar(100) DEFAULT NULL,
  `mail_profesor` varchar(100) DEFAULT NULL,
  `ciudad_profesor` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_profesor`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `profesores`
--

LOCK TABLES `profesores` WRITE;
/*!40000 ALTER TABLE `profesores` DISABLE KEYS */;
INSERT INTO `profesores` VALUES (1,'50333222W','Raul Gonzalez','raulg@utad.com','Madrid'),(2,'50555222E','Carlos Bermudez','carlosb@utad.com','Madrid'),(3,'35222555F','Almudena Grandes','almudenag@utad.com','Bilbao'),(4,'62762722R','Beltran Hidalgo','beltranh@utad.com','Segovia'),(5,'35666777D','Begoña Ramirez','begoñar@utad.com','Segovia'),(6,'35666588Q','Gonzalo Roldan','gonzalor@utad.com','Madrid'),(7,'66666666Q','Benito Perez','benitop@utad.com','Toledo');
/*!40000 ALTER TABLE `profesores` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'utad'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-04-05 22:31:34
