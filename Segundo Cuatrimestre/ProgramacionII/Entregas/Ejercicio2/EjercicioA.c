/*
Busca minas
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PARAMETROS 2

typedef enum boolean_e{
	falso = 0, verdadero = 1
}boolean_e;

typedef struct coordenadas_t{
	int fila;
	int columna;
}coordenadas_t;

typedef struct intento_t{
	coordenadas_t coordenas;
	boolean_e bombaEncontrada;
	boolean_e columnaCorrecta;
	boolean_e filaCorrecta;
}intento_t;

typedef struct listaIntentos_t {
	intento_t *intentos;
	int intentosMax;
	int numIntentos;
}listaIntentos_t;

char **crearMatriz(int numFilasColumnas);
void rellenaMatriz(char **matriz, char valor, int numFilasColumnas);
intento_t pedirIntento();
void testeaIntento(char **matriz, intento_t* nuevoIntento, coordenadas_t coordenadasBomba);
void insertaIntentoEnLista(listaIntentos_t *intentos, intento_t nuevoIntento);
void imprimirMatriz(char **matriz, int numFilasColumnas);
void imprimirIntentos(listaIntentos_t intentos);

int main (int argc, char **argv){
	char **matriz = NULL;
	char *error = NULL;
	int filasColumnas = 0, opcion = 0;
	boolean_e salir = falso;
	coordenadas_t bomba;
	listaIntentos_t intentosJugador = {.intentos = NULL, .numIntentos = 0, .intentosMax = 0};
	intento_t intentoJugador = {.coordenas.fila = 0, .coordenas.columna = 0, .bombaEncontrada = falso, .columnaCorrecta = falso, .filaCorrecta = falso};
	if (argc != MAX_PARAMETROS){
		printf("El minimo y maximo de parametros es 1.");
	}
	else {
		filasColumnas = (int)strtol(argv[1], &error, 10);
		if (*error != '\0' || !filasColumnas){
			printf("El parametro '%s' ingresado no es un numero o es 0", argv[1]);
		}
		else {
			srand(getpid());
			matriz = crearMatriz(filasColumnas);
			rellenaMatriz(matriz, '?', filasColumnas);
			bomba.fila = rand()%filasColumnas;
			bomba.columna = rand()%filasColumnas;
			while(!salir){
				printf("Introduzca una opcion\nPara buscar pulse 1\nPara visualizar intentos pulse 2\nPara ver la matriz 3\nPara salir pulse 0\n");
				printf("***********************\n");
				scanf("%d", &opcion);
				while(getchar() != '\n'); //Limpiar el buffer
				switch(opcion){
					case 0: salir = verdadero; break;
					case 1:
						intentoJugador = pedirIntento();
						if ((intentoJugador.coordenas.fila >= filasColumnas)||(intentoJugador.coordenas.columna >= filasColumnas)){
							printf("La posicion [%d][%d] no existe.\n", intentoJugador.coordenas.fila, intentoJugador.coordenas.columna);
						}
						else {
							testeaIntento(matriz, &intentoJugador, bomba);
							if (intentoJugador.bombaEncontrada){
								salir = verdadero;
								printf("**********BOOM*********\n");
							}
							else {
								insertaIntentoEnLista(&intentosJugador, intentoJugador);
								printf("***********************\n");
							}
						}
					break;
					case 2:
						imprimirIntentos(intentosJugador);
					break;
					case 3:
						imprimirMatriz(matriz, filasColumnas);
					break;
					default:
						printf("La opcion '%d' no es correcta.\n", opcion);
					break;
				}
			}
			for (int i = 0; i < filasColumnas; i++){
				free(matriz[i]);
				matriz[i] = NULL;
			}
			free(matriz);
			matriz = NULL;
			free(intentosJugador.intentos);
			intentosJugador.intentos = NULL;
		}
	}
}

char **crearMatriz(int numFilasColumnas){
	char **matriz = NULL;
	matriz = (char**)malloc(sizeof(char*) * numFilasColumnas);
	for (int i = 0; i < numFilasColumnas; i++){
		matriz[i] = (char*)malloc(sizeof(char)*numFilasColumnas);
	}
	return matriz;
}

void rellenaMatriz(char **matriz, char valor, int numFilasColumnas){
	for (int i = 0; i < numFilasColumnas; i++){
		for (int j = 0; j < numFilasColumnas; j++){
			matriz[i][j] = valor;
		}
	}
}

intento_t pedirIntento(){
	intento_t intento = {.bombaEncontrada = falso, .columnaCorrecta = falso, .filaCorrecta = falso};
	printf("Introduce fila y columna: ");
	scanf("%d %d", &intento.coordenas.fila, &intento.coordenas.columna);
	while(getchar() != '\n'); //Limpiar el buffer
	return intento;
}

void testeaIntento(char **matriz, intento_t *nuevoIntento, coordenadas_t coordenadasBomba){
	if ((coordenadasBomba.fila == nuevoIntento->coordenas.fila) && (coordenadasBomba.columna == nuevoIntento->coordenas.columna)){
		nuevoIntento->bombaEncontrada = verdadero;
	}
	else if (coordenadasBomba.fila == nuevoIntento->coordenas.fila){
		nuevoIntento->filaCorrecta = verdadero;
		matriz[nuevoIntento->coordenas.fila][nuevoIntento->coordenas.columna] = 'O';
	}
	else if (coordenadasBomba.columna == nuevoIntento->coordenas.columna){
		nuevoIntento->columnaCorrecta = verdadero;
		matriz[nuevoIntento->coordenas.fila][nuevoIntento->coordenas.columna] = 'O';
	}
	else {
		matriz[nuevoIntento->coordenas.fila][nuevoIntento->coordenas.columna] = 'O';
	}
}

void insertaIntentoEnLista(listaIntentos_t *intentos, intento_t nuevoIntento){
	if (intentos->intentosMax == intentos->numIntentos){
		intentos->intentosMax++;
		intentos->intentos = (intento_t*)realloc(intentos->intentos, sizeof(intento_t)*intentos->intentosMax);
	}
	intentos->intentos[intentos->numIntentos] = nuevoIntento; 
	intentos->numIntentos++;
}

void imprimirMatriz(char **matriz, int numFilasColumnas){
	for (int i = 0; i < numFilasColumnas; i++){
		for (int j = 0; j < numFilasColumnas; j++){
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("***********************\n");
}

void imprimirIntentos(listaIntentos_t intentos){
	if (intentos.numIntentos){
		for (int i = 0; i < intentos.numIntentos; i++){
			printf("Intento %d\n", i);
			printf("[%d][%d]", intentos.intentos[i].coordenas.fila, intentos.intentos[i].coordenas.columna);
			if (intentos.intentos[i].filaCorrecta){
				printf("...en esa fila.\n");
			}
			else if (intentos.intentos[i].columnaCorrecta){
				printf("...en esa columna.\n");
			}
			else {
				printf("...no fila ni columna.\n");
			}
		}
	}
	else {
		printf("No se han producido intentos.\n");
	}
	printf("***********************\n");
}