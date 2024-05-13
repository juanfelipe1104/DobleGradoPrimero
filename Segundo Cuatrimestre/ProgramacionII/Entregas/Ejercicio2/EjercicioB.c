/*
Listas de grabaciones
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_OPCIONES 5
#define LONG_FECHA 10

typedef enum formato_e{
	wav = 0, mp3 = 1, ogg = 2
}formato_e;

const char *nombreFormatos[] = {"WAV", "MP3", "OGG"};

typedef struct estacion_t{
	char *nombre;
	double latitud;
	double longitud;
}estacion_t;

typedef struct listaEstaciones_t{
	estacion_t *estacion;
	int numEstaciones;
	int tamMax;
}listaEstaciones_t;

typedef struct grabacion_t{
	char *nombre;
	char *fecha;
	formato_e formato;
	char *estacionAsignadaAux;
	estacion_t *estacionAsignada;
}grabacion_t;

typedef struct listaGrabaciones_t{
	grabacion_t *grabacion;
	int numGrabaciones;
	int tamMax;
}listaGrabaciones_t;

grabacion_t introducirGrabacion();
estacion_t introducirEstacion();
void asignarEstacion(grabacion_t *grabacion, listaEstaciones_t estaciones);
void imprimirEstaciones(listaGrabaciones_t grabaciones, listaEstaciones_t estaciones);
int comparaCadenas(char *cadena1, char *cadena2);
char *leeLineaDinamica();
int calcularTamanoCadena(char *cadena);

int main (int argc, char **argv){
	listaEstaciones_t estaciones = {.estacion = NULL, .numEstaciones = 0, .tamMax = 0}; 
	listaGrabaciones_t grabaciones = {.grabacion = NULL, .numGrabaciones = 0, .tamMax = 0};
	int opcion = 0;
	while (opcion != MAX_OPCIONES){
		printf("1. Introducir datos de un archivo de grabacion.\n2. Introducir datos de una estacion de grabacion.\n3. Asignar grabaciones a estaciones de grabacion.\n4. Mostrar datos de estaciones.\n5. Salir.\n");
		scanf("%d", &opcion);
		while(getchar() != '\n');
		switch(opcion){
			case 1:
				if (grabaciones.numGrabaciones == grabaciones.tamMax){
					grabaciones.tamMax++;
					grabaciones.grabacion = (grabacion_t*)realloc(grabaciones.grabacion, sizeof(grabacion_t)*grabaciones.tamMax);
				}
				grabaciones.grabacion[grabaciones.numGrabaciones] = introducirGrabacion();
				grabaciones.numGrabaciones++;
			break;
			case 2:
				if(estaciones.numEstaciones == estaciones.tamMax){
					estaciones.tamMax++;
					estaciones.estacion = (estacion_t*)realloc(estaciones.estacion, sizeof(estacion_t)*estaciones.tamMax);
				}
				estaciones.estacion[estaciones.numEstaciones] = introducirEstacion();
				estaciones.numEstaciones++;
			break;
			case 3:
				if (grabaciones.numGrabaciones && estaciones.numEstaciones){
					for (int i = 0; i < grabaciones.numGrabaciones; i++){
						if (grabaciones.grabacion[i].estacionAsignadaAux == NULL){
							asignarEstacion(&grabaciones.grabacion[i], estaciones);
						}
					}
				}
				else {
					printf("Error, no existen grabaciones o estaciones.\n");
				}
			break;
			case 4:
				imprimirEstaciones(grabaciones, estaciones);
			break;
			case 5:
				if (estaciones.numEstaciones){
					for (int i = 0; i < estaciones.numEstaciones; i++){
						free(estaciones.estacion[i].nombre);
						estaciones.estacion[i].nombre = NULL;
					}
					free(estaciones.estacion);
					estaciones.estacion = NULL;
				}
				if (grabaciones.numGrabaciones){
					for (int i = 0; i < grabaciones.numGrabaciones; i++){
						free(grabaciones.grabacion[i].nombre);
						grabaciones.grabacion[i].nombre = NULL;
						free(grabaciones.grabacion[i].fecha);
						grabaciones.grabacion[i].fecha = NULL;
						free(grabaciones.grabacion[i].estacionAsignadaAux);
						grabaciones.grabacion[i].estacionAsignadaAux = NULL;
					}
					free(grabaciones.grabacion);
					grabaciones.grabacion = NULL;
				}
			break;
		}
	}
}

grabacion_t introducirGrabacion(){
	grabacion_t grabacion = {.estacionAsignadaAux = NULL};
	int auxiliar = 0; //Auxiliar para comprobar que el formato es correcto al ser un enumerado
	int auxiliar2 = 0; //Auxiliar para calcular la longitud de la cadena fecha
	printf("Introduzca nombre de fichero: ");
	grabacion.nombre = leeLineaDinamica();
	do {
		printf("Introduzca fecha en formato 'DD/MM/AAAA': ");
		grabacion.fecha = leeLineaDinamica();
		auxiliar2 = calcularTamanoCadena(grabacion.fecha);
		if ((auxiliar2 != LONG_FECHA)||(grabacion.fecha[2] != '/')||(grabacion.fecha[5]!= '/')){
			printf("Error: formato de fecha incorrecto.\n");
		}
	}while ((auxiliar2 != LONG_FECHA)||(grabacion.fecha[2] != '/')||(grabacion.fecha[5]!= '/'));
	do {
		printf("Introduzca formato:\n0. WAV\n1. MP3\n2. OGG\n");
		scanf("%d", &auxiliar);
		if (auxiliar >= 0 && auxiliar <= 2){
			grabacion.formato = auxiliar;
		}
		else {
			printf("Error, valor '%d' no valido.\n", auxiliar);
		}
	}while(auxiliar < 0 || auxiliar > 2);
	return grabacion;
}

estacion_t introducirEstacion(){
	estacion_t estacion;
	printf("Introduzca nombre de estacion: ");
	estacion.nombre = leeLineaDinamica();
	printf("Introduzca coordenadas en formato 'latitud longitud': ");
	scanf("%lf %lf", &estacion.latitud, &estacion.longitud);
	while(getchar() != '\n'); //Limpiar el buffer
	return estacion;
}

void asignarEstacion(grabacion_t *grabacion, listaEstaciones_t estaciones){
	int error = 0;
	int continuar = 1;
	printf("Nombre archivo: %s\n", grabacion->nombre);
	printf("Fecha de grabacion: %s\n", grabacion->fecha);
	printf("Tipo: %s\n", nombreFormatos[grabacion->formato]);
	printf("Estacion no asignada.\nIntroduzca nombre de estacion: ");
	grabacion->estacionAsignadaAux = leeLineaDinamica();
	for (int i = 0; i < estaciones.numEstaciones && continuar; i++){
		if (comparaCadenas(grabacion->estacionAsignadaAux, estaciones.estacion[i].nombre)){
			grabacion->estacionAsignada = &estaciones.estacion[i];
			continuar = 0;
			error = 0;
		}
		else {
			error = 1;
		}
	}
	if (error){
		printf("Error: Estacion no encontrada.\n");
		grabacion->estacionAsignadaAux = NULL;
	}
}

void imprimirEstaciones(listaGrabaciones_t grabaciones, listaEstaciones_t estaciones){
	int contadorAux = 0; //Auxiliar para indicar el numero de la grabacion (estetico)
	for (int i = 0; i < estaciones.numEstaciones; i++){
		printf("Nombre estacion: %s\n", estaciones.estacion[i].nombre);
		printf("Latitud: %lf\n", estaciones.estacion[i].latitud);
		printf("Longitud: %lf\n", estaciones.estacion[i].longitud);
		contadorAux = 0;
		for (int j = 0; j < grabaciones.numGrabaciones; j++){
			if (comparaCadenas(estaciones.estacion[i].nombre, grabaciones.grabacion[j].estacionAsignadaAux)){
				printf("--- Grabacion %d ---\n", contadorAux);
				contadorAux++;
				printf("Nombre archivo: %s\n", grabaciones.grabacion[j].nombre);
				printf("Fecha de grabacion: %s\n", grabaciones.grabacion[j].fecha);
				printf("Tipo: %s\n", nombreFormatos[grabaciones.grabacion[j].formato]);
			}
		}
	}
}

int comparaCadenas(char *cadena1, char *cadena2){
	int resultado = 1;
	while((*cadena1 != '\0')&&(*cadena2 != '\0')&&(*cadena1 == *cadena2)){
		cadena1++;
		cadena2++;
	}
	resultado = *cadena1 == *cadena2;
	return resultado;
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
	if (numLetrasLeidas == numLetrasMax){
		numLetrasMax++;
		letras = (char*)realloc(letras, sizeof(char)*numLetrasMax);
	}
	letras[numLetrasLeidas] = '\0';
	return letras;
}

int calcularTamanoCadena(char *cadena){
	int tamano = 0;
	while (*cadena != '\0'){
		if (*cadena != '\0'){
			tamano++;
		}
		cadena++;
	}
	return tamano;
}