/*
Registro de alumnos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_FICH "alumnos.txt"

typedef enum boolean_t{
	falso = 0, verdadero = 1
}boolean_t;

typedef struct alumno_t{
	char *nombre;
	char *apellido;
	int edad;
	boolean_t estado;
	boolean_t memoria; //Variable para comprobar si es leido de fichero o de memoria
}alumno_t;

typedef struct alumnos_t{
	alumno_t *alumnos;
	int numAlumnos;
}alumnos_t;

void cargarDatosAlumnos(alumnos_t *listaAlumnos, char *nombreFichero);
char *parsearLinea(char *linea, char *token, char *delimitador); //Token se refiere a la cadena clave que se busca en la linea
alumno_t ingresarAlumno();
void ingresarAlumnoEnLista(alumnos_t *listaAlumnos);
void imprimirAlumnos(alumnos_t listaAlumnos);
void buscarAlumnos(alumnos_t listaAlumnos);
void guardarDatosAlumnos(alumnos_t *listaAlumnos);
char *leeLineaDinamicaFichero(FILE *f);
boolean_t existeFichero(char *nombreFichero);
char *copiarCadenas(char *cadenaOrigen);

int main (int argc, char **argv){
	alumnos_t listaAlumnos = {.alumnos = NULL, .numAlumnos = 0};
	boolean_t salir = falso;
	int opcion = 0;
	if (existeFichero(NOM_FICH)){
		cargarDatosAlumnos(&listaAlumnos, NOM_FICH);
	}
	while(!salir){
		printf("1. Añadir alumno.\n2. Listar alumnos.\n3. Buscar alumno.\n4. Guardar alumnos.\n5. Salir\n");
		scanf("%d", &opcion);
		while(getchar() != '\n');
		switch (opcion){
			case 1:
				ingresarAlumnoEnLista(&listaAlumnos);
			break;
			case 2:
				if (listaAlumnos.numAlumnos){
					imprimirAlumnos(listaAlumnos);
				}
				else {
					printf("No hay alumnos ingresados\n");
				}
			break;
			case 3:
				if (listaAlumnos.numAlumnos){
					buscarAlumnos(listaAlumnos);
				}
				else {
					printf("No hay alumnos ingresados\n");
				}
			break;
			case 4:
				if (listaAlumnos.numAlumnos){
					guardarDatosAlumnos(&listaAlumnos);
				}
				else {
					printf("No hay alumnos ingresados\n");
				}
			break;
			case 5:
				salir = verdadero;
				for (int i = 0; i < listaAlumnos.numAlumnos; i++){
					if (listaAlumnos.alumnos[i].memoria){
						free(listaAlumnos.alumnos[i].nombre);
						listaAlumnos.alumnos[i].nombre = NULL;
						free(listaAlumnos.alumnos[i].apellido);
						listaAlumnos.alumnos[i].apellido = NULL;
					}
				}
				if (listaAlumnos.numAlumnos){
					free(listaAlumnos.alumnos);
					listaAlumnos.alumnos = NULL;
				}
			break;
		}
	}
	return 0;
}

void cargarDatosAlumnos(alumnos_t *listaAlumnos, char *nombreFichero){
	FILE *fichero = NULL;
	char *lineaAux = NULL, *error = NULL;
	fichero = fopen(nombreFichero, "rb");
	while (!feof(fichero)){
		lineaAux = leeLineaDinamicaFichero(fichero);
		if (lineaAux[0] != '\0'){ //Si la linea no esta vacia
			listaAlumnos->numAlumnos++;
			listaAlumnos->alumnos = (alumno_t*)realloc(listaAlumnos->alumnos, sizeof(alumno_t)*listaAlumnos->numAlumnos);
			listaAlumnos->alumnos[listaAlumnos->numAlumnos-1].nombre = parsearLinea(lineaAux, "Nombre: ", ",");
			listaAlumnos->alumnos[listaAlumnos->numAlumnos-1].apellido = parsearLinea(lineaAux, "Apellido: ", ",");
			listaAlumnos->alumnos[listaAlumnos->numAlumnos-1].edad = (int)strtol(parsearLinea(lineaAux, "Edad: ", "\n"), &error, 10);
			if (*error != '\0'){
				listaAlumnos->alumnos[listaAlumnos->numAlumnos-1].edad = 0; //Inicializo a cero la edad si la cadena no es numerica (criterio propio)
			}
			listaAlumnos->alumnos[listaAlumnos->numAlumnos-1].estado = verdadero;
			listaAlumnos->alumnos[listaAlumnos->numAlumnos-1].memoria = falso;
		}
		free(lineaAux);
		lineaAux = NULL;
	}
	fclose(fichero);
}

char *parsearLinea(char *linea, char *token, char *delimitador){
	int posicion = 0;
	char *lineaAux = NULL;
	char *cadena = NULL;
	lineaAux = copiarCadenas(linea);
	posicion = strstr(lineaAux, token) - lineaAux; 
	lineaAux += posicion + strlen(token);
	cadena = strtok(lineaAux, delimitador);
	return cadena;
}

alumno_t ingresarAlumno(){
	char *error = NULL;
	alumno_t alumno = {.nombre = NULL, .apellido = NULL, .edad = 0, .estado = falso, .memoria = verdadero};
	printf("Ingrese el nombre: ");
	alumno.nombre = leeLineaDinamicaFichero(stdin);
	printf("Ingrese el apellido: ");
	alumno.apellido = leeLineaDinamicaFichero(stdin);
	do {
		printf("Ingrese la edad: ");
		alumno.edad = (int)strtol(leeLineaDinamicaFichero(stdin), &error, 10);
		if (*error != '\0'){
			printf("La cadena ingresada no es una edad.\n");
		}
	}while(*error != '\0');
	return alumno;
}

void ingresarAlumnoEnLista(alumnos_t *listaAlumnos){
	listaAlumnos->numAlumnos++;
	listaAlumnos->alumnos = (alumno_t*)realloc(listaAlumnos->alumnos, sizeof(alumno_t)*listaAlumnos->numAlumnos);
	listaAlumnos->alumnos[listaAlumnos->numAlumnos-1] = ingresarAlumno();
}

void imprimirAlumnos(alumnos_t listaAlumnos){
	for (int i = 0; i < listaAlumnos.numAlumnos; i++){
		printf("Alumno %d:\n", i+1);
		printf("Nombre: %s\n", listaAlumnos.alumnos[i].nombre);
		printf("Apellido: %s\n", listaAlumnos.alumnos[i].apellido);
		printf("Edad: %d\n", listaAlumnos.alumnos[i].edad);
	}
}

void buscarAlumnos(alumnos_t listaAlumnos){
	char *lineaAux = NULL;
	boolean_t encontrado = falso;
	printf("Ingrese el nombre o apellido del alumno: ");
	lineaAux = leeLineaDinamicaFichero(stdin);
	for (int i = 0; i < listaAlumnos.numAlumnos; i++){
		if ((strstr(listaAlumnos.alumnos[i].nombre, lineaAux) != NULL)||(strstr(listaAlumnos.alumnos[i].apellido, lineaAux) != NULL)){
			printf("Alumno %d:\n", i+1);
			printf("Nombre: %s\n", listaAlumnos.alumnos[i].nombre);
			printf("Apellido: %s\n", listaAlumnos.alumnos[i].apellido);
			printf("Edad: %d\n", listaAlumnos.alumnos[i].edad);
			encontrado = verdadero;
		}
	}
	if (!encontrado){
		printf("No hay alumnos con el nombre o apellido '%s'\n", lineaAux);
	}
	free(lineaAux);
	lineaAux = NULL;
}

void guardarDatosAlumnos(alumnos_t *listaAlumnos){
	FILE *fichero = NULL;
	if (existeFichero(NOM_FICH)){
		fichero = fopen(NOM_FICH, "ab");
	}
	else {
		fichero = fopen(NOM_FICH, "wb");
	}
	for (int i = 0; i < listaAlumnos->numAlumnos; i++){
		if (!listaAlumnos->alumnos[i].estado){
			fprintf(fichero, "Nombre: %s, ", listaAlumnos->alumnos[i].nombre);
			fprintf(fichero, "Apellido: %s, ", listaAlumnos->alumnos[i].apellido);
			fprintf(fichero, "Edad: %d\n", listaAlumnos->alumnos[i].edad);
			listaAlumnos->alumnos[i].estado = verdadero;
		}
	}
	fclose(fichero);
}

char *leeLineaDinamicaFichero(FILE *f){
	char *letras = NULL, ultimaLetraLeida = '\0';
	int numLetrasLeidas = 0, numLetrasMax = 0;
	do {
		ultimaLetraLeida = getc(f);
		if (numLetrasLeidas == numLetrasMax){
			numLetrasMax++;
			letras = (char*)realloc(letras, sizeof(char)*numLetrasMax);
		}
		if ((ultimaLetraLeida != '\n')&&(ultimaLetraLeida != EOF)){
			letras[numLetrasLeidas] = ultimaLetraLeida;
			numLetrasLeidas++;
		}
	}while((ultimaLetraLeida != '\n') && (!feof(f)));
	letras[numLetrasLeidas] = '\0';
	return letras;
}

boolean_t existeFichero(char *nombreFichero){
	FILE *fichero = NULL;
	boolean_t existe = verdadero;
	fichero = fopen(nombreFichero, "rb");
	if(fichero == NULL){
		existe = falso;
	}
	else {
		fclose(fichero);
	}
	return existe;
}

char *copiarCadenas(char *cadenaOrigen){
	char *cadenaDestino = NULL;
	cadenaDestino = (char*)realloc(cadenaDestino, strlen(cadenaOrigen)+1);
	cadenaDestino[0] = '\0';
	strcpy(cadenaDestino, cadenaOrigen);
	return cadenaDestino;
}