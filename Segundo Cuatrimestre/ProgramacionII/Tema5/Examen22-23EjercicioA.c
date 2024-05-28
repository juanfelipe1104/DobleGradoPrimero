/*
Examen 22-23 EjercicioA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct empleado_t{
	char *nombre;
	char *apellido;
	char *correo;
}empleado_t;

typedef struct empleados_t{
	empleado_t *empleados;
	int numEmpleados;
}empleados_t;

empleado_t crearEmpleado();
char *leeLineaDinamicaFichero(FILE *fichero);
int validaLineaDatosEmpleado(char *linea);
char *crearCorreoEmpleado(char *nombre, char *apellido);
void introduceEmpleadoEnLista(empleados_t *listaEmpleados);
void mostrarCorreos(empleados_t listaEmpleados);
void liberarEmpleados(empleados_t *listaEmpleados);

int main (int argc, char **argv){
	empleados_t listaEmpleados = {.empleados = NULL, .numEmpleados = 0};
	int opcion = 0, salir = 0;
	while (!salir){
		printf("1. Introducir empleados.\n2. Mostrar correos electronicos.\n3. Salir.\n");
		scanf("%d", &opcion);
		while(getchar() != '\n'); //Limpiar el buffer
		switch(opcion){
			case 1:
				introduceEmpleadoEnLista(&listaEmpleados);
			break;
			case 2:
				mostrarCorreos(listaEmpleados);
			break;
			case 3:
				salir = 1;
				liberarEmpleados(&listaEmpleados);
			break;
		}
	}
}

empleado_t crearEmpleado(){
	empleado_t empleado = {.nombre = NULL, .apellido = NULL, .correo = NULL};
	do {
		if (empleado.nombre != NULL){
			free(empleado.nombre);
		}
		printf("Introduzca nombre del empleado: ");
		empleado.nombre = leeLineaDinamicaFichero(stdin);
	}while (!validaLineaDatosEmpleado(empleado.nombre));
	do {
		if (empleado.apellido != NULL){
			free(empleado.apellido);
		}
		printf("Introduzca apellido del empleado: ");
		empleado.apellido = leeLineaDinamicaFichero(stdin);
	}while (!validaLineaDatosEmpleado(empleado.apellido));
	empleado.correo = crearCorreoEmpleado(empleado.nombre, empleado.apellido);
	return empleado;
}

char *leeLineaDinamicaFichero(FILE *fichero){
	char letraLeida = '\0', *linea = NULL;
	int numLetras = 0;
	do {
		letraLeida = getc(fichero);
		linea = (char*)realloc(linea, sizeof(char)*(numLetras+1));
		linea[numLetras] = letraLeida;
		numLetras++;
	}while((letraLeida != '\n')&&(letraLeida != EOF));
	linea[numLetras-1] = '\0';
	return linea;
}

int validaLineaDatosEmpleado(char *linea){
	int valido = 1, tamLinea = 0;
	tamLinea = strlen(linea);
	if (tamLinea){
		for (int i = 0; (i < tamLinea) && (valido); i++){
			if (!((linea[i] == ' ')||(linea[i] >= 'A')&&(linea[i]<='z'))){
				valido = 0;
			}
		}
	}
	else {
		valido = 0;
	}
	return valido;
}

char *crearCorreoEmpleado(char *nombre, char *apellido){
	char *dns = "@acme.com", *correo = NULL;
	correo = (char*)realloc(correo, strlen(nombre)+strlen(apellido)+strlen(dns)+2);
	correo[0] = '\0';
	strcat(correo, nombre);
	strcat(correo, ".");
	strcat(correo, apellido);
	strcat(correo, dns);
	for (int i = 0; i < strlen(correo); i++){
		if (correo[i] == ' '){
			correo[i] = '_';
		}
	}
	return correo;
}

void introduceEmpleadoEnLista(empleados_t *listaEmpleados){
	listaEmpleados->empleados = (empleado_t*)realloc(listaEmpleados->empleados, sizeof(empleado_t)*(listaEmpleados->numEmpleados+1));
	listaEmpleados->empleados[listaEmpleados->numEmpleados] = crearEmpleado();
	listaEmpleados->numEmpleados++;
}

void mostrarCorreos(empleados_t listaEmpleados){
	for (int i = 0; i < listaEmpleados.numEmpleados; i++){
		printf("El nombre es: %s\n", listaEmpleados.empleados[i].nombre);
		printf("El apellido es: %s\n", listaEmpleados.empleados[i].apellido);
		printf("El correo es: %s\n", listaEmpleados.empleados[i].correo);
		printf("================================\n");
	}
}

void liberarEmpleados(empleados_t *listaEmpleados){
	for (int i = 0; i < listaEmpleados->numEmpleados; i++){
		free(listaEmpleados->empleados[i].nombre);
		listaEmpleados->empleados[i].nombre = NULL;
		free(listaEmpleados->empleados[i].apellido);
		listaEmpleados->empleados[i].apellido = NULL;
		free(listaEmpleados->empleados[i].correo);
		listaEmpleados->empleados[i].correo = NULL;
	}
	free(listaEmpleados->empleados);
	listaEmpleados->empleados;
}