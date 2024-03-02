/*
Calculadora mediante parametros
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARG 4
#define TAM_MAX 50

int compararCadena(char *cadena1, char *cadena2);
void obtenerIgual(char *palabra, char *cadena, char *valor);
float calcularOperacion(float a, float b, char operacion);

int main (int argc, char **argv){
	int comprobacion = 1; //Variable booleana
	char palabra[TAM_MAX] = {'\0'};
	char valor[TAM_MAX] = {'\0'};
	char operacion = '\0';
	float operando1 = 0, operando2 = 0, resultado = 0;
	// Minimo y maximo 3 argumentos
	if (argc != MAX_ARG){
		printf("Error, minimo y maximo 3 argumentos.\nVerifique que introduce OP1=operando OP2=operando OPERACION=operacion\n");
	}
	else {
		for (int i = 0; i < 3; i++){
			obtenerIgual(argv[i+1], palabra, valor);
			if (compararCadena(palabra, "OP1")){
				operando1 = atof(valor);
			}
			else if(compararCadena(palabra, "OP2")){
				operando2 = atof(valor);
			}
			else if(compararCadena(palabra, "OPERACION")){
				operacion = valor[0];
			}
			else {
				printf("Error, argumento '%s' no valido\n", palabra);
				comprobacion = 0;
			}
		}
		// Añado a la correcion de clase una comprobacion cuando un argumento es erroneo para no realizar el calculo del resultado
		if (comprobacion){
			resultado = calcularOperacion(operando1, operando2, operacion);
			printf("El resultado obtenido sera: %.2f\n", resultado);
		}
	}
}

int compararCadena(char *cadena1, char *cadena2){
	int resultado = 1;
	while ((*cadena1 != '\0') && (*cadena2 != '\0')&&(*cadena1 == *cadena2)){
		cadena1++;
		cadena2++;
	}
	resultado = (*cadena1 == *cadena2);
	return resultado;
}

void obtenerIgual(char *palabra, char *cadena, char *valor){
	int comprobacionIgual = 0; //Variable booleana
	while (*palabra != '\0'){
		if (comprobacionIgual){
			*valor = *palabra;
			valor++;
		}
		else {
			*cadena = *palabra;
			cadena++;
		}
		if (*palabra == '='){
			comprobacionIgual = 1;
			cadena--;
			*cadena = '\0';
		}
		palabra++;
	}
}

float calcularOperacion(float a, float b, char operacion){
	switch (operacion){
		case 's': //Suma
			return a + b;
		break;
		case 'r': //Resta
			return a - b;
		break;
		case 'm': //Multiplicacion
			return a * b;
		break;
		case 'd': //Division
			return a / b;
		break;
	}
}