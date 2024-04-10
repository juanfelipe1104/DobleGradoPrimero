/*
Agenda
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *leeLineaDinamica();

typedef struct datosPersona_t{
	char *nombre;
	char *apellido;
	char *telefono;
}datosPersona_t;

typedef struct agenda_t{
	datosPersona_t *personas;
	int tamMax;
	int numPersonas;
}agenda_t;

char *leeLineaDinamica();
datosPersona_t pedirDatos();
void salvarDatos(char *nombreFichero, agenda_t agenda);

int main (int argc, char **argv){
	agenda_t agenda = {.personas = NULL, .tamMax = 0, .numPersonas = 0};
	int salir = 0, opcion = 0;
	while (!salir){
		printf("1. Ingresar datos.\n2. Salir.\n");
		scanf("%d", &opcion);
		while(getchar() != '\n'); //Limpiar el buffer
		switch(opcion){
			case 1:
				if (agenda.tamMax == agenda.numPersonas){
					agenda.tamMax++;
					agenda.personas = (datosPersona_t*)realloc(agenda.personas, sizeof(datosPersona_t)*agenda.tamMax);
				}
				agenda.personas[agenda.numPersonas] = pedirDatos();
				agenda.numPersonas++;
			break;
			case 2:
				salir = 1;
				for (int i = 0; i < agenda.numPersonas; i++){
					free(agenda.personas[i].nombre);
					agenda.personas[i].nombre = NULL;
					free(agenda.personas[i].apellido);
					agenda.personas[i].apellido = NULL;
					free(agenda.personas[i].telefono);
					agenda.personas[i].telefono = NULL;
				}
				free(agenda.personas);
				agenda.personas = NULL;
			break;
		}
	}
	salvarDatos("agenda.txt", agenda);
}

datosPersona_t pedirDatos(){
	datosPersona_t persona;
	printf("Ingrese nombre: ");
	persona.nombre = leeLineaDinamica();
	printf("Ingrese apellido: ");
	persona.apellido = leeLineaDinamica();
	printf("Ingrese el numero de telefono: ");
	persona.telefono = leeLineaDinamica();
	return persona;
}

void salvarDatos(char *nombreFichero, agenda_t agenda){
	FILE *fichero = NULL;
	fichero = fopen(nombreFichero, "wb");
	for (int i = 0; i < agenda.numPersonas; i++){
		fwrite(agenda.personas[i].nombre, sizeof(char), strlen(agenda.personas[i].nombre), fichero);
		fwrite("\n", sizeof(char), 1, fichero);
		fwrite(agenda.personas[i].apellido, sizeof(char), strlen(agenda.personas[i].apellido), fichero);
		fwrite("\n", sizeof(char), 1, fichero);
		fwrite(agenda.personas[i].telefono, sizeof(char), strlen(agenda.personas[i].telefono), fichero);
		fwrite("\n", sizeof(char), 1, fichero);
	}
	fclose(fichero);
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