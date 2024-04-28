/*
malloc(), realloc(), pila
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_OPCIONES 5 

typedef struct nodo_t{
	int numero;
	struct nodo_t *siguiente;
}nodo_t;

typedef struct listaNodos_t{
	nodo_t *nodos;
	int numNodos;
	int tamMax;
}listaNodos_t;

void apilar(listaNodos_t *pila);
void desapilar(listaNodos_t *pila);
void verUltimo(listaNodos_t pila);
int consultarEstado(listaNodos_t pila);
void imprimirPila(listaNodos_t pila);

int main (int argc, char **argv){
	listaNodos_t pila = {.nodos = NULL, .numNodos = 0, .tamMax = 0};
	int opcion = 0;
	while (opcion != MAX_OPCIONES){
		printf("1.Apilar nodo.\n2.Desapilar nodo.\n3.Ver ultimo.\n4. Imprimir pila.\n5. Salir.\n");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				apilar(&pila);
			break;
			case 2:
				if (!consultarEstado(pila)){
					printf("La pila esta vacia.\n");
				}
				else {
					desapilar(&pila);
				}
			break;
			case 3:
				if (!consultarEstado(pila)){
					printf("La pila esta vacia.\n");
				}
				else {
					verUltimo(pila);
				}
			break;
			case 4:
				if (!consultarEstado(pila)){
					printf("La pila esta vacia.\n");
				}
				else {
					imprimirPila(pila);
				}
			break;
			case 5:
				free(pila.nodos);
			break;
		}
	}
}

void apilar(listaNodos_t *pila){
	if (pila->numNodos == pila->tamMax){
		pila->tamMax++;
		pila->nodos = (nodo_t*)realloc(pila->nodos, sizeof(nodo_t)*pila->tamMax);
	}
	printf("Introduzca un numero: ");
	scanf("%d", &pila->nodos[pila->numNodos].numero);
	while(getchar() != '\n'); //Limpiar el buffer
	pila->numNodos++;
}

void desapilar(listaNodos_t *pila){
	pila->tamMax--;
	pila->numNodos--;
	nodo_t* nodosAux = (nodo_t*)malloc(sizeof(nodo_t)*pila->tamMax);
	for (int i = 0; i < pila->numNodos; i++){
		nodosAux[i] = pila->nodos[i];
	}
	free(pila->nodos);
	pila->nodos = nodosAux;
}

void verUltimo(listaNodos_t pila){
	printf("El ultimo nodo de la pila es: %d\n", pila.nodos[pila.numNodos-1].numero);
}

int consultarEstado(listaNodos_t pila){
	int resultado = 1; //Suponemos que la pila esta llena
	if (!pila.tamMax){
		resultado = 0;
	}
	return resultado;
}

void imprimirPila(listaNodos_t pila){
	for (int i = 0; i < pila.numNodos; i++){
		printf("Elemento %d: %d\n", i, pila.nodos[i].numero);
	}
}