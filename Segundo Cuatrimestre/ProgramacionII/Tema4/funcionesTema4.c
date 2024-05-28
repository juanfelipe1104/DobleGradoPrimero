/*
Funciones Tema 4 (Ficheros)
*/

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

char *leeLineaDinamicaFichero(FILE *fichero){
	char *linea = NULL, letra = '\0';
	int numLetras = 0;
	do {
		letra = getc(fichero);
		linea = (char*)realloc(linea, sizeof(char)*(numLetras+1));
		linea[numLetras] = letra;
		numLetras++;
	}while((letra != '\n') && (letra != EOF));
	letras[numLetras-1] = '\0';
	return letras;
}

int tamanoFichero(char *nombreFichero){
	FILE *fichero = NULL;
	int size = 0;
	fichero = fopen(nombreFichero, "rb");
	if (fichero != NULL){
		fseek(fichero, 0, SEEK_END); //La primera posicion desde el final
		size = ftell(fichero);
		fclose(fichero);
	}
	return size;
}