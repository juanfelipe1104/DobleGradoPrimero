/*
Crear DNI
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){
	int posicion = 0;
	long int numeroDNI = 0;
	char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
	char *error = NULL;
	//Minimo y maximo 1 parametro
	if (argc != 2){
		printf("Error, minimo y maximo 1 parametro");
	}
	else {
		numeroDNI = strtol(argv[1], &error, 10);
		if (*error != '\0'){
			printf("Error, el parametro introducido no es un numero: %s", argv[1]);
		}
		else {
			posicion = numeroDNI % 23;
			printf("El numero DNI es %d%c", numeroDNI, letra[posicion]);
		}
	}
}