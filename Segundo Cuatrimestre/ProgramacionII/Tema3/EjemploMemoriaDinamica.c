/*
Ingresar alumnos U-tad
*/

#include <stdio.h>
#include <stdlib.h>

#define LEEDATO(formato,dato) scanf(formato,dato); while(getchar()!= '\n');
#define NUM_OPCIONES 3

typedef enum gruposUtad_e{
	IPR1A,IPR1B,IPR1C,MAIS,FIIS
}gruposUtad_e;

const char* gruposUtadNombre[] = {"IPR1A", "IPR1B", "IPR1C", "MAIS", "FIIS"}; 

typedef struct listaEnteros_t{
	int *numeros;
	int tamMax;
	int numUsados;
}listaEnteros_t;

typedef struct listaEdades_t{
	gruposUtad_e grupo;
	listaEnteros_t* edades;
}listaEdades_t;

typedef struct listaGrupos_t{
	listaEdades_t** edadesPorGrupo;
	int tamMax;
	int numUsados;
}listaGrupos_t;

void introduceEnListaNumeros(listaEnteros_t* lista,int posicion,int numero);
void pedirListaEdadesDeGrupo(listaEdades_t* edadesGrupo);
listaEdades_t* pedirNuevoGrupo();
int calcularMaximo(listaEdades_t* grupo);
int calcularMinimo(listaEdades_t* grupo);
float calcularMedia(listaEdades_t* grupo);

int main(int argc,char **argv){
	listaGrupos_t grupos={.edadesPorGrupo=NULL, .tamMax=0, .numUsados=0};
	int opcion = 0, maximo, minimo;
	float media = 0;
	while (opcion != NUM_OPCIONES){
		printf("1. Pedir Grupo\n2. Mostrar datos\n3. Salir\n");
		LEEDATO("%d",&opcion)
		switch(opcion){
			case 1:
				if(grupos.numUsados == grupos.tamMax){
					grupos.tamMax++;
					grupos.edadesPorGrupo=(listaEdades_t**)realloc(grupos.edadesPorGrupo, sizeof(listaEdades_t) * grupos.tamMax);
				}
				grupos.edadesPorGrupo[grupos.numUsados]=pedirNuevoGrupo();
				grupos.numUsados++;
			break;
			case 2:
				for(int i = 0; i < grupos.numUsados; i++){
					printf("Datos del grupo %s\n", gruposUtadNombre[grupos.edadesPorGrupo[i]->grupo]);
					media = calcularMedia(grupos.edadesPorGrupo[i]);
					maximo = calcularMaximo(grupos.edadesPorGrupo[i]);
					minimo = calcularMinimo(grupos.edadesPorGrupo[i]);
					printf("Media %.2f.\nMaximo %d.\nMinimo %d.\n", media, maximo, minimo);
				}
			break;
			case 3: break;
			default:
				printf("La opcion '%d' no es correcta", opcion);
			break;
		}
	}
	for (int i = 0; i < grupos.numUsados; i++){
		free(grupos.edadesPorGrupo[i]->edades->numeros);
		grupos.edadesPorGrupo[i]->edades->numeros = NULL;
		free(grupos.edadesPorGrupo[i]->edades);
		grupos.edadesPorGrupo[i]->edades = NULL;
		free(grupos.edadesPorGrupo[i]);
		grupos.edadesPorGrupo[i] = NULL;
	}
	free(grupos.edadesPorGrupo);
	grupos.edadesPorGrupo = NULL;
	return 0;
}

void introduceEnListaNumeros(listaEnteros_t* lista,int posicion,int numero){
	if(lista->tamMax <= posicion){
		lista->numeros = realloc(lista->numeros, sizeof(int)*(posicion+1));
		lista->tamMax = posicion+1;
	}
	lista->numeros[posicion]=numero;
	if(lista->numUsados <= posicion){
		lista->numUsados = posicion+1;
	}
}

void pedirListaEdadesDeGrupo(listaEdades_t* edadesGrupo){
	int edad = 0, posicion = 0;
	edadesGrupo->edades = NULL;
	edadesGrupo->edades = (listaEnteros_t*)realloc(edadesGrupo->edades, sizeof(listaEnteros_t));
	edadesGrupo->edades->numeros = NULL;
	edadesGrupo->edades->tamMax = 0;
	edadesGrupo->edades->numUsados = 0;
	printf("Introduzca edades del grupo %s, acabar con '-1'\n",gruposUtadNombre[edadesGrupo->grupo]);
	while(edad != -1){
		LEEDATO("%d",&edad);
		if(edad >= 0){
			introduceEnListaNumeros(edadesGrupo->edades, posicion, edad);
			posicion++;
		}
		else if (edad != -1){
			printf("Edad no valida\n");
		}
	}
}

listaEdades_t* pedirNuevoGrupo(){
	listaEdades_t* nuevaLista = NULL;
	nuevaLista = (listaEdades_t*)realloc(nuevaLista, sizeof(listaEdades_t));
	printf("Introduzca nombre del grupo.\n");
	printf("Grupos disponibles:\n");
	for(gruposUtad_e grupo=IPR1A; grupo<=FIIS; grupo++){
		printf("%d %s\n", grupo, gruposUtadNombre[grupo]);
	}
	LEEDATO("%d",&nuevaLista->grupo);
	pedirListaEdadesDeGrupo(nuevaLista);
	return nuevaLista;
}

int calcularMaximo(listaEdades_t* grupo){
	int maximo = grupo->edades->numeros[0];
	for(int i = 0; i < grupo->edades->numUsados; i++){
		if(grupo->edades->numeros[i] > maximo){
			maximo = grupo->edades->numeros[i];
		}
	}
	return maximo;
}

int calcularMinimo(listaEdades_t* grupo){
	int minimo = grupo->edades->numeros[0];
	for(int i = 0; i < grupo->edades->numUsados; i++){
		if(grupo->edades->numeros[i] < minimo){
			minimo = grupo->edades->numeros[i];
		}
	}
	return minimo;
}

float calcularMedia(listaEdades_t* grupo){
	float resultado = 0;
	for(int i = 0; i < grupo->edades->numUsados; i++){
		resultado += grupo->edades->numeros[i];
	}
	return resultado / grupo->edades->numUsados;
}