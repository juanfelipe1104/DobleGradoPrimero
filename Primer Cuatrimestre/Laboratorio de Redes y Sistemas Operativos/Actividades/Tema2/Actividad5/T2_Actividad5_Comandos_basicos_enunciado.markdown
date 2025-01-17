# Tema 2 - Actividad 5: Comandos básicos - Repaso-

1.	Listar todos los archivos del directorio etc que no empiecen por t.

```bash
ls -l /etc/[!t]*
```

2.	Listar todos los archivos del directorio dev que empiecen por tty y acaben en 1,2,3 ó 4.
```bash
ls -l /dev/tty*[1234]
```

3.	Estando en el directorio home del usuario, encontrar un directorio llamado GRADO.
```bash
find . -type d -name GRADO
```

4.	Dado el fichero .profile que se encuentra en el home del usuario, copiar utilizando rutas relativas al directorio /tmp/resultado ( este directorio ya estará creado)
```bash
cp ./.profile ../../tmp/resultado
```

5.	Sobre el fichero /proc/cpuinfo  presentar qué dos informaciones acerca de la cpu son las primeras que aparece en el fichero indicado
```bash
head -n 2 /proc/cpuinfo 
```

6.	Dado el fichero /proc/cpuinfo donde se encuentra información del sistema. Presentar todas las líneas de este fichero donde se presenta información de la cache.
```bash
cat /proc/cpuinfo | grep cache
```

7.	Dado el fichero anterior, (cpuinfo) presentar solamente el número de las líneas donde aparece información acerca de la cpu.
```bash
cat /proc/cpuinfo | grep cpu | wc -l
```


8.	Dados dos ficheros, file1 y file2 añadir al contenido de un fichero llamado resultado.txt que ya existe, el contenido de file2 y después el contenido de file1
```bash
a) file2 >> resultado.txt
b) file1 >> resultado.txt
```


9.	Dado el fichero datos.txt como realizaría una copia del mismo sin utilizar el comando cp. El fichero de destino se llamará salida.dat
```bash
datos.txt > salida.dat
```

10.	Copiar un fichero existente (resultado.txt) que se encuentra en el home de tu usuario al directorio  /tmp/resultado/. Si no existe el directorio indicado lo debes crear.
```bash
cp ./resultado.txt /tmp/resultado
```

11.	Crear un fichero con dos líneas de datos:
Esta es la primera línea de datos del fichero
Esta es la segunda línea de datos del fichero
El fichero se llamará datos.dat y se tendrá que crear en el directorio /tmp
```bash
echo "Esta es la primera linea de datos del fichero" > /tmp/datos.dat
echo "Esta es la segunda linea de datos del fichero" >> /tmp/datos.dat
```

12.	Datos el fichero /etc/passwd presentar por pantalla el tercer campo del fichero, pero solamente de las primeras 5 líneas.
```bash
head -n 5 /etc/passwd | cut -d ":" -f 3
```

13.	Dado el fichero datos.txt que se encuentra en el directorio home del usuario, modificar la fecha de último acceso del mismo
```bash
touch -c datos.txt
```

14.	Copiar en el directorio /tmp/resultado (ya existente) los archivos de /bin que tengan una a como segunda letra y su nombre tenga cuatro letras.
```bash
cp /bin/?a?? /tmp/resultado
```

15.	Copiar al directorio /tmp/resultado los ficheros del directorio home  que  tengan 5 caracteres exactamente en su nombre y que comiencen por “fil” y terminen por un número de 1 a 10.
```bash
cp ./fil*?[[:digit:]].??? /tmp/resultado
```

16.	Crear un enlace simbólico al directorio /tmp/dir1 dentro del directorio home del usuario llamado enlacedir1. Estamos en el directorio home del usuario
```bash
ln -s /tmp/dir1 ./enlacedir1
```

17.	Estando en el directorio /tmp, posicionarnos en el directorio home del usuario utilizando un variable de entorno.
```bash
cd $HOME
```

18.	Visualizar la lista de todos los ficheros que pertenezcan a root.
```bash
ls -lR / | grep root
```

19.	Añadir al fichero resultado la lista de todos los ficheros ordinarios que cuelguen de /etc.
```bash
find /etc -type f >> resultado
```

20.	Mostrar los grupos registrados en el sistema y contar cuantos son. 

```bash
a) cat /etc/group
b) cat /etc/group | wc -l
```