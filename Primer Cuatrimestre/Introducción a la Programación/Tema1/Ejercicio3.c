/*
Ejericio 3 (Suma o Resta)
Pedir al usuario que ingrese 2 números y si el primero es mayor o igual que el segundo realiza la
resta del primero menos el segundo. En caso contrario realiza la suma. Por último, presenta por
pantalla el resultado de la operación que se haya realizado.
*/

#include <stdio.h>

void main () {
	int numero1 = 0, numero2 = 0;
	printf("Ingresa dos numeros: ");
	scanf("%d %d", &numero1, &numero2);
	if (numero1 >= numero2){
		printf("El resultado de la resta es %d\n", numero1 - numero2);
	}
	else{
		printf ("El resultado de la suma es %d\n", numero1 + numero2);
	}
}