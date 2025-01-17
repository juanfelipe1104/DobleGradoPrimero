# Tema 3 - Actividad 1: Usuarios y Grupos. Soluciones

Crea un directorio de prueba para practicar el Tema 3. 
Crea también los ficheros y directorios que se indican. 
 
```
mkdir actividades_tema3
cd actividades_tema3
echo "Ejercicios del Tema 3" > tema3.txt
echo "Ejercicios de permisos" > permisos.txt
echo "Ejercicios de Usuarios" > usuarios.txt
echo "Ejercicios de Grupos" > grupos.ttx
mkdir dir_permisos
echo "prueba permisos" > dir_permisos/prueba.txt
```
 
## Ejercicio 1
Observa los permisos de cada fichero y ejecuta los siguientes cambios: 

- a) Da permisos de ejecución para el owner (user), el grupo (group) y para el resto de usuarios (others) al fichero permisos.txt 
- b) Elimina (revoca o quita) el permiso de lectura para "others" del fichero grupos.txt
- c) Dale permisos de escritura a todos los ficheros para todos (usuario, grupo y others)
- d) Otorga los permisos "400" al directorio "dir_permisos". Observa si puedes acceder a dicho direcorio y si puedes listar su contenido. Prueba también a hacer un cat del fichero prueba.txt.  ¿que observas?
- e) Otorga ahora los permisos "100" a dicho directorio. Repite lo del apartado anterior y observa lo que sucede.

```bash
a) chmod ugo+x permisos.txt
b) chmod o-r grupos.txt
c.1) chmod a+w *.txt
c.2) chmod a+w dir_permisos/*.txt
d.1) chmod 400 dir_permisos/
d.2) cd dir_permisos/ #No funciona
d.3) ls dir_permisos/ #Muestra el archivo
d.4) cat dir_permisos/prueba.txt #No funciona
e.1) chmod 100 dir_permisos/
e.2) cd dir_permisos/ #Funciona
e.3) ls #No funciona
e.4) cat prueba.txt #Funciona 
```

## Ejercicio 2.	 
 
Crea un grupo llamado "developers" y comprueba que dicho grupo se ha almacenado en el fichero correspondiente. 

```bash
a) sudo groupadd developers
b) cat /etc/group | grep developers
```
 
 
## Ejercicio 3.	 
Cambia el grupo propietario del fichero "tema3.txt" y manten su usuario actual. 
  
```bash
sudo chown :developers ./tema3.txt
``` 

## Ejercicio 4.  
 
- a) Crea un usuario en el sistema que se llame "lola". No utilices ninguna opción. Comprueba que se ha creado correctamente. 
- b) Crea un usuario en el sistema que se llame "nemo". Utiliza la opción correspondiente para que su directorio de trabajo sea /home/nemo_pez/. Comprueba que se ha creado correctamente. 
- c) Crea un uuario que se llame "lolo" y evita que se cree su directorio home. Demuestra que lo has hecho correctamente.
- d) Observa que cambios se han producido en el fichero de grupos.  

```bash
a.1) sudo adduser lola
a.2) cat /etc/passwd | grep lola 
b.1) sudo adduser nemo --home /home/nemo_pez/
b.2) cat /etc/passwd | grep nemo
c.1) sudo adduser lolo --no-create-home
c.2) cat /etc/passwd | grep lolo
d) cat /etc/group #Se han añadido los grupos "lola", "nemo", "lolo"
``` 


## Ejercicio 5.  
Cambia el usuario (owner) del fichero "tema3.txt" al usuario "lola" y manten su grupo actual. 

```bash
sudo chown lola ./tema3.txt
```

## Ejercicio 6  

Cambia la contraseña del usuario "lolo"

 ```bash
sudo passwd lolo
```


## Ejercicio 7  

Elimina el usuario nemo y elimina además su directorio de trabajo 

```bash
sudo userdel -r nemo
```



## Ejercicio 8  
Crea dos nuevos grupos en el sistema: "testers" "secgroup"

```bash
a) sudo groupadd testers
b) sudo groupadd secgroup
```


## Ejercicio 9 
- a) Añade el usuario "lola" a los grupos creados en el apartado anterior.

```bash
a) sudo adduser lola testers
b) sudo adduser lola secgroup
```

- b) Intenta borrar el grupo testers y observa si puedes

```bash
sudo groupdel testers #Sí se puede
```


## Ejercicio 10

Añade el usuario "lola" al grupo "sudoers"
```bash
sudo usermod -aG sudo lola
```




