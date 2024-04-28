/*
Gestion vehiculos
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_OPCIONES 5

typedef struct moto_t{
	char *matricula;
	float cilindro;
	float peso;
}moto_t;

typedef struct coche_t{
	char *matricula;
	char *modelo;
	float tiempo;
}coche_t;

typedef struct listaMoto_t{
	moto_t *motos;
	int numMotos;
	int tamMax;
}listaMoto_t;

typedef struct listaCoche_t{
	coche_t *coches;
	int numCoches;
	int tamMax;
}listaCoche_t;

moto_t pedirMoto();
coche_t pedirCoche();
void imprimirMotos(listaMoto_t lista);
void imprimirCoches(listaCoche_t lista);
char *leeLineaDinamica();

int main (int argc, char **argv){
	listaMoto_t listaMotos = {.motos = NULL, .numMotos = 0, .tamMax = 0};
	listaCoche_t listaCoches = {.coches = NULL, .numCoches = 0, .tamMax = 0};
	int opcion = 0;
	while(opcion != MAX_OPCIONES){
		printf("1. Ingresar moto.\n2. Ingresar coche.\n3. Mostrar motos.\n4. Mostrar coches.\n5. Salir.\n");
		scanf("%d", &opcion);
		while(getchar() != '\n'); //Limpiar el buffer
		switch (opcion){
			case 1:
				if (listaMotos.numMotos == listaMotos.tamMax){
					listaMotos.tamMax++;
					listaMotos.motos = (moto_t*)realloc(listaMotos.motos, sizeof(moto_t)*listaMotos.tamMax);
				}
				listaMotos.motos[listaMotos.numMotos] = pedirMoto();
				listaMotos.numMotos++;
			break;
			case 2:
				if (listaCoches.numCoches == listaCoches.tamMax){
					listaCoches.tamMax++;
					listaCoches.coches = (coche_t*)realloc(listaCoches.coches, sizeof(coche_t)*listaCoches.tamMax);
				}
				listaCoches.coches[listaCoches.numCoches] = pedirCoche();
				listaCoches.numCoches++;
			break;
			case 3:
				if (listaMotos.numMotos){
					imprimirMotos(listaMotos);
				}
				else {
					printf("No se han ingresado motos.\n");
				}
			break;
			case 4:
				if (listaCoches.numCoches){
					imprimirCoches(listaCoches);
				}
				else {
					printf("No se han ingresado coches.\n");
				}
			break;
			case 5:
				if (listaCoches.numCoches){
					for (int i = 0; i < listaCoches.numCoches; i++){
						free(listaCoches.coches[i].matricula);
						listaCoches.coches[i].matricula = NULL;
						free(listaCoches.coches[i].modelo);
						listaCoches.coches[i].modelo = NULL;
					}
					free(listaCoches.coches);
					listaCoches.coches = NULL;
				}
				if (listaMotos.numMotos){
					for (int i = 0; i < listaMotos.numMotos; i++){
						free(listaMotos.motos[i].matricula);
						listaMotos.motos[i].matricula = NULL;
					}
					free(listaMotos.motos);
					listaMotos.motos = NULL;
				}
			break;
			default:
				printf("La opcion '%d' es incorrecta.\n", opcion);
			break;
		}
	}
}

moto_t pedirMoto(){
	moto_t moto;
	printf("Introduzca matricula: ");
	moto.matricula = leeLineaDinamica();
	printf("Introduzca cilindrada: ");
	scanf("%f", &moto.cilindro);
	while(getchar() != '\n'); //Limpiar el buffer
	printf("Introduzca peso: ");
	scanf("%f", &moto.peso);
	while(getchar() != '\n'); //Limpiar el buffer
	return moto;
}

coche_t pedirCoche(){
	coche_t coche;
	printf("Introduzca matricula: ");
	coche.matricula = leeLineaDinamica();
	printf("Introduzca modelo: ");
	coche.modelo = leeLineaDinamica();
	printf("Introduzca tiempo: ");
	scanf("%f", &coche.tiempo);
	while(getchar() != '\n'); //Limpiar el buffer
	return coche;
}

void imprimirMotos(listaMoto_t lista){
	for (int i = 0; i < lista.numMotos; i++){
		printf("------------\n");
		printf("Moto %d\n", i+1);
		printf("Matricula: %s\n", lista.motos[i].matricula);
		printf("Cilindros: %.2f\n", lista.motos[i].cilindro);
		printf("Peso: %.2f\n", lista.motos[i].peso);
		printf("------------\n");
	}
}

void imprimirCoches(listaCoche_t lista){
	for (int i = 0; i < lista.numCoches; i++){
		printf("------------\n");
		printf("Coche %d\n", i+1);
		printf("Matricula: %s\n", lista.coches[i].matricula);
		printf("Modelo: %s\n", lista.coches[i].modelo);
		printf("Tiempo: %.2f\n", lista.coches[i].tiempo);
		printf("------------\n");
	}
}

char *leeLineaDinamica(){
	char *letras = NULL, ultimaLetraLeida = '\0';
	int numLetrasLeidas = 0, numLetrasMax = 0;
	while(ultimaLetraLeida != '\n'){
		ultimaLetraLeida = getchar();
		if (numLetrasLeidas == numLetrasMax){
			numLetrasMax++;
			letras = (char*)realloc(letras, sizeof(char)*numLetrasMax);
		}
		if (ultimaLetraLeida != '\n'){
			letras[numLetrasLeidas] = ultimaLetraLeida;
			numLetrasLeidas++;
		}
	}
	letras[numLetrasLeidas] = '\0';
	return letras;
}