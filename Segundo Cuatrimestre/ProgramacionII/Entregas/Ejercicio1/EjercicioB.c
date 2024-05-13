/*
Batalla de gladiadores
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM_MAX 10
#define NUM_GLADIADORES 2
#define MIN_MAX_ARG 3

typedef struct gladiador_t{
	char nombre[TAM_MAX];
	char arma[TAM_MAX];
	int fuerza;
	int salud;
}gladiador_t;

gladiador_t incializarGladiador();
gladiador_t obtenerDatosSinComas(char *argumento);
int compararCadena(char *cadena1, char *cadena2);
void imprimirGladiador(gladiador_t gladiador);

int main (int argc, char **argv){
	gladiador_t gladiadores[NUM_GLADIADORES];
	int opcionJugador = 0, opcionMaquina = 0, salir = 0;
	if (argc != MIN_MAX_ARG){
		printf("Error, el minimo y maximo numero de argumentos es 2.\n");
	}
	else {
		for (int i = 0; i < NUM_GLADIADORES; i++){
			gladiadores[i] = incializarGladiador();
		}
		srand(getpid());
		for (int i = 1; i < argc; i++){
			gladiadores[i-1] = obtenerDatosSinComas(argv[i]);
		}
		for (int i = 0; i < NUM_GLADIADORES; i++){
			if (compararCadena(gladiadores[i].arma, "lanza")){
				gladiadores[i].fuerza *= 2; //El doble de fuerza si el arma es lanza
			}
		}
		while (!salir){
			printf("Turno de %s:\n1. Atacar\n2. Defender.\nSelecciona una opcion: ", gladiadores[0].nombre);
			scanf("%d", &opcionJugador);
			while(getchar() != '\n'); // Limpiar el buffer
			opcionMaquina = rand()%2; //0 para defenderse, 1 para atacar
			if (gladiadores[0].salud > 0){
				switch (opcionJugador){
					case 1:
						if (opcionMaquina){
							printf("Atacaste a %s y le hiciste %d de danio!\n", gladiadores[1].nombre, gladiadores[0].fuerza);
							gladiadores[1].salud -= gladiadores[0].fuerza;
							if (gladiadores[1].salud > 0){
								printf("Turno de %s:\n%s te ataca y te hace %d de danio!\n", gladiadores[1].nombre, gladiadores[1].nombre, gladiadores[1].fuerza);
								gladiadores[0].salud -= gladiadores[1].fuerza;
							}
							else {
								salir = 1; //La maquina ha muerto
							}
						}
						else {
							printf("%s se ha defendido.\n", gladiadores[1].nombre);
						}
					break;
					case 2:
						printf("Te has defendido.\n");
					break;
					default:
						printf("La opcion '%d' no es correcta.\n", opcionJugador);
				}
			}
			else {
				salir = 1; //El jugador ha muerto
			}
		}
		if (gladiadores[0].salud <= 0){
			printf("Has perdido la batalla. El ganador es:\n");
			imprimirGladiador(gladiadores[1]);
		}
		else if (gladiadores[1].salud <= 0){
			printf("Has ganado la batalla!\n");
			imprimirGladiador(gladiadores[0]);
		}
		else {
			printf("Empate!\n");
			imprimirGladiador(gladiadores[0]);
			imprimirGladiador(gladiadores[1]);
		}
	}
}

gladiador_t incializarGladiador(){
	gladiador_t gladiador = {
		.nombre = {'\0'},
		.arma = {'\0'},
		.fuerza = 0,
		.salud = 100
	};
}

gladiador_t obtenerDatosSinComas(char *argumento){
	int existeComa = 0, contador = 0;
	char fuerzaAuxiliar[TAM_MAX] = {'\0'};
	gladiador_t gladiador = {.salud = 100};
	while (*argumento != '\0'){
		if (!existeComa){
			if (*argumento == ','){
				existeComa++;
				contador = 0;
			}
			else{
				if (contador < TAM_MAX){
					gladiador.nombre[contador] = *argumento;
				}
				contador++;
			}
		}
		else if (existeComa == 1){
			if (*argumento == ','){
				existeComa++;
				gladiador.fuerza = atoi(fuerzaAuxiliar);
				contador = 0;
			}
			else {
				fuerzaAuxiliar[contador] = *argumento;
				contador++;
			}
		}
		else {
			gladiador.arma[contador] = *argumento;
			contador++;
		}
		argumento++;
	}
	return gladiador;
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

void imprimirGladiador(gladiador_t gladiador){
	printf("Nombre: %s\n", gladiador.nombre);
	printf("Fuerza: %d\n", gladiador.fuerza);
	printf("Arma: %s\n", gladiador.arma);
	printf("Salud: %d\n", gladiador.salud);
}