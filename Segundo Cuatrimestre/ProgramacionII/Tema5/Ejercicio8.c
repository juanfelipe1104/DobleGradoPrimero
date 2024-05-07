/*
Contar letras
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cuentaLetras(const char *cadena, int *vocales, int *consonantes, int *digitos);
int contarPorSeparador(const char *cadena, const char *separador);

int main (int argc, char **argv){
	int vocales = 0, consonantes = 0, digitos = 0;
	const char *cadena = "Hola123";
	cuentaLetras(cadena, &vocales, &consonantes, &digitos);
	printf("Numero de vocales: %d, consonantes: %d y digitos: %d", vocales, consonantes, digitos);
	return 0;
}

void cuentaLetras(const char *cadena, int *vocales, int *consonantes, int *digitos){
	const char *separadoresVocales = "aeiouAEIOU";
	const char *separadoresConsonantes = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
	const char *separadoresDigitos = "0123456789";
	*vocales = contarPorSeparador(cadena, separadoresVocales);
	*consonantes = contarPorSeparador(cadena, separadoresConsonantes);
	*digitos = contarPorSeparador(cadena, separadoresDigitos);
}

int contarPorSeparador(const char *cadena, const char *separador){
	int contador = 0, posicion = 0, lenghtFrase = 0;
	const char *copia = NULL;
	copia = cadena;
	lenghtFrase = strlen(cadena);
	do {
		posicion = strcspn(copia, separador);
		if (posicion < lenghtFrase){
			contador++;
		}
		copia += posicion+1;
		lenghtFrase -= posicion+1;
		posicion = 0;
	}while (posicion < lenghtFrase);
	return contador;
}