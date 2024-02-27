/*
Calculadora numeros complejos
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARG 6 //Numero maximo de argumentos
#define POS_OPERANDO 1 //Posicion del operando en los parametros

typedef enum boolean {
	verdadero=1, falso=0
}boolean;

typedef struct complejos_t{
	float parteReal;
	float parteImaginaria;
}complejos_t;

int compararCadena(char *cadena1, char *cadena2);
complejos_t suma(complejos_t numero1, complejos_t numero2);
complejos_t resta(complejos_t numero1, complejos_t numero2);
complejos_t multiplicacion(complejos_t numero1, complejos_t numero2);
complejos_t division(complejos_t numero1, complejos_t numero2);

int main (int argc, char **argv){
	complejos_t numero1, numero2, resultado;
	char *error = NULL;
	boolean comprobacion = verdadero;
	if (argc != MAX_ARG){
		printf("Error, el numero minimo y maximo de argumentos es 5.\n");
	}
	else {
		for (int i = 2; i < argc; i++){
			switch (i) {
				case 2: numero1.parteReal = strtof(argv[i], &error); break;
				case 3: numero1.parteImaginaria = strtof(argv[i], &error); break;
				case 4: numero2.parteReal = strtof(argv[i], &error); break;
				case 5: numero2.parteImaginaria = strtof(argv[i], &error); break;
			}
			if (*error != '\0'){
				printf("Argumento incorrecto: %s\n", argv[i]);
				comprobacion = falso;
			}
		}
		if (comprobacion){
			if (compararCadena(argv[POS_OPERANDO], "+")){
				resultado = suma(numero1, numero2);
				printf("La suma es %.2f %.2fi\n", resultado.parteReal, resultado.parteImaginaria);
			}
			else if (compararCadena(argv[POS_OPERANDO], "-")){
				resultado = resta(numero1, numero2);
				printf("La resta es %.2f %.2fi\n", resultado.parteReal, resultado.parteImaginaria);
			}
			else if (compararCadena(argv[POS_OPERANDO], "*")){
				resultado = multiplicacion(numero1, numero2);
				printf("La multiplicacion es %.2f %.2fi\n", resultado.parteReal, resultado.parteImaginaria);
			}
			else if (compararCadena(argv[POS_OPERANDO], "/")){
				resultado = division(numero1, numero2);
				printf("La division es %.2f %.2fi\n", resultado.parteReal, resultado.parteImaginaria);
			}
			else {
				printf("El operando '%s' es incorrecto", argv[POS_OPERANDO]);
			}
		}
	}
}

int compararCadena(char *cadena1, char *cadena2){
	int comprobacion = 1;
	while ((*cadena1 != '\0') && (*cadena2 != '\0') && (*cadena1 == *cadena2)){
		cadena1++;
		cadena2++;
	}
	comprobacion = (*cadena1 == *cadena2);
	return comprobacion;
}

complejos_t suma(complejos_t numero1, complejos_t numero2){
	complejos_t resultado;
	resultado.parteReal = numero1.parteReal + numero2.parteReal;
	resultado.parteImaginaria = numero1.parteImaginaria + numero2.parteImaginaria;
	return resultado;
}

complejos_t resta(complejos_t numero1, complejos_t numero2){
	complejos_t resultado;
	resultado.parteReal = numero1.parteReal - numero2.parteReal;
	resultado.parteImaginaria = numero1.parteImaginaria - numero2.parteImaginaria;
	return resultado;
}

complejos_t multiplicacion(complejos_t numero1, complejos_t numero2){
	complejos_t resultado;
	resultado.parteReal = (numero1.parteReal * numero2.parteReal)-(numero1.parteImaginaria * numero2.parteImaginaria);
	resultado.parteImaginaria = (numero1.parteReal * numero2.parteImaginaria)+(numero1.parteImaginaria * numero2.parteReal);
	return resultado;
}

complejos_t division(complejos_t numero1, complejos_t numero2){
	complejos_t resultado;
	float denominador = ((numero2.parteReal * numero2.parteReal)+(numero2.parteImaginaria * numero2.parteImaginaria));
	resultado.parteReal = ((numero1.parteReal * numero2.parteReal)+(numero1.parteImaginaria * numero2.parteImaginaria))/denominador;
	resultado.parteImaginaria = ((numero1.parteImaginaria * numero2.parteReal)-(numero1.parteReal * numero2.parteImaginaria))/denominador;
	return resultado;
}