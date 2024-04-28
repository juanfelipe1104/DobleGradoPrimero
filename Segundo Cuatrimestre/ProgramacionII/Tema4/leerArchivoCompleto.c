/*
Leer archivo completo
*/

#include <stdio.h>
#include <stdlib.h>

#define MIN_MAX_ARG 2

int existeFichero(char *fichero);
int tamanoFichero(char *fileName); 

int main (int argc, char **argv){
	int sizeFichero = 0;
	char *lineas = NULL;
	FILE *fichero = NULL;
	if (argc != MIN_MAX_ARG){
		printf("El numero minimo y maximo de parametros es 1.\n");
	}
	else {
		if (existeFichero(argv[1])){
			sizeFichero = tamanoFichero(argv[1]);
			lineas = (char*)realloc(lineas, sizeFichero+1);
			fichero = fopen(argv[1], "rb");
			fread(lineas, sizeFichero, 1, fichero);
			lineas[sizeFichero] = '\0';
			printf("%s", lineas);
			free(lineas);
			lineas = NULL;
			fclose(fichero);
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

int tamanoFichero(char *fileName){
	FILE *f = NULL;
	int size = 0;
	f = fopen(fileName, "r+");
	if (f != NULL){
		fseek(f, 0, SEEK_END); //La primera posicion desde el final
		size = ftell(f);
		fclose(f);
	}
	return size;
}