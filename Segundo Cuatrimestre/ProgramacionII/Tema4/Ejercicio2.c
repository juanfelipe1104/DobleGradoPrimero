/*
N primeras lineas
*/

#include <stdio.h>
#include <stdlib.h>

#define MIN_MAX_ARG 3

typedef struct lineas_t{
	int numLineas;
	char **lineas;
}lineas_t;

int existeFichero(char *fichero);
char *leeLineaDinamicaFichero(FILE *f);

int main (int argc, char **argv){
	lineas_t lineasFichero = {.numLineas = 0, .lineas = NULL};
	char *error = NULL;
	FILE *fichero = NULL;
	if (argc != MIN_MAX_ARG){
		printf("Error, el numero minimo y maximo de argumentos es 2.\n");
	}
	else {
		lineasFichero.numLineas = (int)strtol(argv[1], &error, 10);
		if (*error != '\0'){
			printf("El argumento %s no es un numero.\n", argv[1]);
		}
		else {
			if (existeFichero(argv[2])){
				fichero = fopen(argv[2],"r+");
				lineasFichero.lineas = (char**)malloc(sizeof(char*)*lineasFichero.numLineas);
				for (int i = 0; (!feof(fichero)&&(i < lineasFichero.numLineas)); i++){
					lineasFichero.lineas[i] = leeLineaDinamicaFichero(fichero);
					printf("%s\n", lineasFichero.lineas[i]);
				}
				fclose(fichero);
				for (int i = 0; i < lineasFichero.numLineas; i++){
					free(lineasFichero.lineas[i]);
					lineasFichero.lineas[i] = NULL;
				}
				free(lineasFichero.lineas);
				lineasFichero.lineas = NULL;
			}
			else {
				printf("El fichero %s no existe.\n", argv[2]);
			}
		}
	}
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