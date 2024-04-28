/*
malloc(), realloc()
*/

#include <stdio.h>
#include <stdlib.h>

char *leeLineaDinamica();

int main (int argc, char **argv){
	char *nombreAlumno = NULL;
	printf("Ingresa el nombre del alumno: ");
	nombreAlumno = leeLineaDinamica();
	printf("El nombre del alumno es: %s\n", nombreAlumno);
	free(nombreAlumno);
	nombreAlumno = NULL;
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