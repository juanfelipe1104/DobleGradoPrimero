/*
Tabla abecedario
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){
	FILE *fichero = NULL;
	fichero = fopen("tabla.xls", "w");
	if (fichero == NULL){
		printf("El fichero no se puede crear.\n");
	}
	else {
		for (char i = 'A'; i <= 'Z'; i++){
			fprintf(fichero, "%c\t", i);
			fprintf(fichero, "%c\t", i+32);
			fprintf(fichero, "%d\t", i);
			fprintf(fichero, "%d\n", i+32);
		}
		fclose(fichero);
	}
}