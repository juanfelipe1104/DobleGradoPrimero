/*
Torneo de Padel
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PAREJAS 4
#define MAX_PARTIDOS 6
#define MAX_JORNADAS 3
#define MIN_MAX_ARG 9
#define TAM_MAX 10

typedef struct parejas_t{
	int partidosGanados;
	char jugador1[TAM_MAX];
	char jugador2[TAM_MAX];
}parejas_t;

typedef struct partidos_t{
	int setsGanadosPareja1;
	int setsGanadosPareja2;
	parejas_t *pareja1;
	parejas_t *pareja2;
}partidos_t;

typedef struct jornadas_t{
	partidos_t *partido1;
	partidos_t *partido2;
}jornadas_t;

parejas_t obtenerNombres(char *argumento1, char *argumento2);
void introducirResultados(jornadas_t *jornadas, partidos_t *partidos, parejas_t parejas[], int numeroJornada);
void imprimirJornadas(jornadas_t jornadas[], int maxJornadas);
parejas_t* buscarGanador(jornadas_t jornadas[], int maxJornadas);

int main (int argc, char **argv){
	int opcion = -1, numeroJornada = 0;
	int contador = 1; //contador auxiliar para argv
	parejas_t parejas[MAX_PAREJAS];
	partidos_t partidos[MAX_PARTIDOS];
	jornadas_t jornadas[MAX_JORNADAS];
	if (argc != MIN_MAX_ARG){
		printf("Error, el minimo y maximo numero de parametros es 8.\n");
	}
	else {
		for (int i = 0; i < MAX_PAREJAS; i++){
			parejas[i] = obtenerNombres(argv[contador], argv[contador+1]);
			contador += 2;
		}
		while (opcion){
			printf("1.Introducir resultados.\n2. Mostrar resultados.\n3.Mostrar ganador.\n0. Salir\n");
			scanf("%d", &opcion);
			while(getchar() != '\n'); // Limpiar el buffer
			switch (opcion){
				case 1:
					if (numeroJornada < MAX_JORNADAS){
						printf("Resultados de la jornada %d.\n", numeroJornada+1);
						introducirResultados(jornadas, partidos, parejas, numeroJornada);
						if (jornadas[numeroJornada].partido1->setsGanadosPareja1 > jornadas[numeroJornada].partido1->setsGanadosPareja2){
							jornadas[numeroJornada].partido1->pareja1->partidosGanados++;
						}
						else {
							jornadas[numeroJornada].partido1->pareja2->partidosGanados++;
						}
						if (jornadas[numeroJornada].partido2->setsGanadosPareja1 > jornadas[numeroJornada].partido2->setsGanadosPareja2){
							jornadas[numeroJornada].partido2->pareja1->partidosGanados++;
						}
						else {
							jornadas[numeroJornada].partido2->pareja2->partidosGanados++;
						}
						numeroJornada++;
					}
					else {
						printf("Maximo numero de jornadas ingresadas.\n");
					}
				break;
				case 2:
					if (numeroJornada){
						imprimirJornadas(jornadas, numeroJornada);
					}
					else {
						printf("No se han introducido jornadas");
					}
				break;
				case 3:
					if (numeroJornada){
						printf("**********\n");
						printf("%s - %s\n", buscarGanador(jornadas, numeroJornada)->jugador1, buscarGanador(jornadas, numeroJornada)->jugador2);
						printf("**********\n");
					}
					else {
						printf("No se han introducido jornadas");
					}
				break;
				case 0: break;
				default:
					printf("La opcion '%d' es incorrecta.\n", opcion);
				break;
			}
		}
	}
}

parejas_t obtenerNombres(char *argumento1, char *argumento2){
	parejas_t pareja;
	int contador = 0;
	while ((*argumento1 != '\0')&&(contador < TAM_MAX)){
		pareja.jugador1[contador] = argumento1[contador];
		contador++;
	}
	contador = 0;
	while ((*argumento2 != '\0')&&(contador < TAM_MAX)){
		pareja.jugador2[contador] = argumento2[contador];
		contador++;
	}
	return pareja;
}

void introducirResultados(jornadas_t *jornadas, partidos_t *partidos, parejas_t parejas[], int numeroJornada){
	int contadorParejas = 0, contadorPartidos = 0;
	int posicionesPartidos[] = {0, 1, 2, 3, 0, 2, 3, 1, 0, 3, 1, 2};
	switch (numeroJornada){
		case 0:
			for (int i = 0; i < 2; i++){
				printf("%s-%s -- %s-%s: ", parejas[posicionesPartidos[contadorParejas]].jugador1, parejas[posicionesPartidos[contadorParejas]].jugador2,
				parejas[posicionesPartidos[contadorParejas+1]].jugador1, parejas[posicionesPartidos[contadorParejas+1]].jugador2);
				scanf("%d %d", &partidos[i].setsGanadosPareja1, &partidos[i].setsGanadosPareja2);
				while(getchar() != '\n'); // Limpiar el buffer
				partidos[i].pareja1 = &parejas[posicionesPartidos[contadorParejas]];
				partidos[i].pareja2 = &parejas[posicionesPartidos[contadorParejas+1]];
				contadorParejas += 2;
			}
			jornadas[numeroJornada].partido1 = &partidos[contadorPartidos];
			jornadas[numeroJornada].partido2 = &partidos[contadorPartidos+1];
		break;
		case 1:
			contadorParejas = 4;
			contadorPartidos = 2;
			for (int i = 2; i < 4; i++){
				printf("%s-%s -- %s-%s: ", parejas[posicionesPartidos[contadorParejas]].jugador1, parejas[posicionesPartidos[contadorParejas]].jugador2,
				parejas[posicionesPartidos[contadorParejas+1]].jugador1, parejas[posicionesPartidos[contadorParejas+1]].jugador2);
				scanf("%d %d", &partidos[i].setsGanadosPareja1, &partidos[i].setsGanadosPareja2);
				while(getchar() != '\n'); // Limpiar el buffer
				partidos[i].pareja1 = &parejas[posicionesPartidos[contadorParejas]];
				partidos[i].pareja2 = &parejas[posicionesPartidos[contadorParejas+1]];
				contadorParejas += 2;
			}
			jornadas[numeroJornada].partido1 = &partidos[contadorPartidos];
			jornadas[numeroJornada].partido2 = &partidos[contadorPartidos+1];
		break;
		case 2:
			contadorParejas = 8;
			contadorPartidos = 4;
			for (int i = 4; i < 6; i++){
				printf("%s-%s -- %s-%s: ", parejas[posicionesPartidos[contadorParejas]].jugador1, parejas[posicionesPartidos[contadorParejas]].jugador2,
				parejas[posicionesPartidos[contadorParejas+1]].jugador1, parejas[posicionesPartidos[contadorParejas+1]].jugador2);
				scanf("%d %d", &partidos[i].setsGanadosPareja1, &partidos[i].setsGanadosPareja2);
				while(getchar() != '\n'); // Limpiar el buffer
				partidos[i].pareja1 = &parejas[posicionesPartidos[contadorParejas]];
				partidos[i].pareja2 = &parejas[posicionesPartidos[contadorParejas+1]];
				contadorParejas += 2;
			}
			jornadas[numeroJornada].partido1 = &partidos[contadorPartidos];
			jornadas[numeroJornada].partido2 = &partidos[contadorPartidos+1];
		break;
	}
}

void imprimirJornadas(jornadas_t jornadas[], int maxJornadas){
	for (int i = 0; i < maxJornadas; i++){
		printf("%s-%s -- %s-%s: %d %d\n", jornadas[i].partido1->pareja1->jugador1, jornadas[i].partido1->pareja1->jugador2, jornadas[i].partido1->pareja2->jugador1,
		jornadas[i].partido1->pareja2->jugador2, jornadas[i].partido1->setsGanadosPareja1, jornadas[i].partido1->setsGanadosPareja2);
		printf("%s-%s -- %s-%s: %d %d\n", jornadas[i].partido2->pareja1->jugador1, jornadas[i].partido2->pareja1->jugador2, jornadas[i].partido2->pareja2->jugador1,
		jornadas[i].partido2->pareja2->jugador2, jornadas[i].partido2->setsGanadosPareja1, jornadas[i].partido2->setsGanadosPareja2);
	}
}

parejas_t* buscarGanador(jornadas_t jornadas[], int maxJornadas){
	parejas_t *parejaGanadora;
	for (int i = 0; i < maxJornadas; i++){
		if (jornadas[i].partido1->pareja1->partidosGanados > parejaGanadora->partidosGanados){
			parejaGanadora = jornadas[i].partido1->pareja1;
		}
		else if (jornadas[i].partido1->pareja2->partidosGanados > parejaGanadora->partidosGanados){
			parejaGanadora = jornadas[i].partido1->pareja2;
		}
		else if (jornadas[i].partido2->pareja1->partidosGanados > parejaGanadora->partidosGanados){
			parejaGanadora = jornadas[i].partido2->pareja1;
		}
		else if (jornadas[i].partido2->pareja2->partidosGanados > parejaGanadora->partidosGanados){
			parejaGanadora = jornadas[i].partido2->pareja2;
		}
	}
	return parejaGanadora;
}