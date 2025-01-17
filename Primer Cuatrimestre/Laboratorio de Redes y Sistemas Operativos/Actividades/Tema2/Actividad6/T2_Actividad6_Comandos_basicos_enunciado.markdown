### Tema 2 - Actividad 6 

1. Crear en tu espacio de trabajo un directorio (dir1),  dentro de éste, crea otro directorio (dir2) y dentro de este último crea otro directorio (dir3), hazlo  utilzando un solo comnado. 
```bash
mkdir -p dir1/dir2/dir3

```
2. Cambia a dir2. Copia en dicho directorio todos los ficheros que empiecen por s y que se encuentren en el directorio /etc/ asegurando que no sale ningun error en la pantalla, los debes redirigir a un fichero que se llama errores.log.  Asegurate de que es así usando algún comando para ver el contenido de errores.log
```bash
cd dir1/dir2
cp /etc/s* ./ 2>errores.log
cat errores.log

```
3. Crea en dir2 un fichero .tgz con todos los ficheros que hay en dicho directorio (dir2). 
```bash
tar cvzf fichero.tgz s* e*

```

4. Ejecuta el comando tar con las opciones necesarias para mostrar los ficheros comprimidos en dicho fichero .tgz
```bash
tar tvzf fichero.tgz

```

5. Copia el fichero .tgz en dir3
```bash
cp ./fichero.tgz ./dir3/

```

6. Extrae en dir3 el contenido del fichero .tgz que has creado en el punto 3.
```bash
cd dir3
tar xvzf fichero.tgz

```

7. En dir3 comprime cada uno de los ficheros con gzip manteniendo los ficheros originales
```bash
gzip -k s* e*

```

8. Ejecuta el comando "ls -l z* s*" en dir3 y envía la salida al fichero listado.dat y los errores al mismo fichero al que has enviado la salida del comando.
```bash
ls -l z* s* &>listado.dat

```

9. Muestra la fecha actual en el siguioente formato, Año: 2023, Mes: 10, Día: 25
```bash
date +"Año: %Y, Mes: %m, Día: %d"

```
10. Muestra el mes de enero del año 2020
```bash
cal -m 1 2020

```
