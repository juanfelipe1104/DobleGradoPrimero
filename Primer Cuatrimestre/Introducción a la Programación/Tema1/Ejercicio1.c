/*
Ejercicio 1 (Programa de calificación)
El usuario ingresa una nota numérica entre 0 y 9, y el programa debe imprimir la calificación
correspondiente, siguiendo el siguiente criterio: suspenso menor a 5, aprobado mayor o igual a 5 y
menor a 9 y sobresaliente mayor ). Utilizando una estructura if else
*/

#include <stdio.h>

void main () {
	int nota = 0;
	printf("Ingresa una nota numerica: ");
	scanf("%d", &nota);
	if(nota < 5){
		printf("Suspenso: %d\n", nota);
	}
	else{
		if(nota >= 9){
			printf("Sobresaliente: %d\n", nota);
		}
		else{
			printf("Aprobado: %d\n", nota);
		}
	}
}