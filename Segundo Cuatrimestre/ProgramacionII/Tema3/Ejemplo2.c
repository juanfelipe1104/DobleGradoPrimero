/*
Uso de malloc() y free()
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char** argv){
	int *numeros1 = NULL, *numeros2 = NULL, tamMax = 0;
	srand(getpid());
	printf("Ingrese el tamano maximo de numeros: ");
	scanf("%d", &tamMax);
	numeros1 = (int*)realloc(numeros1, sizeof(int) * tamMax);
	for (int i = 0; i < tamMax; i++){
		numeros1[i] = rand()%tamMax;
	}
	numeros2 = numeros1;
	printf("Los %d numeros aleatorios son: ", tamMax);
	for (int i = 0; i < tamMax; i++){
		printf("%d ", numeros2[i]);
	}
	free(numeros1);
	numeros1 = NULL;
}