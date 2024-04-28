/*
cadenas_malloc
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usuario_t{
	char *nombre;
	char *apellido1;
	char *apellido2;
}usuario_t;

char *leeLineaDinamica();
usuario_t ingresarUsuario();
char *copiarCadenas(char *cadenaOrigen);
char *concatenarCadenas(usuario_t *usuario);
void guardarEnFichero(char *nombreFichero, usuario_t usuario);
void liberarUsuario(usuario_t *usuario);

int main (int argc, char **argv){
	usuario_t usuario = {.nombre = NULL, .apellido1 = NULL, .apellido2 = NULL};
	usuario_t copiaUsuario = {.nombre = NULL, .apellido1 = NULL, .apellido2 = NULL};
	char *nombreCompleto = NULL;
	usuario = ingresarUsuario();
	copiaUsuario.nombre = copiarCadenas(usuario.nombre);
	copiaUsuario.apellido1 = copiarCadenas(usuario.apellido1);
	copiaUsuario.apellido2 = copiarCadenas(usuario.apellido2);
	nombreCompleto = concatenarCadenas(&usuario);
	printf("El nombre completo es: %s", nombreCompleto);
	guardarEnFichero("usuarios.txt", copiaUsuario);
	liberarUsuario(&usuario);
	liberarUsuario(&copiaUsuario);
	free(nombreCompleto);
	nombreCompleto = NULL;
	return 0;
}

usuario_t ingresarUsuario(){
	usuario_t usuario = {.nombre = NULL, .apellido1 = NULL, .apellido2 = NULL};
	printf("Ingrese nombre: ");
	usuario.nombre = leeLineaDinamica();
	printf("Ingrese primer apellido: ");
	usuario.apellido1 = leeLineaDinamica();
	printf("Ingrese segundo apellido: ");
	usuario.apellido2 = leeLineaDinamica();
	return usuario;
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

char *copiarCadenas(char *cadenaOrigen){
	char *cadenaDestino = NULL;
	cadenaDestino = (char*)realloc(cadenaDestino, strlen(cadenaOrigen)+1);
	cadenaDestino[0] = '\0';
	strcpy(cadenaDestino, cadenaOrigen);
	return cadenaDestino;
}

char *concatenarCadenas(usuario_t *usuario){
	char *cadenaDestino = NULL;
	cadenaDestino = (char*)realloc(cadenaDestino, strlen(usuario->nombre)+strlen(usuario->apellido1)+strlen(usuario->apellido2)+1);
	cadenaDestino[0] = '\0';
	strcat(cadenaDestino, usuario->nombre);
	strcat(cadenaDestino, usuario->apellido1);
	strcat(cadenaDestino, usuario->apellido2);
	return cadenaDestino;
}

void guardarEnFichero(char *nombreFichero, usuario_t usuario){
	FILE *fichero = NULL;
	fichero = fopen(nombreFichero, "wb");
	fwrite(usuario.nombre, 1, strlen(usuario.nombre), fichero);
	fwrite("\n", 1, 1, fichero);
	fwrite(usuario.apellido1, 1, strlen(usuario.apellido1), fichero);
	fwrite("\n", 1, 1, fichero);
	fwrite(usuario.apellido2, 1, strlen(usuario.apellido2), fichero);
	fwrite("\n", 1, 1, fichero);
	fclose(fichero);
}

void liberarUsuario(usuario_t *usuario){
	free(usuario->nombre);
	usuario->nombre = NULL;
	free(usuario->apellido1);
	usuario->apellido1 = NULL;
	free(usuario->apellido2);
	usuario->apellido2 = NULL;
}