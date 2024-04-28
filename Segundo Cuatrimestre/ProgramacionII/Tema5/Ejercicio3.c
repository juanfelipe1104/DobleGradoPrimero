/*
strcmp
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_MAX_ARG 2

typedef struct lineas_t{
	int numLineas;
	char **lineas;
}lineas_t;

int existeFichero(char *fichero);
char *leeLineaDinamicaFichero(FILE *f);
void ordenaCadenas(lineas_t *lineasFichero);

int main (int argc, char **argv){
	lineas_t lineasFichero = {.numLineas = 0, .lineas = NULL};
	FILE *fichero = NULL;
	if (argc != MIN_MAX_ARG){
		printf("El numero maximo y minimo de argumentos es 1.\n");
	}
	else {
		if (existeFichero(argv[1])){
			fichero = fopen(argv[1], "r+");
			while(!feof(fichero)){
				lineasFichero.numLineas++;
				lineasFichero.lineas = (char**)realloc(lineasFichero.lineas, sizeof(char*)*lineasFichero.numLineas);
				lineasFichero.lineas[lineasFichero.numLineas-1] = leeLineaDinamicaFichero(fichero);
			}
			fclose(fichero);
			ordenaCadenas(&lineasFichero);
			for (int i = 0; i < lineasFichero.numLineas; i++){
				printf("%s\n", lineasFichero.lineas[i]);
			}
			for (int i = 0; i < lineasFichero.numLineas; i++){
				free(lineasFichero.lineas[i]);
				lineasFichero.lineas[i] = NULL;
			}
			free(lineasFichero.lineas);
			lineasFichero.lineas = NULL;
		}
		else {
			printf("El fichero '%s' no existe.\n", argv[1]);
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

void ordenaCadenas(lineas_t *lineasFichero){
	char *auxiliar = NULL;
	for (int i = 0; i < lineasFichero->numLineas; i++){
		for (int j = i+1; j < lineasFichero->numLineas; j++){
			if(strcmp(lineasFichero->lineas[i],lineasFichero->lineas[j])>0){
				auxiliar = lineasFichero->lineas[i];
				lineasFichero->lineas[i] = lineasFichero->lineas[j];
				lineasFichero->lineas[j] = auxiliar;
			}
		}
	}
}