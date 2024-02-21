/*
Media de numeros pasados como argumento
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	float media = 0;
	char *error = NULL;
	int correcto = 0;
	// Minimo de dos argumentos para que funcione
	if (argc <= 2){
		printf("Error, minimo dos argumentos");
		return 1;
	}
	else {
		for (int i = 1; i < argc; i++){
			media += (float)(strtol(argv[i], &error, 10));
			if (*error != '\0'){
				correcto = 1;
				printf("No es un numero entero: %s\n", argv[i]);
			}
		}
		if (correcto != 1){
			printf("La media es: %.2f\n", media/(float)(argc-1));
			return 0;
		}
		else {
			printf("No se pudo calcular la media\n");
			return 1;
		}
	}
}