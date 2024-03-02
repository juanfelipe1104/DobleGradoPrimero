/*
Gestion de biblioteca
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_AUTORES 3 //Numero maximo de autores
#define MAX_AUTOR_T 10 //Caracteres maximos de un autor
#define MAX_LIBROS 10 //Numero maximo de libros
#define MAX_LIBRO_T 20 //Caracteres maximos de un libro
#define NUM_OPCIONES 5 //Opciones menu a presentar

typedef enum boolean {
	verdadero=1, falso=0
}boolean;

typedef struct autor_t {
	char nombre[MAX_AUTOR_T];
	char apellido[MAX_AUTOR_T];
	char nacionalidad[MAX_AUTOR_T];
}autor_t;

typedef struct libro_t {
	char titulo[MAX_LIBRO_T];
	char ISBN[MAX_LIBRO_T];
	int numeroPaginas;
	char editorial[MAX_LIBRO_T];
	autor_t* autor;
}libro_t;

typedef enum tipoLista_e {
	tipoLibro, tipoAutor
}tipoLista_e;

typedef struct lista_t {
	enum tipoLista_e tipo;
	union {
		autor_t autores_t[MAX_AUTORES];
		libro_t libros_t[MAX_LIBROS];
	};
	int size;
	int numeroDatosIntroducidos;
}lista_t;

autor_t ingresarAutor();
libro_t ingresarLibro(char *autor);
int compararCadena(char *cadena1, char *cadena2);
void imprimirLibrosAutor(char *cadena1, libro_t libros[], int totalLibros);
void imprimirLibros(libro_t libros[], int totalLibros);

int main (int argc, char **argv){
	boolean error = verdadero; //Variable de comprobacion booleana
	int eleccion = 0; //Variable para el menu 
	char auxiliarAutor[MAX_AUTOR_T] = {'\0'}; //Variable auxiliar
	lista_t autores = {
		.tipo=tipoAutor,
		.size=MAX_AUTORES,
		.numeroDatosIntroducidos=0
	};
	lista_t libros = {
		.tipo=tipoLibro,
		.size=MAX_LIBROS,
		.numeroDatosIntroducidos=0
	};
	do {
		printf("Ingrese la opcion que desea:\n1. Ingresar autor.\n2. Ingresar libro.\n3. Busqueda por autor.\n4. Mostrar libros.\n5. Salir.\n");
		scanf("%d", &eleccion);
		switch (eleccion) {
			case 1:
				autores.autores_t[autores.numeroDatosIntroducidos]=ingresarAutor();
				autores.numeroDatosIntroducidos++;
			break;
			case 2:
				libros.libros_t[libros.numeroDatosIntroducidos]=ingresarLibro(auxiliarAutor);
				for (int i = 0; i < autores.numeroDatosIntroducidos; i++){
					if (compararCadena(auxiliarAutor, autores.autores_t[i].nombre)){
						error = falso;
						libros.libros_t[libros.numeroDatosIntroducidos].autor = &autores.autores_t[i];
					}
				}
				if (error){
					printf("El autor '%s' no existe en la biblioteca.\nIntroduzca sus datos.\n", auxiliarAutor);
					autores.autores_t[autores.numeroDatosIntroducidos]=ingresarAutor();
					libros.libros_t[libros.numeroDatosIntroducidos].autor = &autores.autores_t[autores.numeroDatosIntroducidos];
					autores.numeroDatosIntroducidos++;
				}
				libros.numeroDatosIntroducidos++;
			break;
			case 3:
				printf("Ingrese el nombre del autor(solo el nombre): ");
				scanf("%s", auxiliarAutor);
				while(getchar() != '\n'); // Limpiar el buffer
				imprimirLibrosAutor(auxiliarAutor, libros.libros_t, libros.numeroDatosIntroducidos);
			break;
			case 4:
				imprimirLibros(libros.libros_t, libros.numeroDatosIntroducidos);
			break;
			case 5: break;
			default:
				printf("'%d' no es una opcion correcta", eleccion);
			break;
		}
	}while (eleccion != NUM_OPCIONES);
}

autor_t ingresarAutor(){
	autor_t autor;
	printf("Ingrese el nombre: ");
	scanf("%s", autor.nombre);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el apellido: ");
	scanf("%s", autor.apellido);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese la nacionalidad: ");
	scanf("%s", autor.nacionalidad);
	while(getchar() != '\n'); // Limpiar el buffer
	return autor;
}

libro_t ingresarLibro(char *autor){
	libro_t libro;
	printf("Ingrese el titulo: ");
	scanf("%s", libro.titulo);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el ISBN: ");
	scanf("%s", libro.ISBN);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el numero de paginas: ");
	scanf("%d", &libro.numeroPaginas);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese la editorial: ");
	scanf("%s", libro.editorial);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Ingrese el autor(Solo el nombre): ");
	scanf("%s", autor);
	while(getchar() != '\n'); // Limpiar el buffer
	return libro;
}

int compararCadena(char *cadena1, char *cadena2){
	int comprobacion = 1;
	while ((*cadena1 != '\0') && (*cadena2 != '\0') && (*cadena1 == *cadena2)){
		cadena1++;
		cadena2++;
	}
	comprobacion = (*cadena1 == *cadena2);
	return comprobacion;
}

void imprimirLibrosAutor(char *cadena1, libro_t libros[], int totalLibros){
	boolean error = verdadero; //Variable booleana
	for (int i = 0; i < totalLibros; i++){
		if (compararCadena(cadena1, libros[i].autor->nombre)){
			printf("Titulo: %s\n", libros[i].titulo);
			printf("ISBN: %s\n", libros[i].ISBN);
			printf("Numero de paginas: %d\n", libros[i].numeroPaginas);
			printf("Editorial: %s\n", libros[i].editorial);
			error = falso;
		}
	}
	if (error){
		printf("No existe el autor '%s' con libros en la biblioteca.\n", cadena1);
	}
}

void imprimirLibros(libro_t libros[], int totalLibros){
	boolean error = verdadero; //Variable booleana
	for (int i = 0; i < totalLibros; i++){
		printf("Titulo: %s\n", libros[i].titulo);
		printf("ISBN: %s\n", libros[i].ISBN);
		printf("Numero de paginas: %d\n", libros[i].numeroPaginas);
		printf("Editorial: %s\n", libros[i].editorial);
		printf("Autor: %s %s\n", libros[i].autor->nombre, libros[i].autor->apellido);
		error = falso; //Existen libros
	}
	if (error){
		printf("No existen libros en la biblioteca.\n");
	}
}