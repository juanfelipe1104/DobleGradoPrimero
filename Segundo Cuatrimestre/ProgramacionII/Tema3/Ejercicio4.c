/*
malloc(), realloc()
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_OPCIONES 3

typedef struct libro_t{
	int numPaginas;
	char *autor;
	char *titulo;
}libro_t;

typedef struct listaLibros_t{
	libro_t *libros;
	int tamMax;
	int numUsados;
}listaLibros_t;

char *leeLineaDinamica();
libro_t ingresarLibro();
void imprimirLibros(listaLibros_t lista);
void prestar(listaLibros_t *lista, int prestado);

int main (int argc, char **argv){
	listaLibros_t biblioteca = {.libros = NULL, .tamMax = 0, .numUsados = 0};
	int opcion = 0, prestamo = 0;
	while (opcion != MAX_OPCIONES){
		printf("Biblioteca:\n1. Introducir un libro.\n2. Elegir prestamo.\n3. Salir.\n");
		scanf("%d", &opcion);
		while(getchar()!= '\n'); //Limpiar el buffer
		switch(opcion){
			case 1:
				if (biblioteca.tamMax == biblioteca.numUsados){
					biblioteca.tamMax++;
					biblioteca.libros = (libro_t*)realloc(biblioteca.libros, sizeof(libro_t)*biblioteca.tamMax);
				}
				biblioteca.libros[biblioteca.numUsados] = ingresarLibro();
				biblioteca.numUsados++;
			break;
			case 2:
				imprimirLibros(biblioteca);
				printf("Ingrese el numero del ejemplar que desea prestar: ");
				scanf("%d", &prestamo);
				while(getchar() != '\n'); //Limpiar el buffer
				if (prestamo >= biblioteca.numUsados){
					printf("Numero '%d' de ejemplar incorrecto.\n", prestamo);
				}
				else {
					prestar(&biblioteca, prestamo);
				}
			break;
			case 3: break;
			default:
				printf("La opcion '%d' es incorrecta.\n", opcion);
			break;
		}
	}
	for (int i = 0; i < biblioteca.numUsados; i++){
		free(biblioteca.libros[i].autor);
		biblioteca.libros[i].autor = NULL;
		free(biblioteca.libros[i].titulo);
		biblioteca.libros[i].titulo = NULL;
	}
	free(biblioteca.libros);
	biblioteca.libros = NULL;
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

libro_t ingresarLibro(){
	libro_t libro;
	printf("Ingrese el nombre del autor: ");
	libro.autor=leeLineaDinamica();
	printf("Ingrese el titulo: ");
	libro.titulo=leeLineaDinamica();
	printf("Ingrese el numero de paginas: ");
	scanf("%d", &libro.numPaginas);
	while(getchar()!= '\n'); //Limpiar el buffer
	return libro;
}

void imprimirLibros(listaLibros_t lista){
	for (int i = 0; i < lista.numUsados; i++){
		printf("Ejemplar %d:\n", i);
		printf("Autor: %s\n", lista.libros[i].autor);
		printf("Titulo: %s\n", lista.libros[i].titulo);
		printf("Paginas: %d\n", lista.libros[i].numPaginas);
	}
}

void prestar(listaLibros_t *lista, int prestado){
	libro_t *librosAux = (libro_t*)malloc((lista->tamMax-1)*sizeof(libro_t));
	for (int i = 0; i < prestado; i++){
		librosAux[i] = lista->libros[i];
	}
	for (int i = prestado+1; i < lista->tamMax; i++){
		librosAux[i] = lista->libros[i]; 
	}
	free(lista->libros);
	lista->numUsados-=1;
	lista->libros = librosAux;
}