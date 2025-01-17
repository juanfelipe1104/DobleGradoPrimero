# Tema 2 - Actividad 4: Comandos básicos


## Ejercicio 1.	(grep)
El comando `netstat` nos permite listar todas las conexiones TCP y UDP en un sistema Linux. 
Para listar todas las conexiones TCP y UDP en todos los estados posibles podemos utiliar `netstat -tun`. Si además se desea conocer el proceso con el que está establecida cada conexión, se agrega la opción -p.  
Teniendo en cuenta eso muestra usando dicho comando y la herramienta `grep` **solo aquellas conexiones que estan en estado ESTABLISH**.  

Antes de hacerlo abre un navegador en tu maquina y conectate a un par de páginas web. 

```bash
 netstat -tun | grep "ESTABLECIDO"

```

## Ejercicio 2.	(wc)

Usando el comando anterior muestra ahora por pantalla **sólo el número** de conexiones en estado ESTABLISH (ESTABLCIDO).   

```bash
 netstat -tun | grep "ESTABLECIDO" | wc -l

```

## Ejercicio 3. (tr + cut)
Uitiliza de nuevo los comandos `netstat` y `grep` para obtener las conexsiones en estado "establecidas". 

Elimina los espacios en blanco repetidos y luego haz los cambios necesarios para obtener solo la IP remota (Foreign Address)con el puerto. 

```bash
 netstat -tun | grep "ESTABLECIDO" | tr -s [:space:] | cut -d " " -f 5
 netstat -tun | grep "ESTABLECIDO" | tr -s [:space:] | cut -d " " -f 5 | cut -d ":" -f 1
 
```

## Ejercicio 4. (awk)
Utilizando el comando awk obten del fichero de usuarios (/etc/passwd) el nombre de cada usuario y su UID separados por un espacio en blanco.  El nombre de usuario debe ir precedido de "user:" y el UID de la cadena "UID:"

```bash
 awk -F ":" '{print "user: " $1 " " "UID: " $3}' /etc/passwd

```

## Ejercicio 5 (sed)
Utilizando la salida del comando anterior, sustituye la cadena user por "login de usuario"

 ```bash
 awk -F ":" '{print "user: " $1 " " "UID: " $3}' /etc/passwd | sed s/user/login\ de\ usuario/

```



