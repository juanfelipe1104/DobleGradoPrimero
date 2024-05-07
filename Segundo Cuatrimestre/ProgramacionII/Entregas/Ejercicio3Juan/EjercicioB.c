/*
Estrechar fichero
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_MAX_ARG 4

typedef struct lineas_t{
	char **lineas;
	int numLineas;
}lineas_t;

void leerFicheroIn(lineas_t *lineasFicheroIn, char *nombreFichero);
void estrecharFichero(lineas_t *lineasFicheroIn, lineas_t *lineasFicheroOut, int tamMax);
void escribirFicheroOut(lineas_t lineasFicheroOut, char *nombreFichero);
char *leeLineaDinamicaFichero(FILE *f); //Empleo de memoria dinamica en vez de fgets
int existeFichero(char *nombreFichero);
char *copiarCadenas(char *cadenaOrigen, int tamMax);
char *concatenarCadenas(char *cadenaOrigen, char *cadenaDestino);

int main (int argc, char **argv){
	FILE *ficheroOut = NULL;
	lineas_t lineasFicheroIn = {.lineas = NULL, .numLineas = 0};
	lineas_t lineasFicheroOut = {.lineas = NULL, .numLineas = 0};
	int lineasMax = 0;
	char *error = NULL;
	if (argc != MIN_MAX_ARG){
		printf("El numero minimo y maximo de argumentos es 3.\n");
	}
	else {
		lineasMax = (int)strtol(argv[3], &error, 10);
		if (*error != '\0'){
			printf("La cadena '%s' no es un numero.\n", argv[3]);
		}
		else {
			if (existeFichero(argv[1])){
				leerFicheroIn(&lineasFicheroIn, argv[1]);
				estrecharFichero(&lineasFicheroIn, &lineasFicheroOut, lineasMax);
				escribirFicheroOut(lineasFicheroOut, argv[2]);
				free(lineasFicheroIn.lineas);
				lineasFicheroIn.lineas = NULL;
				free(lineasFicheroOut.lineas);
				lineasFicheroOut.lineas = NULL;
			}
			else {
				printf("El fichero '%s' no existe.\n", argv[1]);
			}
		}
	}
	return 0;
}

void leerFicheroIn(lineas_t *lineasFicheroIn, char *nombreFichero){
	FILE *ficheroIn = NULL;
	ficheroIn = fopen(nombreFichero, "rb");
	while (!feof(ficheroIn)){
		lineasFicheroIn->numLineas++;
		lineasFicheroIn->lineas = (char**)realloc(lineasFicheroIn->lineas, sizeof(char*)*lineasFicheroIn->numLineas);
		lineasFicheroIn->lineas[lineasFicheroIn->numLineas-1] = leeLineaDinamicaFichero(ficheroIn);
	}
	fclose(ficheroIn);
}

void estrecharFichero(lineas_t *lineasFicheroIn, lineas_t *lineasFicheroOut, int tamMax){
	char *trozoSobra = NULL; //Linea donde se guardara lo sobrante de la cadena
	trozoSobra = copiarCadenas("\0", 1);
	for (int i = 0; i < lineasFicheroIn->numLineas; i++){
		if (lineasFicheroIn->lineas[i][0] != '\0'){
			lineasFicheroIn->lineas[i] = concatenarCadenas(lineasFicheroIn->lineas[i], trozoSobra);
			do {
				if (strlen(lineasFicheroIn->lineas[i]) > tamMax){
					lineasFicheroOut->numLineas++;
					lineasFicheroOut->lineas = (char**)realloc(lineasFicheroOut->lineas, sizeof(char*) * lineasFicheroOut->numLineas);
					lineasFicheroOut->lineas[lineasFicheroOut->numLineas-1] = copiarCadenas(lineasFicheroIn->lineas[i], tamMax);
					lineasFicheroIn->lineas[i] += tamMax;
					trozoSobra = copiarCadenas(lineasFicheroIn->lineas[i], strlen(lineasFicheroIn->lineas[i]));
					if ((lineasFicheroOut->lineas[lineasFicheroOut->numLineas-1][strlen(lineasFicheroOut->lineas[lineasFicheroOut->numLineas-1])-1]!= ' ') && (trozoSobra[0] != ' ')){
						lineasFicheroOut->lineas[lineasFicheroOut->numLineas-1] = concatenarCadenas("-", lineasFicheroOut->lineas[lineasFicheroOut->numLineas-1]);
					}
				}
				else {
					lineasFicheroOut->numLineas++;
					lineasFicheroOut->lineas = (char**)realloc(lineasFicheroOut->lineas, sizeof(char*) * lineasFicheroOut->numLineas);
					lineasFicheroOut->lineas[lineasFicheroOut->numLineas-1] = copiarCadenas(lineasFicheroIn->lineas[i], strlen(lineasFicheroIn->lineas[i]));
				}
			}while(strlen(lineasFicheroIn->lineas[i]) > tamMax);
		}
	}
	if (trozoSobra != NULL || trozoSobra[0] != '\0'){
		lineasFicheroOut->numLineas++;
		lineasFicheroOut->lineas = (char**)realloc(lineasFicheroOut->lineas, sizeof(char*) * lineasFicheroOut->numLineas);
		lineasFicheroOut->lineas[lineasFicheroOut->numLineas-1] = copiarCadenas(trozoSobra, strlen(trozoSobra));
	}
	free(trozoSobra);
	trozoSobra = NULL;
}

void escribirFicheroOut(lineas_t lineasFicheroOut, char *nombreFichero){
	FILE *ficheroOut = NULL;
	ficheroOut = fopen(nombreFichero, "wb");
	for (int i = 0; i < lineasFicheroOut.numLineas; i++){
		fprintf(ficheroOut, "%s\n", lineasFicheroOut.lineas[i]);
	}
	fclose(ficheroOut);
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
		else if (ultimaLetraLeida == '\n'){
			letras[numLetrasLeidas] = ' ';
			numLetrasLeidas++;
		}
	}while((ultimaLetraLeida != '\n') && (!feof(f)));
	if (numLetrasLeidas == numLetrasMax){
		numLetrasMax++;
		letras = (char*)realloc(letras, sizeof(char)*numLetrasMax);
	}
	letras[numLetrasLeidas] = '\0';
	return letras;
}

int existeFichero(char *nombreFichero){
	FILE *fichero = NULL;
	int existe = 1;
	fichero = fopen(nombreFichero, "rb");
	if(fichero == NULL){
		existe = 0;
	}
	else {
		fclose(fichero);
	}
	return existe;
}

char *copiarCadenas(char *cadenaOrigen, int tamMax){
	char *cadenaDestino = NULL;
	cadenaDestino = (char*)realloc(cadenaDestino, tamMax+1);
	memcpy(cadenaDestino, cadenaOrigen, sizeof(char)*tamMax);
	cadenaDestino[tamMax] = '\0';
	return cadenaDestino;
}

char *concatenarCadenas(char *cadenaOrigen, char *cadenaDestino){
	if (strlen(cadenaDestino)){
		cadenaDestino = (char*)realloc(cadenaDestino, strlen(cadenaOrigen)+strlen(cadenaDestino));
	}
	else {
		cadenaDestino = (char*)realloc(cadenaDestino, strlen(cadenaOrigen)+strlen(cadenaDestino)+1);
		cadenaDestino[0] = '\0';
	}
	strcat(cadenaDestino, cadenaOrigen);
	return cadenaDestino;
}