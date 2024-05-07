/*
strtok con fichero por argumentos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_MAX_ARG 2

typedef enum boolean_t{
	falso = 0, verdadero = 1
}boolean_t;

typedef struct lineas_t{
	int numLineas;
	char **lineas;
}lineas_t;

typedef struct usuario_t{
	char *nombre;
	char *apellido;
	int edad;
}usuario_t;

typedef struct usuarios_t{
	usuario_t *usuarios;
	int numUsuarios;
}usuarios_t;

boolean_t existeFichero(char *fichero);
char *leeLineaDinamicaFichero(FILE *f);
void imprimirUsuarios(usuarios_t listaUsuarios);

int main (int argc, char **argv){
	usuarios_t listaUsuarios = {.usuarios = NULL, .numUsuarios = 0};
	lineas_t lineasFichero = {.numLineas = 0, .lineas = NULL};
	FILE *fichero = NULL;
	char *error = NULL;
	boolean_t comprobacion = verdadero;
	if (argc != MIN_MAX_ARG){
		printf("Error, el numero minimo y maximo de argumentos es 1.\n");
	}
	else {
		if (existeFichero(argv[1])){
			fichero = fopen(argv[1], "rb");
			while (!feof(fichero)){
				lineasFichero.numLineas++;
				lineasFichero.lineas = (char**)realloc(lineasFichero.lineas, sizeof(char*)*lineasFichero.numLineas);
				lineasFichero.lineas[lineasFichero.numLineas-1] = leeLineaDinamicaFichero(fichero);
			}
			fclose(fichero);
			listaUsuarios.numUsuarios = lineasFichero.numLineas;
			listaUsuarios.usuarios = (usuario_t*)realloc(listaUsuarios.usuarios, sizeof(usuario_t)*listaUsuarios.numUsuarios);
			for (int i = 0; (i < listaUsuarios.numUsuarios) && (comprobacion); i++){
				listaUsuarios.usuarios[i].nombre = strtok(lineasFichero.lineas[i], ",");
				listaUsuarios.usuarios[i].apellido = strtok(NULL, ",");
				listaUsuarios.usuarios[i].edad = (int)strtol(strtok(NULL, ","), &error, 10);
				if (*error != '\0'){
					comprobacion = falso;
					printf("La linea %d del fichero '%s' contiene una edad no numerica.\n", i+1, argv[1]);
				}
			}
			if (comprobacion){
				imprimirUsuarios(listaUsuarios);
			}
			for (int i = 0; i < lineasFichero.numLineas; i++){
				free(lineasFichero.lineas[i]);
				lineasFichero.lineas[i] = NULL;
			}
			free(lineasFichero.lineas);
			free(listaUsuarios.usuarios);
		}
		else {
			printf("El fichero '%s' no existe.\n", argv[1]);
		}
	}
}

char *leeLineaDinamicaFichero(FILE *f){
	char *letras = NULL, ultimaLetraLeida = '\0';
	int numLetrasLeidas = 0, numLetrasMax = 0;
	do {
		ultimaLetraLeida = getc(f);
		if (numLetrasLeidas == numLetrasMax){
			numLetrasMax++;
			letras = (char*)realloc(letras, sizeof(char)*numLetrasMax);
		}
		if ((ultimaLetraLeida != '\n') && (ultimaLetraLeida != EOF)){
			letras[numLetrasLeidas] = ultimaLetraLeida;
			numLetrasLeidas++;
		}
	}while((ultimaLetraLeida != '\n') && (ultimaLetraLeida != EOF));
	letras[numLetrasLeidas] = '\0';
	return letras;
}

boolean_t existeFichero(char *fichero){
	FILE *f=NULL;
	boolean_t existe = verdadero;
	f = fopen(fichero, "rb");
	if(f==NULL){
		existe = falso;
	}
	else {
		fclose(f);
	}
	return existe;
}

void imprimirUsuarios(usuarios_t listaUsuarios){
	for (int i = 0; i < listaUsuarios.numUsuarios; i++){
		printf("Usuario %d:\n", i+1);
		printf("Nombre %s.\n", listaUsuarios.usuarios[i].nombre);
		printf("Apellido %s.\n", listaUsuarios.usuarios[i].apellido);
		printf("Edad: %d.\n", listaUsuarios.usuarios[i].edad);
	}
}