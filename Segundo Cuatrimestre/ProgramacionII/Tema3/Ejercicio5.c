/*
malloc(), realloc()
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){
	int *numeros = NULL;
	int numeroLeido = 0, numerosUsados = 0, tamMax = 0, salir = 0;
	while(!salir){
		printf("Introduzca un numero entero: ");
		scanf("%d", &numeroLeido);
		if (tamMax == numerosUsados){
			tamMax++;
			numeros = (int*)realloc(numeros, sizeof(int)*tamMax);
		}
		numeros[numerosUsados] = numeroLeido;
		if (numeros[numerosUsados]>numeros[0]){
			salir = 1;
		}
		numerosUsados++;
	}
	printf("Los numeros son: ");
	for (int i = 0; i < numerosUsados; i++){
		printf("%d ", numeros[i]);
	}
	free(numeros);
	numeros = NULL;
}