/*
Funciones Tema 5 (Parseo de Cadenas)
*/

typedef struct lineas_t{
	int numLineas;
	char **lineas;
}lineas_t;

char *copiarCadenas(char *cadenaOrigen){
	char *cadenaDestino = NULL;
	cadenaDestino = (char*)realloc(cadenaDestino, strlen(cadenaOrigen)+1);
	cadenaDestino[0] = '\0';
	strcpy(cadenaDestino, cadenaOrigen);
	return cadenaDestino;
}

void ordenaCadenas(lineas_t *lineasFichero){
	char *auxiliar = NULL;
	for (int i = 0; i < lineasFichero->numLineas; i++){
		for (int j = i+1; j < lineasFichero->numLineas; j++){
			if(strcmp(lineasFichero->lineas[i],lineasFichero->lineas[j])>0){
				auxiliar = lineasFichero->lineas[i];
				lineasFichero->lineas[i] = lineasFichero->lineas[j];
				lineasFichero->lineas[j] = auxiliar;
			}
		}
	}
}