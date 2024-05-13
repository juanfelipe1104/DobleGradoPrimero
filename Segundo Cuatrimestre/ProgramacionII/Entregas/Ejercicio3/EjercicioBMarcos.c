/*
Estrechar fichero
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_MAX_ARG 4

typedef struct string_t{
	char *cadena;
	int longitud;
}string_t;

void leeFichero(string_t *lineasFicheroIn, char *nombreFichero);
void estrecharFichero(string_t lineasFicheroIn, int tamMaxLinea, char *nombreFicheroOut);
string_t leeLineaDinamicaDeFichero (FILE *f);
string_t concatenaStrings(string_t string1, string_t string2);
int existeFichero(char *nombreFichero);

int main(int argc, char** argv){
	string_t lineasFicheroIn={.cadena = NULL, .longitud = 0};
	int tamMaxLinea = 0;
	char *error = NULL;
	if (argc != MIN_MAX_ARG){
		printf("El numero minimo y maximo de argumentos es 3.\n");
	}
	else {
		tamMaxLinea = (int)strtol(argv[3], &error, 10);
		if (*error != '\0'){
			printf("La cadena '%s' no es un numero.\n", argv[3]);
		}
		else {
			if (existeFichero(argv[1])){
				leeFichero(&lineasFicheroIn, argv[1]);
				estrecharFichero(lineasFicheroIn, tamMaxLinea, argv[2]);
				free(lineasFicheroIn.cadena);
				lineasFicheroIn.cadena = NULL;
			}
		}
	}
	return 0;
}

void leeFichero(string_t *lineasFicheroIn, char *nombreFichero){
	FILE *ficheroIn = NULL;
	string_t lineaAux = {.cadena = NULL, .longitud = 0};
	ficheroIn = fopen(nombreFichero, "rb");
	do {
		lineaAux = leeLineaDinamicaDeFichero(ficheroIn);
		*lineasFicheroIn = concatenaStrings(*lineasFicheroIn, lineaAux);
		free(lineaAux.cadena);
	}while(!feof(ficheroIn));
	fclose(ficheroIn);
}

void estrecharFichero(string_t lineasFicheroIn, int tamMaxLinea, char *nombreFicheroOut){
	string_t *lineasFicheroOut = NULL;
	int numBloques = 0, restoCaracteres = 0, numLineas = 0;
	char caracterSiguiente = '\0';
	FILE *ficheroOut = NULL;
	numBloques = lineasFicheroIn.longitud / tamMaxLinea;
	restoCaracteres = lineasFicheroIn.longitud % tamMaxLinea;
	for (int i = 0; i < numBloques; i++){
		lineasFicheroOut = (string_t*)realloc(lineasFicheroOut, sizeof(string_t)*(numLineas+1));
		lineasFicheroOut[numLineas].cadena = NULL;
		lineasFicheroOut[numLineas].longitud = 0;
		for (int j = 0; j < tamMaxLinea; j++){
			lineasFicheroOut[numLineas].cadena = (char*)realloc(lineasFicheroOut[numLineas].cadena, sizeof(char)*(lineasFicheroOut[numLineas].longitud+1));
			lineasFicheroOut[numLineas].cadena[j] = lineasFicheroIn.cadena[(i*tamMaxLinea)+j];
			lineasFicheroOut[numLineas].longitud++;
			caracterSiguiente = lineasFicheroIn.cadena[(i*tamMaxLinea)+j+1];
		}
		if ((lineasFicheroOut[numLineas].cadena[lineasFicheroOut[numLineas].longitud-1] != ' ')&&(caracterSiguiente != ' ')&&(caracterSiguiente != ',')){
			lineasFicheroOut[numLineas].cadena = (char*)realloc(lineasFicheroOut[numLineas].cadena, sizeof(char)*(lineasFicheroOut[numLineas].longitud+1));
			lineasFicheroOut[numLineas].cadena[lineasFicheroOut[numLineas].longitud] = '-';
			lineasFicheroOut[numLineas].longitud++;
			lineasFicheroOut[numLineas].cadena[lineasFicheroOut[numLineas].longitud] = '\0';
		}
		else {
			lineasFicheroOut[numLineas].cadena = (char*)realloc(lineasFicheroOut[numLineas].cadena, sizeof(char)*(lineasFicheroOut[numLineas].longitud));
			lineasFicheroOut[numLineas].cadena[lineasFicheroOut[numLineas].longitud] = '\0';
		}
		numLineas++;
	}
	ficheroOut = fopen(nombreFicheroOut, "wb");
	for (int i = 0; i < numLineas; i++){
		if (lineasFicheroOut[i].cadena[0] == ' '){
			lineasFicheroOut[i].cadena++;
		}
		fprintf(ficheroOut, "%s\n", lineasFicheroOut[i].cadena);
	}
	fclose(ficheroOut);
	for (int i = 0; i < numLineas; i++){
		free(lineasFicheroOut[i].cadena);
		lineasFicheroOut[i].cadena = NULL;
	}
	free(lineasFicheroOut);
	lineasFicheroOut = NULL;
}

string_t leeLineaDinamicaDeFichero (FILE *f){
	string_t linea={.cadena = NULL, .longitud = 0};
	char letraLeida = '\0';
	do{
		letraLeida = getc(f);
		linea.cadena = (char*)realloc(linea.cadena, sizeof(char)*(linea.longitud+1));
		linea.cadena[linea.longitud]= letraLeida;
		linea.longitud++;
	}while((letraLeida != '\n') && (letraLeida != EOF));
	if(letraLeida == '\n'){
		linea.cadena = (char*)realloc(linea.cadena, sizeof(char)*(linea.longitud+1));
		linea.cadena[linea.longitud-1] = ' ';
		linea.longitud++;
		linea.cadena[linea.longitud-1] = '\0';
	}
	else{
		linea.cadena[linea.longitud-1] = '\0';
	}
	return linea;
}

string_t concatenaStrings(string_t string1, string_t string2){
	string1.cadena = (char*)realloc(string1.cadena, sizeof(char) * (string1.longitud+string2.longitud+1));
	string1.cadena[string1.longitud] = '\0';
	string1.longitud += string2.longitud;
	strcat(string1.cadena, string2.cadena);
	return string1;
}

int existeFichero(char *nombreFichero){
	FILE *fichero = NULL;
	int existe = 1;
	fichero = fopen(nombreFichero, "rb");
	if(fichero == NULL){
		existe = 0;
	}
	else {
		fclose(fichero);
	}
	return existe;
}