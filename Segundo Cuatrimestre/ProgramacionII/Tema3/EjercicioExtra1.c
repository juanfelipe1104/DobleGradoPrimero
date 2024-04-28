/*
Array inverso
*/

#include <stdio.h>
#include <stdlib.h>

int *devuelveInverso(int *array, int nElementos);

int main (int argc, char **argv){
	int *numeros = NULL, *numerosInversos = NULL, comprobacion = 1;
	char *error = NULL;
	if (argc <= 1){
		printf("El numero minimo de parametros es 1.\n");
	}
	else{
		numeros = (int*)realloc(numeros, sizeof(int)*(argc-1));
		for (int i = 1; i < argc && comprobacion; i++){
			numeros[i-1] = (int)strtol(argv[i], &error, 10);
			if (*error != '\0'){
				comprobacion = 0;
				printf("El argumento '%s' no es un numero.\n", argv[i]);
			}
		}
		if (comprobacion){
			numerosInversos = devuelveInverso(numeros, argc-1);
			printf("Los numeros inversos son: ");
			for (int i = 0; i < argc-1; i++){
				printf("%d ", numerosInversos[i]);
			}
		}
		free(numeros);
		numeros = NULL;
		free(numerosInversos);
		numerosInversos = NULL;
	}
}

int *devuelveInverso(int *array, int nElementos){
	int *inverso = NULL, tamMax = 0;
	inverso = (int*)realloc(inverso, sizeof(int)*nElementos);
	tamMax = nElementos;
	for (int i = 0; i < tamMax; i++){
		nElementos--;
		inverso[i] = array[nElementos];
	}
	return inverso;
}