/*
Arboles
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_OPCIONES 3 //Opciones menu
#define TAM_MAX 100 //Cantidad maxima de arboles

typedef long long int int64;
typedef int int32;
typedef short int16;
typedef char byte;

typedef enum tipoArbol_e{
	pino=1, haya=2, roble=3, eucalipto=4
}tipoArbol_e;

typedef struct arbol_t{
	int64 numeroHojas;
	int32 numeroRamas;
	int16 numeroRaices;
	tipoArbol_e nombreArbol;
}arbol_t;

arbol_t crearArbol();
void mostrarArboles(arbol_t arbol[], int totalArboles);

int main (int argc, char **argv){
	arbol_t arbol[TAM_MAX];
	int opcion = 0, contadorArboles = 0;
	do {
		printf("Ingrese una opcion:\n1. Crear arbol.\n2. Mostrar Arbol.\n3. Salir.\n");
		scanf("%d", &opcion);
		while(getchar() != '\n'); // Limpiar el buffer
		switch (opcion){
			case 1: arbol[contadorArboles] = crearArbol(); contadorArboles++; break;
			case 2:
				if (contadorArboles){
					mostrarArboles(arbol, contadorArboles);
				}
				else{
					printf("No se han ingresado arboles.\n");
				}
			break;
			case 3: break;
			default: printf("'%d' no es una opcion correcta", opcion); break;
		}
	}while (opcion != NUM_OPCIONES);
}

arbol_t crearArbol(){
	arbol_t arbol;
	int salir = 0;
	while (!salir){
		printf("Ingrese el numero de hojas: ");
		scanf("%ld", &arbol.numeroHojas);
		while(getchar() != '\n'); // Limpiar el buffer
		printf("Ingrese el numero de ramas: ");
		scanf("%d", &arbol.numeroRamas);
		while(getchar() != '\n'); // Limpiar el buffer
		printf("Ingrese el numero de raices: ");
		scanf("%d", &arbol.numeroRaices);
		while(getchar() != '\n'); // Limpiar el buffer
		printf("Ingrese el tipo del arbol:\n1. Pino.\n2. Haya.\n3. Roble.\n4. Eucalipto.\n");
		scanf("%d", &arbol.nombreArbol);
		while(getchar() != '\n'); // Limpiar el buffer
		if (arbol.nombreArbol > 4 || arbol.nombreArbol < 1){
			printf("Error, opcion incorrecta. Ingrese los datos nuevamente.\n");
		}
		else {
			salir = 1;
		}
	}
	return arbol;
}

void mostrarArboles(arbol_t arbol[], int totalArboles){
	char* nombreArboles[] = {"Pino", "Haya", "Roble", "Eucalipto"};
	for (int i = 0; i < totalArboles; i++){
		printf("-------------------\n"); //Separador
		printf("Numero de hojas: %ld\n", arbol[i].numeroHojas);
		printf("Numero de ramas: %d\n", arbol[i].numeroRamas);
		printf("Numero de raices: %d\n", arbol[i].numeroRaices);
		printf("Nombre del arbol: %s\n", nombreArboles[arbol[i].nombreArbol - 1]);
		printf("-------------------\n"); //Separador
	}
}