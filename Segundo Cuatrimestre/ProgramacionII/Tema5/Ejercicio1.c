/*
strcpy, strcat
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_MAX_ARG 2

typedef struct persona_t{
	char *nombre;
	char *apellido;
}persona_t;

int existeFichero(char *nombreFichero);
char *leeLineaDinamicaFichero(FILE *f);

int main (int argc, char **argv){
	persona_t persona = {.nombre = NULL, .apellido = NULL};
	char *nombreCompleto = NULL;
	FILE *fichero = NULL;
	if (argc != MIN_MAX_ARG){
		printf("El numero minimo y maximo de parametros es 1.\n");
	}
	else {
		if (existeFichero(argv[1])){
			fichero = fopen(argv[1], "rb");
			persona.nombre = leeLineaDinamicaFichero(fichero);
			persona.apellido = leeLineaDinamicaFichero(fichero);
			fclose(fichero);
			nombreCompleto = (char*)realloc(nombreCompleto, strlen(persona.nombre)+strlen(persona.apellido)+1);
			nombreCompleto[0] = '\0';
			strcat(nombreCompleto, persona.nombre);
			strcat(nombreCompleto, persona.apellido);
			printf("El nombre completo es: %s", nombreCompleto);
			free(persona.nombre);
			persona.nombre = NULL;
			free(persona.apellido);
			persona.apellido = NULL;
			free(nombreCompleto);
			nombreCompleto = NULL;
		}
	}
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

int existeFichero(char *fichero){
	FILE *f=NULL;
	int existe = 1;
	f = fopen(fichero, "r+");
	if(f==NULL){
		existe = 0;
	}
	else {
		fclose(f);
	}
	return existe;
}