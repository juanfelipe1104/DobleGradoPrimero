/*
Imprimir el nombre o apellido pasado por parametros 
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANO_MAX 100

int obtenerCadenaUnica(char* palabra, char *cadena, int j);

int main (int argc, char **argv){
	char auxiliar[200] = {'\0'};
	char nombre[TAMANO_MAX] = {'\0'};
	char apellido[TAMANO_MAX] = {'\0'};
	char *pAuxiliar = NULL;
	int j = 0, k = 0, n = 0; //Contadores auxiliares
	pAuxiliar = auxiliar;
	for(int i = 1; i < argc; i++){
		j = obtenerCadenaUnica(argv[i], pAuxiliar, j);
		auxiliar[j] = ' ';
		j++;
	}
	do {
		apellido[k] = auxiliar[k];
		k++;
	}while(auxiliar[k] != ',');
	k++; // Suprimir la posicion de la coma del contador
	do {
		nombre[n] = auxiliar[k];
		n++;
		k++;
	}while(auxiliar[k] != '\0');
	printf("El nombre del alumno es %s%s", nombre, apellido);
}

int obtenerCadenaUnica(char* palabra, char *cadena, int j){
	while(*palabra != '\0'){
		cadena[j] = *palabra;
		palabra++;
		j++;
	}
	return j;
}

/*
//Programa hecho por Marcos
//Si la coma esta junta a una palabra, el programa repite el apellido
char* obtenerComa(char* palabra);
void concatenar(char* destino, char* origen, int maxSize);

int main (int argc, char **argv){
	char nombre[TAMANO_MAX] = {'\0'};
	char apellido[TAMANO_MAX] = {'\0'};
	int i = 1;
	int leeApellido = 1;
	char* coma = NULL;
	do {
		coma = obtenerComa(argv[i]);
		leeApellido = (*coma != ',');
		if (leeApellido){
			concatenar(apellido, argv[i], 100);
		}
	}while (leeApellido && (++i)<argc);
	if (coma == argv[i]){
		coma++;
		concatenar(nombre, coma, 100);
	}
	else if (coma[1] == '\0'){
		concatenar(apellido, argv[i], 100);
	}
	do {
		concatenar(nombre, argv[i++], 100);
	}while(i < argc);
	printf("El nombre/apellido es %s %s", nombre, apellido);
}

char* obtenerComa(char* palabra){
	while((*palabra != '\0')&&(*palabra != ',')){
		palabra++;
	}
	return palabra;
}

void concatenar(char* destino, char* origen, int maxSize){
	int sizeDestino = 0;
	while (*destino != '\0'){
		destino++;
		sizeDestino++;
	}
	while ((sizeDestino++ < maxSize)&&(*origen != '\0')&&(*origen != ',')){
		*destino++ = *origen++;
	}
	if (sizeDestino < maxSize){
		*destino = '\0';
	}
}
*/