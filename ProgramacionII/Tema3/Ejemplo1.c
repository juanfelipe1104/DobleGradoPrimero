/*
Uso de malloc() y free()
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10

int main (int argc, char **argv){
	int *numeros = NULL;
	numeros = (int*)realloc(numeros, sizeof(int)*10);
	for (int i = 0; i < TAM_MAX; i++){
		numeros[i] = i;
	}
	printf("Los numeros son: ");
	for (int i = 0; i < TAM_MAX; i++){
		printf("%d ", numeros[i]);
	}
	free(numeros);
	return 0;
}