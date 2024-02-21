/*
Clase de alumnos
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100

struct clase_t{
	int edad;
	float altura;
	char nombre[TAM_MAX], apellido[TAM_MAX];
};

struct clase_t pedirAlumno(){
	struct clase_t alumno;
	printf("Ingresa el nombre: ");
	scanf("%s", alumno.nombre);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingresa el apellido: ");
	scanf("%s", alumno.apellido);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingresa edad: ");
	scanf("%d", &alumno.edad);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingresa altura: ");
	scanf("%f", &alumno.altura);
	while(getchar() != '\n'); // Limpiar el buffer
	return alumno;
}
int main (int argc, char **argv){
	struct clase_t clase[25];
	struct clase_t auxiliar1 = {
		.edad = 20,
		.nombre = "Santiago",
		.apellido = "Castillo",
		.altura = 1.81
	};
	clase[0] = auxiliar1;
	for (int i = 0; i < 1; i++){
		clase[i]=pedirAlumno();
	}
}