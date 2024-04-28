#include <stdio.h>
#include <stdlib.h>

#define NUM_COLUMNS 3
#define NUM_FILAS 3

int main (int argc, char **argv){
	float matriz[NUM_FILAS][NUM_COLUMNS];
	char *error = NULL;
	int comprobacion = 0;
	//Minimo y maximo 9 argumentos
	if (argc != 10){
		printf("Error, minimo y maximo 9 argumentos\n");
	}
	else {
		for (int i = 1; i < NUM_FILAS+1; i++){
			for (int j = 0; j < NUM_COLUMNS; j++){
				matriz[i-1][j] = strtof(argv[i+j], &error);
				if (*error != '\0'){
					comprobacion = 1;
					printf("No es un numero decimal: %s", argv[i+j]);
				}
			}
		}
		if (comprobacion != 1){
			for (int i = 0; i < NUM_FILAS; i++){
				for (int j = 0; j < NUM_COLUMNS; j++){
					printf("%.2f ",matriz[i][j]);
				}
				printf("\n");
			}
		}
		else {
			printf("No se puede rellenar la matriz");
		}
	}
}