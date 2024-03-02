/*
Edades estudiantes U-tad
*/

#include <stdio.h>
#include <stdlib.h>

int calcularMedia(int *numeros, int tamMax);
int calcularMaximo(int *numeros, int tamMax);
int calcularMinimo(int *numeros, int tamMax);

int main (int argc, char **argv){
	int *edades = NULL;
	int edadesMax = 10, contadorEdades = 0, edadLeida = 0;
	edades = realloc(edades, sizeof(int)*edadesMax);
	if (edades == NULL){
		printf("Error, no hay espacio en memoria.\n");
	}
	else {
		printf("Ingrese las edades de los alumnos:(Ingrese un numero negativo para terminar)\n");
		while (edadLeida >= 0){
			scanf("%d", &edadLeida);
			if (contadorEdades == edadesMax){
				edadesMax+=10;
				edades = realloc(edades, sizeof(int)*edadesMax);
			}
			if (edadLeida >= 0){
				edades[contadorEdades] = edadLeida;
				contadorEdades++;
			}
		}
		printf("La media de edades es: %d\n", calcularMedia(edades, contadorEdades));
		printf("La edad maxima es: %d\n", calcularMaximo(edades, contadorEdades));
		printf("La edad minima es: %d\n", calcularMinimo(edades, contadorEdades));
	}
	free(edades);
	edades = NULL;
	return 0;
}

int calcularMedia(int *numeros, int tamMax){
	int resultado = 0;
	for (int i = 0; i < tamMax; i++){
		resultado += numeros[i];
	}
	return resultado/tamMax;
}

int calcularMaximo(int *numeros, int tamMax){
	int resultado = numeros[0];
	for (int i = 0; i < tamMax; i++){
		if (numeros[i] > resultado){
			resultado = numeros[i];
		}
	}
	return resultado;
}

int calcularMinimo(int *numeros, int tamMax){
	int resultado = numeros[0];
	for (int i = 0; i < tamMax; i++){
		if (numeros[i] < resultado){
			resultado = numeros[i];
		}
	}
	return resultado;
}