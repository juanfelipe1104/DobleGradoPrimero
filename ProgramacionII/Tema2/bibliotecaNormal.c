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

struct autor_t {
	char nombre[MAX_AUTOR_T];
	char apellido[MAX_AUTOR_T];
	char nacionalidad[MAX_AUTOR_T];
};

struct libro_t {
	char titulo[MAX_LIBRO_T];
	char ISBN[MAX_LIBRO_T];
	int numeroPaginas;
	char editorial[MAX_LIBRO_T];
	struct autor_t autor;
};

struct autor_t ingresarAutor();
struct libro_t ingresarLibro(char *autor);
int compararCadena(char *cadena1, char *cadena2);
void imprimirLibrosAutor(char *cadena1, struct libro_t libros[], int totalLibros);
void imprimirLibros(struct libro_t libros[], int totalLibros);

int main (int argc, char **argv){
	int error = 1; //Variable de comprobacion booleana
	int eleccion = 0; //Variable para el menu
	int contadorLibros = 0, contadorAutores = 0; //Contadores para los autores y los libros 
	char auxiliarAutor[MAX_AUTOR_T] = {'\0'}; //Variable auxiliar
	struct autor_t autores[MAX_AUTORES];
	struct libro_t libros[MAX_LIBROS];
	do {
		printf("Ingrese la opcion que desea:\n1. Ingresar autor.\n2. Ingresar libro.\n3. Busqueda por autor.\n4. Mostrar libros.\n5. Salir.\n");
		scanf("%d", &eleccion);
		switch (eleccion) {
			case 1:
				autores[contadorAutores]=ingresarAutor();
				contadorAutores++;
			break;
			case 2:
				libros[contadorLibros]=ingresarLibro(auxiliarAutor);
				for (int i = 0; i < contadorAutores; i++){
					if (compararCadena(auxiliarAutor, autores[i].nombre)){
						error = 0;
						libros[contadorLibros].autor = autores[i];
					}
				}
				if (error){
					printf("El autor '%s' no existe en la biblioteca.\nIntroduzca sus datos.\n", auxiliarAutor);
					autores[contadorAutores]=ingresarAutor();
					libros[contadorLibros].autor = autores[contadorAutores];
					contadorAutores++;
				}
				contadorLibros++;
			break;
			case 3:
				printf("Ingrese el nombre del autor(solo el nombre): ");
				scanf("%s", auxiliarAutor);
				while(getchar() != '\n'); // Limpiar el buffer
				imprimirLibrosAutor(auxiliarAutor, libros, contadorLibros);
			break;
			case 4:
				imprimirLibros(libros, contadorLibros);
			break;
			case 5: break;
			default:
				printf("'%d' no es una opcion correcta", eleccion);
			break;
		}
	}while (eleccion != NUM_OPCIONES);
}

struct autor_t ingresarAutor(){
	struct autor_t autor;
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

struct libro_t ingresarLibro(char *autor){
	struct libro_t libro;
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

void imprimirLibrosAutor(char *cadena1, struct libro_t libros[], int totalLibros){
	int error = 1; //Variable booleana
	for (int i = 0; i < totalLibros; i++){
		if (compararCadena(cadena1, libros[i].autor.nombre)){
			printf("Titulo: %s\n", libros[i].titulo);
			printf("ISBN: %s\n", libros[i].ISBN);
			printf("Numero de paginas: %d\n", libros[i].numeroPaginas);
			printf("Editorial: %s\n", libros[i].editorial);
			error = 0;
		}
	}
	if (error){
		printf("No existe el autor '%s' en la biblioteca.\n", cadena1);
	}
}

void imprimirLibros(struct libro_t libros[], int totalLibros){
	int error = 1; //Variable booleana
	for (int i = 0; i < totalLibros; i++){
		printf("Titulo: %s\n", libros[i].titulo);
		printf("ISBN: %s\n", libros[i].ISBN);
		printf("Numero de paginas: %d\n", libros[i].numeroPaginas);
		printf("Editorial: %s\n", libros[i].editorial);
		printf("Autor: %s %s\n", libros[i].autor.nombre, libros[i].autor.apellido);
		error = 0; //Existen libros
	}
	if (error){
		printf("No existen libros en la biblioteca.\n");
	}
}