# Guia SQL

¿Como acceder a MariaDB desde la terminal?

```bash
#Primero hay que conectarse a root
su -
#Despues se accede a MariaDB
mysql -u root -p
```

¿Como crear una base de datos?

```bash
#Primero se crea la base de datos
CREATE DATABASE nombre;
#Despues se le dan privilegios al usuario
GRANT ALL PRIVILEGES ON baseDeDatos.* TO 'usuario'@localhost;
#Se recargan los privilegios para efectuar los cambios
FLUSH PRIVILEGES;
```

Comandos SQL sobre bases de datos:

```bash
#Ver bases de datos en el sistema
SHOW DATABASES;
#Utilizar una base de datos
USE baseDeDatos;
#Mostrar las tablas que hay en la base de datos
SHOW TABLES;
#Mostrar lo que contiene cada tabla
DESC nombreTabla;
```