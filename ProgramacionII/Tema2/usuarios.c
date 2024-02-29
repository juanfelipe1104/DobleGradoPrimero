/*
Gestion de Usuarios
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100
#define JOVEN 30 //Supongo que el enunciado se refiere a imprimir los mas jovenes (<30 años)

typedef struct usuarios_t {
	char nombre[10];
	char apellido[15];
	char dni[9];
	int edad;
	float peso;
	int telefono;
}usuarios_t;

usuarios_t ingresarUsuario();
void imprimirUsuario(usuarios_t usuario);

int main (int argc, char **argv){
	usuarios_t usuarios[TAM_MAX];
	int cantidad = 0;
	printf("Ingrese el numero de usuarios que desea ingresar: ");
	scanf("%d", &cantidad);
	while(getchar() != '\n'); // Limpiar el buffer
	if (cantidad > TAM_MAX){
		printf("No hay suficiente espacio para esa cantidad\n");
	}
	else {
		for (int i = 0; i < cantidad; i++){
			usuarios[i] = ingresarUsuario();
		}
		printf("-------------------\n"); //Separador
		printf("Los usuarios son:\n");
		for (int i = 0; i < cantidad; i++){
			imprimirUsuario(usuarios[i]);
		}
		printf("-------------------\n"); //Separador
		printf("Los usuarios mas jovenes son:\n");
		for (int i = 0; i < cantidad; i++){
			if(usuarios[i].edad < JOVEN){
				imprimirUsuario(usuarios[i]);
			}
		}
	}
}

usuarios_t ingresarUsuario(){
	usuarios_t usuario;
	printf("-------------------\n"); //Separador
	printf("Ingrese el nombre: ");
	scanf("%s", usuario.nombre);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el apellido: ");
	scanf("%s", usuario.apellido);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el DNI: ");
	scanf("%s", usuario.dni);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese la edad: ");
	scanf("%d", &usuario.edad);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el peso: ");
	scanf("%f", &usuario.peso);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el telefono: ");
	scanf("%d", &usuario.telefono);
	while(getchar() != '\n'); // Limpiar el buffer
	return usuario;
}

void imprimirUsuario(usuarios_t usuario){
	printf("-------------------\n"); //Separador
	printf("Nombre: %s\n", usuario.nombre);
	printf("Apellido: %s\n", usuario.apellido);
	printf("DNI: %s\n", usuario.dni);
	printf("Edad: %d\n", usuario.edad);
	printf("Peso: %.2f\n", usuario.peso);
	printf("Telefono: %d\n", usuario.telefono);
}