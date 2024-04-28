/*
Intercambiar lineas
*/

#include <stdio.h>
#include <stdlib.h>

#define MIN_MAX_ARG 4

typedef struct lineas_t{
	int numLineas;
	char **lineas;
}lineas_t;

int existeFichero(char *fichero);
char *leeLineaDinamicaFichero(FILE *f);
void intercambiarLineas(lineas_t *lineasFichero, int linea1, int linea2);

int main (int argc, char **argv){
	lineas_t lineasFichero = {.lineas = NULL, .numLineas = 0};
	int numLinea1 = 0, numLinea2 = 0, tamanoLinea = 0;
	char *error1 = NULL, *error2 = NULL, *lineaAux = NULL;
	FILE *fichero = NULL;
	if (argc != MIN_MAX_ARG){
		printf("El numero minimo y maximo de parametros es 3.\n");
	}
	else {
		numLinea1 = (int)strtol(argv[1], &error1, 10);
		numLinea2 = (int)strtol(argv[2], &error2, 10);
		if ((*error1 != '\0')||(*error2 != '\0')){
			printf("%s o %s no son un numero.\n", argv[1], argv[2]);
		}
		else {
			if (existeFichero(argv[3])){
				fichero = fopen(argv[3], "r+");
				while(!feof(fichero)){
					lineasFichero.numLineas++;
					lineasFichero.lineas = (char**)realloc(lineasFichero.lineas, sizeof(char*)*lineasFichero.numLineas);
					lineasFichero.lineas[lineasFichero.numLineas-1] = leeLineaDinamicaFichero(fichero);
				}
				fclose(fichero);
				if ((numLinea1 >= lineasFichero.numLineas)||(numLinea2 >= lineasFichero.numLineas)){
					printf("Error, el fichero no contiene linea %d o %d\n", numLinea1, numLinea2);
				}
				else {
					intercambiarLineas(&lineasFichero, numLinea1, numLinea2);
					fichero = fopen(argv[3], "wb");
					for (int i = 0; i < lineasFichero.numLineas; i++){
						fprintf(fichero, "%s\n", lineasFichero.lineas[i]);
						free(lineasFichero.lineas[i]);
						lineasFichero.lineas[i] = NULL;
					}
					free(lineasFichero.lineas);
					lineasFichero.lineas = NULL;
					fclose(fichero);
				}
			}
			else {
				printf("El fichero %s no existe.\n", argv[3]);
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

void intercambiarLineas(lineas_t *lineasFichero, int linea1, int linea2){
	char *auxiliar = NULL;
	auxiliar = lineasFichero->lineas[linea1];
	lineasFichero->lineas[linea1] = lineasFichero->lineas[linea2];
	lineasFichero->lineas[linea2] = auxiliar;
}