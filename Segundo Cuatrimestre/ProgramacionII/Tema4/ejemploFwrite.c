/*
Ejemplo fwrite()
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum tiposLista_e {
	contacto = 0, string = 1, integer = 2
}tiposLista_e;

typedef struct listaGenerica_t {
	tiposLista_e tipo;
	union{
		struct contacto_t *contactos;
		char *cadena;
		int *arrayInt;
	};
	int tamMax;
	int numUsados;
}listaGenerica_t;

typedef struct contacto_t{
	listaGenerica_t nombre;
	listaGenerica_t apellido;
	listaGenerica_t telefono;
}contacto_t;

listaGenerica_t leeLineaDinamicaFichero(FILE *f);
listaGenerica_t leeNumerosDinamicosFichero(FILE *f);
contacto_t pedirContacto();
void introducirContactoEnLista(listaGenerica_t *agenda);
void mostrarContactos(listaGenerica_t agenda);
void salvarContactos(char *nombreFichero, listaGenerica_t agenda);
int existeFichero(char *fichero);
void cargarContactos(char *nombreFichero, listaGenerica_t *agenda);

int main(int argc, char **argv){
	listaGenerica_t agenda = {.tipo = contacto, .contactos = NULL, .tamMax = 0, .numUsados = 0};
	listaGenerica_t nombreFicheroOut = {.tipo = string, .cadena = NULL, .tamMax = 0, .numUsados = 0};
	listaGenerica_t nombreFicheroIn = {.tipo = string, .cadena = NULL, .tamMax = 0, .numUsados = 0};
	int salir = 0, opcion = 0;
	while(!salir){
		printf("1. Ingresar contacto.\n2. Mostrar contactos.\n3. Salvar contactos.\n4. Cargar contactos.\n5. Salir.\n");
		scanf("%d", &opcion);
		while(getchar() != '\n'); //Limpiar el buffer
		switch(opcion){
			case 1:
				introducirContactoEnLista(&agenda);
			break;
			case 2:
				mostrarContactos(agenda);
			break;
			case 3:
				printf("Ingrese el nombre del fichero donde desea guardar los contactos (se sobreescribira): ");
				nombreFicheroOut = leeLineaDinamicaFichero(stdin);
				salvarContactos(nombreFicheroOut.cadena, agenda);
			break;
			case 4:
				printf("Ingrese el nombre del fichero de donde desea cargar datos al programa: ");
				nombreFicheroIn = leeLineaDinamicaFichero(stdin);
				cargarContactos(nombreFicheroIn.cadena, &agenda);
			break;
			case 5:
				salir = 1;
				if (agenda.numUsados){
					for (int i = 0; i < agenda.numUsados; i++){
						free(agenda.contactos[i].nombre.cadena);
						agenda.contactos[i].nombre.cadena = NULL;
						free(agenda.contactos[i].apellido.cadena);
						agenda.contactos[i].apellido.cadena = NULL;
						free(agenda.contactos[i].telefono.arrayInt);
						agenda.contactos[i].telefono.arrayInt = NULL;
					}
					free(agenda.contactos);
					agenda.contactos = NULL;
				}
				free(nombreFicheroIn.cadena);
				nombreFicheroIn.cadena = NULL;
				free(nombreFicheroOut.cadena);
				nombreFicheroOut.cadena = NULL;
			break;
		}
	}
}

listaGenerica_t leeLineaDinamicaFichero(FILE *f){
	listaGenerica_t linea = {.tipo = string, .cadena = NULL, .tamMax = 0, .numUsados = 0};
	char ultimaLetraLeida = '\0';
	do {
		ultimaLetraLeida = getc(f);
		if (linea.numUsados == linea.tamMax){
			linea.tamMax++;
			linea.cadena = (char*)realloc(linea.cadena, sizeof(char)*linea.tamMax);
		}
		if ((ultimaLetraLeida != '\n') && (ultimaLetraLeida != EOF)){
			linea.cadena[linea.numUsados] = ultimaLetraLeida;
			linea.numUsados++;
		}
	}while((ultimaLetraLeida != '\n') && (!feof(f)));
	linea.cadena[linea.numUsados] = '\0';
	return linea;
}

listaGenerica_t leeNumerosDinamicosFichero(FILE *f){
	listaGenerica_t linea = {.tipo = integer, .arrayInt = NULL, .tamMax = 0, .numUsados = 0};
	int ultimoNumeroLeido = 0;
	while((ultimoNumeroLeido >= '0') && (ultimoNumeroLeido <= '9') && (!feof(f))){
		ultimoNumeroLeido = getc(f);
		if (linea.numUsados == linea.tamMax){
			linea.tamMax++;
			linea.arrayInt = (int*)realloc(linea.arrayInt, sizeof(int)*linea.tamMax);
		}
		linea.cadena[linea.numUsados] = ultimoNumeroLeido;
		linea.numUsados++;
	}
	return linea;
}

contacto_t pedirContacto(){
	contacto_t contacto;
	printf("Introduzca nombre: ");
	contacto.nombre = leeLineaDinamicaFichero(stdin);
	printf("Introduzca apellido: ");
	contacto.apellido = leeLineaDinamicaFichero(stdin);
	printf("Introduzca telefono: ");
	contacto.telefono = leeNumerosDinamicosFichero(stdin);
	while(getchar() != '\n'); //Limpiar el buffer 
	return contacto;
}

void introducirContactoEnLista(listaGenerica_t *agenda){
	if (agenda->tamMax == agenda->numUsados){
		agenda->tamMax++;
		agenda->contactos = (contacto_t*)realloc(agenda->contactos, sizeof(contacto_t)*agenda->tamMax);
	}
	agenda->contactos[agenda->numUsados] = pedirContacto();
	agenda->numUsados++;
}

void mostrarContactos(listaGenerica_t agenda){
	if (agenda.numUsados){
		for (int i = 0; i < agenda.numUsados; i++){
			printf("Nombre: %s\n", agenda.contactos[i].nombre.cadena);
			printf("Apellido: %s\n", agenda.contactos[i].apellido.cadena);
			printf("Telefono: ");
			for (int j = 0; j < agenda.contactos[i].telefono.numUsados; j++){
				printf("%d ", agenda.contactos[i].telefono.arrayInt[j]);
			}
			printf("\n");
		}
	}
	else {
		printf("No existen contactos.\n");
	}
}

void salvarContactos(char *nombreFichero, listaGenerica_t agenda){
	FILE *fichero = NULL;
	fichero = fopen(nombreFichero, "wb");
	for (int i = 0; i < agenda.numUsados; i++){
		fwrite(agenda.contactos[i].nombre.cadena, sizeof(char), agenda.contactos[i].nombre.numUsados, fichero);
		fwrite("\n", sizeof(char), 1, fichero);
		fwrite(agenda.contactos[i].apellido.cadena, sizeof(char), agenda.contactos[i].apellido.numUsados, fichero);
		fwrite("\n", sizeof(char), 1, fichero);
		fwrite(agenda.contactos[i].telefono.cadena, sizeof(char), agenda.contactos[i].telefono.numUsados, fichero);
		fwrite("\n", sizeof(char), 1, fichero);
	}
	fclose(fichero);
}

int existeFichero(char *nombreFichero){
	FILE *fichero = NULL;
	int existe = 1;
	fichero = fopen(nombreFichero, "r+");
	if(fichero == NULL){
		existe = 0;
	}
	else {
		fclose(fichero);
	}
	return existe;
}

void cargarContactos(char *nombreFichero, listaGenerica_t *agenda){
	FILE *fichero = NULL;
	fichero = fopen(nombreFichero, "rb+");
	if (existeFichero(nombreFichero)){
		while(!feof(fichero)){
			if (agenda->tamMax == agenda->numUsados){
				agenda->tamMax++;
				agenda->contactos = (contacto_t*)realloc(agenda->contactos, sizeof(contacto_t)*agenda->tamMax);
			}
			agenda->contactos[agenda->numUsados].nombre = leeLineaDinamicaFichero(fichero);
			agenda->contactos[agenda->numUsados].apellido = leeLineaDinamicaFichero(fichero);
			agenda->contactos[agenda->numUsados].telefono = leeLineaDinamicaFichero(fichero);
			agenda->numUsados++;
		}
	}
	else {
		printf("El fichero '%s' no existe.\n");
	}
	fclose(fichero);
}