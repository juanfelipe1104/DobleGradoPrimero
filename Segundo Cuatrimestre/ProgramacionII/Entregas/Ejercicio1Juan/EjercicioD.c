/*
Tienda de mesas
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100 //Maximo 100 mesas
#define MAX_OPCIONES 4 //Opciones menu
#define MAX_BUSCAR 14 //Maximo 14 (5 mesas por indices de 2 y 4 comas);

typedef enum material_e{
	plastico=0, madera=1, cristal=2, metal=3
}material_e;

typedef struct mesas_t{
	int alto;
	int ancho;
	int fondo;
	material_e material;
	float precio;
}mesas_t;

typedef struct listaMesas_t{
	mesas_t mesas[TAM_MAX];
	int tamMax;
	int numeroIntroducidos;
}listaMesas_t;

mesas_t ingresarMesa();
void imprimirMesas(listaMesas_t lista);
float calcularPrecio(listaMesas_t lista, char *cadena, int *comprobacion);

int main (int argc, char **argv){
	int opcion = 0, comprobacion = 1;
	char auxiliar[MAX_BUSCAR] = {'\0'};
	float precio = 0; 
	listaMesas_t listaMesas = {
		.tamMax = TAM_MAX,
		.numeroIntroducidos = 0
	};
	while (opcion != MAX_OPCIONES){
		printf("1. Introducir caracteristicas de una nueva mesa.\n2. Mostrar las mesas disponibles.\n3. Calcular precio pedido.\n4. Salir\n");
		scanf("%d", &opcion);
		while(getchar() != '\n'); // Limpiar el buffer
		switch (opcion){
			case 1:
				if (listaMesas.numeroIntroducidos < listaMesas.tamMax){
					listaMesas.mesas[listaMesas.numeroIntroducidos] = ingresarMesa();
					listaMesas.numeroIntroducidos++;
				}
				else {
					printf("Maximo numero de mesas ingresado (%d).\n", listaMesas.tamMax);
				}
			break;
			case 2:
				if (listaMesas.numeroIntroducidos){ //Si existe alguna mesa en el sistema
					imprimirMesas(listaMesas);
				}
				else {
					printf("No existen mesas en el sistema.\n");
				}
			break;
			case 3:
				if (listaMesas.numeroIntroducidos){
					printf("Hay %d mesas.\n", listaMesas.numeroIntroducidos);
					printf("Introduzca la lista de indices de mesas separadas por comas sin espacios. Maximo 5 mesas\n");
					scanf("%14s", auxiliar);
					while(getchar() != '\n'); // Limpiar el buffer
					precio = calcularPrecio(listaMesas, auxiliar, &comprobacion);
					if (comprobacion){
						printf("El precio final calculado es: %.2f\n", precio);
					}
				}
				else {
					printf("No existen mesas en el sistema.\n");
				}
			break;
			case 4: break;
			default:
				printf("La opcion '%d' no es correcta", opcion);
			break;
		}
	}
}

mesas_t ingresarMesa(){
	mesas_t mesa;
	printf("Introduzca alto: ");
	scanf("%d", &mesa.alto);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Introduzca ancho: ");
	scanf("%d", &mesa.ancho);
	while(getchar() != '\n'); // Limpiar el buffer
	printf("Introduzca fondo: ");
	scanf("%d", &mesa.fondo);
	while(getchar() != '\n'); // Limpiar el buffer
	do {
		printf("Introduzca material:\n0. Plastico.\n1. Cristal.\n2. Madera.\n3. Metal.\n");
		scanf("%d", &mesa.material);
		while(getchar() != '\n'); // Limpiar el buffer
		if ((mesa.material < 0)||(mesa.material > 3)){
			printf("Opcion incorrecta.\n");
		}
	}while ((mesa.material < 0)||(mesa.material > 3)); //Control de errores en caso de no elegir una opcion correcta
	printf("Introduzca precio: ");
	scanf("%f", &mesa.precio);
	while(getchar() != '\n'); // Limpiar el buffer
	return mesa;
}

void imprimirMesas(listaMesas_t lista){
	char *materiales[] = {"Plastico", "Cristal", "Madera", "Metal"};
	for (int i = 0; i < lista.numeroIntroducidos; i++){
		printf("==========\n");
		printf("Mesa: %d\n", i);
		printf("Alto: %d\n", lista.mesas[i].alto);
		printf("Ancho: %d\n", lista.mesas[i].ancho);
		printf("Fondo: %d\n", lista.mesas[i].fondo);
		printf("Material: %s\n", materiales[lista.mesas[i].material]);
		printf("Precio: %.2f\n", lista.mesas[i].precio);
	}
}

float calcularPrecio(listaMesas_t lista, char *cadena, int *comprobacion){
	char *error = NULL;
	float resultado = 0;
	int posicionMesa = 0, contadorAuxiliar = 0;
	char auxiliar[2] = {'\0'}; //Auxiliar para leer el caracter como un string y poder usar atoi (Maximo 2 ya que el numero maximo no supera tres cifras (100))
	*comprobacion = 1; //Suponemos que la comprobacion de strtol es cierta (1)
	while ((*cadena != '\0')&& (*comprobacion)){
		contadorAuxiliar = 0;
		while ((*cadena != ',') && (*cadena != '\0') && (*comprobacion)){
			auxiliar[contadorAuxiliar] = *cadena;
			contadorAuxiliar++;
			cadena++;
		}
		posicionMesa = (int)strtol(auxiliar, &error, 10);
		if (*error != '\0'){
			*comprobacion = 0;
			printf("Se ha ingresado un caracter no numerico\n");
		}
		else {
			if (posicionMesa < lista.numeroIntroducidos){
				resultado += lista.mesas[posicionMesa].precio;
			}
			if (*cadena != '\0'){
				cadena++; //Suprimir posiciones de coma
			}
		}
	}
	return resultado;
}