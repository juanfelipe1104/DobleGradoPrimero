/*
Ejemplo uniones
*/

#include <stdio.h>
#include <stdlib.h>

typedef union datos_u {
	int edad;
	float peso;
	char nombre[10];
}datos_u;

typedef struct datos_t {
	int edad;
	float peso;
	char nombre[10];
}datos_t;

datos_u pedirUnion();
datos_t pedirEstructura();
void imprimirEstructura(datos_t datos);
void imprimirUnion(datos_u datos);

int main (int argc, char **argv){
	datos_u datos;
	datos_t datos2;
	datos = pedirUnion();
	datos2 = pedirEstructura();
	imprimirEstructura(datos2);
	imprimirUnion(datos);
	printf("Tamano union: %ld\n", sizeof(datos));
	printf("Tamano estructura %ld\n", sizeof(datos2));
}

datos_u pedirUnion(){
	datos_u datos;
	printf("Ingrese la edad: ");
	scanf("%d", &datos.edad);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el peso: ");
	scanf("%f", &datos.peso);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el nombre: ");
	scanf("%s", datos.nombre);
	while(getchar() != '\n'); // Limpiar el buffer
	return datos;
}

datos_t pedirEstructura(){
	datos_t datos;
	printf("Ingrese la edad: ");
	scanf("%d", &datos.edad);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el peso: ");
	scanf("%f", &datos.peso);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el nombre: ");
	scanf("%s", datos.nombre);
	while(getchar() != '\n'); // Limpiar el buffer
	return datos;
}

void imprimirEstructura(datos_t datos){
	printf("La edad es: %d\n", datos.edad);
	printf("El peso es: %f\n", datos.peso);
	printf("El nombre es: %s\n", datos.nombre);
}

void imprimirUnion(datos_u datos){
	printf("La edad es: %d\n", datos.edad);
	printf("El peso es: %f\n", datos.peso);
	printf("El nombre es: %s\n", datos.nombre);
}