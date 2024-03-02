-- MariaDB dump 10.19  Distrib 10.6.16-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: yiutube
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
-- Table structure for table `Comentario`
--

DROP TABLE IF EXISTS `Comentario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Comentario` (
  `IdComentario` varchar(100) NOT NULL,
  `TextoComentario` varchar(100) NOT NULL,
  `IdUsuarioCom` varchar(100) NOT NULL,
  `IdContenidoCom` varchar(100) NOT NULL,
  PRIMARY KEY (`IdComentario`),
  KEY `Comentario_Usuario_FK` (`IdUsuarioCom`),
  KEY `Comentario_Contenido_FK` (`IdContenidoCom`),
  CONSTRAINT `Comentario_Contenido_FK` FOREIGN KEY (`IdContenidoCom`) REFERENCES `Contenido` (`IdContenido`),
  CONSTRAINT `Comentario_Usuario_FK` FOREIGN KEY (`IdUsuarioCom`) REFERENCES `Usuario` (`IdUsuario`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Comentario`
--

LOCK TABLES `Comentario` WRITE;
/*!40000 ALTER TABLE `Comentario` DISABLE KEYS */;
/*!40000 ALTER TABLE `Comentario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Contenido`
--

DROP TABLE IF EXISTS `Contenido`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Contenido` (
  `IdContenido` varchar(100) NOT NULL,
  `Nombre` varchar(100) NOT NULL,
  `FicheroDisco` varchar(100) NOT NULL,
  `FechaSubida` date NOT NULL,
  `NumeroVisualisaciones` int(11) NOT NULL,
  `IdUsuarioCon` varchar(100) NOT NULL,
  PRIMARY KEY (`IdContenido`),
  KEY `Contenido_Usuario_FK` (`IdUsuarioCon`),
  CONSTRAINT `Contenido_Usuario_FK` FOREIGN KEY (`IdUsuarioCon`) REFERENCES `Usuario` (`IdUsuario`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Contenido`
--

LOCK TABLES `Contenido` WRITE;
/*!40000 ALTER TABLE `Contenido` DISABLE KEYS */;
/*!40000 ALTER TABLE `Contenido` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Usuario`
--

DROP TABLE IF EXISTS `Usuario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Usuario` (
  `IdUsuario` varchar(100) NOT NULL,
  `Nombre` varchar(100) NOT NULL,
  `Contrasena` varchar(100) NOT NULL,
  `E-mail` varchar(100) NOT NULL,
  `LugarResidencia` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`IdUsuario`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Usuario`
--

LOCK TABLES `Usuario` WRITE;
/*!40000 ALTER TABLE `Usuario` DISABLE KEYS */;
/*!40000 ALTER TABLE `Usuario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `VotosComentario`
--

DROP TABLE IF EXISTS `VotosComentario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `VotosComentario` (
  `IdUsuarioVCom` varchar(100) NOT NULL,
  `IdComentarioV` varchar(100) NOT NULL,
  `Votacion` tinyint(1) NOT NULL,
  `Fecha` date NOT NULL,
  PRIMARY KEY (`IdUsuarioVCom`,`IdComentarioV`),
  KEY `VotosComentario_Comentario_FK` (`IdComentarioV`),
  CONSTRAINT `VotosComentario_Comentario_FK` FOREIGN KEY (`IdComentarioV`) REFERENCES `Comentario` (`IdComentario`),
  CONSTRAINT `VotosComentario_Usuario_FK` FOREIGN KEY (`IdUsuarioVCom`) REFERENCES `Usuario` (`IdUsuario`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `VotosComentario`
--

LOCK TABLES `VotosComentario` WRITE;
/*!40000 ALTER TABLE `VotosComentario` DISABLE KEYS */;
/*!40000 ALTER TABLE `VotosComentario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `VotosContenido`
--

DROP TABLE IF EXISTS `VotosContenido`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `VotosContenido` (
  `IdUsuarioVCon` varchar(100) NOT NULL,
  `IdContenidoV` varchar(100) NOT NULL,
  `Votacion` tinyint(1) NOT NULL,
  `Fecha` date NOT NULL,
  PRIMARY KEY (`IdUsuarioVCon`,`IdContenidoV`),
  KEY `VotosContenido_Contenido_FK` (`IdContenidoV`),
  CONSTRAINT `VotosContenido_Contenido_FK` FOREIGN KEY (`IdContenidoV`) REFERENCES `Contenido` (`IdContenido`),
  CONSTRAINT `VotosContenido_Usuario_FK` FOREIGN KEY (`IdUsuarioVCon`) REFERENCES `Usuario` (`IdUsuario`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `VotosContenido`
--

LOCK TABLES `VotosContenido` WRITE;
/*!40000 ALTER TABLE `VotosContenido` DISABLE KEYS */;
/*!40000 ALTER TABLE `VotosContenido` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'yiutube'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-02-26 20:43:26
