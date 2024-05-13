/*
Contador de caracteres mediante parametros
*/

#include <stdio.h>
#include <stdlib.h>

#define MIN_PARAMETROS 2
#define MAX_PARAMETROS 11
#define TAM_MAX 40

int main (int argc, char **argv){
	int contadores[MAX_PARAMETROS] = {0}; //Array de contadores
	char texto[TAM_MAX] = {'\0'}; //Variable auxiliar para almacenar el texto introducido
	int opcion = -1; //Variable para el menu
	if ((argc < MIN_PARAMETROS)||(argc > MAX_PARAMETROS)){
		printf("Error, el numero de parametros es incorrecto.(Minimo 1 y maximo 10)\n");
	}
	else {
		while (opcion){
			printf("------------\n");
			printf("Para introducir una frase pulse 1\nPara mostrar el resultado pulse 2.\nPara salir pulse 0.\n");
			printf("------------\n");
			scanf("%d", &opcion);
			while(getchar() != '\n'); // Limpiar el buffer
			switch (opcion){
				case 1:
					printf("Introduce el texto: ");
					scanf("%40[^\n]s", texto);
					while(getchar() != '\n'); // Limpiar el buffer
					for (int i = 1; i < argc; i++){
						for (int j = 0; texto[j] != '\0'; j++){
							if (argv[i][0] == texto[j]){
								contadores[i]++;
							}
						}
					}
				break;
				case 2:
					for (int i = 1; i < argc; i++){
						printf("%c			%d\n", argv[i][0], contadores[i]);
					}
				break;
				case 0:
					printf("Este programa ha terminado...\n");
				break;
				default:
					printf("La opcion '%d' es incorrecta.\n", opcion);
				break;
			}
		}
	}
}