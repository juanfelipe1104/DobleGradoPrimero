/*
Ejercicio 2 (Comparación de tres números)
El usuario ingresa tres números enteros entre el 0 y el 9, y el programa debe determinar e
imprimir cuál de los tres números es el mayor, utilizando una estructura if else
*/

#include <stdio.h>

void main () {
	int numero1 = 0, numero2 = 0, numero3 = 0;
	printf("Ingresa tres numeros: ");
	scanf("%d %d %d", &numero1, &numero2, &numero3);
	if((numero1 >= numero2) && (numero1 >= numero3)){
		printf("El numero mayor es %d\n", numero1);
	}
	else if ((numero2 >= numero3)&&(numero2 >= numero1)){
		printf("El numero mayor es %d\n", numero2);
	}
	else {
		printf("El numero mayor es %d\n", numero3);
	}
}