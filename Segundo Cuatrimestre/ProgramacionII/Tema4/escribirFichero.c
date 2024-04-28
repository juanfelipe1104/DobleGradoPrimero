/*
Crear y escribir en fichero
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){
	FILE *fOut = NULL;
	fOut = fopen("abecedario.txt", "w");
	if (fOut == NULL){
		printf("Error al crear fichero\n");
	}
	else {
		for (char i = 'A'; i <= 'Z'; i++){
			fprintf(fOut, "%c ", i);
		}
		fprintf(fOut, "\n");
		for (char i = 'a'; i <= 'z'; i++){
			fprintf(fOut, "%c ", i);
		}
		fprintf(fOut, "\n");
		fclose(fOut);
	}
}