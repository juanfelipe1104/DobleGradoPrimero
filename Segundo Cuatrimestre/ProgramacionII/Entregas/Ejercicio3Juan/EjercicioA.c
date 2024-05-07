/*
Analisis palabras fichero
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_ARG 2

typedef struct palabraInfo_t{
	char *palabra;
	int ocurrencias;
	int *numLineas;
}palabraInfo_t;

typedef struct listaPalabras_t{
	palabraInfo_t *palabras;
	int numPalabras;
}listaPalabras_t;

void examinaLinea(char *lineaAux, int numLinea, listaPalabras_t *listaPalabras);
char *leeLineaDinamicaFile(FILE *fd);
void escribirResultado(listaPalabras_t lista, char *nombreFichOrigen);
char *copiarCadenas(char *cadenaOrigen);
int existeFichero(char *nombreFichero);

int main (int argc, char **argv){
	FILE *ficheroIn = NULL;
	listaPalabras_t listaPalabras = {.palabras = NULL, .numPalabras = 0};
	char *lineaAux = NULL;
	int numLineasFichero = 0;
	if (argc > MIN_ARG){
		if (existeFichero(argv[1])){
			ficheroIn = fopen(argv[1], "rb");
			listaPalabras.numPalabras = argc-2; //Se le restan dos debido al nombre del ejecutable y del fichero de entrada
			listaPalabras.palabras = (palabraInfo_t*)realloc(listaPalabras.palabras, sizeof(palabraInfo_t)*listaPalabras.numPalabras);
			for (int i = 0; i < listaPalabras.numPalabras; i++){
				listaPalabras.palabras[i].palabra = argv[i+2]; //Las palabras empiezan a partir del segundo parametro
				listaPalabras.palabras[i].ocurrencias = 0;
				listaPalabras.palabras[i].numLineas = NULL;
			}
			while (!feof(ficheroIn)){
				lineaAux = leeLineaDinamicaFile(ficheroIn);
				numLineasFichero++;
				examinaLinea(lineaAux, numLineasFichero, &listaPalabras);
				free(lineaAux);
				lineaAux = NULL;
			}
			fclose(ficheroIn);
			escribirResultado(listaPalabras, argv[1]);
			for (int i = 0; i < listaPalabras.numPalabras; i++){
				free(listaPalabras.palabras[i].numLineas);
				listaPalabras.palabras[i].numLineas = NULL;
			}
			free(listaPalabras.palabras);
			listaPalabras.palabras = NULL;
		}
		else {
			printf("El fichero '%s' no existe.\n", argv[1]);
		}
	}
	else {
		printf("El numero minimo de argumentos es 2.\n");
	}
	return 0;
}

void examinaLinea(char *lineaAux, int numLinea, listaPalabras_t *listaPalabras){
	char *prompt = NULL;
	int posicionPalabra = 0;
	char *auxiliar1 = NULL, *auxiliar2 = NULL; //auxiliar1 para tener referencia de la primera posicion de la linea, auxiliar2 para recorrer la linea
	auxiliar1 = &lineaAux[0];
	for (int i = 0; i < listaPalabras->numPalabras; i++){
		auxiliar2 = auxiliar1;
		prompt = strstr(auxiliar2, listaPalabras->palabras[i].palabra);
		while (prompt != NULL){
			posicionPalabra = prompt - auxiliar2;
			listaPalabras->palabras[i].ocurrencias++;
			listaPalabras->palabras[i].numLineas = (int*)realloc(listaPalabras->palabras[i].numLineas, sizeof(int)*listaPalabras->palabras[i].ocurrencias);
			listaPalabras->palabras[i].numLineas[listaPalabras->palabras[i].ocurrencias-1] = numLinea;
			auxiliar2 += posicionPalabra + strlen(listaPalabras->palabras[i].palabra) + 1;
			prompt = strstr(auxiliar2, listaPalabras->palabras[i].palabra);
		}
	}
}

char *leeLineaDinamicaFile(FILE *fd){
	char *linea = NULL, ultimaLetraLeida = '\0';
	int numLetrasLeidas = 0, numLetrasMax = 0;
	do {
		ultimaLetraLeida = getc(fd);
		if (numLetrasLeidas == numLetrasMax){
			numLetrasMax++;
			linea = (char*)realloc(linea, sizeof(char)*numLetrasMax);
		}
		if ((ultimaLetraLeida != '\n')&&(ultimaLetraLeida != EOF)){
			linea[numLetrasLeidas] = ultimaLetraLeida;
			numLetrasLeidas++;
		}
	}while((ultimaLetraLeida != '\n') && (!feof(fd)));
	linea[numLetrasLeidas] = '\0';
	return linea;
}

void escribirResultado(listaPalabras_t lista, char *nombreFichOrigen){
	FILE *ficheroOut = NULL;
	char *nombreFichOut = NULL;
	char *extensionFichOrigen = NULL;
	char *copiaParaExtension = copiarCadenas(nombreFichOrigen);
	extensionFichOrigen = strstr(copiaParaExtension, "."); //Busco el . suponiendo que la extension inicia por este 
	nombreFichOut = strtok(nombreFichOrigen, "."); //Obtengo todo lo que hay antes del punto como nombre
	strcat(nombreFichOut, ".out");
	strcat(nombreFichOut, extensionFichOrigen);
	ficheroOut = fopen(nombreFichOut, "wb");
	for (int i = 0; i < lista.numPalabras; i++){
		if (lista.palabras[i].ocurrencias){
			fprintf(ficheroOut, "%s. Numero de ocurrencias: %d. Lineas: ", lista.palabras[i].palabra, lista.palabras[i].ocurrencias);
			for (int j = 0; j < lista.palabras[i].ocurrencias; j++){
				fprintf(ficheroOut, "%d ", lista.palabras[i].numLineas[j]);
			}
			fprintf(ficheroOut, "\n");
		}
	}
	fclose(ficheroOut);
	free(copiaParaExtension);
	copiaParaExtension = NULL;
}

int existeFichero(char *nombreFichero){
	FILE *fichero = NULL;
	int existe = 1;
	fichero = fopen(nombreFichero, "r+");
	if(fichero == NULL){
		existe = 0;
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