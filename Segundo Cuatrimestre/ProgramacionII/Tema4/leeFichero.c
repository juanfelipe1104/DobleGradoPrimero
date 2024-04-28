/*
Abrir fichero, leer letra y mostrar letra (fgetc)
*/

#include <stdio.h>
#include <stdlib.h>

int existeFichero(char *fichero);
char *leeLineaDinamicaFichero(FILE *f);

int main (int argc, char **argv){
	FILE *fichero = NULL;
	char *linea = NULL;
	if (existeFichero(argv[1])){
		printf("El fichero %s existe.\n", argv[1]);
		fichero = fopen(argv[1],"r+");
		while(!feof(fichero)){
			linea = leeLineaDinamicaFichero(fichero);
			printf("%s\n", linea);
			free(linea);
		}
		fclose(fichero);
	}
	else {
		printf("El fichero %s no existe.\n", argv[1]);
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